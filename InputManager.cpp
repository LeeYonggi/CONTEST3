#include "DXUT.h"
#include "InputManager.h"


void InputManager::Init()
{
	memset(updateKey, false, sizeof(updateKey));
	memset(pastKey, false, sizeof(updateKey));
	mouse = { 0, 0 };
}

void InputManager::Update()
{
	memcpy(pastKey, updateKey, sizeof(updateKey));

	for (int i = 0; i < MAX_KEY; i++)
		updateKey[i] = GetAsyncKeyState(i) & 0x8000;

	::GetCursorPos(&mouse);
	::ScreenToClient(DXUTGetHWND(), &mouse);
}

InputManager::InputManager()
{
	Init();
}


InputManager::~InputManager()
{
}
