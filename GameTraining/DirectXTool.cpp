#include "DirectXTool.h"


DirectXTool::DirectXTool(void)
{
	this->hWnd = Form::getInstance()->getHandleWindow();
	init();
}


DirectXTool::~DirectXTool(void)
{
	Release();
}

DirectXTool* DirectXTool::instance=0;

DirectXTool* DirectXTool::getInstance()
{
	if(instance==0)
		instance = new DirectXTool();
	return instance;
}


bool DirectXTool::isInitDirectX()
{
	LPDIRECT3D9 d3d;
	if (NULL == (d3d = Direct3DCreate9(D3D_SDK_VERSION)))
		return false;
	
	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferWidth = BACKBUFFER_WIDTH;
	d3dpp.BackBufferHeight = BACKBUFFER_HEIGHT;

	if (FAILED(d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddv)))
	{
		return false;
	}
	if (!d3ddv)
		return false;
	d3d->Release();
	return true;
}

bool DirectXTool::isInitSprite()
{
	HRESULT hr = D3DXCreateSprite(d3ddv, &sprite);
	return !FAILED(hr);
}

bool DirectXTool::isSetFrameBuffer()
{
	HRESULT hr = d3ddv->CreateOffscreenPlainSurface(272,
		192,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&frameBuffer,
		0);
	return !FAILED(hr);
}

bool DirectXTool::isSetBackBuffer()
{
	HRESULT hr = d3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO,
		&backBuffer);
	return !FAILED(hr);
}

void DirectXTool::init()
{
	if (!isInitDirectX() || !isInitSprite() || !isSetBackBuffer() || !isSetFrameBuffer())
		error();
}

void DirectXTool::error()
{
	MessageBox(hWnd, "Không the khoi tao graphics", "Loi", MB_ICONERROR);
}




void DirectXTool::Release()
{
	if (d3ddv)
	{
		d3ddv->Release();
		d3ddv = 0;
	}
	if (frameBuffer)
	{
		frameBuffer->Release();
		frameBuffer = 0;
	}
	if (backBuffer)
	{
		backBuffer->Release();
		backBuffer = 0;

	}
	if (sprite)
	{
		sprite->Release();
		sprite = 0;
	}
}



LPDIRECT3DDEVICE9 DirectXTool::GetDevice()
{
	return d3ddv;
}

LPDIRECT3DSURFACE9 DirectXTool::GetBackBuffer()
{
	return backBuffer;
}

LPD3DXSPRITE DirectXTool::GetSprite()
{
	return sprite;
}

void DirectXTool::PrintText(char* str, int size, int x, int y, DWORD color)
{
	ID3DXFont* dxfont;
	RECT textbox;
	SetRect(&textbox, x, y, 272, 272);
	D3DXCreateFont(d3ddv,    // the D3D Device
		size,    // font height
		0,    // default font width
		FW_NORMAL,    // font weight
		1,    // not using MipLevels
		false,    // italic font
		DEFAULT_CHARSET,    // default character set
		OUT_DEFAULT_PRECIS,    // default OutputPrecision,
		DEFAULT_QUALITY,    // default Quality
		DEFAULT_PITCH | FF_DONTCARE,    // default pitch and family
		"Arial",    // use Facename Arial
		&dxfont);    // the font object
	dxfont->DrawTextA(NULL,
		str,
		strlen(str),
		&textbox,
		DT_LEFT | DT_TOP,
		color);

	dxfont->Release();
}

void DirectXTool::BeginGraphics()
{
	HRESULT hr = d3ddv->BeginScene();
	HRESULT hr1 = sprite->Begin(D3DXSPRITE_ALPHABLEND);
	d3ddv->Clear(0, 0, D3DCLEAR_TARGET, D3DCOLOR_XRGB(10, 10, 10), 1.0f, 0);
	if (FAILED(hr) || FAILED(hr1))
	{
		MessageBox(0, "Khong the bat dau ve", "Loi", MB_ICONERROR);
		PostQuitMessage(0);
	}
}

void DirectXTool::EndGraphics()
{
	HRESULT hr1 = sprite->End();
	HRESULT hr = d3ddv->EndScene();
	if (FAILED(hr) || FAILED(hr1))
	{
		MessageBox(0, "Khong the ket thuc ve", "Loi", MB_ICONERROR);
		PostQuitMessage(0);
	}

}

void DirectXTool::PresentBackBuffer()
{
	d3ddv->Present(0, 0, 0, 0);
}
