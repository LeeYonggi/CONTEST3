#include "DXUT.h"
#include "MainProc.h"


void MainProc::Init()
{
	srand(time(NULL));
	SCENEMANAGER->AddScenes(new LoadScene);
}

void MainProc::Update()
{
	SCENEMANAGER->Update();
	INPUTMANAGER->Update();
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
	INPUTMANAGER->ReleaseSingleton();
	TEXTMANAGER->ReleaseSingleton();
	OBJECTMANAGER->Release();
	OBJECTMANAGER->ReleaseSingleton();
	UIMANAGER->ReleaseSingleton();
	UIMANAGER->Release();
	EFFECTMANAGER->ReleaseSingleton();
	EFFECTMANAGER->Release();
}

MainProc::MainProc()
{
}


MainProc::~MainProc()
{
}
