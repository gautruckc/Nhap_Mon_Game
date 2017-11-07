#include "QuadTree.h"

extern void ignoreLineIfstream(ifstream& fs, int lineCount);

QuadTree::QuadTree(char * quadTreePath, BaseObject ** allObjects, int stageHeight)
{
	ifstream fs(quadTreePath);
	ignoreLineIfstream(fs, 1);
	rootNode = new QuadNode(fs, allObjects, stageHeight);
}

QuadTree::~QuadTree()
{
}

void QuadTree::update() //***
{
	//xoa doi tuong trong camera
	removeObjects();
	//do doi tuong vao camera
	fillObject();
	List<BaseObject*>* allObjects =  &Camera::getInstance()->objects.allObjects;
	for (int i = 0; i < allObjects->Count; i++)
	{
		auto obj = allObjects->at(i);
		if (!Collision::AABBCheck(Camera::getInstance(), obj) && !Collision::AABBCheck(Camera::getInstance(), &(obj->oldRect)))
		{
			obj->restoreLocation();
		}

	}
}

void QuadTree::removeObjects()
{
	Camera::getInstance()->objects.clear();
}

void QuadTree::fillObject()
{
	rootNode->fillObjectToCamera();
}
