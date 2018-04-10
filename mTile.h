#pragma once

class Tile;
class BattleShip;
class mTile :
	public Object
{
public:
	Tile *tiles[10][10];
	Tile *etiles[10][10];
	void Init();
	void Update();
	void Render();
	void Release();
	bool SetTwoShip(Tile *tile[][10], OBJECT_STATE kind);
	bool SetThreeShip(Tile *tile[][10], OBJECT_STATE kind);
	bool SetFourShip(Tile *tile[][10], OBJECT_STATE kind);
	void AutoDisposition(Tile *tile[][10], OBJECT_STATE kind);

	mTile(OBJECT_STATE state)
	{
		obj_kind = state;
	}
	mTile();
	virtual ~mTile();
};

