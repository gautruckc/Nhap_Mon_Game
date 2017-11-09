#pragma once
#include "Enemy.h"
#include "BeakBullet.h"

enum BEAK_TYPE {
};

enum BEAK_STATE
{
	BEAK_CLOSED,
	BEAK_OPENING,
	BEAK_SHOOTING,
	BEAK_CLOSING
};

class Beak :
	public Enemy
{
public:
	BEAK_STATE beakState;
	GameTime delay;

	void updateBeakSprite();
	/*DelayTime beakDelay;*/

	void update();
	void updateAttack();
	Beak();
	~Beak();
};
