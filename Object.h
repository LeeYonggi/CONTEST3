#pragma once
class Object
{
private:
	FRAME frame;
public:
	virtual void Init()		PURE;
	virtual void Update()	PURE;
	virtual void Render()	PURE;
	virtual void Release()	PURE;

	Object();
	virtual ~Object();
};

