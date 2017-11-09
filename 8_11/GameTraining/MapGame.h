#pragma once
#include "TileMap.h"
#include "BaseObject.h"
#include "QuadTree.h"
#include "Sprite.h"
#include "MapView.h"
#include "List.h"
#include"IMapGame.h"
#include "OuterSpace.h"
class MapGame :
	public TileMap, IMapGame
{
public:
	int getWidth();
	int getHeight();

	QuadTree* quadtree;
	BaseObject** objects;

	List<MapView*> MapViews;
	int nObject;
	void init(char* tileSheetPath, char* matrixPath, char* objectsPath, char* quadTreePath);
	void initMapView(char * MapViewPath);

	void readObjects(char* objectsPath);
	void update();
	void render();
	MapGame();
	~MapGame();

#pragma region MapViewS

	bool onMapViewChangeNext; // ==true thi cho moi thu dung yen
	bool onMapViewChangePrev;

	void updateMapViewChangeNext();
	void updateMapViewChangePrev();
};
