#pragma once
#include "AbstractScene.h"

//�V�[���}�l�[�W���[�N���X
//�e�V�[���̐؂�ւ����Ǘ�����
class SceneManeger : public AbstractScene
{
private:
	AbstractScene* mScene;     //���݂̃V�[��

public:
	//�R���X�g���N�^
	SceneManeger(AbstractScene* scene) : mScene(scene) { }

	//�f�X�g���N�^
	~SceneManeger()
	{
		delete mScene;
	}

	//�`��ȊO�̍X�V����������
	AbstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	void Draw() const override;
};