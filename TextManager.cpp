#include "DXUT.h"
#include "TextManager.h"


void TextManager::Init()
{
	D3DXCreateFont(DEVICE, 50, 0, 10, 1, false, DEFAULT_CHARSET, 0, 0, 0, TEXT("Fixedys"), &m_font);
}

void TextManager::Drawtext(TCHAR * tchar, D3DXVECTOR2 pos, int type, Color color)
{
	RECT re = { 0 };

	D3DXMATRIXA16	mat;

	D3DXMatrixTranslation(&mat, pos.x, pos.y, 0);

	IMAGEMANAGER->sprite->SetTransform(&mat);

	m_font->DrawTextW(IMAGEMANAGER->sprite, tchar, lstrlen(tchar), &re, DT_NOCLIP, D3DCOLOR_RGBA(color.r, color.g, color.b, color.alpha));
}

TextManager::TextManager()
{
	Init();
}


TextManager::~TextManager()
{
	SAFE_RELEASE(m_font);
}
