#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene
{
private:
	int g_BackImage = 0;

public:
	virtual ~Title()
	{

	}

	virtual AbstractScene* Update() override;

	virtual void Draw() const override;
};

