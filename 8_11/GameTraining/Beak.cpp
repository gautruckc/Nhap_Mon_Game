#include "Beak.h"

void Beak::updateBeakSprite()
{
	//beakDelay.update();
	//switch (beakState)
	//{
	//case BEAK_CLOSED:
	//	//setAction(BEAK_CLOSE);
	//	this->setAction( BEAK_CLOSED);
	//	setFrameIndex(0);
	//	if (beakDelay.isTerminated())
	//	{
	//		beakState = BEAK_OPENING;
	//		beakDelay.start(TIME_BEAK_CHANGE_STATE);
	//	}
	//	return;
	//case BEAK_OPENING:
	//	//setAction(BEAK_OPEN);
	//	this->setAction(BEAK_OPENING);
	//	setFrameIndex(0);
	//	if (beakDelay.isTerminated())
	//	{
	//		beakState = BEAK_SHOOTING;
	//		beakDelay.start(TIME_BEAK_SHOOTING);
	//	}
	//	return;
	//case BEAK_SHOOTING:
	//	//setAction(BEAK_SHOOT);
	//	this->setAction(BEAK_SHOOTING);
	//	setFrameIndex(0);
	//	updateAttack();
	//	if (beakDelay.isTerminated())
	//	{
	//		beakState = BEAK_CLOSING;
	//		beakDelay.start(TIME_BEAK_CHANGE_STATE);
	//	}
	//	return;
	//case BEAK_CLOSING:
	//	//setAction(BEAK_OPEN);
	//	this->setAction(BEAK_CLOSING);
	//	setFrameIndex(0);
	//	if (beakDelay.isTerminated())
	//	{
	//		beakState = BEAK_CLOSED;
	//		beakDelay.start(TIME_BEAK_CLOSED);
	//	}
	//	return;
	//default:
	//	break;
	//}
}

void Beak::update()
{
	/*Enemy::update();
	updateBeakSprite();*/
}

void Beak::updateAttack()
{
	/*if (delay.atTime())
	{
		BeakBullet* bullet = new BeakBullet();
		bullet->setDx(direction);
		bullet->setDy(0);
		bullet->x = x;
		bullet->y = y - height / 2 + bullet->height / 2;
	}*/
}

Beak::Beak()
{
	/*beakState = BEAK_CLOSED;
	beakDelay.start(TIME_BEAK_CLOSED);
	direction = Left;
	delay.setTickPerFrame(200);*/
}

Beak::~Beak()
{
}