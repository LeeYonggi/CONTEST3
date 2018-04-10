#pragma once


#define MAX_KEY 256
class InputManager :
	public Singleton<InputManager>
{
private:
	bool nowKey[MAX_KEY];
	bool pastKey[MAX_KEY];
	POINT pMouse;

public:
	void Update();
	bool KeyDown(int key) { return (pastKey[key] == false && nowKey[key] == true) ? true : false; }
	bool KeyHold(int key) { return (pastKey[key] == true && nowKey[key] == true) ? true : false; }
	bool KeyUp(int key) { return (pastKey[key] == true && nowKey[key] == false) ? true : false; }
	POINT  GetMousePos() { return pMouse; }


	InputManager();
	virtual ~InputManager();
};

#define INPUTMANAGER InputManager::GetSingleton()