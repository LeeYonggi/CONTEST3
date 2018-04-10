#pragma once

#define MAX_OBJECTSTATE 9
enum OBJECT_STATE
{
	BACK, //�޹��
	FORG, //����
	BACKGROUND, //���
	TILE,
	M_OBJECT, //�÷��̾� ������Ʈ
	E_OBJECT, //�� ������Ʈ
	BULLET, //�Ѿ�
	EFFECT, //����Ʈ
	M_UI //���� �������̽�
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
	vector<Object*> GetvObject(OBJECT_STATE kind);
	ObjectManager();
	virtual ~ObjectManager();
};

#define OBJECTMANAGER ObjectManager::GetSingleton()
