#pragma once
class TextManager :
	public Singleton<TextManager>
{
private:
	LPD3DXFONT m_font;

public:
	void Init();
	void Drawtext(TCHAR *tchar, D3DXVECTOR2 pos, int type, Color color = Color(255, 255, 255, 255));

	TextManager();
	virtual ~TextManager();
};

#define TEXTMANAGER TextManager::GetSingleton()