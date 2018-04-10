#pragma once
class CameraManager :
	public Singleton<CameraManager>
{
private:
	D3DXVECTOR2 pastPos;
	float frame;
	bool shakeCam;
public:
	D3DXVECTOR2 camPos;
	float camAngle;
	void Init();
	void Update();
	void SetFrame(float frame) { this->frame = frame; pastPos = camPos;  shakeCam = true;}
	CameraManager();
	virtual ~CameraManager();
};

#define CAMERAMANAGER CameraManager::GetSingleton()