#pragma once
#include"Enemy.h"

enum THINGMAN_ACTION
{
	TM_STAND,
	TM_RUN,
	TM_THROWM
};


class ThingMan:public Enemy
{
public:
	THINGMAN_ACTION tm_action;
	int xTarget, yTarget;
	void update();
	void onCollision(FBox* other, int nx, int ny);
	void render();
	void onLastFrameAnimation();
	ThingMan();
	~ThingMan();
};

