#pragma once
class MainProc
{
public:
	void Init();
	void Update();
	void Render();
	void Release();

	MainProc();
	virtual ~MainProc();
};

