#include "DXUT.h"
#include "Forg.h"


void Forg::Init()
{
	forgState = rand() % 20 + 12;
	int num = rand() % 2;
	if (num == 0)
	{
		pos.x = rand() % 2000;
		pos.y = 900;
	}
	else
	{
		pos.x = -100;
		pos.y = rand() % 900;
	}
	speed.x = rand() % 3 + 1;
	speed.y = -(rand() % 3 + 1);
	active = true;
}

void Forg::Update()
{
	pos += speed;
	if (pos.x > 4600)
		active = false;
}

void Forg::Render()
{
	string str = "Forg";
	char ctr[10];
	sprintf(ctr, "%d", forgState);
	if(STAGEMANAGER->kind_turn != STATE_TURN::INTRO)
		IMAGEMANAGER->DrawImage(str + ctr, pos);
}

void Forg::Release()
{
}

Forg::Forg()
{
}


Forg::~Forg()
{
}
