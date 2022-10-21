#pragma once
#include "AbstractScene.h"

class GameMainScene : public AbstractScene
{
private:

public:
	virtual ~GameMainScene()
	{

	}

	virtual AbstractScene* Update() override;

	virtual void Draw() const override;
};