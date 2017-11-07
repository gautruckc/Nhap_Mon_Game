#include"KEY.h"
#include "MapGame.h"
#include"Picket.h"
#include"ThingMan.h"
#include"Beak.h"
#include"Aladin.h"
#include"Collision.h"
#include"Stairs.h"
#include"OuterSpace.h"

extern void ignoreLineIfstream(ifstream& fs, int lineCount);

void MapGame::init(char * tileSheetPath, char * matrixPath, char * objectsPath, char* quadTreePath)
{
	TileMap::init(tileSheetPath, matrixPath);
	readObjects(objectsPath);
	quadtree = new QuadTree(quadTreePath, objects, rowCount * 16);
	Camera::getInstance()->setMapInterface(this);
}

int MapGame::getWidth()
{
	return width;
}
int MapGame::getHeight()
{
	return height;
}

void MapGame::initMapView(char * MapViewPath)
{
	int count, MapViewBeginIndex;
	ifstream fs(MapViewPath);
	MapView* mapView;
	ignoreLineIfstream(fs, 1);
	fs >> count;
	ignoreLineIfstream(fs, 3);
	for (int i = 0; i < count; i++)
	{
		mapView = new MapView(fs);
		MapViews._Add(mapView);
		mapView->y = rowCount * 16 - mapView->y;
	}

	Camera* camera = Camera::getInstance();
	/*Rockman* rockman = Rockman::getInstance();*/
	Aladin* aladin = Aladin::getInstance();

	ignoreLineIfstream(fs, 3);
	fs >> camera->x >> camera->y;
	camera->y = rowCount * 16 - camera->y;
	ignoreLineIfstream(fs, 3);
	fs >> aladin->x >> aladin->y;
	aladin->y = rowCount * 16 - aladin->y;
	ignoreLineIfstream(fs, 3);
	fs >> MapViewBeginIndex;

	if (MapView::curMapView == 0)
	{
		MapView::curMapView = MapViews[MapViewBeginIndex];
	}
}

void MapGame::updateMapViewChangeNext()
{
	auto nextMapView = MapViews.at(MapView::curMapView->index + 1);
	Camera* camera = Camera::getInstance();
	camera->setDy(CAMERA_CHANGEMAPVIEW_DY);
	if (camera->bottom() + camera->getDy() > nextMapView->bottom())
	{
		camera->y = nextMapView->bottom() + camera->height;
		camera->setDy(0);
		onMapViewChangeNext = false;
		MapView::curMapView = nextMapView;
		return;
	}
	Aladin* aladin = Aladin::getInstance();
	//KEY::getInstance()->isUpDown = true;
	//rockman->update();
	aladin->y += ALADIN_CHANGEMAPVIEW_DY;
	aladin->pauseAnimation = false;
	aladin->BaseObject::update();
	camera->updateLocation();
}

void MapGame::updateMapViewChangePrev()
{
	auto prevMapView = MapViews.at(MapView::curMapView->index - 1);
	Camera* camera = Camera::getInstance();
	camera->setDy(-CAMERA_CHANGEMAPVIEW_DY);
	if (camera->bottom() + camera->getDy() < prevMapView->bottom())
	{
		camera->y = prevMapView->bottom() + camera->height;
		camera->setDy(0);
		onMapViewChangePrev = false;
		MapView::curMapView = prevMapView;
		return;
	}
	Aladin* aladin = Aladin::getInstance();
	/*if (aladin->onStair)
	{
		aladin->y += -ALADIN_CHANGEMAPVIEW_DY;
		aladin->pauseAnimation = false;
		aladin->BaseObject::update();
	}*/
	camera->updateLocation();
}



// doc file object
void MapGame::readObjects(char * objectsPath)
{

	int id;
	ifstream fs(objectsPath);
	fs >> nObject;
	objects = new BaseObject*[nObject];
	for (auto i = 0; i < nObject; i++)
	{
		fs >> id;
		switch (id % 100)
		{
		case SPR_THINGMAN:
			objects[i] = new ThingMan();
			break;
		case SPR_PICKET:
			objects[i] = new Picket();
			break;
		case SPR_BEAK:
			objects[i] = new Beak();
			break;
		case SPR_STAIR:
			objects[i] = new Stairs();
			break;
		case SPR_OUTERSPACE:
			objects[i] = new OuterSpace();
			break;
		default:
			objects[i] = new BaseObject();
			break;
		}
		objects[i]->id = id;
		fs >> objects[i]->x
			>> objects[i]->y
			>> objects[i]->width
			>> objects[i]->height;

		objects[i]->y = rowCount * 16 - objects[i]->y;

		objects[i]->oldRect.x = objects[i]->x;
		objects[i]->oldRect.y = objects[i]->y;
		objects[i]->oldRect.width = objects[i]->width;
		objects[i]->oldRect.height = objects[i]->height;

		if (id >= 0)
		{
			objects[i]->sprite = SpriteManager::getInstance()->sprites[id];
			auto mov = (MovableObject*)objects[i];
			fs >> mov->spaceMove.x
				>> mov->spaceMove.y
				>> mov->spaceMove.width
				>> mov->spaceMove.height;
			mov->spaceMove.y = rowCount * 16 - mov->spaceMove.y;
		}
	}
}

void MapGame::update()
{
	auto camera = Camera::getInstance();

	camera->update();
	/*Rockman::getInstance()->update();*/
	Aladin::getInstance()->update();
	//tao danh sach object trong camera
	quadtree->update();

	int nObjectsCam = Camera::getInstance()->objects.allObjects.size();
	auto allObjectsInCam = &Camera::getInstance()->objects.allObjects;

	int nEnemies = Camera::getInstance()->objects.enemies.size();
	auto enemies = &Camera::getInstance()->objects.enemies;

	int nSpace = Camera::getInstance()->objects.outerSpaces.size();
	auto spacesInCam = &Camera::getInstance()->objects.outerSpaces;

	for (int i = 0; i < Camera::getInstance()->objects.grounds.size(); i++)
	{
		Collision::CheckCollision(Aladin::getInstance(), Camera::getInstance()->objects.grounds.at(i));
	}

	Aladin::getInstance()->updateLocation();
	/*Rockman::getInstance()->updateLocation();*/
	
	camera->updateLocation();

}

void MapGame::render()
{
	TileMap::render();
	int nObjectsCam = Camera::getInstance()->objects.allObjects.size();
	auto allObjectsInCam = &Camera::getInstance()->objects.allObjects;

	for (size_t i = 0; i < nObjectsCam; i++)
	{
		allObjectsInCam->at(i)->render();
	}

	for (size_t i = 0; i < BeakBullet::bullets->Count; i++)
	{
		BeakBullet::bullets->at(i)->render();
	}

	/*for (size_t i = 0; i < RockmanBullet::bullets->Count; i++)
	{
		RockmanBullet::bullets->at(i)->render();
	}*/
}

MapGame::MapGame()
{
}

MapGame::~MapGame()
{
}