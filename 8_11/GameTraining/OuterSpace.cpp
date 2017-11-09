#include "OuterSpace.h"


//
//OuterSpace* OuterSpace::instance = 0;
//OuterSpace* OuterSpace::getInstance() {
//	if (instance == 0) {
//		instance = new OuterSpace();
//	}
//	return instance;
//}
//
//void OuterSpace::add(BaseObject * space)
//{
//	outerSpaces._Add(space);
//}
//
//void OuterSpace::remove(BaseObject * space)
//{
//	outerSpaces._Remove(space);
//}
//
//void OuterSpace::clear()
//{
//	outerSpaces.Clear();
//}

OuterSpace::OuterSpace()
{
	collisionType = CT_OUTERSPACE;
}


OuterSpace::~OuterSpace()
{
}
