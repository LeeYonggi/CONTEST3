#pragma once
class InGameScene :
	public BaseScene
{
private:
public:
	void Init();
	void Update();
	void Render();
	void Release();

	InGameScene();
	virtual ~InGameScene();
};

