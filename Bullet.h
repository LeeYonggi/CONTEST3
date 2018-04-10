#pragma once
class Bullet :
	public Object
{
private:
	FLOAT speed;
	D3DXVECTOR2 *target;
	float scale;
	float num;

public:
	bool active;
	void Init();
	void Update();
	void Render();
	void Release();
	D3DXVECTOR2 TrackingDirection(D3DXVECTOR2 _pos)
	{
		D3DXVECTOR2 temp = _pos - pos;
		D3DXVec2Normalize(&temp, &temp);
		return temp * 1;
	}

	Bullet(FLOAT _speed, D3DXVECTOR2 *_target, D3DXVECTOR2 _pos)
	{
		speed = _speed;
		target = _target;
		pos = _pos;
	}
	Bullet();
	virtual ~Bullet();
};

