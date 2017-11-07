#pragma once
#include"Enemy.h"

class ThingMan:public Enemy
{
public:
	int xTarget, yTarget;
	void update();
	void onCollision(FBox* other, int nx, int ny);
	ThingMan();
	~ThingMan();
};

