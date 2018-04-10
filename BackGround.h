#pragma once
#include "Object.h"
class BackGround :
	public Object
{
private:
	FRAME frame;
public:
	void Init();
	void Update();
	void Render();
	void Release();

	BackGround();
	virtual ~BackGround();
};

