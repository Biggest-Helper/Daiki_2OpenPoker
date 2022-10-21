#include "DxLib.h"
#include "GameMainScene.h"

//描画以外の更新を実装する
AbstractScene* GameMainScene::Update()
{
	return this;
}

//描画に関することを実装する
void GameMainScene::Draw() const
{
	DrawString(100, 100, "Title", 0xffffff, TRUE);
	DrawString(200, 200, "STARTボタンでGameMain", 0xffffff, TRUE);
}