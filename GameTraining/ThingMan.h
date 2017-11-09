#pragma once
#include"Enemy.h"

enum THINGMAN_ACTION
{
	TM_RUN,
	TM_HIT,
	TM_JUMP
};


class ThingMan:public Enemy
{
public:
	THINGMAN_ACTION tm_Action;
	int xTarget, yTarget;
	void update();
	void render();
	void onLastFrameAnimation();
	void onCollision(FBox* other, int nx, int ny);
	ThingMan();
	~ThingMan();
};

