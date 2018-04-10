#pragma once
#include "Singleton.h"

#include <thread>

class BattleShip;
enum STATE_TURN
{
	INTRO,
	READY,
	M_READY,
	M_ATTACK,
	M_ANIMATION,
	E_READY,
	E_ATTACK,
	E_ANIMATION
};
enum STATE_BATTLESHIP
{
	NONE1 = -1,
	NONE2,
	TWOSHIP1,
	TWOSHIP2,
	THREESHIP1,
	THREESHIP2,
	FOURSHIP1,
	FOURSHIP2
};
class StageManager :
	public Singleton<StageManager>
{
private:
	FRAME forgFrame;

public:
	vector<Forg*> forg;
	BattleShip *battleShip;
	bool isShoot;
	bool isanime;
	Bullet *bullet;
	D3DXVECTOR2 arrEffectPos[10];
	D3DXVECTOR2 arrShootPos[10];
	D3DXVECTOR2 effectPos;
	D3DXVECTOR2 *ShootPos;
	bool camZoom;
	BackGround *back;
	BackWorld *backWorld;
	FRAME frame;
	bool moreTurn;
	mTile *tile;
	STATE_TURN kind_turn;
	INT ship_Kind;
	INT kind_Change;
	eAI ai;
	int ShipCheck[3];
	int Shootnum;
	bool item;

public:
	void ImageInit();
	void Stage1Init();
	void Update();
	template<typename p>
	inline void lerp(p *dot, p p1, p p2, float d)
	{
		*dot = p1 + (p2 - p1) * d;
	}

	StageManager();
	virtual ~StageManager();
};

#define STAGEMANAGER StageManager::GetSingleton()