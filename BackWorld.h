#pragma once
#include "Object.h"
class BackWorld :
	public Object
{
public:
	void Init();
	void Update();
	void Render();
	void Release();

	BackWorld();
	virtual ~BackWorld();
};

