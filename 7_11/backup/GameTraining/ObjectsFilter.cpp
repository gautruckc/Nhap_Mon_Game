#include "ObjectsFilter.h"
#include"BaseObject.h"



void ObjectsFilter::addObject(BaseObject * object)
{
	allObjects._Add(object);
	switch (object->collisionType)
	{
	case CT_GROUND:
		grounds._Add(object);
		break;
	case CT_STAIR:
		stairs._Add(object);
		break;
	case CT_ENEMY:
		enemies._Add(object);
		break;
	case CT_ITEM:
		items._Add(object);
		break;
	case CT_OUTERSPACE:
		outerSpaces._Add(object);
		break;
	default:
		break;
	}
}

void ObjectsFilter::removeObject(BaseObject * object)
{
	allObjects._Remove(object);
	switch (object->collisionType)
	{
	case CT_GROUND:
		grounds._Remove(object);
		break;
	case CT_STAIR:
		stairs._Remove(object);
		break;
	case CT_ENEMY:
		enemies._Remove(object);
		break;
	case CT_ITEM:
		items._Remove(object);
		break;
	case CT_OUTERSPACE:
		outerSpaces._Remove(object);
		break;
	default:
		break;
	}
}

void ObjectsFilter::clear()
{
	allObjects.Clear();
	grounds.Clear();
	enemies.Clear();
	outerSpaces.Clear();
	items.Clear();
}

ObjectsFilter::ObjectsFilter()
{
}


ObjectsFilter::~ObjectsFilter()
{
}
