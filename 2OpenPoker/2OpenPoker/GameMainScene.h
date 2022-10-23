#pragma once
#include "AbstractScene.h"

class GameMainScene : public AbstractScene
{
private:
	int g_BackImage = 0;
public:
	virtual ~GameMainScene()
	{

	}

	virtual AbstractScene* Update() override;

	virtual void Draw() const override;
};