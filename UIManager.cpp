#include "DXUT.h"
#include "UIManager.h"


void UIManager::AddUI(string str, D3DXVECTOR2 pos, RECT size)
{
	auto iter = m_UI.find(str);
	if (iter != m_UI.end()) return;

	UI *ui = new UI;
	ui->Init(str, pos, size);
	m_UI.insert(make_pair(str, ui));
}

bool UIManager::IsCollision(string str)
{
	auto iter = m_UI.find(str);
	if (iter == m_UI.end()) return false;
	
	return iter->second->IsCollision();
}

D3DXVECTOR2 UIManager::AddPosition(string str, D3DXVECTOR2 pos)
{
	auto iter = m_UI.find(str);
	if (iter == m_UI.end()) return iter->second->pos;
	iter->second->pos += pos;
	return iter->second->pos;
}

void UIManager::Render()
{
	for (auto iter : m_UI)
	{
		iter.second->Render();
		iter.second->color = { 255, 255, 255, 255 };
	}
}

void UIManager::Release()
{
	for (auto iter : m_UI)
	{
		SAFE_DELETE(iter.second);
	}
	m_UI.clear();
}

void UIManager::DestroyUI(string str)
{
	auto iter = m_UI.find(str);
	if (iter == m_UI.end()) return;
	m_UI.erase(str);
}

UIManager::UIManager()
{
}


UIManager::~UIManager()
{
}

void UI::Render()
{
	IMAGEMANAGER->DrawImage(str, pos, 0, 1, color);
}

bool UI::IsCollision()
{
	RECT re;
	re.left = pos.x - size.left / 2;
	re.top = pos.y - size.top / 2;
	re.right = re.left + size.right;
	re.bottom = re.top + size.bottom;
	POINT mouse = INPUTMANAGER->GetMousePos();
	if (re.left <= mouse.x  &&
		re.top <= mouse.y   &&
		re.right >= mouse.x &&
		re.bottom >= mouse.y)
	{
		color = { 255, 255, 255, 150 };
		return true;
	}
	return false;
}
