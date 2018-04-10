#pragma once
#include "Singleton.h"

struct UI
{
	D3DXVECTOR2 pos;
	RECT size;
	string str;
	Color color;

	void Init(string _str, D3DXVECTOR2 _pos, RECT _size)
	{
		pos = _pos;
		size = _size;
		str = _str;
		color = { 255, 255, 255, 255 };
	}
	void Render();
	bool IsCollision();
};

class UIManager :
	public Singleton<UIManager>
{
private:
	map<string, UI*> m_UI;

public:
	void AddUI(string str, D3DXVECTOR2 pos, RECT size);
	bool IsCollision(string str);
	D3DXVECTOR2 AddPosition(string str, D3DXVECTOR2 pos);
	void Render();
	void Release();
	void DestroyUI(string str);

	UIManager();
	virtual ~UIManager();
};

#define UIMANAGER UIManager::GetSingleton()