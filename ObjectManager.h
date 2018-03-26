#pragma once

#define MAX_OBJECTSTATE 5
enum OBJECT_STATE
{
	BACKGROUND, //���
	M_OBJECT, //�÷��̾� ������Ʈ
	E_OBJECT, //�� ������Ʈ
	EFFECT, //����Ʈ
	UI //���� �������̽�
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
