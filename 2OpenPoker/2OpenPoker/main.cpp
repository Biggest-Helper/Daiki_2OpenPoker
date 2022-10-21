#include "DxLib.h"
#include "GameMainScene.h"

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

int	g_OldKey;				// 前回の入力キー
int	g_NowKey;				// 今回の入力キー
int	g_KeyFlg;				// 入力キー情報

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
	// タイトルを test に変更
	SetMainWindowText(" 2 Open Poker ");
	ChangeWindowMode(TRUE);		// ウィンドウモードで起動
	SetGraphMode(1280, 720, 32);

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SetFontSize(20);		// 文字サイズを設定

	GAME_STATE	g_GameState = GAME_STATE::GAME_MAIN; // ゲームステータス
													 
	// ゲームループ
	while (ProcessMessage() == 0 && g_GameState != GAME_STATE::EXIT)
	{
		// 入力キー取得
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

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