#include "DXUT.h"
#include "MainScene.h"


void MainScene::Init()
{
	RECT re = { 316, 44, 316, 44 };
	UIMANAGER->AddUI("GameStart", D3DXVECTOR2(640, 450), re);
	RECT re2 = { 286, 41, 286, 41};
	UIMANAGER->AddUI("GameInfo", D3DXVECTOR2(640, 500), re2);
	UIMANAGER->AddUI("ExitGame", D3DXVECTOR2(640, 600), re2);
	scale = 1;
	isScale = false;
}

void MainScene::Update()
{
	if (UIMANAGER->IsCollision("GameStart"))
	{
		if(INPUTMANAGER->KeyDown(VK_LBUTTON))
			SCENEMANAGER->AddScenes(new InGameScene);
	}
	if (!isScale)
	{
		STAGEMANAGER->lerp(&scale, scale, 1.4f, 0.01f);
		if (scale > 1.35f)
			isScale = true;
	}
	else
	{
		STAGEMANAGER->lerp(&scale, scale, 1.0f, 0.01f);
		if (scale < 1.05f)
			isScale = false;
	}
}

void MainScene::Render()
{
	IMAGEMANAGER->DrawImage("Back", D3DXVECTOR2(640, 360));
	IMAGEMANAGER->DrawImage("main", D3DXVECTOR2(640, 230), 0, scale);
	UIMANAGER->Render();
}

void MainScene::Release()
{
	UIMANAGER->Release();
}

MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}
