#include "DXUT.h"
#include "EffectManager.h"



void EffectManager::AddEffect(string str, D3DXVECTOR2 pos, FLOAT _frame, FLOAT maxFrame, FLOAT _addFrame)
{
	Effect *effect = new Effect;
	effect->Init(str, pos, _frame, maxFrame, _addFrame);

	v_Effect.push_back(effect);
}

void EffectManager::Update()
{
	for (int i = 0; i < v_Effect.size(); i++)
	{
		if (!v_Effect[i]->Update())
			v_Effect.erase(v_Effect.begin() + i);
	}
}

void EffectManager::Render()
{
	for (int i = 0; i < v_Effect.size(); i++)
	{
		v_Effect[i]->Render();
	}
}

void EffectManager::Release()
{
	for (auto iter : v_Effect)
	{
		SAFE_DELETE(iter);
	}
	v_Effect.clear();
}

EffectManager::EffectManager()
{
}


EffectManager::~EffectManager()
{
}

void Effect::Init(string _str, D3DXVECTOR2 _pos, FLOAT _frame, FLOAT _maxFrame, FLOAT _addFrame)
{
	str = _str;
	pos = _pos;
	maxFrame = _maxFrame;
	frame = _frame;
	addFrame = _addFrame;
}

bool Effect::Update()
{
	if (frame < maxFrame)
		frame += addFrame;
	else
		return false;
}

void Effect::Render()
{
	char ctr[10];
	sprintf(ctr, "%d", (INT)frame);
	IMAGEMANAGER->DrawImage(str + ctr, pos - CAMERAMANAGER->camPos + (pos * CAMERAMANAGER->camAngle),
		0, 1 + CAMERAMANAGER->camAngle);
}
