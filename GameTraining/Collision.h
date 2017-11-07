#pragma once
#include "FBox.h"
#define MAX(a,b) a>b? a:b
#define MIN(a,b) a>b? b:a
#include<iostream>
using namespace std;

class Collision
{
public:
	static FBox* GetSweptBroadPhaseBox(FBox* box);
	static bool AABBCheck(FRectangle* M, FRectangle* S);
	static float SweptAABB(FBox* M, FBox* S, float &normalX, float &normalY);
	static void CheckCollision(FBox* M, FBox* S);

	/* CONSTRUCTOR & DESTRUCTOR */
	Collision();
	~Collision();
};
