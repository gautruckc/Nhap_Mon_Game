#pragma once
#include "MovableObject.h"
#include"Keyboard.h"
#include "DelayTime.h"


enum ALADIN_TYPE
{
	ALD_NORMAL,
};

enum ALADIN_STAND_STATE
{
	ALDSTATE_LOOKAROUND,
	ALDSTATE_THROW_APPLE1,
	ALDSTATE_THROW_APPLE2

};


enum ALADIN_STATE
{
	LOOK_ARROUND,
	OTHER
};

enum ALADIN_ACTION
{
	ALD_LOOKAROUND,
	ALD_THROW_APPLE1,
	ALD_THROW_APPLE2,
	ALD_STAND_THROW,
	ALD_PRIORITY,
	ALD_SIT_DOWN,
	ALD_KILL,
	ALD_KILL_TOP,
	ALD_SIT_DOWN_THROW,
	ALD_RUN_THROW,
	ALD_SIT_DOWN_KILL,
	ALD_JUMP_NORMAL,
	ALD_JUMP_HEIGHT,
	ALD_JUMP_STOP,
	ALD_JUMP_KILL,
	ALD_CAPSIZE,
	ALD_CLIMB_THROW,
	ALD_CLIMB_JUMP,
	ALD_CLIMB_KILL,
	ALD_CLIMB_MID,
	ALD_RUN,
	ALD_RUN_STOP,
	ALD_CLIMB_UP,
	ALD_TIRED,
	ALD_PUSH,
	ALD_HOP,
	ALD_LIED_DOWN,
	ALD_PRIORITY_DOWN,
	ALD_AND_GOD,
	ALD_AND_LAMP
};

class Aladin :
	public MovableObject
{
	ALADIN_STATE aladinState;
	ALADIN_STAND_STATE aladinStandState;

public:
	bool onAttack=false;
	void setWidth(int width);
	Aladin();
	~Aladin();
	ALADIN_TYPE ald_type;
	ALADIN_ACTION ald_action;
	static Aladin* instance;
	static Aladin* getInstance();
	void onCollision(FBox* other, int nx, int ny);
	void update();
	void aladinLookAroundAction();
	void render();
	void onLastFrameAnimation();
	void onAnimationFinishLoop(int action);
	/*bool checkChangeNextMapView(List<MapView*>* mapViews);
	bool checkChangePrevMapView(List<MapView*>* mapViews);*/
};


