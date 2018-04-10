#pragma once

#include <thread>
//FrameWork
#include "Singleton.h"
#include "ImageManager.h"
#include "BaseScene.h"
#include "SceneManager.h"
#include "TextManager.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "EffectManager.h"

#include "FRAME.h"
#include "Object.h"
#include "ObjectManager.h"
#include "CameraManager.h"	
#include "UIManager.h"

//custom	
#include "Forg.h"
#include "BackWorld.h"
#include "BackGround.h"
#include "Bullet.h"
#include "Tile.h"
#include "mTile.h"
#include "eAI.h"
#include "InGameScene.h"
#include "StageManager.h"
#include "EndingScene.h"
#include "MainScene.h"
#include "LoadScene.h"
#include "MainProc.h"

#define DEVICE DXUTGetD3D9Device()
#define SCREEN_X 1280
#define SCREEN_Y 720