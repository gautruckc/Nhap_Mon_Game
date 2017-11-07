#pragma once
#include"MovableObject.h"
#include"Camera.h"

class RockmanBullet : public MovableObject
{
public:
	static List<RockmanBullet*>* bullets;
	void update();

	RockmanBullet();
	~RockmanBullet();

	void deleteBullet();
};

