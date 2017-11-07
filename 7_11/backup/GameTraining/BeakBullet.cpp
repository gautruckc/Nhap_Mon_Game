#include "BeakBullet.h"

List<BeakBullet*>* BeakBullet::bullets = new List<BeakBullet*>();

void BeakBullet::update()
{
}

BeakBullet::BeakBullet()
{
 	sprite = SpriteManager::getInstance()->sprites[SPR_BEAK_BULLET];
	width = sprite->anims[0].frames[0].right - sprite->anims[0].frames[0].left;
	height = sprite->anims[0].frames[0].bottom - sprite->anims[0].frames[0].top;
	bullets->_Add(this);
	collisionType = CT_BULLET;
}


BeakBullet::~BeakBullet()
{
}
