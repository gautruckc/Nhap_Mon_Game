#include "MovableObject.h"



void MovableObject::update()
{
	ground = false;
	BaseObject::update();
	FBox::updateMove();
}

void MovableObject::onCollision(FBox * other, int nx, int ny)
{
	if (other->collisionType == CT_GROUND && ny == 1)
		ground = true;
	BaseObject::onCollision(other, nx, ny);
}

MovableObject::MovableObject()
{
	//getDx() = -1;
	setDy(0);
}


MovableObject::~MovableObject()
{
}
