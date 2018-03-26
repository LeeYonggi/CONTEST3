#pragma once

enum OBJECT_STATE
{
	BACKGROUND, //배경
	M_OBJECT, //플레이어 오브젝트
	E_OBJECT //적 오브젝트
};
class ObjectManager :
	public Singleton<ObjectManager>
{
private:
	map<string, vector<Object*>> m_Object;
public:
	void Init();

	vector<Object*> GetvObject(string str);
	ObjectManager();
	virtual ~ObjectManager();
};

#define OBJECTMANAGER ObjectManager::GetSingleton()
