#include "DxLib.h"
#include "GameMainScene.h"
#include "Card.h"

#define PI    3.1415926535897932384626433832795f

//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•‚·‚é
AbstractScene* GameMainScene::Update()
{
	g_BackImage = LoadGraph("../images/GreenFelt.png");

	return this;
}

//•`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ğÀ‘•‚·‚é
void GameMainScene::Draw() const
{
	Card C;
	C.LoadImages();
	//”wŒi•`‰æˆ—
	DrawExtendGraph(0, 0, 1280, 720, g_BackImage, FALSE);
	DrawRotaGraph(480, 500, 1.0f, 0, C.s_1(), FALSE);
	DrawRotaGraph(560, 500, 1.0f, 0, C.s_2(), FALSE);
	DrawRotaGraph(640, 500, 1.0f, 0, C.s_3(), FALSE);
	DrawRotaGraph(720, 500, 1.0f, 0, C.s_4(), FALSE);
	DrawRotaGraph(800, 500, 1.0f, 0, C.s_5(), FALSE);
}