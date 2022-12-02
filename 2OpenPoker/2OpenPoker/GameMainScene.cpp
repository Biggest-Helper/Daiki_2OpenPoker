#include "DxLib.h"
#include "GameMainScene.h"
#include "Card.h"
#include "Point.h"

#define PI    3.1415926535897932384626433832795f
int	g_OldKey;				// 前回の入力キー
int	g_NowKey;				// 今回の入力キー
int	g_KeyFlg;				// 入力キー情報
int GetCard[20];
int selectNum = 0;
int CardSelect = 0;
int Phase = 0;
int CardSelectFlg[5];
int DownKeyFlg = FALSE;


//描画以外の更新を実装する
AbstractScene* GameMainScene::Update()
{
	g_OldKey = g_NowKey;
	g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	g_KeyFlg = g_NowKey & ~g_OldKey;

	g_BackImage = LoadGraph("../images/GreenFelt.png");

	Point pt;



	if (Phese == 0)
	{
		//カーソル移動処理
		if (g_KeyFlg & PAD_INPUT_RIGHT)
		{
			selectNum++;
			if (selectNum > 2)
			{
				selectNum = 0;
			}
		}
		if (g_KeyFlg & PAD_INPUT_LEFT)
		{
			selectNum--;
			if (selectNum < 0)
			{
				selectNum = 2;
			}
		}

		//Aボタンで選択肢決定
		if (g_KeyFlg & PAD_INPUT_A)
		{
			//レイズ処理
			if (selectNum == 0)
			{
				pt.BetSelectFlg(selectNum);
				selectNum = 0;
				for (int i = 0; i < 5; i++)
				{
					if (i == 0)
					{
						CardSelectFlg[i] = TRUE;
					}
					else 
					{
						CardSelectFlg[i] = FALSE;
					}
				}
				Phese = 1;
			}

			//コール処理
			if (selectNum == 1)
			{
				pt.BetSelectFlg(selectNum);
				selectNum = 1;
				for (int i = 0; i < 5; i++)
				{
					if (i == 0)
					{
						CardSelectFlg[i] = TRUE;
					}
					else
					{
						CardSelectFlg[i] = FALSE;
					}
				}
				Phese = 1;
			}

			//フォールド処理
			if (selectNum == 2)
			{
				pt.BetSelectFlg(selectNum);
				selectNum = 2;
				for (int i = 0; i < 5; i++)
				{
					if (i == 0)
					{
						CardSelectFlg[i] = TRUE;
					}
					else
					{
						CardSelectFlg[i] = FALSE;
					}
				}
				Phese = 1;
			}
		}
	}



	if (Phese == 1)
	{
		//カーソル移動処理
		if (g_KeyFlg & PAD_INPUT_DOWN)
		{
			DownKeyFlg = TRUE;
		}
		else if (g_KeyFlg & PAD_INPUT_UP)
		{
			DownKeyFlg = FALSE;
		}
		
		if(DownKeyFlg == FALSE)
		{
			if (g_KeyFlg & PAD_INPUT_RIGHT)
			{
				CardSelect++;
				if (CardSelect > 4)
				{
					CardSelect = 0;
				}
			}
			if (g_KeyFlg & PAD_INPUT_LEFT)
			{
				CardSelect--;
				if (CardSelect < 0)
				{
					CardSelect = 4;
				}
			}
		}

		/*if (g_KeyFlg & PAD_INPUT_RIGHT)
		{
			CardSelect++;
			if (CardSelect > 4)
			{
				CardSelect = 0;
			}
		}
		if (g_KeyFlg & PAD_INPUT_LEFT)
		{
			CardSelect--;
			if (CardSelect < 0)
			{
				CardSelect = 4;
			}
		}
		if (g_KeyFlg & PAD_INPUT_DOWN && DownKeyFlg != TRUE)
		{
			DownKeyFlg == TRUE;
		}*/

		//Aボタンで選択肢決定
		if (DownKeyFlg == TRUE)
		{
			if (g_KeyFlg & PAD_INPUT_A)
			{
				Phese = 2;
			}
		}
		else if (DownKeyFlg == FALSE)
		{
			if (g_KeyFlg & PAD_INPUT_A)
			{
				if (CardSelectFlg[CardSelect] == FALSE)
				{
					CardSelectFlg[CardSelect] = TRUE;
				}
				else if (CardSelectFlg[CardSelect] == TRUE)
				{
					CardSelectFlg[CardSelect] = FALSE;
				}
			}
		}

		/*if (g_KeyFlg & PAD_INPUT_A)
		{
			if (CardSelectFlg[CardSelect] == FALSE)
			{
				CardSelectFlg[CardSelect] = TRUE;
			}
			else if (CardSelectFlg[CardSelect] == TRUE)
			{
				CardSelectFlg[CardSelect] = FALSE;
			}
		}*/
	}

	return this;
}

