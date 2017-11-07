#include "TileMap.h"

extern void ignoreLineIfstream(ifstream& fs, int lineCount);

void TileMap::init(char * tileSheetPath, char * matrixPath)
{
	ifstream fs(matrixPath);
	fs >> rowCount >> colCount >> colTileSheetCount;
	width = colCount * 16;
	height = rowCount * 16;
	/*ignoreLineIfstream(fs, 2);*/

	tileSheet = new Texture();
	tileSheet->Init(tileSheetPath, 0);
	matrix = new int*[rowCount];
	for (int rowIndex = 0; rowIndex < rowCount; rowIndex++)
	{
		matrix[rowIndex] = new int[colCount];
		for (int colIndex = 0; colIndex < colCount; colIndex++)
		{
			fs >> matrix[rowIndex][colIndex];
		}
	}

}

void TileMap::renderTile(int rowIndex, int colIndex)
{
	int tileIndex = matrix[rowIndex][colIndex];
	int xTile = colIndex * 16;
	int yTile = (rowCount - rowIndex) * 16;
	float xRender, yRender;
	Camera::getInstance()->Transform(xTile, yTile, xRender, yRender);
	int xTileSheet = (tileIndex % colTileSheetCount) * 16;
	int yTileSheet = (tileIndex / colTileSheetCount) * 16;
	RECT rect;
	SetRect(&rect, xTileSheet, yTileSheet, xTileSheet + 16, yTileSheet + 16);
	tileSheet->RenderTexture(xRender, yRender, &rect);
}

void TileMap::renderTiles(int rowBegin, int rowEnd, int colBegin, int colEnd)
{
	for (int rowIndex = rowBegin; rowIndex <= rowEnd; rowIndex++)
	{
		for (int colIndex = colBegin; colIndex <= colEnd; colIndex++)
		{
			renderTile(rowIndex, colIndex);
		}
	}
}

void TileMap::render()
{
	Camera::getInstance()->x = (int)Camera::getInstance()->x;
	Camera::getInstance()->y = (int)Camera::getInstance()->y;
	int rowBegin, rowEnd, colBegin, colEnd;
	colBegin = Camera::getInstance()->left() / 16;
	colEnd = Camera::getInstance()->right() / 16;
	rowBegin = (rowCount * 16 - Camera::getInstance()->top()) / 16;//***
	rowEnd = (rowCount * 16 - Camera::getInstance()->bottom()) / 16;//***
	renderTiles(rowBegin, rowEnd, colBegin, colEnd);
}

TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}
