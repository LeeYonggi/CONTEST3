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
	auto find = m_Object.find(M_OBJECT);
	auto iter_ = *find->second;
	for (int i = 0; i < find->second->size(); i++)
	{
		for (int j = 1 + i; j < find->second->size(); j++)
		{
			if (iter_[i]->GetPos().y >= iter_[j]->GetPos().y)
			{
				auto temp = iter_[i];
				iter_[i] = iter_[j];
				iter_[j] = temp;
			}
		}
	}
	*m_Object.find(M_OBJECT)->second = iter_;

	auto find2 = m_Object.find(E_OBJECT);
	auto iter_2 = *find2->second;
	for (int i = 0; i < find2->second->size(); i++)
	{
		for (int j = 1 + i; j < find2->second->size(); j++)
		{
			if (iter_2[i]->GetPos().y >= iter_2[j]->GetPos().y)
			{
				auto temp = iter_2[i];
				iter_2[i] = iter_2[j];
				iter_2[j] = temp;
			}
		}
	}
	*m_Object.find(E_OBJECT)->second = iter_2;

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
		iter.second->clear();
	}
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

	obj->Init();
	return obj;
}

vector<Object*> ObjectManager::GetvObject(OBJECT_STATE kind)
{
	auto iter = m_Object.find(kind);
	if (iter != m_Object.end())
	return *(iter->second);
}

ObjectManager::ObjectManager()
{

}


ObjectManager::~ObjectManager()
{
	for (auto iter : m_Object)
	{
		SAFE_DELETE(iter.second);
	}
	m_Object.clear();
}
