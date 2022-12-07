#include "Dxlib.h"
#include "common.h"
#include "time.h"
#include "SceneManager.h"
#include "GameMainScene.h"
#include "Fps.h"




/***********************************************
 * クラス型変数
 ***********************************************/
GameMainScene MAIN;
//SceneManeger sceneMng;



/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd) 
{
	srand(time(NULL));

	// タイトルを test に変更
	SetMainWindowText(" 2 Open Poker ");
	ChangeWindowMode(TRUE);		// ウィンドウモードで起動
	SetWindowSize(1280, 720);   //ウィンドウのサイズ変更
	SetGraphMode(1280, 720, 16);

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	Fps* fps;
	fps = new Fps;

	GAME_STATE	g_GameState = GAME_STATE::GAME_MAIN; // ゲームステータス
													 
	// ゲームループ
	while (ProcessMessage() == 0)
	{
		double dNextTime = GetNowCount();
		ClearDrawScreen();		// 画面の初期化

		switch (g_GameState)
		{
		case GAME_STATE::GAME_TITLE:
			break;

		case GAME_STATE::GAME_MAIN:
			MAIN.Update();		       //ゲームメイン処理
			MAIN.Draw();

			fps->Update();
			fps->Draw();
			break;
		}

		if (dNextTime + 16.66 > GetNowCount()) {
			WaitTimer((int)dNextTime - GetNowCount());
		}
		ScreenFlip();
		fps->Wait();
	}
	
	DxLib_End();	// DXライブラリ使用の終了処理

	return 0;	// ソフトの終了
}
