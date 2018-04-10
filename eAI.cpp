#include "DXUT.h"
#include "eAI.h"


void eAI::Init()
{
	data = { 0, 0 };
	ai_attack = AI_ATTACK_STATE::HUNTMODE;
	ai_direction = AI_DIRECTION_STATE::D_BOTTOM;
	over = 0;
	hit = true;
}

void eAI::Update()
{
	while (true)
	{
		switch (ai_attack)
		{
		case HUNTMODE:
			if (!HuntMode())
				continue;
			break;
		case TARGETMODE:
			if (!TargetMode())
				continue;
			break;
		default:
			break;
		}
		break;
	}
}

void eAI::HitTile(int x, int y, AI_DIRECTION_STATE direction)
{
	if (STAGEMANAGER->tile->tiles[y][x]->isShipOn)
	{
		STAGEMANAGER->tile->tiles[y][x]->SetColor(Color(0, 255, 0, 255));
		data = D3DXVECTOR2(x, y);
		ai_attack = TARGETMODE;
		hit = true;
		STAGEMANAGER->frame.SetTime(timeGetTime(), 15);
		CAMERAMANAGER->SetFrame(40);
		EFFECTMANAGER->AddEffect("Bomb", STAGEMANAGER->tile->tiles[y][x]->campos, 1, 9, 0.3);
		SOUNDMANAGER->PlayEffect(L"./droid_destroyed3.wav");
	}
	else
	{
		STAGEMANAGER->tile->tiles[y][x]->SetColor(Color(255, 0, 0, 255));
		ai_direction = direction;
		hit = false;
		CAMERAMANAGER->SetFrame(40);
		STAGEMANAGER->frame.SetTime(timeGetTime(), 15);
		EFFECTMANAGER->AddEffect("Bomb", STAGEMANAGER->tile->tiles[y][x]->campos, 1, 9, 0.3);
	}
	STAGEMANAGER->tile->tiles[y][x]->colorCheck = true;
	STAGEMANAGER->tile->tiles[y][x]->isBoom = true;
}

bool eAI::HuntMode()
{
	int x = rand() % 9;
	int y = rand() % 10;
	if (over < 30)
	{
		if (y % 2 == 0)
		{
			if (x % 2 == 0)
			{
				x++;
			}
		}
		else
		{
			if (x % 2 == 1)
			{
				x--;
			}
		}
	}
	if (STAGEMANAGER->tile->tiles[y][x]->isBoom == true)
	{
		over++;
		return false;
	}
	over = 0;
	HitTile(x, y, D_BOTTOM);
	return true;
}

bool eAI::TargetMode()
{
	if (STAGEMANAGER->tile->tiles[(INT)data.y][(INT)data.x]->isDestroy)
	{
		ai_attack = HUNTMODE;
		ai_direction = D_BOTTOM;
		data = { 0, 0 };
		return false;
	}
	switch (ai_direction)
	{
	case D_BOTTOM:
		if (data.y + 1 > 9)
		{
			ai_direction = D_LEFT;
			return false;
		}
		if (STAGEMANAGER->tile->tiles[(INT)data.y + 1][(INT)data.x]->isBoom)
		{
			ai_direction = D_LEFT;
			return false;
		}
		HitTile(data.x, data.y + 1, D_LEFT);
		break;
	case D_LEFT:
		if (data.x - 1 < 0)
		{
			ai_direction = D_TOP;
			return false;
		}
		if (STAGEMANAGER->tile->tiles[(INT)data.y][(INT)data.x - 1]->isBoom)
		{
			ai_direction = D_TOP;
			return false;
		}
		HitTile(data.x - 1, data.y, D_TOP);
		break;
	case D_TOP:
		
		for(int i = 1; i < 4; i++)
		{
			if (data.y - i < 0)
			{
				ai_direction = D_RIGHT;
				return false;
			}
			if (STAGEMANAGER->tile->tiles[(INT)data.y - i][(INT)data.x]->isBoom) continue;
			else
			{
				HitTile(data.x, data.y - i, D_RIGHT);
				return true;
			}
		}
		ai_direction = D_RIGHT;
		return false;
		break;
	case D_RIGHT:
		for (int i = 1; i < 4; i++)
		{
			if (data.x + i > 9)
			{
				ai_direction = D_BOTTOM;
				ai_attack = HUNTMODE;
				return false;
			}
			if (STAGEMANAGER->tile->tiles[(INT)data.y][(INT)data.x + i]->isBoom) continue;
			else
			{
				HitTile(data.x + i, data.y, D_BOTTOM);
				return true;
			}
		}
		ai_direction = D_BOTTOM;
		ai_attack = HUNTMODE;
		return false;
		break;
	default:
		break;
	}
	return true;
}

eAI::eAI()
{
}


eAI::~eAI()
{
}
