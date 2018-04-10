#include "DXUT.h"
#include "InputManager.h"

void InputManager::Update()
{
	memcpy(pastKey, nowKey, sizeof(nowKey));

	for (int i = 0; i < MAX_KEY; i++)
		nowKey[i] = GetAsyncKeyState(i) & 0x8000;

	GetCursorPos(&pMouse);
	ScreenToClient(DXUTGetHWND(), &pMouse);
}

InputManager::InputManager()
{
	memset(nowKey, false, sizeof(nowKey));
	memset(pastKey, false, sizeof(pastKey));
	pMouse = { 0, 0 };
}


InputManager::~InputManager()
{
}
