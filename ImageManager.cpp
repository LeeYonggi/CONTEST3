#include "DXUT.h"
#include "ImageManager.h"


HRESULT ImageManager::AddImage(string str, const LPWSTR route)
{
	auto iter = m_Texture.find(str);
	if (iter != m_Texture.end()) return E_FAIL;
	Texture *texture = new Texture;
	HRESULT hr = D3DXCreateTextureFromFileEx
	(
		DEVICE,
		route,
		D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
		1, 0, D3DFMT_A8B8G8R8, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT,
		0, &texture->info, nullptr, &texture->tex
	);
	if (FAILED(hr))
	{
		int a = 4;
	}
	m_Texture.insert(make_pair(str, texture));
	return S_OK;
}

HRESULT ImageManager::DrawImage(string str, D3DXVECTOR2 pos, float angle, float scale, Color color)
{
	auto iter = m_Texture.find(str);
	if (iter == m_Texture.end())
	{
		return E_FAIL;
	}
	D3DXMATRIX matWorld, matS, matR, matT;
	D3DXMatrixScaling(&matS, scale, scale, 1);
	D3DXMatrixRotationZ(&matR, angle);
	D3DXMatrixTranslation(&matT, pos.x, pos.y, 0);
	matWorld = matS * matR * matT;

	sprite->SetTransform(&matWorld);

	D3DXVECTOR3 center = { (FLOAT)iter->second->info.Width / 2, (FLOAT)iter->second->info.Height / 2, 0.0f };

	sprite->Draw(iter->second->tex, nullptr, &center, nullptr, D3DCOLOR_RGBA(color.r, color.g, color.b, color.alpha));

	return S_OK;
}

void ImageManager::Release()
{
	for (auto iter : m_Texture)
	{
		SAFE_RELEASE(iter.second->tex);
		SAFE_DELETE(iter.second);
	}
	m_Texture.clear();
	
}

ImageManager::ImageManager()
{
	D3DXCreateSprite(DEVICE, &sprite);
}


ImageManager::~ImageManager()
{
	sprite->Release();
	sprite->OnLostDevice();
}
