#pragma once
#include "Animation.h"
#include "Texture.h"
#include <fstream>
#include <string>
using namespace std;


static void ignoreLineIfstream(ifstream& fs, int lineCount)
{
	string s;
	for (int i = 0; i < lineCount; i++)
	{
		std::getline(fs, s);
	}
}

class Sprite
{
public:
	Animation* anims;
	int animCount;
	Texture* img;
	Sprite();
	~Sprite();
	void render(int x, int y, int action, int frameIndex);
	void update(int action, int &frameIndex);
	void ReadFromFile(char * infopath, char * imagepath);
	void readInfo(const char* infoPath);
};

