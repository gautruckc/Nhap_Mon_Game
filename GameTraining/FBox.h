#pragma once
#include "FRectangle.h"
#include"Config.h"

enum COLLISION_TYPE
{
	CT_STAIR,
	CT_GROUND,
	CT_ENEMY,
	CT_ITEM,
	CT_BULLET,
	CT_OUTERSPACE
};

class FBox : public FRectangle
{
	float dx, dy;
	float vx, vy, ax, ay;
public:
	COLLISION_TYPE collisionType;

	bool alive;

	float getDx();
	float getDy();
	float getVx();
	float getVy();
	float getAx();
	float getAy();

	void setDx(float value);
	void setDy(float value);
	void setVx(float value);
	void setVy(float value);
	void setAx(float value);
	void setAy(float value);

	bool isChangeDelta; // ktra xem xet va cham cua M voi nhiu S, M co thay doi getDx() dy hay ko
	bool isCollision; // ktra xem trong vong lap M co va cham voi bat cu thu gi ko

	virtual void update();
	void updateMove();

	//xu ly va cham
	virtual void onCollision(FBox* other, int nx, int ny);
	virtual void onIntersect(FBox* other);
	virtual void slideHandle();
	void updateLocation();

	FBox();
	~FBox();
};
