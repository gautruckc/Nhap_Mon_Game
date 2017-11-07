#pragma once
#include "FRectangle.h"
#include<fstream>
#include"Collision.h"
#include"BaseObject.h"
#include"Camera.h"
using namespace std;
class QuadNode :
	public FRectangle
{
public:


	QuadNode* TL,* BL,* TR,* BR;
	int id;
	int nObject;
	BaseObject** objectsInNode;
	
	QuadNode(ifstream &fs, BaseObject** allObjects,int stageHeight);
	
	void fillObjectToCamera();

	~QuadNode();
};

