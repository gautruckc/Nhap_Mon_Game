#pragma once
#include "Config.h"
#include "Texture.h"
#include"FBox.h"
#include"ObjectsFilter.h"
#include"MapView.h"
#include"IMapGame.h"
class Camera : public FBox
{
private:
	static Camera* instance;
	IMapGame* mapInterface;
public:
	void setMapInterface(IMapGame* mapInterface);
	static Camera* getInstance();
	void Transform(float x, float y, float& xRender, float& yRender);
	void update();
	ObjectsFilter objects;

	void onCollision(FBox * other, int nx, int ny);
	Camera();
	~Camera();
};
