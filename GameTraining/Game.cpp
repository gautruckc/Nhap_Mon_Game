#include "Game.h"


Game::Game(void)
{
}
Game* Game::instance = 0;

Game* Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}

//void Game::readFile(const char * objectsPath)
//{
//	int t;
//	ifstream fs(objectsPath);
//	fs >> nObject;
//	objects = new BaseObject[nObject];
//	for (auto i = 0; i < nObject; i++)
//	{
//		fs >> t;
//		fs >> objects[i].x
//			>> objects[i].y
//			>> objects[i].width
//			>> objects[i].height;
//		objects[i].y = tilestage.rowCount * 16 - objects[i].y;
//	}
//}

void Game::init()
{
	camera = Camera::getInstance();
	Aladin::getInstance()->x = 95;
	Aladin::getInstance()->y = 200;
	Aladin::getInstance()->width = 22;
	Aladin::getInstance()->height = 75;
	camera->x = 10;
	camera->y = 300;
	/*brick.x = 200;
	brick.y = 200;
	brick.width = 16;
	brick.height = 22;
	brick.action = 0;*/
	tilestage.init("Data\\Map\\Map1\\tileSheet.png", 
		"Data\\Map\\Map1\\matrix.txt",
		"Data\\Map\\Map1\\objects.txt",
		"Data\\Map\\Map1\\quadtree.txt"
		);
}

void Game::update()
{
	/*Aladin::getInstance()->update();
	Aladin::getInstance()->updateLocation();*/
	tilestage.update();

}
void Game::render()
{
	tilestage.render();
	Aladin::getInstance()->render();
}


Game::~Game(void)
{
}
