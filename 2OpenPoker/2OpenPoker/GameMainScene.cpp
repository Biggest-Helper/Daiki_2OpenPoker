#include "DxLib.h"
#include "GameMainScene.h"
#include "Card.h"
#include "Point.h"

#define PI    3.1415926535897932384626433832795f
int	g_OldKey;				// �O��̓��̓L�[
int	g_NowKey;				// ����̓��̓L�[
int	g_KeyFlg;				// ���̓L�[���
int GetCard[20];
int selectNum = 0;
int CardSelect = 0;
int Phase = 0;
int CardSelectFlg[5];


//�`��ȊO�̍X�V����������
AbstractScene* GameMainScene::Update()
{
	g_OldKey = g_NowKey;
	g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	g_KeyFlg = g_NowKey & ~g_OldKey;

	g_BackImage = LoadGraph("../images/GreenFelt.png");

	Point pt;



	if (Phese == 0)
	{
		//�J�[�\���ړ�����
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

		//A�{�^���őI��������
		if (g_KeyFlg & PAD_INPUT_A)
		{
			//���C�Y����
			if (selectNum == 0)
			{
				pt.BetSelectFlg(selectNum);
				selectNum = 0;
				CardSelectFlg[selectNum] = FALSE;
				Phese = 1;
			}

			//�R�[������
			if (selectNum == 1)
			{
				pt.BetSelectFlg(selectNum);
				selectNum = 1;
				CardSelectFlg[selectNum] = FALSE;
				Phese = 1;
			}

			//�t�H�[���h����
			if (selectNum == 2)
			{
				pt.BetSelectFlg(selectNum);
				selectNum = 2;
				CardSelectFlg[selectNum] = FALSE;
				Phese = 1;
			}
		}
	}



	if (Phese == 1)
	{
		//�J�[�\���ړ�����
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

		//A�{�^���őI��������
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

	return this;
}

//�`��Ɋւ��邱�Ƃ���������
void GameMainScene::Draw() const
{
	Card C;
	Point pt;
	C.LoadImages();
	//�w�i�`�揈��
	DrawExtendGraph(0, 0, 1280, 720, g_BackImage, FALSE);
	


	if (Phese == 0)
	{
		//�v���C���[�ACPU�̏����x�b�g�`��
		//�x�b�g���v�`��
		pt.DrawPhese();
	}

	if (Phese == 1)
	{
		//�v���C���[�ACPU�̏����x�b�g�`��
		//�x�b�g���v�`��
		pt.BetSelectFlg(selectNum);
	}



	//�J�[�h�z�z(�v���C���[)
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

	//�J�[�h�z�z(CPU1)
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

	//�J�[�h�z�z(CPU2)
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

	//�J�[�h�z�z(CPU3)
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
		//�I�����`��
		SetFontSize(15);
		DrawBox(440, 650, 540, 690, GetColor(255, 255, 255), TRUE);
		DrawFormatString(464, 662, GetColor(0, 0, 0), "���C�Y");
		DrawBox(590, 650, 690, 690, GetColor(255, 255, 255), TRUE);
		DrawFormatString(615, 662, GetColor(0, 0, 0), "�R�[��");
		DrawBox(740, 650, 840, 690, GetColor(255, 255, 255), TRUE);
		DrawFormatString(748, 662, GetColor(0, 0, 0), "�t�H�[���h");

		//�J�[�\���`��
		DrawBox(cursorX[selectNum], 650, cursorX[selectNum] + 100, 690, GetColor(255, 0, 0), FALSE);
	}

	if (Phese == 1)
	{
		if (CardSelectFlg[CardSelect] == TRUE)
		{
			DrawBox(cardCursorX[CardSelect] - 25, 505, cardCursorX[CardSelect] + 25, 575, GetColor(255, 0, 0), FALSE);
		}
		else
		{
			DrawBox(cardCursorX[CardSelect] - 25, 515, cardCursorX[CardSelect] + 25, 585, GetColor(255, 0, 0), FALSE);
		}
	}
}