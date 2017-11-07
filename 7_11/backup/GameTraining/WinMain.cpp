#include<Windows.h>
#include"Form.h"
#include"DirectXTool.h"
#include"Texture.h"
#include"Game.h"
#include"KEY.h"

//#ifdef RELEASE
//void* operator new  (std::size_t count)
//{
//	void *s = malloc(count);
//	memset(s, 0x1,count);
//	return s;
//}
//#endif
//
//#define STR(s) std::to_string(s)

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Form::getInstance()->initHandleWindows(hInstance, nCmdShow);
	DWORD timeSleep = 1000.0/FPS;

	CKeyboard::Create(hInstance,Form::getInstance()->getHandleWindow());

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));


	Game::getInstance()->init();

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		CKeyboard::getInstance()->PollKeyboard();
		CKeyboard::getInstance()->UpdateKeyboard();
		KEY::getInstance()->update();

		Game::getInstance()->update();
		DirectXTool::getInstance()->BeginGraphics();//bat dau ve len backbuffer
		Game::getInstance()->render();
		DirectXTool::getInstance()->EndGraphics();// ket thuc ve len backbuffer
		DirectXTool::getInstance()->PresentBackBuffer();// ve backbuffer len man hinh
		Sleep(timeSleep);
	}


	return nCmdShow;
}
