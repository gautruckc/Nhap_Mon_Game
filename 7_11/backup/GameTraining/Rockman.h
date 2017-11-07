#pragma once
#include "MovableObject.h"
#include"Keyboard.h"
#include "DelayTime.h"
#include"RockmanBullet.h"
#include"StageView.h"

enum ROCKMAN_TYPE
{
	RMT_NORMAL,
	RMT_CUTMAN,
	RMT_GUSTMAN
};

enum ROCKMAN_ACTION
{
	RM_STAND,
	RM_BLINK,
	RM_PREPARE_RUN,
	RM_RUN,
	RM_JUMP,
	RM_STAIR,
	RM_END_STAIR,
	RM_STAND_SHOOT,
	RM_RUN_SHOOT,
	RM_ACTION_COUNT
};

enum BLINK_STATE
{
	BLINK_OPEN,
	BLINK_CLOSE
};

class Rockman :
	public MovableObject
{
	//phan tren rockman co va cham voi cau thang nao hay k
	bool isIntersectStair;
	BLINK_STATE blinkState;
public:
	ROCKMAN_TYPE rm_type;
	ROCKMAN_ACTION rm_action;
	static Rockman* instance;
	static Rockman* getInstance();
	void update();
	void render();
	void setWidth(int width);
	//dia chi cau thang dang va cham voi rockman
	BaseObject* stairIntersect;

	void onLastFrameAnimation();
	bool onAttack;
	bool isAttack();

	void setIsIntersectStair(bool isIntersectStair);
	GameTime delay;
	Rockman();
	~Rockman();
	void onCollision(FBox* other, int nx, int ny);

	void updateBlink();
	DelayTime blinkDelay;
	DelayTime shootDelay;

#pragma region STAIR

	bool onStair;
	void setOnStair(bool onStair);
	void updateStair();

#pragma endregion

	void setAction(int actionValue);

#pragma region StageViewS

	bool checkChangeNextStageView(List<StageView*>* StageViews);
	bool checkChangePrevStageView(List<StageView*>* StageViews);

#pragma endregion

	DelayTime rmBulletDelay;
	void updateAttack();

};

