#include "DXUT.h"
#include "ObjectManager.h"


void ObjectManager::Init()
{

}

vector<Object*> ObjectManager::GetvObject(string str)
{
	auto iter = m_Object.find(str);
	if (iter != m_Object.end())
		return iter->second;
}

ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}
