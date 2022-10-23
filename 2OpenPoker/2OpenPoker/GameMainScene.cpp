#include "DxLib.h"
#include "GameMainScene.h"

//描画以外の更新を実装する
AbstractScene* GameMainScene::Update()
{
	g_BackImage = LoadGraph("../images/GreenFelt.png");

	return this;
}

//描画に関することを実装する
void GameMainScene::Draw() const
{
	DrawExtendGraph(0, 0, 1280, 720, g_BackImage, TRUE);
}