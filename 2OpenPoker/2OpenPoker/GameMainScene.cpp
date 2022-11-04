#include "DxLib.h"
#include "GameMainScene.h"
#include "Card.h"
#include "Point.h"

#define PI    3.1415926535897932384626433832795f
int Flag = TRUE;

//描画以外の更新を実装する
AbstractScene* GameMainScene::Update()
{
	g_BackImage = LoadGraph("../images/GreenFelt.png");

	Point P;

	//アンティ処理
	P.Anty();

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

	//ベット合計描画
	pt.DrawSumBetPoints();

	int GetCard[20];

	//カード配布(プレイヤー)
	int PosX = 480;
	int PosY = 550;
	for (int i = 0; i < 5; i++)
	{
		GetCard[i] = C.CardDistribution();
		DrawRotaGraph(PosX, PosY , 1.0f, 0, GetCard[i], FALSE);
		PosX += 80;
	}

	//カード配布(CPU1)
	PosX = 330;
	PosY = 190;
	for (int i = 0; i < 5; i++)
	{
		GetCard[i + 5] = C.CardDistribution();
		DrawRotaGraph(PosX, PosY, 0.9f, PI / 2, GetCard[i + 5], FALSE);
		PosY += 80;
	}

	//カード配布(CPU2)
	PosX = 480;
	PosY = 160;
	for (int i = 0; i < 5; i++)
	{
		GetCard[i + 10] = C.CardDistribution();
		DrawRotaGraph(PosX, PosY, 1.0f, -PI, GetCard[i + 10], FALSE);
		PosX += 80;
	}

	//カード配布(CPU3)
	PosX = 950;
	PosY = 190;
	for (int i = 0; i < 5; i++)
	{
		GetCard[i + 15] = C.CardDistribution();
		DrawRotaGraph(PosX, PosY, 0.9f, PI / -2, GetCard[i + 15], FALSE);
		PosY += 80;
	}
}