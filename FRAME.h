#pragma once

#define TIME_DELTA timeGetTime() / 100
class FRAME
{
public:
	FLOAT	frame;
	INT64	time;
	float	delay;
	void SetTime(INT64 time, float delay);
	FLOAT CheckFrame(FLOAT frame, int low, int high, FLOAT delay);
	bool IsTimeDelay()
	{
		return TIME_DELTA > time + delay;
	}

	FRAME();
	virtual ~FRAME();
};

