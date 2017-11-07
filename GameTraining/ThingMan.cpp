#include "ThingMan.h"


ThingMan::ThingMan()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_THINGMAN];
	getAnimationDelay()->setTickPerFrame(100);

	direction = Right;
	setHeight(30);

	setDy(0);
	setAy(0);//xoa trong luc

}

void ThingMan::update()
{

}
void ThingMan::onCollision(FBox* other, int nx, int ny)
{

}

ThingMan::~ThingMan()
{
}
