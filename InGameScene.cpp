#include "DXUT.h"
#include "InGameScene.h"


void InGameScene::Init()
{
	IMAGEMANAGER->AddImage("Test", L"./PNG/Test.png");
}

void InGameScene::Update()
{
}

void InGameScene::Render()
{
	IMAGEMANAGER->DrawImage("Test", D3DXVECTOR2(640, 360), 0, 0.5);
}

void InGameScene::Release()
{
}

InGameScene::InGameScene()
{
}


InGameScene::~InGameScene()
{
}
