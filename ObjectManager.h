#pragma once

enum OBJECT_STATE
{
	BACKGROUND, //���
	M_OBJECT, //�÷��̾� ������Ʈ
	E_OBJECT //�� ������Ʈ
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
