#include "DXUT.h"
#include "CameraManager.h"


void CameraManager::Init()
{
	camPos = D3DXVECTOR2(0, 0);
	pastPos = D3DXVECTOR2(0, 0);
	camAngle = 0;
	frame = 0;
	shakeCam = false;
}

void CameraManager::Update()
{
	if (frame > 0 && shakeCam)
	{
		int x = rand() % 7 - 3;
		int y = rand() % 7 - 3;
		camPos += D3DXVECTOR2(x, y);
		frame--;
	}
	else if(shakeCam)
	{
		camPos = pastPos;
		frame = 0;
		shakeCam = false;
	}
}

CameraManager::CameraManager()
{
}


CameraManager::~CameraManager()
{
}
