#include "Blader.h"



void Blader::update()
{
	switch (bladerState)
	{
	case BLADER_PREPARE:
		if (Rockman::getInstance()->xCenter() > xCenter())
			direction = Right;
		else
			direction = Left;
		setDx(2 * direction);
		if (abs(this->xCenter() - Rockman::getInstance()->xCenter()) <= BLADER_FIND_ROCKMAN_DISTANCE)
		{
			bladerState = BLADER_ATTACK;
			xTarget = Rockman::getInstance()->x;
			yTarget = Rockman::getInstance()->y;
			//if (Rockman::getInstance()->y > y)
			//	setDy( BLADER_ATTACK_DY;
			//else
			//	setDy( -BLADER_ATTACK_DY;
			//
			//getDx() = ((xTarget - x) / (yTarget - y)) * getDy();

			float m = (xTarget - x) / (yTarget - y);

			float k = 4;

			setDy(k / sqrt(m*m + 1));

			if (yTarget > y)
			{
				setDy(abs(getDy()));
			}
			else
			{
				setDy(-abs(getDy()));
			}

			setDx(m*getDy());


		}
		break;
	case BLADER_ATTACK:
		if ((this->y + getDy() < yTarget && (oldRect.y > yTarget)) || (this->y + getDy() > yTarget && (oldRect.y < yTarget)))
		{
			setDy(-getDy());
		}
		if ((this->y + getDy() > oldRect.y && oldRect.y > yTarget) || (this->y + getDy() < oldRect.y && oldRect.y < yTarget))
		{
			setDy(0);
			bladerState = BLADER_PREPARE;
		}
		break;
	default:
		break;
	}
}

void Blader::onCollision(FBox * other, int nx, int ny)
{
	//auto rockman = Rockman::getInstance();
	//if (other == rockman)
	//{
	//	// xu li va cham Rockman voi Blader
	//}
}

Blader::Blader()
{
	bladerState = BLADER_PREPARE;
	setDy(0);
	setAy(0);//xoa trong luc
}


Blader::~Blader()
{
}
