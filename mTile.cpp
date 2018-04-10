#include "DXUT.h"
#include "mTile.h"
#include "BattleShip.h"
#define TILE_SIZE_WIDTH 25
#define TILE_SIZE_HEIGHT 14


void mTile::Init()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			tiles[i][j] = new Tile(D3DXVECTOR2(650 + j * TILE_SIZE_WIDTH - i * TILE_SIZE_WIDTH, 
				370 + i * TILE_SIZE_HEIGHT + j * TILE_SIZE_HEIGHT), j, i);
			tiles[i][j]->Init();

			etiles[i][j] = new Tile(D3DXVECTOR2(2550 + j * TILE_SIZE_WIDTH - i * TILE_SIZE_WIDTH,
				-290 + i * TILE_SIZE_HEIGHT + j * TILE_SIZE_HEIGHT), j, i);
			etiles[i][j]->Init();
		}
	}
}

bool mTile::SetTwoShip(Tile *tile[][10], OBJECT_STATE kind)
{
	int direction = rand() % 2;
	D3DXVECTOR2 vDirection;
	if (direction == 1)
	{
		vDirection.x = 1;
		vDirection.y = 0;
		direction = 0;
	}
	else
	{
		vDirection.x = 0;
		vDirection.y = 1;
		direction = 1;
	}
	int x = rand() % (int)(10 - vDirection.x);
	int y = rand() % (int)(10 - vDirection.y);
	for (int i = 0; i < 2; i++)
	{
		if (tile[y + (int)vDirection.y * i][x + (int)vDirection.x * i]->isShipOn) return false;
	}
	tile[y][x]->battleShip = dynamic_cast<BattleShip*>(OBJECTMANAGER->AddObject(kind,
		new BattleShip(tile[y][x]->campos, D3DXVECTOR2(x, y), STATE_BATTLESHIP(TWOSHIP1 + direction))));
	if (kind == OBJECT_STATE::M_OBJECT)
		tile[y][x]->battleShip->kind = MY;
	else
		tile[y][x]->battleShip->kind = ENEMY;
	for (int i = 0; i < 2; i++)
		tile[y + (int)vDirection.y * i][x + (int)vDirection.x * i]->isShipOn = true;
	return true;
}

bool mTile::SetThreeShip(Tile *tile[][10], OBJECT_STATE kind)
{
	int direction = rand() % 2;
	D3DXVECTOR2 vDirection;
	if (direction == 1)
	{
		vDirection.x = 2;
		vDirection.y = 0;
		direction = 0;
	}
	else
	{
		vDirection.x = 0;
		vDirection.y = 2;
		direction = 1;
	}
	int x = rand() % (int)(10 - vDirection.x);
	int y = rand() % (int)(10 - vDirection.y);
	if (vDirection.x > 0)
		vDirection.x = 1;
	if (vDirection.y > 0)
		vDirection.y = 1;
	for (int i = 0; i < 3; i++)
	{
		if (tile[y + (int)vDirection.y * i][x + (int)vDirection.x * i]->isShipOn) return false;
	}
	tile[y][x]->battleShip = dynamic_cast<BattleShip*>(OBJECTMANAGER->AddObject(kind,
		new BattleShip(tile[y][x]->campos, D3DXVECTOR2(x, y), STATE_BATTLESHIP(THREESHIP1 + direction))));
	if (kind == OBJECT_STATE::M_OBJECT)
		tile[y][x]->battleShip->kind = MY;
	else
		tile[y][x]->battleShip->kind = ENEMY;
	for (int i = 0; i < 3; i++)
		tile[y + (int)vDirection.y * i][x + (int)vDirection.x * i]->isShipOn = true;
	return true;
}

bool mTile::SetFourShip(Tile *tile[][10], OBJECT_STATE kind)
{
	int direction = rand() % 2;
	D3DXVECTOR2 vDirection;
	if (direction == 1)
	{
		vDirection.x = 3;
		vDirection.y = 0;
		direction = 0;
	}
	else
	{
		vDirection.x = 0;
		vDirection.y = 3;
		direction = 1;
	}

	int x = rand() % static_cast<int>(10 - vDirection.x);
	int y = rand() % static_cast<int>(10 - vDirection.y);
	if (vDirection.x > 0)
		vDirection.x = 1;
	if (vDirection.y > 0)
		vDirection.y = 1;
	for (int i = 0; i < 4; i++)
	{
		if (tile[y + (int)vDirection.y * i][x + (int)vDirection.x * i]->isShipOn) return false;
	}
	tile[y][x]->battleShip = dynamic_cast<BattleShip*>(OBJECTMANAGER->AddObject(kind,
		new BattleShip(tile[y][x]->campos, D3DXVECTOR2(x, y), STATE_BATTLESHIP(FOURSHIP1 + direction))));
	if(kind == OBJECT_STATE::M_OBJECT)
		tile[y][x]->battleShip->kind = MY;
	else
		tile[y][x]->battleShip->kind = ENEMY;
	for (int i = 0; i < 4; i++)
		tile[y + (int)vDirection.y * i][x + (int)vDirection.x * i]->isShipOn = true;
	return true;
}

void mTile::AutoDisposition(Tile *tile[][10], OBJECT_STATE kind)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			tile[i][j]->Init();
		}
	}
	for (int i = 0; i < 2; i++)
	{
		while (true)
		{
			if (SetTwoShip(tile, kind))
				break;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		while (true)
		{
			if (SetThreeShip(tile, kind))
				break;
		}
	}
	while (true)
	{
		if (SetFourShip(tile, kind))
			break;
	}
	for(int i = 0; i < 3; i++)
		STAGEMANAGER->ShipCheck[i] = 0;
}

void mTile::Update()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			if (!tiles[i][j]->colorCheck)
				tiles[i][j]->SetColor(Color(255, 255, 255, 255));
			if (!etiles[i][j]->colorCheck)
				etiles[i][j]->SetColor(Color(255, 255, 255, 255));
		}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			tiles[i][j]->Update();
			etiles[i][j]->Update();
		}
	}
}

void mTile::Render()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			tiles[i][j]->Render();
			etiles[i][j]->Render();
		}
	}
}

void mTile::Release()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			SAFE_RELEASE(tiles[i][j]);
			SAFE_DELETE(tiles[i][j]);
			SAFE_RELEASE(etiles[i][j]);
			SAFE_DELETE(etiles[i][j]);
		}
	}
}



mTile::mTile()
{
}


mTile::~mTile()
{
}
