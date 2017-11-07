#pragma once
#include<Windows.h>
#include"Config.h"
class Form
{
	HWND hWnd;
	static Form* instance;
public:
	static Form* getInstance();
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	void initHandleWindows(HINSTANCE hInstance, int nCmdShow);
	HWND getHandleWindow();
	Form(void);
	~Form(void);
};

