#pragma once
#include "AbstractScene.h"

class GameMainScene : public AbstractScene
{
private:
	int g_BackImage = 0;
	int cursorX[3] = {440, 590, 740};

public:
	int Phese = 0;

public:
	virtual ~GameMainScene()
	{

	}

	virtual AbstractScene* Update() override;

	virtual void Draw() const override;

	int getSelectNum();
};