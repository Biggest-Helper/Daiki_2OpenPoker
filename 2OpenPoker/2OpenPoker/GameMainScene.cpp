#include "DxLib.h"
#include "GameMainScene.h"
#include "Card.h"
#include "Point.h"

#define PI    3.1415926535897932384626433832795f

//�`��ȊO�̍X�V����������
AbstractScene* GameMainScene::Update()
{
	g_BackImage = LoadGraph("../images/GreenFelt.png");

	Point P;
	P.Anty();

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

	//�v���C���[��D
	DrawRotaGraph(480, 500, 1.0f, 0, C.s_1(), FALSE);
	DrawRotaGraph(560, 500, 1.0f, 0, C.s_2(), FALSE);
	DrawRotaGraph(640, 500, 1.0f, 0, C.s_3(), FALSE);
	DrawRotaGraph(720, 500, 1.0f, 0, C.s_4(), FALSE);
	DrawRotaGraph(800, 500, 1.0f, 0, C.s_5(), FALSE);

	//�J�[�h�z�z
	/*for (int i = 0; i < 5; i++)
	{
		int GetCard = C.CardDistribution();
		DrawRotaGraph(480, 500, 1.0f, 0, GetCard, FALSE);
	}*/

}