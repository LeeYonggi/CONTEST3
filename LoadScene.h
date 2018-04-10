#pragma once
#include "BaseScene.h"
class LoadScene :
	public BaseScene
{
private:
	FRAME frame;
public:
	thread load;
	bool isLoadEnd;
public:
	void AnimeImage(string _str, TCHAR tchar[], int low, int dnum);
	void ImageInit();
	void Init();
	void Update();
	void Render();
	void Release();


	LoadScene();
	virtual ~LoadScene();
};

