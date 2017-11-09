#include "ThingMan.h"


ThingMan::ThingMan()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_THINGMAN];
	getAnimationDelay()->setTickPerFrame(100);
	tm_Action = TM_RUN;

	direction = Right;
	setHeight(30);

	setDy(0);
	setAy(0);//xoa trong luc

}

void ThingMan::update()
{

}
void ThingMan::onCollision(FBox* other, int nx, int ny)
{

}

void ThingMan::render()
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

void ThingMan::onLastFrameAnimation()
{
	BaseObject::onLastFrameAnimation();
}

ThingMan::~ThingMan()
{
}
