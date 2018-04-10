#include "DXUT.h"
#include "StageManager.h"
#include "BattleShip.h"
#define CAM_MOVE_SPEED 0.05f
#define CAM_DIRECT_SPEED 0.025f




void StageManager::ImageInit()
{//
	
	kind_turn = INTRO;
	ShipCheck[0] = 2;
	ShipCheck[1] = 2;
	ShipCheck[2] = 1;
	back = dynamic_cast<BackGround*>(OBJECTMANAGER->AddObject(BACK, new BackGround));
	backWorld = dynamic_cast<BackWorld*>(OBJECTMANAGER->AddObject(BACKGROUND, new BackWorld));
	moreTurn = false;
	ai.Init();
	camZoom = false;
	isShoot = false;
	isanime = false;
	item = true;
	//
}

void StageManager::Stage1Init()
{
	tile = dynamic_cast<mTile*>(OBJECTMANAGER->AddObject(TILE, new mTile));
	ship_Kind = TWOSHIP1;
	kind_Change = 1;
}

bool EndDisposition(int *ship)
{
	for (int i = 0; i < 3; i++)
	{
		if (ship[i] > 0)
			return false;
	}
	return true;
}

void StageManager::Update()
{
	RECT re = { 100, 102, 100, 102 };
	RECT re2 = { 100, 137, 100, 137 };
	RECT re3 = { 100, 186, 100, 186 };
	RECT re4 = { 250, 100, 250, 100 };
	auto iter = OBJECTMANAGER->GetvObject(M_OBJECT);
	frame.frame = frame.CheckFrame(frame.frame, 0, 10, 1);
	if(frame.frame == 0)
		forg.push_back(dynamic_cast<Forg*>(OBJECTMANAGER->AddObject(FORG, new Forg)));
	for (int i = 0; i < forg.size(); i++)
	{
		if (!forg[i]->active)
			forg.erase(forg.begin() + i);
	}
	auto eiter = OBJECTMANAGER->GetvObject(E_OBJECT);
	for (int i = 0; i < eiter.size(); i++)
	{
		if (eiter[i]->destroy)
		{
			if (i == eiter.size() - 1)
				SCENEMANAGER->AddScenes(new EndingScene);
			continue;
		}
		else
			break;
	}
	if (INPUTMANAGER->KeyDown(VK_LBUTTON) && kind_turn != INTRO && kind_turn != READY)
	{
		if (UIMANAGER->IsCollision("auto"))
		{
			item = true;
		}
	}
	switch (kind_turn)
	{
	case INTRO:

		break;
	case READY:
		UIMANAGER->AddUI("ex_Siege", D3DXVECTOR2(100, 35), re4);
		UIMANAGER->AddUI("enemy_2", D3DXVECTOR2(100, 100), re);
		UIMANAGER->AddUI("enemy_3", D3DXVECTOR2(100, 260), re2);
		UIMANAGER->AddUI("enemy_4", D3DXVECTOR2(100, 420), re3);
		UIMANAGER->AddUI("auto", D3DXVECTOR2(1100, 250), re4);
		UIMANAGER->AddUI("bat", D3DXVECTOR2(100, 270), re4);
		if (INPUTMANAGER->KeyHold(0x41))
		{
			lerp<D3DXVECTOR2>(&CAMERAMANAGER->camPos, CAMERAMANAGER->camPos, D3DXVECTOR2(900, 800), CAM_DIRECT_SPEED);
			lerp<FLOAT>(&CAMERAMANAGER->camAngle, CAMERAMANAGER->camAngle, 1.4f, CAM_DIRECT_SPEED);
		}
		if (INPUTMANAGER->KeyHold(0x53))
		{
			lerp<D3DXVECTOR2>(&CAMERAMANAGER->camPos, CAMERAMANAGER->camPos, D3DXVECTOR2(0, 0), CAM_DIRECT_SPEED);
			lerp<FLOAT>(&CAMERAMANAGER->camAngle, CAMERAMANAGER->camAngle, 0.0f, CAM_DIRECT_SPEED);
		}
		if (INPUTMANAGER->KeyDown(VK_RBUTTON))
		{
			ship_Kind += kind_Change;
			kind_Change = -kind_Change;
		}
		if (UIMANAGER->IsCollision("enemy_2") && INPUTMANAGER->KeyDown(VK_LBUTTON))
		{
			ship_Kind = TWOSHIP1;
			kind_Change = 1;
		}
		if (UIMANAGER->IsCollision("enemy_3") && INPUTMANAGER->KeyDown(VK_LBUTTON))
		{
			ship_Kind = THREESHIP1;
			kind_Change = 1;
		}
		if (UIMANAGER->IsCollision("enemy_4") && INPUTMANAGER->KeyDown(VK_LBUTTON))
		{
			ship_Kind = FOURSHIP1;
			kind_Change = 1;
		}
		if (UIMANAGER->IsCollision("auto") && INPUTMANAGER->KeyDown(VK_LBUTTON))
		{
			OBJECTMANAGER->DestroyObject(M_OBJECT);
			tile->AutoDisposition(tile->tiles, M_OBJECT);
		}
		if (EndDisposition(ShipCheck))
		{
			RECT size = { 249, 60, 249, 60 };
			UIMANAGER->AddUI("In_game_START", D3DXVECTOR2(1100, 600), size);
			if (UIMANAGER->IsCollision("In_game_START") && INPUTMANAGER->KeyDown(VK_LBUTTON))
			{
				kind_turn = M_READY;
				tile->AutoDisposition(tile->etiles, E_OBJECT);
				UIMANAGER->DestroyUI("In_game_START");
				UIMANAGER->DestroyUI("enemy_2");
				UIMANAGER->DestroyUI("enemy_3");
				UIMANAGER->DestroyUI("enemy_4");
				UIMANAGER->DestroyUI("bat");
				UIMANAGER->DestroyUI("ex_Siege");
			}
		}
		break;
	case M_READY:
		if (!camZoom)
		{
			lerp<D3DXVECTOR2>(&CAMERAMANAGER->camPos, CAMERAMANAGER->camPos, D3DXVECTOR2(1780, -500), CAM_DIRECT_SPEED);
			lerp<FLOAT>(&CAMERAMANAGER->camAngle, CAMERAMANAGER->camAngle, 0.0f, CAM_DIRECT_SPEED);
			if (1770 <= CAMERAMANAGER->camPos.x)
				camZoom = true;
		}
		if (camZoom)
		{
			if (INPUTMANAGER->KeyHold(0x41))
			{
				lerp<D3DXVECTOR2>(&CAMERAMANAGER->camPos, CAMERAMANAGER->camPos, D3DXVECTOR2(4600, -700), CAM_DIRECT_SPEED);
				lerp<FLOAT>(&CAMERAMANAGER->camAngle, CAMERAMANAGER->camAngle, 1.1f, CAM_DIRECT_SPEED);
			}
			if (INPUTMANAGER->KeyHold(0x53))
			{
				lerp<D3DXVECTOR2>(&CAMERAMANAGER->camPos, CAMERAMANAGER->camPos, D3DXVECTOR2(1780, -500), CAM_DIRECT_SPEED);
				lerp<FLOAT>(&CAMERAMANAGER->camAngle, CAMERAMANAGER->camAngle, 0.0f, CAM_DIRECT_SPEED);
			}
		}
		break;
	case M_ATTACK:
		if (!isanime)
		{
			while (true)
			{
				Shootnum = rand() % iter.size();
				if (iter[Shootnum]->destroy)
					continue;
				battleShip = dynamic_cast<BattleShip*>(iter[Shootnum]);
				battleShip->AnimeOn(true);
				break;
			}
			isanime = true;
		}
		if (isShoot)
		{
			lerp<D3DXVECTOR2>(&CAMERAMANAGER->camPos, CAMERAMANAGER->camPos, D3DXVECTOR2(1280, -300), CAM_DIRECT_SPEED);
			lerp<FLOAT>(&CAMERAMANAGER->camAngle, CAMERAMANAGER->camAngle, 0.0f, CAM_DIRECT_SPEED);
			if (CAMERAMANAGER->camAngle <= 0.1f)
			{
				kind_turn = M_ANIMATION;
				frame.SetTime(timeGetTime(), 30);
				isShoot = false;
				isanime = false;
			}
		}
		break;
	case M_ANIMATION:
		lerp<D3DXVECTOR2>(&CAMERAMANAGER->camPos, CAMERAMANAGER->camPos, D3DXVECTOR2(4600, -700), CAM_DIRECT_SPEED);
		lerp<FLOAT>(&CAMERAMANAGER->camAngle, CAMERAMANAGER->camAngle, 1.1f, CAM_DIRECT_SPEED);
		if (!bullet->active && frame.IsTimeDelay())
		{
			if (moreTurn)
			{
				SOUNDMANAGER->PlayEffect(L"./droid_destroyed3.wav");
				CAMERAMANAGER->SetFrame(40);
				kind_turn = M_READY;
				moreTurn = false;
			}
			else
			{
				CAMERAMANAGER->SetFrame(30);
				kind_turn = E_READY;
				frame.SetTime(timeGetTime(), 20);
			}
		}
		break;
	case E_READY:
		if (frame.IsTimeDelay())
		{
			lerp<D3DXVECTOR2>(&CAMERAMANAGER->camPos, CAMERAMANAGER->camPos, D3DXVECTOR2(900, 800), CAM_MOVE_SPEED);
			lerp<FLOAT>(&CAMERAMANAGER->camAngle, CAMERAMANAGER->camAngle, 1.4f, CAM_DIRECT_SPEED);
			if (CAMERAMANAGER->camPos.x <= 950)
			{
				kind_turn = E_ATTACK;
			}
		}
		break;
	case E_ATTACK:
		if (ai.hit && frame.IsTimeDelay())
		{
			ai.Update();
		}
		else
		{
			if (frame.IsTimeDelay())
			{
				kind_turn = M_READY;
				ai.hit = true;
				camZoom = false;
			}
		}
		break;
	case E_ANIMATION:
		break;
	default:
		break;
	}
}


StageManager::StageManager()
{
}


StageManager::~StageManager()
{
}
