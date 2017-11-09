#include "DelayTime.h"


void DelayTime::start(DWORD time)
{
	ready= false;
	terminated = false;
	startTime = GetTickCount();
	if (time != (DWORD)-1)
	{
		init(time);
	}
}

void DelayTime::init(DWORD time)
{
	tickPerFrame = time;
}

DelayTime::DelayTime()
{
	ready= true;
	terminated = true;
}

bool DelayTime::isReady()
{
	return ready;
}
bool DelayTime::isTerminated()
{
	if (terminated)
	{
		ready= true;
		terminated = false;
		return true;
	}
	return false;
}
bool DelayTime::isOnTime()
{
	return !terminated && !ready;
}
void DelayTime::update()
{
	DWORD now = GetTickCount();
	DWORD deltaTime = now - startTime;
	if (deltaTime >= tickPerFrame)
	{
		terminated = true;
	}
}

DelayTime::~DelayTime()
{
}
