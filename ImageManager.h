#pragma once

struct Texture
{
	D3DXIMAGE_INFO info;
	LPDIRECT3DTEXTURE9 tex;
};
struct Color
{
	int r, g, b, alpha;

	Color(int _r, int _g, int _b, int _alpha)
	{
		r = _r; g = _g; b = _b; alpha = _alpha;
	}
	Color() { }
	virtual ~Color() { }
};
class ImageManager :
	public Singleton<ImageManager>
{
private:
	map<string, Texture*> m_Texture;

public:
	LPD3DXSPRITE sprite;
	HRESULT AddImage(string str, const LPWSTR route);
	HRESULT DrawImage(string str, D3DXVECTOR2 pos, float angle = 0.0f, float scale = 1.0f,
		Color color = Color(255, 255, 255, 255));
	void Release();

	ImageManager();
	virtual ~ImageManager();
};

#define IMAGEMANAGER ImageManager::GetSingleton()