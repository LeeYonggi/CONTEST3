#include "DXUT.h"
#include "SceneManager.h"


void SceneManager::AddScenes(BaseScene *scene)
{
	for (int i = 0; i < v_Scenes.size(); i++)
	{
		if (v_Scenes[i] == scene)
		{
			update = i;
			return;
		}
	}
	v_Scenes.push_back(scene);
	update = v_Scenes.size() - 1;
}

void SceneManager::Update()
{
	if (pastUpdate != update)
	{
		if (pastUpdate != -1)
			v_Scenes[pastUpdate]->Release();
		v_Scenes[update]->Init();
		v_Scenes[update]->Update();
		pastUpdate = update;
		return;
	}
	v_Scenes[update]->Update();
}

void SceneManager::Render()
{
	v_Scenes[update]->Render();
}

void SceneManager::Release()
{
	for (auto iter : v_Scenes)
	{
		SAFE_RELEASE(iter);
		SAFE_DELETE(iter);
	}	
	v_Scenes.clear();
}

SceneManager::SceneManager()
{
	pastUpdate = -1;
	update = 0;
}


SceneManager::~SceneManager()
{
}
