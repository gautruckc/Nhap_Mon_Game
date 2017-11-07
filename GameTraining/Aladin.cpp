#include"Stairs.h"
#include "Aladin.h"
#include"KEY.h"
#include"MapGame.h"

Aladin * Aladin::instance = 0;
Aladin * Aladin::getInstance()
{
	if (instance == 0)
		instance = new Aladin();
	return instance;
}

void Aladin::onCollision(FBox* other, int nx, int ny)
{
	/*setAction(ALD_LOOKAROUND);*/
	//if (other->collisionType == CT_ENEMY)
	//{
	//	//chan di chuyen
	//	slideHandle();
	//}
	//if (other->collisionType == CT_GROUND){
	//	slideHandle();
	//	ground = true;
	//}
	MovableObject::onCollision(other, nx, ny);
}



Aladin::Aladin()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_ALADIN];
	getAnimationDelay()->setTickPerFrame(100);
	/*delay.tickPerFrame = 100;*/
	ald_action = ALD_LOOKAROUND; //khoi tao la aladin nhin xung quanh
	/*ald_type = ALD_NORMAL;*/
	direction = Right;
	setHeight(30);
	setBackgroundAction(ALD_LOOKAROUND);
	setAction(ALD_LOOKAROUND, 2,true);

	aladinState = ALADIN_STATE::LOOK_ARROUND;
	aladinStandState = ALDSTATE_LOOKAROUND;
}

Aladin::~Aladin()
{
}



void Aladin::update()
{
	switch (aladinState)
	{
	case LOOK_ARROUND:

		break;
	case OTHER:
		break;
	default:
		break;
	}



	// ham update check va chạm và keyboard 
	bool keyUp, keyDown, keyLeft, keyRight, keyAttackPress;
	bool keyJump, keyJumpPress, keyUpPress, keyDownPress;
	keyAttackPress = KEY::getInstance()->isAttackPress;
	keyLeft = KEY::getInstance()->isLeftDown;
	keyRight = KEY::getInstance()->isRightDown;
	keyUp = KEY::getInstance()->isUpDown;
	keyUpPress = KEY::getInstance()->isUpPress;
	keyDown = KEY::getInstance()->isDownDown;
	keyDownPress = KEY::getInstance()->isDownPress;
	bool keyMove = keyLeft || keyRight;
	keyJump = KEY::getInstance()->isJumpDown;
	keyJumpPress = KEY::getInstance()->isJumpPress;

	if (keyLeft)
	{
		setAction(ALD_RUN,1); // set khi chay qua trai
		direction = Left;
		setVx(-ALD_V_RUN);
	}
	else if (keyRight)
	{
			setAction(ALD_RUN,1);
			direction = Right;
			setVx(ALD_V_RUN);
	}
	else
	{
		/*setAction(ALD_LOOKAROUND,2);*/
		
			setVx(0);
	}

	if (ground)
	{
		if (keyUpPress)
		{
			setAction(ALD_PRIORITY,1);
			setWidth(10);
		}
		/*else
		{
			setAction(ALD_LOOKAROUND);
		}*/
		if (keyDownPress)
		{
			setAction(ALD_SIT_DOWN,1);
			setWidth(10);
		}
		/*else
		{
			setAction(ALD_LOOKAROUND);
		}*/
	}
	
	MovableObject::update();
}

void Aladin::setWidth(int width)
{
	if (direction == Right)
	{
		x += this->width - width;
	}

	this->width = width;
}


void Aladin::render()
{
	if (sprite == 0)
		return;
	float yRender;
	float xRender;

	D3DXMATRIX flipMatrix;
	int frameWidth = sprite->anims[getAction()].frames[getFrameIndex()].right - sprite->anims[getAction()].frames[getFrameIndex()].left;
	Camera::getInstance()->Transform(x, y, xRender, yRender);
	xRender = (int)xRender;
	yRender = (int)yRender;

	xRender -= (frameWidth - width) / 2;

	if (direction != sprite->img->direction)
	{
		D3DXMatrixIdentity(&flipMatrix);
		flipMatrix._11 = -1;
		flipMatrix._41 = 2 * (xRender + frameWidth / 2);

		DirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
	sprite->render(xRender, yRender, getAction(), getFrameIndex());
	if (direction != sprite->img->direction)
	{
		D3DXMatrixIdentity(&flipMatrix);
		DirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
}

//bool Aladin::checkChangeNextMapView(List<MapView*>* mapViews)
//{
//	if (MapView::curMapView->index + 1 == mapViews->Count)
//		return false;
//	auto nextMapView = mapViews->at(MapView::curMapView->index + 1);
//
//	if (Collision::AABBCheck(this, nextMapView))
//		return true;
//
//	return false;
//}
//
//bool Aladin::checkChangePrevMapView(List<MapView*>* mapViews)
//{
//	if (MapView::curMapView->index == 0)
//		return false;
//	auto prevMapView = mapViews->at(MapView::curMapView->index - 1);
//
//	if (Collision::AABBCheck(this, prevMapView))
//		return true;
//
//	return false;
//}

void Aladin::onAnimationFinishLoop(int action)
{
	if (aladinState == ALADIN_STATE::LOOK_ARROUND)
	{
		switch (aladinStandState)
		{
		case ALDSTATE_LOOKAROUND:
			setAction(ALD_THROW_APPLE1, 1);
			aladinStandState = ALDSTATE_THROW_APPLE1;
			break;
		case ALDSTATE_THROW_APPLE1:
			setAction(ALD_THROW_APPLE2, 2);
			aladinStandState = ALDSTATE_THROW_APPLE2;
			break;
		case ALDSTATE_THROW_APPLE2:
			setAction(ALD_LOOKAROUND, 2);
			aladinStandState = ALDSTATE_LOOKAROUND;
			break;
		default:
			break;
		}
	}


}

void Aladin::onLastFrameAnimation()
{
	/*if (ald_action == ALD_RUN)
	{
	bool keyLeft = KEY::getInstance()->isLeftDown;
	bool keyRight = KEY::getInstance()->isRightDown;
	bool keyMove = keyLeft || keyRight;

	if (keyMove)
	setAction(ALD_RUN);
	else
	setAction(ALD_LOOKAROUND);
	}*/

	BaseObject::onLastFrameAnimation();
}
