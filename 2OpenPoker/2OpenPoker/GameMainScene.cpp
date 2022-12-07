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
int DownKeyFlg = FALSE;


//�`��ȊO�̍X�V����������
AbstractScene* GameMainScene::Update()
{
	g_OldKey = g_NowKey;
	g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	g_KeyFlg = g_NowKey & ~g_OldKey;

	////�f�o�b�O�p
	g_BackImage = LoadGraph("../images/GreenFelt.png");

	//�����[�X�p
	/*g_BackImage = LoadGraph("images/GreenFelt.png");*/

	Point pt;

	//BACK�{�^���������ꂽ��Q�[���I��
	if (g_KeyFlg & 1024)
	{
		DxLib_End();

		return 0;
	}

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
				/*for (int i = 0; i < 5; i++)
				{
					if (i == 0)
					{
						CardSelectFlg[i] = TRUE;
					}
					else 
					{
						CardSelectFlg[i] = FALSE;
					}
				}*/
				Phese = 0;
			}

			//�R�[������
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

			//�t�H�[���h����
			if (selectNum == 2)
			{
				pt.BetSelectFlg(selectNum);
				selectNum = 2;
				for (int i = 0; i < 5; i++)
				{
					CardSelectFlg[i] = FALSE;
				}
				Phese = 2;
			}
		}
	}



	if (Phese == 1)
	{
		//�J�[�\���ړ�����
		//�����{�^���I��
		if (g_KeyFlg & PAD_INPUT_DOWN)
		{
			DownKeyFlg = TRUE;
		}
		else if (g_KeyFlg & PAD_INPUT_UP)
		{
			DownKeyFlg = FALSE;
		}
		
		//�J�[�h�I��
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

		

		//A�{�^���őI��������
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
		//if (Phese > 1)
		//{
		//	//�J�[�h��������
		//	if (CardSelectFlg[i] == TRUE)
		//	{
		//		GetCard[i] = C.CardDistribution(i);
		//		while (GetCard[i] == -1)
		//		{
		//			GetCard[i] = C.CardDistribution(i);
		//		}
		//		CardSelectFlg[i] = FALSE;
		//	}
		//	else if(CardSelectFlg[i] == FALSE)
		//	{
		//		DrawRotaGraph(PosX, PosY, 1.0f, 0, GetCard[i], FALSE);
		//	}
		//	PosX += 80;
		//}
		//else 
		//{
			GetCard[i] = C.CardDistribution(i);
			while (GetCard[i] == -1)
			{
				GetCard[i] = C.CardDistribution(i);
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
		/*}*/
	}

	//�J�[�h�z�z(CPU1)
	PosX = 330;
	PosY = 190;
	for (int i = 5; i < 10; i++)
	{
		GetCard[i] = C.CardDistribution(i);
		while (GetCard[i] == -1)
		{
			GetCard[i] = C.CardDistribution(i);
		}

		//2���̃J�[�h�̂݃I�[�v���ɂ���
		if (i == 5 || i == 6)
		{
			DrawRotaGraph(PosX, PosY, 0.9f, PI / 2, GetCard[i], FALSE);
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
	for (int i = 10; i < 15; i++)
	{
		GetCard[i] = C.CardDistribution(i);
		while (GetCard[i] == -1)
		{
			GetCard[i] = C.CardDistribution(i);
		}

		//2���̃J�[�h�̂݃I�[�v���ɂ���
		if (i == 10 || i == 11)
		{
			
			DrawRotaGraph(PosX, PosY, 1.0f, -PI, GetCard[i], FALSE);
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
	for (int i = 15; i < 20; i++)
	{
		GetCard[i] = C.CardDistribution(i);
		while (GetCard[i] == -1)
		{
			GetCard[i] = C.CardDistribution(i);
		}

		//2���̃J�[�h�̂݃I�[�v���ɂ���
		if (i == 18 || i == 19)
		{
			
			DrawRotaGraph(PosX, PosY, 0.9f, PI / -2, GetCard[i], FALSE);
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
		//�����I�����`��
		SetFontSize(15);
		DrawBox(610, 615, 670, 645, GetColor(255, 255, 255), TRUE);
		DrawFormatString(624, 622, GetColor(0, 0, 0), "����");

		//�J�[�\���`��
		//�����I���J�[�\��
		if (DownKeyFlg == TRUE)
		{
				DrawBox(610, 615, 670, 645, GetColor(255, 0, 0), FALSE);
		}
		else if (DownKeyFlg == FALSE)
		{
			//�J�[�h�I���J�[�\��
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
	}
}