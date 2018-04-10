#include "DXUT.h"
#include "FRAME.h"


void FRAME::SetTime(INT64 time, float delay)
{
	this->time = time / 100;
	this->delay = delay;
}

FLOAT FRAME::CheckFrame(FLOAT frame, int low, int high, FLOAT delay)
{
	if (frame < high)
		frame += delay;
	else
		frame = low;
	return frame;
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
