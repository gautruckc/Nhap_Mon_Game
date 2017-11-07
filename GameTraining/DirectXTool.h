#pragma once

#include<d3d9.h>
#include<d3dx9.h>
#include<Windows.h>
#include"Config.h"
#include"Form.h"

class DirectXTool
{
public:
	DirectXTool(void);
	~DirectXTool(void);

	static DirectXTool* getInstance();

private:
	LPDIRECT3DDEVICE9 d3ddv;// Cong cu load hinh ve hinh ve surface
	LPDIRECT3DSURFACE9 frameBuffer;// Hinh luon nam tren man hinh
	LPDIRECT3DSURFACE9 backBuffer;// Bo nho tam
	LPD3DXSPRITE sprite;
	HWND hWnd;
	static DirectXTool* instance;

	bool isInitDirectX();
	bool isInitSprite();
	bool isSetFrameBuffer();
	bool isSetBackBuffer();
	void init();
	void error();

public:
	void Release();
	LPDIRECT3DDEVICE9 GetDevice();
	LPDIRECT3DSURFACE9 GetBackBuffer();
	LPD3DXSPRITE GetSprite();
	void PrintText(char* str, int size, int x, int y, DWORD color);
	void BeginGraphics();
	void EndGraphics();
	void PresentBackBuffer();
};
