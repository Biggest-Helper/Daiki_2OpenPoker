#include "DxLib.h"
#include "GameMainScene.h"

//�`��ȊO�̍X�V����������
AbstractScene* GameMainScene::Update()
{
	return this;
}

//�`��Ɋւ��邱�Ƃ���������
void GameMainScene::Draw() const
{
	DrawString(100, 100, "Title", 0xffffff, TRUE);
	DrawString(200, 200, "START�{�^����GameMain", 0xffffff, TRUE);
}