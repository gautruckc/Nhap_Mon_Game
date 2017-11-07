#include"KEY.h"
#include "Stage.h"
#include"Picket.h"
#include"Blader.h"
#include"Beak.h"
#include"Rockman.h"
#include"Collision.h"
#include"Stairs.h"
#include"OuterSpace.h"
#include"RockmanBullet.h"
void Stage::init(char * tileSheetPath, char * matrixPath, char * objectsPath, char* quadTreePath)
{
	TileMap::init(tileSheetPath, matrixPath);
	readObjects(objectsPath);
	quadtree = new QuadTree(quadTreePath, objects, rowCount * 16);
}

void Stage::initStageView(char * StageViewPath)
{
	int count, StageViewBeginIndex;
	ifstream fs(StageViewPath);
	StageView* stageView;
	ignoreLineIfstream(fs, 1);
	fs >> count;
	ignoreLineIfstream(fs, 3);
	for (int i = 0; i < count; i++)
	{
		stageView = new StageView(fs);
		StageViews._Add(stageView);
		stageView->y = rowCount * 16 - stageView->y;
	}

	Camera* camera = Camera::getInstance();
	Rockman* rockman = Rockman::getInstance();

	ignoreLineIfstream(fs, 3);
	fs >> camera->x >> camera->y;
	camera->y = rowCount * 16 - camera->y;
	ignoreLineIfstream(fs, 3);
	fs >> rockman->x >> rockman->y;
	rockman->y = rowCount * 16 - rockman->y;
	ignoreLineIfstream(fs, 3);
	fs >> StageViewBeginIndex;

	if (StageView::curStageView == 0)
	{
		StageView::curStageView = StageViews[StageViewBeginIndex];
	}
}

void Stage::updateStageViewChangeNext()
{
	auto nextStageView = StageViews.at(StageView::curStageView->index + 1);
	Camera* camera = Camera::getInstance();
	camera->setDy(CAMERA_CHANGESTAGEVIEW_DY);
	if (camera->bottom() + camera->getDy() > nextStageView->bottom())
	{
		camera->y = nextStageView->bottom() + camera->height;
		camera->setDy(0);
		onStageViewChangeNext = false;
		StageView::curStageView = nextStageView;
		return;
	}
	Rockman* rockman = Rockman::getInstance();
	//KEY::getInstance()->isUpDown = true;
	//rockman->update();
	rockman->y += ROCKMAN_CHANGESTAGEVIEW_DY;
	rockman->pauseAnimation = false;
	rockman->BaseObject::update();
	camera->updateLocation();
}

void Stage::updateStageViewChangePrev()
{
	auto prevStageView = StageViews.at(StageView::curStageView->index - 1);
	Camera* camera = Camera::getInstance();
	camera->setDy(-CAMERA_CHANGESTAGEVIEW_DY);
	if (camera->bottom() + camera->getDy() < prevStageView->bottom())
	{
		camera->y = prevStageView->bottom() + camera->height;
		camera->setDy(0);
		onStageViewChangePrev = false;
		StageView::curStageView = prevStageView;
		return;
	}
	Rockman* rockman = Rockman::getInstance();
	if (rockman->onStair)
	{
		rockman->y += -ROCKMAN_CHANGESTAGEVIEW_DY;
		rockman->pauseAnimation = false;
		rockman->BaseObject::update();
	}
	camera->updateLocation();
}

void Stage::readObjects(char * objectsPath)
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
		/*case SPR_BLADER:
			objects[i] = new Blader();*/
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

void Stage::update()
{
	if (!onStageViewChangeNext && Rockman::getInstance()->checkChangeNextStageView(&StageViews))
	{
		onStageViewChangeNext = true;
	}
	if (!onStageViewChangePrev && Rockman::getInstance()->checkChangePrevStageView(&StageViews))
	{
		onStageViewChangePrev = true;
	}

	if (onStageViewChangeNext)
	{
		updateStageViewChangeNext();
		return;
	}
	if (onStageViewChangePrev)
	{
		updateStageViewChangePrev();
		return;
	}
	auto camera = Camera::getInstance();

	Rockman::getInstance()->update();

	//tao danh sach object trong camera
	quadtree->update();

	int nObjectsCam = Camera::getInstance()->objects.allObjects.size();
	auto allObjectsInCam = &Camera::getInstance()->objects.allObjects;

	int nEnemyObjectsCam = Camera::getInstance()->objects.enemies.size();
	auto enemiesInCam = &Camera::getInstance()->objects.enemies;

	int nStair = Camera::getInstance()->objects.stairs.size();
	auto stairsInCam = &Camera::getInstance()->objects.stairs;

	int nSpace = Camera::getInstance()->objects.outerSpaces.size();
	auto spacesInCam = &Camera::getInstance()->objects.outerSpaces;

	int nGroundObjectsCam = Camera::getInstance()->objects.grounds.size();
	auto groundsInCam = &Camera::getInstance()->objects.grounds;

	for (size_t i = 0; i < nObjectsCam; i++)
	{
		auto obj = allObjectsInCam->at(i);
		obj->update();
	}

	for (size_t i = 0; i < nStair; i++)
	{
		auto obj = stairsInCam->at(i);
		Collision::CheckCollision(Rockman::getInstance(), obj);
	}
	for (size_t i = 0; i < nGroundObjectsCam; i++)
	{
		auto obj = groundsInCam->at(i);
		Collision::CheckCollision(Rockman::getInstance(), obj);
	}

	for (size_t i = 0; i < nEnemyObjectsCam; i++)
	{
		auto enemy = allObjectsInCam->at(i);
		Collision::CheckCollision(Rockman::getInstance(), enemy);
		for (size_t j = 0; j < nGroundObjectsCam; j++)
		{
			Collision::CheckCollision(enemy, groundsInCam->at(j));
		}
	}

	for (size_t i = 0; i < nEnemyObjectsCam; i++)
	{
		auto enemy = enemiesInCam->at(i);
		enemy->updateLocation();
	}

	Rockman::getInstance()->updateLocation();
	camera->update();

	for (size_t i = 0; i < nSpace; i++)
	{
		auto obj = spacesInCam->at(i);
		Collision::CheckCollision(Camera::getInstance(), obj);
	}

	camera->updateLocation();
	for (size_t i = 0; i < RockmanBullet::bullets->Count; i++)
	{
		RockmanBullet::bullets->at(i)->updateLocation();
		if (!Collision::AABBCheck(Camera::getInstance(), RockmanBullet::bullets->at(i)))
		{
			RockmanBullet::bullets->at(i)->deleteBullet();
			i--;
		}
	}

	for (size_t i = 0; i < BeakBullet::bullets->Count; i++)
	{
		BeakBullet::bullets->at(i)->updateLocation();
	}
}

void Stage::render()
{
	TileMap::render();
	if (onStageViewChangeNext || onStageViewChangePrev)
		return;
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

	for (size_t i = 0; i < RockmanBullet::bullets->Count; i++)
	{
		RockmanBullet::bullets->at(i)->render();
	}
}

Stage::Stage()
{
	onStageViewChangeNext = false;
	onStageViewChangePrev = false;
}

Stage::~Stage()
{
}