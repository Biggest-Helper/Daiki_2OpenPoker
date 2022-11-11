#include "DxLib.h"
#include "GameMainScene.h"
#include "Card.h"
#include "Point.h"

#define PI    3.1415926535897932384626433832795f
int Flag = TRUE;

//�`��ȊO�̍X�V����������
AbstractScene* GameMainScene::Update()
{
	g_BackImage = LoadGraph("../images/GreenFelt.png");

	Point P;

	////�A���e�B����
	//P.Anty();

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

	//�v���C���[�ACPU�̏����x�b�g�`��
	pt.DrawHavePoints();

	//�x�b�g���v�`��
	pt.DrawSumBetPoints();



	//�����͈�x�����Ăяo��&�Q�Ƃ��A
	//�ȍ~�̃��[�v�͗�������n�����ϐ����Q�Ƃ���
	//�A���S���Y�������

	int GetCard[20];

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
		DrawRotaGraph(PosX, PosY, 1.0f, 0, GetCard[i], FALSE);
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
}