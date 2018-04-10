#include "DXUT.h"
#include "BackWorld.h"


void BackWorld::Init()
{
}

void BackWorld::Update()
{
}

void BackWorld::Render()
{

	D3DXVECTOR2 camPos = CAMERAMANAGER->camPos;
	FLOAT camAngle = CAMERAMANAGER->camAngle;
	switch (STAGEMANAGER->kind_turn)
	{
	case INTRO:
		break;
	default:
		IMAGEMANAGER->DrawImage("m_World", D3DXVECTOR2(640, 360) - camPos + (D3DXVECTOR2(640, 360) * camAngle), 0, 1 + camAngle);
		IMAGEMANAGER->DrawImage("e_World", D3DXVECTOR2(2560, 0) - camPos + (D3DXVECTOR2(2560, 0) * camAngle), 0, 1 + camAngle);
		break;
	}
}

void BackWorld::Release()
{
}

BackWorld::BackWorld()
{
}


BackWorld::~BackWorld()
{
}
