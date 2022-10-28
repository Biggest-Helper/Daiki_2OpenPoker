#include "DxLib.h"
#include "GameMainScene.h"
#include "Card.h"
#include "Point.h"

#define PI    3.1415926535897932384626433832795f

//描画以外の更新を実装する
AbstractScene* GameMainScene::Update()
{
	g_BackImage = LoadGraph("../images/GreenFelt.png");

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

	//プレイヤー、CPUの所持ベット描画
	pt.DrawHavePoints();
	pt.DrawSumBetPoints();

	//プレイヤー手札
	DrawRotaGraph(480, 500, 1.0f, 0, C.s_1(), FALSE);
	DrawRotaGraph(560, 500, 1.0f, 0, C.s_2(), FALSE);
	DrawRotaGraph(640, 500, 1.0f, 0, C.s_3(), FALSE);
	DrawRotaGraph(720, 500, 1.0f, 0, C.s_4(), FALSE);
	DrawRotaGraph(800, 500, 1.0f, 0, C.s_5(), FALSE);
}