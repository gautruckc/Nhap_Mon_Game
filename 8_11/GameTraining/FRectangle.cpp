#include "FRectangle.h"



FRectangle::FRectangle()
{
}


void FRectangle::setHeight(int height)
{
	this->height = height;
}


FRectangle::~FRectangle()
{
}

float FRectangle::left()
{
	return x;
}

float FRectangle::right()
{
	return x + width - 1;
}

float FRectangle::top()
{
	return y;
}

float FRectangle::bottom()
{
	return y - height + 1;
}

float FRectangle::xCenter()
{
	return x + width/2;
}

float FRectangle::yCenter()
{
	return y - height / 2;
}
