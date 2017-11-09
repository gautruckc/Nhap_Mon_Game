#include "Animation.h"

Animation::Animation()
{
}


Animation::~Animation()
{
}

void Animation::next(int &index)
{
	index++;
	if (index >= frameCount)
		index = 0;
}
