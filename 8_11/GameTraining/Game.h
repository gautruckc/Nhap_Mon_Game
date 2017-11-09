#pragma once
#include"Config.h"
#include"Aladin.h"
#include "Collision.h"
#include"MapGame.h"
class Game
{
	static Game* instance;
public:
	static Game* getInstance();
	int x,y;
	int getDx(),getDy();
	Aladin man;

	int nObject;
	BaseObject* objects;
	Camera* camera;
	Texture* img;
	MapGame tilestage;

	//void readFile(const char* objectsPath);
	

	void init();
	void update();
	void render();

	Game(void);
	~Game(void);
};

