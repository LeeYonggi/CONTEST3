#pragma once
#include "BaseScene.h"
class MainScene :
	public BaseScene
{
private:
	float scale;
	bool isScale;
public:
	void Init();
	void Update();
	void Render();
	void Release();

	MainScene();
	virtual ~MainScene();
};

