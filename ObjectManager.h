#pragma once

#define MAX_OBJECTSTATE 5
enum OBJECT_STATE
{
	BACKGROUND, //배경
	M_OBJECT, //플레이어 오브젝트
	E_OBJECT, //적 오브젝트
	EFFECT, //이펙트
	UI //유저 인터페이스
};
class ObjectManager :
	public Singleton<ObjectManager>
{
private:
	map<OBJECT_STATE, vector<Object*>*> m_Object;
public:
	void Init();
	void Update();
	void Render();
	void Release();
	void DestroyObject(OBJECT_STATE kind);

	Object* AddObject(OBJECT_STATE kind, Object *obj);
	vector<Object*>* GetvObject(OBJECT_STATE kind);
	ObjectManager();
	virtual ~ObjectManager();
};

#define OBJECTMANAGER ObjectManager::GetSingleton()
