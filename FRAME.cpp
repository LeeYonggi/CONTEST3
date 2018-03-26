#include "DXUT.h"
#include "FRAME.h"


void FRAME::SetTime(INT64 time, float delay)
{
	this->time = time;
	this->delay = delay;
}

void FRAME::CheckFrame(int frame, int low, int high, int delay)
{
	if (frame < high)
		frame++;
	else
		frame = low;
}

FRAME::FRAME()
{
	frame = 0;
	time = 0;
	delay = 0;
}


FRAME::~FRAME()
{
}
