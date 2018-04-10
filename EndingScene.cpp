#include "DXUT.h"
#include "EndingScene.h"


void EndingScene::Init()
{
	frame.frame = 140;
	screen = false;
}

void EndingScene::Update()
{
	if ((INT)frame.frame >= 170)
	{
		if(INPUTMANAGER->KeyDown(VK_LBUTTON))
			SCENEMANAGER->AddScenes(new MainScene);
		screen = true;
	}
	else
		frame.frame = frame.CheckFrame(frame.frame, 140, 172, 0.3f);
}

void EndingScene::Render()
{
	string str = "Ending";
	char ctr[10];
	sprintf(ctr, "%d", (INT)frame.frame);
	IMAGEMANAGER->DrawImage(str + ctr, D3DXVECTOR2(640, 360));
	if(screen)
		IMAGEMANAGER->DrawImage("Victory", D3DXVECTOR2(640, 360));
}

void EndingScene::Release()
{
}

EndingScene::EndingScene()
{
}


EndingScene::~EndingScene()
{
}
