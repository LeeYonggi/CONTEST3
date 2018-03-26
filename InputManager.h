#pragma once

#define MAX_KEY 255

class InputManager :
	public Singleton<InputManager>
{
private:
	bool updateKey[MAX_KEY];
	bool pastKey[MAX_KEY];
	POINT mouse;

public:
	void Init();
	void Update();
	bool KeyDown(int vk_key) { return (pastKey[vk_key] == false && updateKey[vk_key] == true) ? true : false; }
	bool KeyHold(int vk_key) { return (pastKey[vk_key] == true && updateKey[vk_key] == true) ? true : false; }
	bool KeyUp(int vk_key) { return (pastKey[vk_key] == true && updateKey[vk_key] == false) ? true : false; }
	POINT GetMousePos() { return mouse; }

	InputManager();
	virtual ~InputManager();
};

#define INPUTMANAGER InputManager::GetSingleton()