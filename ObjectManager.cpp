#include "DXUT.h"
#include "ObjectManager.h"


void ObjectManager::Init()
{
	for (int i = 0; i < MAX_OBJECTSTATE; i++)
	{
		m_Object.insert(make_pair(OBJECT_STATE(i), new vector<Object*>));
	}
}

void ObjectManager::Update()
{
	for (auto iter : m_Object)
	{
		for (auto iter_ : *iter.second)
		{
			if(iter_)
				iter_->Update();
		}
	}
}

void ObjectManager::Render()
{
	for (auto iter : m_Object)
	{
		for (auto iter_ : *iter.second)
		{
			if (iter_)
				iter_->Render();
		}
	}
}

void ObjectManager::Release()
{
	for (auto iter : m_Object)
	{
		for (auto iter_ : *(iter.second))
		{
			SAFE_RELEASE(iter_);
			SAFE_DELETE(iter_);
		}
	}
	m_Object.clear();
}

void ObjectManager::DestroyObject(OBJECT_STATE kind)
{
	auto iter = m_Object.find(kind);
	if (iter == m_Object.end()) return;
	for (auto iter_ : *iter->second)
	{
		SAFE_RELEASE(iter_);
		SAFE_DELETE(iter_);
	}
	iter->second->clear();
}

Object * ObjectManager::AddObject(OBJECT_STATE kind, Object * obj)
{
	auto iter = m_Object.find(kind);
	if (iter == m_Object.end()) return nullptr;
	iter->second->push_back(obj);

	return obj;
}

vector<Object*>* ObjectManager::GetvObject(OBJECT_STATE kind)
{
	auto iter = m_Object.find(kind);
	if (iter != m_Object.end())
		return iter->second;
}

ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}
