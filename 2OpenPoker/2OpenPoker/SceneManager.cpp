#include "SceneManager.h"

AbstractScene* SceneManeger::Update()
{
	AbstractScene* p = mScene->Update();
	if (p != mScene)
	{
		delete mScene;
		mScene = p;
	}

	return p;
}

void SceneManeger::Draw() const
{
	mScene->Draw();
}