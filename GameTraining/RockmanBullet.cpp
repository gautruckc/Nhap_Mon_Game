#include "RockmanBullet.h"


List<RockmanBullet*>* RockmanBullet::bullets = new List<RockmanBullet*>();

void RockmanBullet::update()
{
}

RockmanBullet::RockmanBullet()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_BULLET];
	bullets->_Add(this); // moi lan tao ra dan la add dan vao luon
	width = sprite->anims[0].frames[0].right - sprite->anims[0].frames[0].left;
	height = sprite->anims[0].frames[0].bottom - sprite->anims[0].frames[0].top;
	collisionType = CT_BULLET;

}


RockmanBullet::~RockmanBullet()
{
}

void RockmanBullet::deleteBullet()
{
	bullets->_Remove(this);
	delete this;
}
