#pragma once


class Forg :
	public Object
{
private:
	int forgState;
	D3DXVECTOR2 speed;

public:
	bool active;
	void Init();
	void Update();
	void Render();
	void Release();

	Forg();
	virtual ~Forg();
};

