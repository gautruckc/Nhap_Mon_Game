#include "FBox.h"
#include"Collision.h"
#include<iostream>
using namespace std;

int time = 15; //

extern double collisionTime;
extern float nx, ny;

void FBox::updateLocation()
{
	if (isCollision && !isChangeDelta)
	{
		if (abs(getDx()) > abs(dy))
			setDy(0);
		else
			setDx(0);
	}
	x += getDx();
	y += getDy();
}

void FBox::update()
{
	isChangeDelta = false;
	isCollision = false;
}

void FBox::updateMove()
{
	setVx(getVx() + getAx()*time);
	setVy(getVy() + getAy()*time);
	setDx(getVx()*time);
	setDy(getVy()*time);
}

void FBox::slideHandle()
{
	//float remainingTime = 1.0f - collisionTime;

	//float dotprod = (getDx()*ny + dy*nx) * remainingTime;
	//getDx() = dotprod*ny;
	//setDy( dotprod*nx;

	if (nx != 0)
	{
		isChangeDelta = true;
		setDx(getDx()*collisionTime);
		return;
	}
	if (ny != 0)
	{
		isChangeDelta = true;
		setDy(dy*collisionTime);
		return;
	}
}

float FBox::getDy()
{
	return dy;
}

float FBox::getDx()
{
	return dx;
}

float FBox::getVx()
{
	return vx;
}

float FBox::getVy()
{
	return vy;
}

float FBox::getAx()
{
	return ax;
}

float FBox::getAy()
{
	return ay;
}


void FBox::setDx(float value)
{
	dx = value;
}

void FBox::setDy(float value)
{
	dy = value;
}

void FBox::setVx(float value)
{
	vx = value;
}

void FBox::setVy(float value)
{
	vy = value;
}

void FBox::setAx(float value)
{
	ax = value;
}

void FBox::setAy(float value)
{
	ay = value;
}


void FBox::onCollision(FBox * other, int nx, int ny)
{
	if (other->collisionType == CT_GROUND)
	{
		//van toc khong duoc tang dan deu khi dung tren san
		if (ny != 0)
			setVy(-0.1f); //****
		slideHandle();
	}
}

void FBox::onIntersect(FBox * other)
{
}

FBox::FBox()
{
	collisionType = CT_GROUND;
	setDx(0);
	setDy(0);
	setVx(0);
	setVy(0);
	setAx(0);
	setAy(-0.001); // Gravitational acceleration gia toc trong truong
}

FBox::~FBox()
{
}