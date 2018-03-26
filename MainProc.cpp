#include "DXUT.h"
#include "MainProc.h"


void MainProc::Init()
{
	SCENEMANAGER->AddScenes(new InGameScene);
}

void MainProc::Update()
{
	SCENEMANAGER->Update();
}

void MainProc::Render()
{
	IMAGEMANAGER->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	SCENEMANAGER->Render();

	IMAGEMANAGER->sprite->End();
}

void MainProc::Release()
{
	IMAGEMANAGER->Release();
	IMAGEMANAGER->ReleaseSingleton();
	SCENEMANAGER->Release();
	SCENEMANAGER->ReleaseSingleton();
}

MainProc::MainProc()
{
}


MainProc::~MainProc()
{
}
