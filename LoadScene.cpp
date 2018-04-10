#include "DXUT.h"
#include "LoadScene.h"

void LoadScene::AnimeImage(string _str, TCHAR tchar[], int low, int dnum)
{
	for (int i = low; i < dnum; i++)
	{
		char ctr[10];
		sprintf(ctr, "%d", i);

		TCHAR ttr[128] = L"";
		wsprintf(ttr, tchar, i);
		IMAGEMANAGER->AddImage(_str + ctr, ttr);
	}
}

void LoadScene::ImageInit()
{
	isLoadEnd = false;
	IMAGEMANAGER->AddImage("tile", L"./PNG/BackGround/Badak.png");

	//Enemy
	AnimeImage("TwoShip1", L"./PNG/Siege/5/0 (%d).png", 1, 37);
	AnimeImage("TwoShip2", L"./PNG/Siege/puy/0 (%d).png", 1, 37);
	AnimeImage("ThreeShip1", L"./PNG/Siege/bomb!/2/0 (%d).png", 1, 37);
	AnimeImage("ThreeShip2", L"./PNG/Siege/bomb!/1/0 (%d).png", 1, 37);
	AnimeImage("FourShip1", L"./PNG/Siege/arr/4/0 (%d).png", 1, 37);
	AnimeImage("FourShip2", L"./PNG/Siege/arr/3/0 (%d).png", 1, 37);

	//UI
	IMAGEMANAGER->AddImage("In_game_START", L"./PNG/In_game_START.png");
	IMAGEMANAGER->AddImage("ex_Siege", L"./PNG/kot/Siege.png");
	IMAGEMANAGER->AddImage("bat", L"./PNG/kot/bat.png");
	IMAGEMANAGER->AddImage("enemy_2", L"./PNG/kot/blo2.png");
	IMAGEMANAGER->AddImage("enemy_3", L"./PNG/kot/blo3.png");
	IMAGEMANAGER->AddImage("enemy_4", L"./PNG/kot/blo4.png");
	IMAGEMANAGER->AddImage("auto", L"./PNG/auto.png");
	
	//Intro
	for (int i = 0; i < 115; i++)
	{
		string str = "MainIntro";
		char ctr[10];
		sprintf(ctr, "%d", i);
		TCHAR tchar[100] = L"./PNG/Main/000";
		wchar_t wtr[10];
		_itow(i, wtr, 10);
		wcscat(tchar, wtr);
		wcscat(tchar, L".png");
		IMAGEMANAGER->AddImage(str + ctr, tchar);
	}
	IMAGEMANAGER->AddImage("m_World", L"./PNG/BackGround/m_World.png");
	IMAGEMANAGER->AddImage("e_World", L"./PNG/BackGround/e_World.png");

	IMAGEMANAGER->AddImage("Victory", L"./PNG/Victory.png");


	//Effect
	for (int i = 1; i < 9; i++)
	{
		string str = "Bomb";
		char ctr[10];
		sprintf(ctr, "%d", i);
		TCHAR tchar[100] = L"./PNG/bomb/";
		wchar_t wtr[10];
		_itow(i, wtr, 10);
		wcscat(tchar, wtr);
		wcscat(tchar, L".png");
		IMAGEMANAGER->AddImage(str + ctr, tchar);
	}
	AnimeImage("Forg", L"./PNG/air/000%02d.png", 0, 37);
	AnimeImage("Ending", L"./PNG/end/00%d.png", 140, 171);

	//Bullet 
	IMAGEMANAGER->AddImage("Bullet1", L"./PNG/Bullet/5250000.png");
	IMAGEMANAGER->AddImage("Bullet2", L"./PNG/Bullet/52560000.png");
	IMAGEMANAGER->AddImage("Missile", L"./PNG/item/bullet.png");

	//start, exit
	IMAGEMANAGER->AddImage("ExitGame", L"./PNG/ex/ExitGame.png");
	IMAGEMANAGER->AddImage("GameInfo", L"./PNG/ex/GameInfo.png");
	IMAGEMANAGER->AddImage("GameStart", L"./PNG/ex/GameStart.png");
	IMAGEMANAGER->AddImage("main", L"./PNG/ex/mainmain.png");

	isLoadEnd = true;
}

void LoadScene::Init()
{
	IMAGEMANAGER->AddImage("Loading0", L"./PNG/Loading/Loading.png");
	IMAGEMANAGER->AddImage("Loading1", L"./PNG/Loading/Loading2.png");
	IMAGEMANAGER->AddImage("Loading2", L"./PNG/Loading/Loading3.png");
	IMAGEMANAGER->AddImage("Back", L"./PNG/BackGround/Back.png");

	load = thread([&]() {ImageInit(); });
	frame.frame = 0;
}

void LoadScene::Update()
{
	frame.frame = frame.CheckFrame(frame.frame, 0, 2, 0.1);
	if (isLoadEnd)
	{
		if (load.joinable())
			load.join();
		SCENEMANAGER->AddScenes(new MainScene);
	}
}

void LoadScene::Render()
{
	string str = "Loading";
	char ctr[10];
	sprintf(ctr, "%d", (INT)frame.frame);
	IMAGEMANAGER->DrawImage("Back", D3DXVECTOR2(640, 360));
	IMAGEMANAGER->DrawImage(str + ctr, D3DXVECTOR2(640, 360));
}

void LoadScene::Release()
{
}

LoadScene::LoadScene()
{
}


LoadScene::~LoadScene()
{
}
