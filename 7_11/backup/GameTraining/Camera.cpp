#include "Camera.h"
#include"Aladin.h"
#include"OuterSpace.h"

Camera* Camera::instance = 0;
Camera* Camera::getInstance(){
	if (instance == 0){
		instance = new Camera();
	}
	return instance;
}
void Camera::onCollision(FBox * other, int nx, int ny)
{
	if (other->collisionType == CT_OUTERSPACE)
	{
		slideHandle();
	}
}

Camera::Camera()
{
	this->x = 0;
	this->y = 10;
	this->width = BACKBUFFER_WIDTH;
	this->height = BACKBUFFER_HEIGHT;
	setDy(0);
}

Camera::~Camera()
{
}

void Camera::setMapInterface(IMapGame* mapInterface)
{
	this->mapInterface = mapInterface;
}

void Camera::Transform(float x, float y, float& xRender, float& yRender)
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	matrix._22 = -1;
	matrix._41 = -this->x;
	matrix._42 = this->y;

	D3DXVECTOR3 pos3(x, y, 1);
	D3DXVECTOR4 MatrixResult;
	D3DXVec3Transform(&MatrixResult, &pos3, &matrix);

	xRender = MatrixResult.x;
	yRender = MatrixResult.y;
}

void Camera::update()
{
	FBox::update();
	setDy(0);
	auto aladin = Aladin::getInstance();

	/*if (this->left() <= 0)
		this->setDx(0);

	if (this->bottom() <= 0)
		this->setDy(0);*/

	if (((aladin->xCenter() + aladin->getDx() > this->xCenter()) && aladin->getDx() > 0) ||
		((aladin->xCenter() + aladin->getDx() < this->xCenter()) && aladin->getDx() < 0))
		this->setDx(aladin->getDx());
	else
		setDx(0);

	if (((aladin->yCenter() + aladin->getDy() > this->yCenter()) && aladin->getDy() > 0) ||
		((aladin->yCenter() + aladin->getDy() < this->yCenter()) && aladin->getDy() < 0))
		this->setDy(aladin->getDy());
	else
		setDy(0);


	if (this->top() - height + getDy() < 0)
	{
		setDy(height - this->top());
	}
	if (this->top() + getDy() > mapInterface->getHeight())
	{
		setDy(mapInterface->getHeight() - this->top());
	}
	if (this->left() + getDx() < 0)
	{
		setDx(-this->left());
	}
	if (this->left() + getDx() + width > mapInterface->getWidth())
	{
		setDx(mapInterface->getWidth() - (this->left() + width));
	}

/*
	if (x + getDx() < MapView::curMapView->left() && getDx() < 0)
	{
		x = MapView::curMapView->left();
		setDx(0);
	}

	if (right() + getDx() > MapView::curMapView->right() && getDx() > 0)
	{
		x = MapView::curMapView->right() - width;
		setDx(0);
	}*/

	/*if (aladin->x + aladin->getDx() < MapView::curMapView->left() && aladin->getDx() < 0)
	{
		aladin->x = MapView::curMapView->left();
		aladin->setDx(0);
	}

	if (aladin->right() + aladin->getDx() > MapView::curMapView->right() && aladin->getDx() > 0)
	{
		aladin->x = MapView::curMapView->right() - aladin->width;
		aladin->setDx(0);
	}*/
}