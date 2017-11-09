#include "SpriteManager.h"



SpriteManager * SpriteManager::instance = 0;
SpriteManager * SpriteManager::getInstance()
{
	if (instance == 0)
		instance = new SpriteManager();
	return instance;
}

SpriteManager::SpriteManager()
{
	//add
	sprites = new Sprite*[SPR_COUNT];

	sprites[SPR_ALADIN] = new Sprite();
	sprites[SPR_ALADIN]->ReadFromFile("Data\\Sprite\\Aladin\\info.simple.txt", "Data\\Sprite\\Aladin\\Aladin.png");
	sprites[SPR_ALADIN]->img->direction = Right;

	

	sprites[SPR_PEA] = new Sprite();
	sprites[SPR_PEA]->ReadFromFile("Data\\Sprite\\Enemies\\Pea\\pea.txt", "Data\\Sprite\\Enemies\\Enemies.png");

	sprites[SPR_THINGMAN] = new Sprite();
	/*sprites[SPR_THINGMAN]->img = sprites[SPR_THINGMAN]->img;*/
	sprites[SPR_THINGMAN]->ReadFromFile("Data\\Sprite\\Enemies\\ThingMan\\info.simple.txt", "Data\\Sprite\\Enemies\\ThingMan\\ganesis.png");
	sprites[SPR_THINGMAN]->img->direction = Right;

	sprites[SPR_FATMAN] = new Sprite();
	/*sprites[SPR_FATMAN]->img = sprites[SPR_FATMAN]->img;*/
	sprites[SPR_FATMAN]->ReadFromFile("Data\\Sprite\\Enemies\\FatMan\\info.simple.txt", "Data\\Sprite\\Enemies\\FatMan\\ganesis.png");
	sprites[SPR_FATMAN]->img->direction = Right;

	/*sprites[SPR_BLADER] = new Sprite();
	sprites[SPR_BLADER]->img = sprites[SPR_PEA]->img;
	sprites[SPR_BLADER]->readInfo("Data\\Sprite\\Enemies\\Blader\\blader.txt");
*/
	sprites[SPR_PICKET] = new Sprite();
	sprites[SPR_PICKET]->img = sprites[SPR_PEA]->img;
	sprites[SPR_PICKET]->readInfo("Data\\Sprite\\Enemies\\Picket\\picket.txt");

	sprites[SPR_BEAK] = new Sprite();
	sprites[SPR_BEAK]->img = sprites[SPR_PEA]->img;
	sprites[SPR_BEAK]->readInfo("Data\\Sprite\\Enemies\\Beak\\beak.txt");

	sprites[SPR_BEAK_BULLET] = new Sprite();
	sprites[SPR_BEAK_BULLET]->img = sprites[SPR_PEA]->img;
	sprites[SPR_BEAK_BULLET]->readInfo("Data\\Sprite\\Enemies\\Beak\\beakbullet.txt");

	sprites[SPR_BULLET] = new Sprite();
	sprites[SPR_BULLET]->ReadFromFile("Data\\Sprite\\Rockman\\bullet.txt", "Data\\Sprite\\Rockman\\bullet.png");

}




SpriteManager::~SpriteManager()
{
}
