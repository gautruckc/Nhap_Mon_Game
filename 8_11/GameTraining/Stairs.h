#pragma once
#include "BaseObject.h"
enum STAIR_TYPE
{
	STAIR_LEFT = -102,
	STAIR_RIGHT = -2
};
class Stairs :
	public BaseObject
{
public:
	Stairs();
	void onIntersect(FBox* other);
	void onCollision(FBox* other, int nx, int ny);
	~Stairs();
};

