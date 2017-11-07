#pragma once
#include "Enemy.h"
#include "Rockman.h"

enum BLADER_STATE {
	BLADER_PREPARE,
	BLADER_ATTACK
};

class Blader :
	public Enemy
{
public:
	int xTarget, yTarget;
	BLADER_STATE bladerState;
	void update();
	void onCollision(FBox* other, int nx, int ny);
	Blader();
	~Blader();
};
