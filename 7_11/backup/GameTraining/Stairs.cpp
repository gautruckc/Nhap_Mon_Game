#include "Stairs.h"
#include"Rockman.h"
#include"KEY.h"

Stairs::Stairs()
{
	collisionType = CT_STAIR;
}

void Stairs::onIntersect(FBox * other)
{
	Rockman::getInstance()->stairIntersect = this;
	int rockManXCenter = other->xCenter();
	int stairXCenter = xCenter();

	if (y > other->y - DISTANCE_OUT_STAIR)
	{
		Rockman::getInstance()->setIsIntersectStair(true);
	}


	if (rockManXCenter < stairXCenter - STAIR_DELTA || rockManXCenter > stairXCenter + STAIR_DELTA)
		return;



	if (Rockman::getInstance()->onStair)
		return;

	bool keyUp = KEY::getInstance()->isUpDown;
	bool keyDown = KEY::getInstance()->isDownDown;

	if (keyUp || (keyDown && bottom() < Rockman::getInstance()->bottom() + Rockman::getInstance()->getDy()))
	{
		Rockman::getInstance()->setAction(RM_STAIR);
		Rockman::getInstance()->setOnStair(true);

		Rockman::getInstance()->setVx(0);
		Rockman::getInstance()->setDx(0);
		Rockman::getInstance()->x = x;

		return;
	}

}

void Stairs::onCollision(FBox * other, int nx, int ny)
{
	if (ny != 1)
		return;
	int rockManXCenter = other->xCenter();
	int stairXCenter = xCenter();

	if (rockManXCenter < stairXCenter - STAIR_DELTA || rockManXCenter > stairXCenter + STAIR_DELTA)
		return;

	bool keyDown = KEY::getInstance()->isDownDown;

	if (Rockman::getInstance()->onStair)
		return;

	if (keyDown)
	{
		Rockman::getInstance()->setAction(RM_STAIR);
		Rockman::getInstance()->setOnStair(true);

		Rockman::getInstance()->setVx(0);
		Rockman::getInstance()->setDx(0);

		Rockman::getInstance()->y = y + 2 * DISTANCE_OUT_STAIR;
		Rockman::getInstance()->x = x;
		return;
	}
}


Stairs::~Stairs()
{
}
