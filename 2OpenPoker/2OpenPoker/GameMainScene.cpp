#include "DxLib.h"
#include "GameMainScene.h"

//�`��ȊO�̍X�V����������
AbstractScene* GameMainScene::Update()
{
	g_BackImage = LoadGraph("../images/GreenFelt.png");

	return this;
}

//�`��Ɋւ��邱�Ƃ���������
void GameMainScene::Draw() const
{
	DrawExtendGraph(0, 0, 1280, 720, g_BackImage, TRUE);
}