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

int	g_OldKey;				// �O��̓��̓L�[
int	g_NowKey;				// ����̓��̓L�[
int	g_KeyFlg;				// ���̓L�[���

/***********************************************
 * �N���X�^�ϐ�
 ***********************************************/
GameMainScene MAIN;

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd) 
{
	// �^�C�g���� test �ɕύX
	SetMainWindowText(" 2 Open Poker ");
	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��
	SetGraphMode(1280, 720, 32);

	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SetFontSize(20);		// �����T�C�Y��ݒ�

	GAME_STATE	g_GameState = GAME_STATE::GAME_MAIN; // �Q�[���X�e�[�^�X
													 
	// �Q�[�����[�v
	while (ProcessMessage() == 0 && g_GameState != GAME_STATE::EXIT)
	{
		// ���̓L�[�擾
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();		// ��ʂ̏�����
		
		switch (g_GameState)
		{
		case GAME_STATE::GAME_MAIN:
			MAIN.Update();		       //�Q�[�����C������
			MAIN.Draw();
			break;
		}
	}

	DxLib_End();	// DX���C�u�����g�p�̏I������

	return 0;	// �\�t�g�̏I��
}