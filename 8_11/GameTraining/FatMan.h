#pragma once
#include "Enemy.h"

enum FATMAN_ACTION
{
	FM_STAND,
	FM_RUN,
	FM_THROWM
};

class FatMan :
	public Enemy
{
public:
	FATMAN_ACTION fm_action;
	int xTarget, yTarget;
	void update();
	void onCollision(FBox* other, int nx, int ny);
	void render();
	void onLastFrameAnimation();
	FatMan();
	~FatMan();
};

