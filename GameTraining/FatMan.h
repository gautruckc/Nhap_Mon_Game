#pragma once
#include"Enemy.h"

enum FATMAN_ACTION
{
	FM_STAND,
	FM_RUN,
	FM_THROWN
};



class FatMan: public Enemy
{
public:
	FATMAN_ACTION fm_Action;
	int xTarget, yTarget;
	void update();
	void render();
	void onLastFrameAnimation();
	void onCollision(FBox* other, int nx, int ny);
	FatMan();
	~FatMan();
};

