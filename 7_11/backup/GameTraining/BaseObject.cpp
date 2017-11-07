#include "BaseObject.h"



void BaseObject::setAction(int actionValue, int loop, bool reset)
{
	if (reset || action != actionValue)
	{
		this->action = actionValue;
		frameIndex = 0;
		actionLoop.setLoop(loop);
	}
}

void BaseObject::setBackgroundAction(int action)
{
	backgroundAction = action;
	setAction(backgroundAction);
}

void BaseObject::setAnimationDelay(GameTime delay)
{
	this->delay = delay;
}
GameTime* BaseObject::getAnimationDelay()
{
	return &delay;
}
int BaseObject::getAction()
{
	return action;
}
void BaseObject::setFrameIndex(int frameIndex)
{
	this->frameIndex = frameIndex;
}
int BaseObject::getFrameIndex()
{
	return this->frameIndex;
}



void BaseObject::restoreLocation()
{
	x = oldRect.x;
	y = oldRect.y;
	width = oldRect.width;
	height = oldRect.height;
}

BaseObject::BaseObject()
{
	sprite = 0;
	delay.setTickPerFrame(0);
	frameIndex = 0;
	action = 0;
	pauseAnimation = false;
}


BaseObject::~BaseObject()
{
}

void BaseObject::update()
{
	if (sprite == 0)
		return;
	FBox::update();

	if (pauseAnimation)
		return;

	if (delay.atTime())
	{
		sprite->update(action, frameIndex);
		if (frameIndex == 0)
		{
			onLastFrameAnimation();
		}
	}
}

void BaseObject::onAnimationFinishLoop(int action)
{

}


void BaseObject::onLastFrameAnimation()
{
	if (!actionLoop.isForeverLoop())
	{
		if (!actionLoop.decreaseLoop())
		{
			setAction(backgroundAction);
			onAnimationFinishLoop(getAction());
		}
	}
}

void BaseObject::render()
{
	if (sprite == 0)
		return;
	float yRender;
	float xRender;

	D3DXMATRIX flipMatrix;
	Camera::getInstance()->Transform(x, y, xRender, yRender);
	xRender = (int)xRender;
	yRender = (int)yRender;
	if (direction != sprite->img->direction)
	{
		int frameWidth = sprite->anims[action].frames[frameIndex].right - sprite->anims[action].frames[frameIndex].left;
		D3DXMatrixIdentity(&flipMatrix);
		flipMatrix._11 = -1;
		flipMatrix._41 = 2*(xRender + frameWidth/2 );
		
		DirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
	sprite->render(xRender, yRender, action, frameIndex);
	if (direction != sprite->img->direction)
	{
		D3DXMatrixIdentity(&flipMatrix);
		DirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
}
