#pragma once
#include "Animation.h"
#include "Texture.h"
#include <fstream>
#include <string>
using namespace std;


void ignoreLineIfstream(ifstream& fs, int lineCount);

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