//描画に関することを実装する
void GameMainScene::Draw() const
{
	Card C;
	Point pt;
	C.LoadImages();
	//背景描画処理
	DrawExtendGraph(0, 0, 1280, 720, g_BackImage, FALSE);
	


	if (Phese == 0)
	{
		//プレイヤー、CPUの所持ベット描画
		//ベット合計描画
		pt.DrawPhese();
	}

	if (Phese == 1)
	{
		//プレイヤー、CPUの所持ベット描画
		//ベット合計描画
		pt.BetSelectFlg(selectNum);
	}



	//カード配布(プレイヤー)
	int PosX = 480;
	int PosY = 550;
	for (int i = 0; i < 5; i++)
	{
		GetCard[i] = C.CardDistribution();
		while (GetCard[i] == -1)
		{
			GetCard[i] = C.CardDistribution();
		}

		if (CardSelectFlg[i] == TRUE)
		{
			DrawRotaGraph(PosX, PosY - 10, 1.0f, 0, GetCard[i], FALSE);
		}
		else
		{
			DrawRotaGraph(PosX, PosY, 1.0f, 0, GetCard[i], FALSE);
		}

		PosX += 80;
	}

	//カード配布(CPU1)
	PosX = 330;
	PosY = 190;
	for (int i = 0; i < 5; i++)
	{
		GetCard[i + 5] = C.CardDistribution();
		while (GetCard[i + 5] == -1)
		{
			GetCard[i + 5] = C.CardDistribution();
		}
		if (i == 0 || i == 1)
		{
			DrawRotaGraph(PosX, PosY, 0.9f, PI / 2, GetCard[i + 5], FALSE);
			PosY += 80;
		}
		else
		{
			DrawRotaGraph(PosX, PosY, 0.9f, PI / 2, C.GetBack(), FALSE);
			PosY += 80;
		}
	}

	//カード配布(CPU2)
	PosX = 480;
	PosY = 160;
	for (int i = 0; i < 5; i++)
	{
		GetCard[i + 10] = C.CardDistribution();
		while (GetCard[i + 10] == -1)
		{
			GetCard[i + 10] = C.CardDistribution();
		}
		if (i == 0 || i == 1)
		{
			
			DrawRotaGraph(PosX, PosY, 1.0f, -PI, GetCard[i + 10], FALSE);
			PosX += 80;
		}
		else
		{
			DrawRotaGraph(PosX, PosY, 1.0f, -PI, C.GetBack(), FALSE);
			PosX += 80;
		}
	}

	//カード配布(CPU3)
	PosX = 950;
	PosY = 190;
	for (int i = 0; i < 5; i++)
	{
		GetCard[i + 15] = C.CardDistribution();
		while (GetCard[i + 15] == -1)
		{
			GetCard[i + 15] = C.CardDistribution();
		}
		if (i == 3 || i == 4)
		{
			
			DrawRotaGraph(PosX, PosY, 0.9f, PI / -2, GetCard[i + 15], FALSE);
			PosY += 80;
		}
		else
		{
			DrawRotaGraph(PosX, PosY, 0.9f, PI / -2, C.GetBack(), FALSE);
			PosY += 80;
		}
	}



	if (Phese == 0)
	{
		//選択肢描画
		SetFontSize(15);
		DrawBox(440, 650, 540, 690, GetColor(255, 255, 255), TRUE);
		DrawFormatString(464, 662, GetColor(0, 0, 0), "レイズ");
		DrawBox(590, 650, 690, 690, GetColor(255, 255, 255), TRUE);
		DrawFormatString(615, 662, GetColor(0, 0, 0), "コール");
		DrawBox(740, 650, 840, 690, GetColor(255, 255, 255), TRUE);
		DrawFormatString(748, 662, GetColor(0, 0, 0), "フォールド");

		//カーソル描画
		DrawBox(cursorX[selectNum], 650, cursorX[selectNum] + 100, 690, GetColor(255, 0, 0), FALSE);
	}

	if (Phese == 1)
	{
		SetFontSize(15);
		DrawBox(610, 615, 670, 645, GetColor(255, 255, 255), TRUE);
		DrawFormatString(624, 622, GetColor(0, 0, 0), "交換");

		//カーソル描画
		if (DownKeyFlg == TRUE)
		{
				DrawBox(610, 615, 670, 645, GetColor(255, 0, 0), FALSE);
		}
		else if (DownKeyFlg == FALSE)
		{
			if (CardSelectFlg[CardSelect] == TRUE)
			{
				DrawBox(cardCursorX[CardSelect] - 25, 505, cardCursorX[CardSelect] + 25, 575,
					GetColor(255, 0, 0), FALSE);
			}
			else
			{
				DrawBox(cardCursorX[CardSelect] - 25, 515, cardCursorX[CardSelect] + 25, 585, 
					GetColor(255, 0, 0), FALSE);
			}
		}

		/*if (CardSelectFlg[CardSelect] == TRUE)
		{
			DrawBox(cardCursorX[CardSelect] - 25, 505, cardCursorX[CardSelect] + 25, 575, GetColor(255, 0, 0), FALSE);
		}
		else
		{
			DrawBox(cardCursorX[CardSelect] - 25, 515, cardCursorX[CardSelect] + 25, 585, GetColor(255, 0, 0), FALSE);
		}*/
	}
}