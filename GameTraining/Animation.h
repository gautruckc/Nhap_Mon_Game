#pragma once
#include <Windows.h>
#include "GameTime.h"

class Animation
{
public:
	RECT* frames;
	int frameCount;

	Animation();
	~Animation();
	void next(int &index);
};

