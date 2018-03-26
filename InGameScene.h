#pragma once
class InGameScene :
	public BaseScene
{
public:
	void Init();
	void Update();
	void Render();
	void Release();

	InGameScene();
	virtual ~InGameScene();
};

