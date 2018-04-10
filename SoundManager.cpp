#include "DXUT.h"
#include "SoundManager.h"


void SoundManager::AddSound(string str, LPCWSTR route)
{
	auto iter = m_Sound.find(str);
	if (iter != m_Sound.end()) return;	

	mciOpen.lpstrElementName = route;
	mciOpen.lpstrDeviceType = L"mpegvideo";

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
		(DWORD)(LPVOID)&mciOpen);

	int dwID = mciOpen.wDeviceID;

	m_Sound.insert(make_pair(str, dwID));
}

void SoundManager::Playbgm(string str)
{
	auto iter = m_Sound.find(str);
	if (iter == m_Sound.end()) return;

	mciSendCommand(iter->second, MCI_PLAY, MCI_DGV_PLAY_REPEAT,
		(DWORD)(LPVOID)&mciPlay);
}

void SoundManager::PlayEffect(LPCWSTR route)
{
	sndPlaySound(L"./droid_destroyed3.wav", SND_ASYNC | SND_NODEFAULT | SND_NOSTOP);
}

void SoundManager::Release()
{
	m_Sound.clear();
}

SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
}
