#pragma once
#include "BaseObject.h"
class MovableObject : public BaseObject
{
public:
	bool ground;
	FRectangle spaceMove;
	virtual void update();
	virtual void onCollision(FBox* other, int nx, int ny);
	MovableObject();
	~MovableObject();
};

