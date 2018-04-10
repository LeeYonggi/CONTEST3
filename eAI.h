#pragma once

enum AI_DIRECTION_STATE
{
	D_BOTTOM,
	D_LEFT,
	D_TOP,
	D_RIGHT
};
enum AI_ATTACK_STATE
{
	HUNTMODE,
	TARGETMODE
};
class eAI
{
private:
	AI_DIRECTION_STATE ai_direction;
	AI_ATTACK_STATE ai_attack;
	D3DXVECTOR2 data;
	int over;

public:
	int hit;
	void Init();
	void Update();
	void HitTile(int x, int y, AI_DIRECTION_STATE direction);
	bool HuntMode();
	bool TargetMode();


	eAI();
	virtual ~eAI();
};

