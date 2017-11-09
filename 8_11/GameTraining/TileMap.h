#pragma once
#include "Texture.h"
#include "Camera.h"
#include <fstream>
using namespace std;

class TileMap
{
public:
	int width, height;
	int rowCount, colCount, colTileSheetCount;
	Texture* tileSheet;
	int** matrix;
	void init(char* tileSheetPath, char* matrixPath);
	void renderTile(int rowIndex, int colIndex);
	void renderTiles(int rowBegin, int rowEnd, int colBegin, int colEnd);
	virtual void render();

	TileMap();
	~TileMap();
};

