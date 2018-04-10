#include "DXUT.h"
#include "BackGround.h"


void BackGround::Init()
{
	pos = { 640, 360 };
}

void BackGround::Update()
{
	switch (STAGEMANAGER->kind_turn)
	{
	case INTRO:
		frame.frame = frame.CheckFrame(frame.frame, 0, 115, 0.3f);
		if (frame.frame >= 113)
			STAGEMANAGER->kind_turn = READY;
		break;
	default:
		pos.y = 0;
		if (pos.x < 1500)
			pos.x += 2;
		else
			pos.x = 0;
		break;
	}
}

void BackGround::Render()
{
	string str = "MainIntro";
	D3DXVECTOR2 camPos = CAMERAMANAGER->camPos;
	FLOAT camAngle = CAMERAMANAGER->camAngle;
	IMAGEMANAGER->DrawImage("Back", pos );
	switch (STAGEMANAGER->kind_turn)
	{
	case INTRO:
		char ctr[10];
		sprintf(ctr, "%d", (INT)frame.frame);
		IMAGEMANAGER->DrawImage(str + ctr, pos);
		break;
	default:
		break;
	}
}

void BackGround::Release()
{
}

BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}
