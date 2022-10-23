#include "DxLib.h"
#include "GameMainScene.h"
#include "Card.h"

#define PI    3.1415926535897932384626433832795f

//�`��ȊO�̍X�V����������
AbstractScene* GameMainScene::Update()
{
	g_BackImage = LoadGraph("../images/GreenFelt.png");

	return this;
}

//�`��Ɋւ��邱�Ƃ���������
void GameMainScene::Draw() const
{
	Card C;
	DrawExtendGraph(0, 0, 1280, 720, g_BackImage, TRUE);
	DrawRotaGraph(270, 180, 1.0f, PI / 2, C.getCard(), TRUE);
}