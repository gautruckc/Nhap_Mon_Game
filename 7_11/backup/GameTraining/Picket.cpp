#include "Picket.h"



Picket::Picket()
{
	setVx( -0.1); //***
}


Picket::~Picket()
{
}

void Picket::update()
{
	Enemy::update();
	if (Rockman::getInstance()->xCenter() > xCenter())
		direction = Right;
	else
		direction=Left;
	setVx( direction * 0.1);
}
