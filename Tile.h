#pragma once

class BattleShip;
class Tile : 
	public Object
{
protected:
	float tempradius;
	D3DXVECTOR2 point;
	D3DXVECTOR2 mouse;

public:
	D3DXVECTOR2 campos;
	BattleShip *battleShip;
	bool colorCheck;
	bool isShipOn;
	bool isBoom;
	bool isDestroy;
	void Init();
	void Update();
	void Render();
	void Release();
	void Setutility();
	
	Tile(D3DXVECTOR2 _pos, FLOAT _pointx, FLOAT _pointy)
	{
		pos = _pos;
		campos = pos;
		point.x = _pointx;
		point.y = _pointy;
	}
	Tile();
	virtual ~Tile();
};

