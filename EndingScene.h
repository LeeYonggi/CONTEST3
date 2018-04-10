#pragma once
#include "BaseScene.h"
class EndingScene :
	public BaseScene
{
private:
	FRAME frame;
	bool screen;

public:
	void Init();
	void Update();
	void Render();
	void Release();

	EndingScene();
	virtual ~EndingScene();
};

