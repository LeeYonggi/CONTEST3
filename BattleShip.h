#pragma once
#include "Object.h"
#include "StageManager.h"

enum STATE_ENEMY
{
	MY,
	ENEMY
};

class BattleShip :
	public Object
{
private:
	vector<D3DXVECTOR2> point;
	int shipKind;
	bool animeOn;
public:
	D3DXVECTOR2 initPos;
	STATE_ENEMY kind;

public:
	void Init();
	void Update();
	void Render();
	void Release();
	bool IsDestroy(Tile *tile[][10]);
	void AnimeOn(bool is) { animeOn = is; }

	BattleShip(D3DXVECTOR2 _pos, D3DXVECTOR2 _point, STATE_BATTLESHIP kind)
	{
		pos = _pos;
		shipKind = kind;
		int ship_num = ceil((FLOAT)shipKind / 2);
		for (int i = 0; i < ship_num + 1; i++)
		{
			if(shipKind % 2 == 1)
				point.push_back(D3DXVECTOR2(_point.x + i, _point.y));
			else
				point.push_back(D3DXVECTOR2(_point.x, _point.y + i));
		}
	}
	BattleShip();
	virtual ~BattleShip();
};

