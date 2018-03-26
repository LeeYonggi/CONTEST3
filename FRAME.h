#pragma once
class FRAME
{
public:
	int		frame;
	INT64	time;
	float	delay;
	void SetTime(INT64 time, float delay);
	void CheckFrame(int frame, int low, int high, int delay);
	bool IsTimeDelay()
	{
		return timeGetTime() > time + delay;
	}

	FRAME();
	virtual ~FRAME();
};

