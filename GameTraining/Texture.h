#pragma once


#include"DirectXTool.h"
#include"Point.h"

enum Direction
{
	Left = -1,
	Right = 1
};



class Texture
{

private:
	LPDIRECT3DTEXTURE9 m_image;
public:
	
	int Width, Height;
	Point anchorPoint;
	Direction direction;

	Texture(const char* filepath,D3DCOLOR transColor);
	////tao texture
	// filepath: duong dan file hinh anh
	// transColor: mau can trong suot
	Texture(){}
	void Init(const char* filepath,D3DCOLOR transColor);

	////ham ve
	// x,y
	// r vung muon ve
	
	void RenderTexture(int x,int y,RECT *r);
	~Texture();
};
