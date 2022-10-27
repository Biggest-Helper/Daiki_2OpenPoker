#include "DxLib.h"
#include "GameMainScene.h"
#include "Card.h"

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
	DrawExtendGraph(0, 0, 1280, 720, g_BackImage, FALSE);
	/*DrawString(200, 200, "テストテストあー、あー、", 0xffffff);*/
	DrawRotaGraph(0, 180, 1.0f, 0, C.s_1(), FALSE);
	DrawRotaGraph(50, 180, 1.0f, 0, C.s_2(), FALSE);
	DrawRotaGraph(100, 180, 1.0f, 0, C.s_3(), FALSE);
	DrawRotaGraph(150, 180, 1.0f, 0, C.s_4(), FALSE);
	DrawRotaGraph(200, 180, 1.0f, 0, C.s_5(), FALSE);
	DrawRotaGraph(250, 180, 1.0f, 0, C.s_6(), FALSE);
}