#pragma once


class SceneManager :
	public Singleton<SceneManager>
{
private:
	vector<BaseScene*> v_Scenes;
	int pastUpdate;
	int update;

public:
	void AddScenes(BaseScene *scene);
	void Update();
	void Render();
	void Release();

	SceneManager();
	virtual ~SceneManager();
};

#define SCENEMANAGER SceneManager::GetSingleton()