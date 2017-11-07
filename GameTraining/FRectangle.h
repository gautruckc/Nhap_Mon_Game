#pragma once
class FRectangle
{
public:
	float x, y;
	float width, height;

	virtual void setHeight(int height);

	FRectangle();
	~FRectangle();
	float left();
	float right();
	float top();
	float bottom();

	float xCenter();
	float yCenter();
};
