#pragma once
#include "TileMap.h"
#include"BaseObject.h"
#include"QuadTree.h"
#include"Sprite.h"
#include "StageView.h"
#include"List.h"
#include"OuterSpace.h"
class Stage :
	public TileMap
{
public:
	QuadTree* quadtree;
	BaseObject** objects;
	int nObject;
	List<StageView*> StageViews;
	//List<OuterSpace*> spaces;
	void init(char* tileSheetPath, char* matrixPath, char* objectsPath, char* quadTreePath);
	void initStageView(char* StageViewPath);

#pragma region StageViewS

	bool onStageViewChangeNext; // ==true thi cho moi thu dung yen
	bool onStageViewChangePrev;

	void updateStageViewChangeNext();
	void updateStageViewChangePrev();

#pragma endregion

	void readObjects(char* objectsPath);
	void update();
	void render();
	Stage();
	~Stage();
};
