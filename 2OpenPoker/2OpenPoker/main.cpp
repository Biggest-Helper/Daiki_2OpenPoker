#include "DxLib.h"
#include "time.h"
#include "GameMainScene.h"

//ゲームステート
enum class GAME_STATE {
	GAME_TITLE,
	GAME_MAIN = 0,
	DRAW_RANKING,
	DRAW_END,
	DRAW_GAME_OVER,
	DRAW_GAME_CLEAR,
	INPUT_RANKING,

	EXIT = 99
};



/***********************************************
 * クラス型変数
 ***********************************************/
GameMainScene MAIN;



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
	SetGraphMode(1280, 720, 32);   //ウィンドウのサイズ変更

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	SetFontSize(20);		// 文字サイズを設定

	GAME_STATE	g_GameState = GAME_STATE::GAME_MAIN; // ゲームステータス
													 
	// ゲームループ
	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();		// 画面の初期化
		
		switch (g_GameState)
		{
		case GAME_STATE::GAME_MAIN:
			MAIN.Update();		       //ゲームメイン処理
			MAIN.Draw();
			break;
		}
	}

	DxLib_End();	// DXライブラリ使用の終了処理

	return 0;	// ソフトの終了
}