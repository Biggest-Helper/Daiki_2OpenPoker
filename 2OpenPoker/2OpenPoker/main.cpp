#include "DxLib.h"
#include "time.h"
#include "SceneManager.h"
#include "GameMainScene.h"

//�Q�[���X�e�[�g
enum class GAME_STATE {
	GAME_TITLE,
	GAME_MAIN = 0,
	DRAW_END,
	DRAW_GAME_OVER,
	DRAW_GAME_CLEAR,

	EXIT = 99
};



/***********************************************
 * �N���X�^�ϐ�
 ***********************************************/
GameMainScene MAIN;
//SceneManeger sceneMng;



/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd) 
{
	srand(time(NULL));

	// �^�C�g���� test �ɕύX
	SetMainWindowText(" 2 Open Poker ");
	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��
	SetWindowSize(1280, 720);   //�E�B���h�E�̃T�C�Y�ύX
	SetGraphMode(1280, 720, 16);

	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	GAME_STATE	g_GameState = GAME_STATE::GAME_MAIN; // �Q�[���X�e�[�^�X
													 
	// �Q�[�����[�v
	while (ProcessMessage() == 0)
	{
		double dNextTime = GetNowCount();
		ClearDrawScreen();		// ��ʂ̏�����

		switch (g_GameState)
		{
		case GAME_STATE::GAME_MAIN:
			MAIN.Update();		       //�Q�[�����C������
			MAIN.Draw();
			break;
		}

		if (dNextTime + 16.66 > GetNowCount()) {
			WaitTimer((int)dNextTime - GetNowCount());
		}
		ScreenFlip();
	}

	DxLib_End();	// DX���C�u�����g�p�̏I������

	return 0;	// �\�t�g�̏I��
}