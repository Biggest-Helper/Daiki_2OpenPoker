#include "DxLib.h"
#include "GameMainScene.h"

//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•‚·‚é
AbstractScene* GameMainScene::Update()
{
	g_BackImage = LoadGraph("../images/GreenFelt.png");

	return this;
}

//•`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ğÀ‘•‚·‚é
void GameMainScene::Draw() const
{
	DrawExtendGraph(0, 0, 1280, 720, g_BackImage, TRUE);
}