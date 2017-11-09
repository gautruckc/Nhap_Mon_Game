#include "Point.h"


Point::Point(int x , int y )
{
	set(x, y);
}

void Point::set(int x, int y)
{
	X = x;
	Y = y;
}


Point::~Point()
{
}