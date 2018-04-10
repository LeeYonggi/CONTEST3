#include "DXUT.h"
#include "Tile.h"
#include "BattleShip.h"


void Tile::Init()
{
	color = Color(255, 255, 255, 255);
	colorCheck = false;
	radius = 7;
	tempradius = 7;
	isShipOn = false;
	isBoom = false;
	isDestroy = false;
	center = pos;
}

void Tile::Setutility()
{
	radius = tempradius + (tempradius * CAMERAMANAGER->camAngle * 3);
	mouse.x = INPUTMANAGER->GetMousePos().x + CAMERAMANAGER->camPos.x;
	mouse.y = INPUTMANAGER->GetMousePos().y + CAMERAMANAGER->camPos.y;
}

void Tile::Update()
{
	D3DXVECTOR2 camPos = CAMERAMANAGER->camPos;
	float camAngle = CAMERAMANAGER->camAngle;
	pos = campos - camPos + (campos * camAngle);
	center = campos + (campos * camAngle);
	Setutility();
	auto tiles = STAGEMANAGER->tile->tiles;
	int shipnum = ceil((FLOAT)STAGEMANAGER->ship_Kind / 2);
	int shipCount = STAGEMANAGER->ship_Kind;
	POINT exitTile = {1, 1};
	if (point.x + shipnum > 9)
	{
		exitTile.x = -1;
	}
	if (point.y + shipnum > 9)
	{
		exitTile.y = -1;
	}
	switch (STAGEMANAGER->kind_turn)
	{
	case READY:
		if (IsCollision_dot(mouse))
		{
			if (shipCount == -1 || shipCount == 0) break;
			if (STAGEMANAGER->ShipCheck[shipnum - 1] <= 0) break;
			for (int i = 0; i < shipnum + 1; i++)
			{
				if(shipCount % 2 == 1)
					if(tiles[(int)point.y][(int)point.x + i * exitTile.x]->isShipOn)
						return;
				if (shipCount % 2 == 0)
					if (tiles[(int)point.y + i * exitTile.y][(int)point.x]->isShipOn)
						return;
			}
			for (int i = 0; i < shipnum + 1; i++)
			{
				if (STAGEMANAGER->ship_Kind % 2 == 1)
					tiles[(int)point.y][(int)point.x + i * exitTile.x]->SetColor(Color(255, 0, 0, 255));
				if (STAGEMANAGER->ship_Kind % 2 == 0)
					tiles[(int)point.y + i * exitTile.y][(int)point.x]->SetColor(Color(255, 0, 0, 255));
			}
			if (STAGEMANAGER->ship_Kind % 2 == 1 && INPUTMANAGER->KeyDown(VK_LBUTTON) == true)
			{
				battleShip = dynamic_cast<BattleShip*>(OBJECTMANAGER->AddObject(M_OBJECT,
					new BattleShip(tiles[(int)point.y][(int)point.x + (int)ceil((float)shipnum * exitTile.x / 2)]->campos, point, (STATE_BATTLESHIP)shipCount)));
				battleShip->kind = MY;
				for (int i = 0; i < shipnum + 1; i++)
				{
					if (STAGEMANAGER->ship_Kind % 2 == 1)
						tiles[(int)point.y][(int)point.x + i * exitTile.x]->isShipOn = true;
					if (STAGEMANAGER->ship_Kind % 2 == 0)
						tiles[(int)point.y + i * exitTile.y][(int)point.x]->isShipOn = true;
				}
				STAGEMANAGER->ShipCheck[shipnum - 1] -= 1;
			}
			if (STAGEMANAGER->ship_Kind % 2 == 0 && INPUTMANAGER->KeyDown(VK_LBUTTON) == true)
			{
				battleShip = dynamic_cast<BattleShip*>(OBJECTMANAGER->AddObject(M_OBJECT,
					new BattleShip(tiles[(int)point.y + (int)ceil((float)shipnum * exitTile.y / 2)][(int)point.x]->campos, point, (STATE_BATTLESHIP)shipCount)));
				battleShip->kind = MY;
				for (int i = 0; i < shipnum + 1; i++)
				{
					if (STAGEMANAGER->ship_Kind % 2 == 1)
						tiles[(int)point.y][(int)point.x + i * exitTile.x]->isShipOn = true;
					if (STAGEMANAGER->ship_Kind % 2 == 0)
						tiles[(int)point.y + i * exitTile.y][(int)point.x]->isShipOn = true;
				}
				STAGEMANAGER->ShipCheck[shipnum - 1] -= 1;
			}
		}
		break;
	case STATE_TURN::M_READY:
		if (IsCollision_dot(mouse))
		{
			if (isBoom) break;
			color = { 255, 0, 0, 255 };
			if (STAGEMANAGER->item)
			{
				auto etiles = STAGEMANAGER->tile->etiles;
				for (int i = 0; i < 10; i++)
				{
					etiles[i][(INT)point.x]->SetColor(Color(255, 0, 0, 255));
				}
				if (INPUTMANAGER->KeyDown(VK_LBUTTON))
				{
					STAGEMANAGER->kind_turn = M_ATTACK;
					STAGEMANAGER->camZoom = false;
					CAMERAMANAGER->camPos = D3DXVECTOR2(900, 800);
					CAMERAMANAGER->camAngle = 1.5;
					for (int i = 0; i < 10; i++)
					{
						etiles[i][(INT)point.x]->colorCheck = true;
						etiles[i][(INT)point.x]->isBoom = true;
						STAGEMANAGER->arrEffectPos[i] = etiles[i][(INT)point.x]->campos;
						STAGEMANAGER->arrShootPos[i] = etiles[i][(INT)point.x]->GetPos();
						if (etiles[i][(INT)point.x]->isShipOn)
						{
							STAGEMANAGER->moreTurn = true;
							etiles[i][(INT)point.x]->SetColor(Color(0, 255, 0, 255));
						}
					}
					STAGEMANAGER->ShootPos = &pos;
				}
			}
			else
			{
				if (INPUTMANAGER->KeyDown(VK_LBUTTON))
				{
					colorCheck = true;
					isBoom = true;
					STAGEMANAGER->kind_turn = M_ATTACK;
					STAGEMANAGER->camZoom = false;
					CAMERAMANAGER->camPos = D3DXVECTOR2(900, 800);
					CAMERAMANAGER->camAngle = 1.5;
					STAGEMANAGER->effectPos = campos;
					STAGEMANAGER->ShootPos = &pos;
					if (isShipOn)
					{
						STAGEMANAGER->moreTurn = true;
						color = { 0, 255, 0, 255 };
					}
				}
			}
		}
		break;
	case M_ATTACK:

		break;
	case M_ANIMATION:
		break;
	case E_ATTACK:
		break;
	case E_ANIMATION:
		break;
	default:
		break;
	}
	int a = STAGEMANAGER->ShipCheck[shipnum - 1];
}

void Tile::Render()
{
	if(STAGEMANAGER->kind_turn != INTRO)
		IMAGEMANAGER->DrawImage("tile", pos, 0, 1 + CAMERAMANAGER->camAngle, color);
}

void Tile::Release()
{
}



Tile::Tile()
{
}


Tile::~Tile()
{
}
