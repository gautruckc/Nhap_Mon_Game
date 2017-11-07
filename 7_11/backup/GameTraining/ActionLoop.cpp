#include "ActionLoop.h"


ActionLoop::ActionLoop()
{
}

void ActionLoop::setLoop(int loop)
{
	this->loop = loop;
}
bool ActionLoop::decreaseLoop()
{
	if (loop == 0)
		return false;
	loop--;
	return true;
}

bool ActionLoop::isForeverLoop()
{
	return loop < 0;
}


ActionLoop::~ActionLoop()
{
}
