#include "DXUT.h"
#include "Bullet.h"


void Bullet::Init()
{
	active = true;
	scale = 0.4f;
	num = 0.005f;
}

void Bullet::Update()
{
	if (!active) return;
	if ((INT)pos.x >= (INT)target->x && (INT)pos.y <= (INT)target->y)
	{
		active = false;
		if (STAGEMANAGER->item)
		{
			for (int i = 0; i < 10; i++)
			{
				EFFECTMANAGER->AddEffect("Bomb", STAGEMANAGER->arrEffectPos[i], 1, 9, 0.3);
			}
			STAGEMANAGER->item = false;
		}
		else
			EFFECTMANAGER->AddEffect("Bomb", STAGEMANAGER->effectPos, 1, 9, 0.3);
	}
	pos += TrackingDirection(*target) * speed;
	if (scale > 1.2)
		num = -num;

	if(scale > 0.3f)
		scale += num;
	//if (pos.x < 640)
	//	pos += D3DXVECTOR2(4, 2);
}

void Bullet::Render()
{
	if (!active) return;
	if(STAGEMANAGER->item)
		IMAGEMANAGER->DrawImage("Missile", pos, 0, scale);
	else
		IMAGEMANAGER->DrawImage("Bullet1", pos, 0, scale);
}

void Bullet::Release()
{
}

Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}
