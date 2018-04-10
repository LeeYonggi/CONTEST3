#pragma once
class SoundManager :
	public Singleton<SoundManager>
{
private:
	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;
	map<string, int> m_Sound;

public:
	void AddSound(string str, LPCWSTR route);
	void Playbgm(string str);
	void PlayEffect(LPCWSTR route);
	void Release();

	SoundManager();
	virtual ~SoundManager();
};

#define SOUNDMANAGER SoundManager::GetSingleton()