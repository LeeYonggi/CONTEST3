#pragma once

enum OBJECT_STATE;
class Object
{
protected:
	FRAME frame;
	D3DXVECTOR2 pos;
	Color color;
	OBJECT_STATE obj_kind;
	D3DXVECTOR2 center;
	float radius;

public:
	bool destroy;
	virtual void Init()		PURE;
	virtual void Update()	PURE;
	virtual void Render()	PURE;
	virtual void Release()	PURE;
	void SetPos(D3DXVECTOR2 _pos) { pos = _pos; }
	D3DXVECTOR2 GetPos() { return  pos; }
	bool IsCollision_dot(D3DXVECTOR2 _pos)
	{
		float x = center.x - _pos.x;
		float y = center.y - _pos.y;
		float d = x * x + y * y;
		return d <= radius * radius;
	}
	void SetColor(Color _color) { color = _color; }

	Object();
	virtual ~Object();
};

