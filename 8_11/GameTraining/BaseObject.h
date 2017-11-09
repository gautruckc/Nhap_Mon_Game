#pragma once
#include "FBox.h"
#include "Sprite.h"
#include "GameTime.h"
#include"SpriteManager.h"
#include "Camera.h"
#include"Collision.h"
#include"ActionLoop.h"
class BaseObject : public FBox
{
private:
	GameTime delay;
	int action, frameIndex;

	int backgroundAction;
	ActionLoop actionLoop;

public:
	bool pauseAnimation;
	FRectangle oldRect;
	Sprite* sprite;
	//-1 forever
	virtual void setAction(int actionValue,int loop=-1,bool reset=false);
	Direction direction;

	void setAnimationDelay(GameTime delay);
	void setBackgroundAction(int action);
	GameTime* getAnimationDelay();
	int getAction();
	void setFrameIndex(int frameIndex);
	int getFrameIndex();



	int id;

	//phuc hoi vi tri cu
	virtual void restoreLocation();

	BaseObject();
	~BaseObject();
	virtual void update();
	virtual void onLastFrameAnimation();
	virtual void render();

	virtual void onAnimationFinishLoop(int action);
};
