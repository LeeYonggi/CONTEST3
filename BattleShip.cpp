#include "DXUT.h"
#include "BattleShip.h"


BattleShip::BattleShip()
{
}


void BattleShip::Init()
{
	color = Color(255, 255, 255, 255);
	destroy = false;
	animeOn = false;
	frame.frame = 1;
	initPos = pos;
}

bool BattleShip::IsDestroy(Tile *tile[][10])
{
	for (int i = 0; i < point.size(); i++)
	{
		if (!tile[(INT)point[i].y][(INT)point[i].x]->isBoom) return false;
	}
	return true;
}

void BattleShip::Update()
{
	pos = initPos - CAMERAMANAGER->camPos + (initPos * CAMERAMANAGER->camAngle);
	switch (kind)
	{
	case MY:
		if (IsDestroy(STAGEMANAGER->tile->tiles))
		{
			destroy = true;
			int num = (INT)ceil((FLOAT)shipKind / 2);
			for (int i = 0; i < point.size(); i++)
			{
				STAGEMANAGER->tile->tiles[(INT)point[i].y][(INT)point[i].x]->isDestroy = true;
			}
		}
		break;
	case ENEMY:
		if (IsDestroy(STAGEMANAGER->tile->etiles))
		{
			destroy = true;
			int num = (INT)ceil((FLOAT)shipKind / 2);
			for (int i = 0; i < point.size(); i++)
			{
				STAGEMANAGER->tile->etiles[(INT)point[i].y][(INT)point[i].x]->isDestroy = true;
			}
		}
		break;
	default:
		break;
	}
	
	if (animeOn)
	{
		frame.frame = frame.CheckFrame(frame.frame, 1, 36, 0.3);
		if ((INT)frame.frame >= 36)
		{
			STAGEMANAGER->bullet = dynamic_cast<Bullet*>(OBJECTMANAGER->AddObject(BULLET, new Bullet(2, STAGEMANAGER->ShootPos, pos)));
			animeOn = false;
			STAGEMANAGER->isShoot = true;
		}
	}
}

void BattleShip::Render()
{
	string str;
	switch (shipKind)
	{
	case TWOSHIP1:
		str = "TwoShip1";
		break;
	case TWOSHIP2:
		str = "TwoShip2";
		break;
	case THREESHIP1:
		str = "ThreeShip1";
		break;
	case THREESHIP2:
		str = "ThreeShip2";
		break;
	case FOURSHIP1:
		str = "FourShip1";
		break;
	case FOURSHIP2:
		str = "FourShip2";
		break;
	default:
		break;
	}
	switch (kind)
	{
	case MY:
		if (animeOn)
		{
			char ctr[10];
			sprintf(ctr, "%d", (INT)frame.frame);
			IMAGEMANAGER->DrawImage(str + ctr, pos, 0, 1 + CAMERAMANAGER->camAngle, color);
		}
		else
		{
			char ctr[10];
			sprintf(ctr, "%d", 1);
			IMAGEMANAGER->DrawImage(str + ctr, pos, 0, 1 + CAMERAMANAGER->camAngle, color);
		}
		break;
	case ENEMY:
		if (destroy)
		{
			char ctr[10];
			sprintf(ctr, "%d", 1);
			IMAGEMANAGER->DrawImage(str + ctr, pos, 0, 1 + CAMERAMANAGER->camAngle, color);
		}
		break;
	default:
		break;
	}
}

void BattleShip::Release()
{
}

BattleShip::~BattleShip()
{
}
