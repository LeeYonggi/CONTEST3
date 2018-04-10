#include "DXUT.h"
#include "InGameScene.h"


void InGameScene::Init()
{
	//SOUNDMANAGER->AddSound("XACTGameGroove2", L"./XACTGameGroove2.wav");
	//SOUNDMANAGER->Playbgm("XACTGameGroove2");
	OBJECTMANAGER->Init();
	STAGEMANAGER->ImageInit();
	STAGEMANAGER->Stage1Init();
	CAMERAMANAGER->Init();
}

void InGameScene::Update()
{
	STAGEMANAGER->Update();
	CAMERAMANAGER->Update();
	OBJECTMANAGER->Update();
	EFFECTMANAGER->Update();
}

void InGameScene::Render()
{
	OBJECTMANAGER->Render();
	EFFECTMANAGER->Render();
	UIMANAGER->Render();
}

void InGameScene::Release()
{
	OBJECTMANAGER->Release();
	SOUNDMANAGER->Release();
	UIMANAGER->Release();
}

InGameScene::InGameScene()
{
}


InGameScene::~InGameScene()
{
}
