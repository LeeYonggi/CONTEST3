#pragma once
#include "Singleton.h"

struct Effect
{
	string str;
	D3DXVECTOR2 pos;
	FLOAT frame;
	FLOAT maxFrame;
	FLOAT addFrame;

	void Init(string _str, D3DXVECTOR2 _pos, FLOAT _frame, FLOAT _maxFrame, FLOAT _addFrame);
	bool Update();
	void Render();
};
class EffectManager :
	public Singleton<EffectManager>
{
private:
	vector<Effect*> v_Effect;

public:
	void AddEffect(string str, D3DXVECTOR2 pos, FLOAT _frame, FLOAT maxFrame, FLOAT _addFrame);
	void Update();
	void Render();
	void Release();

	EffectManager();
	virtual ~EffectManager();
};

#define EFFECTMANAGER EffectManager::GetSingleton()