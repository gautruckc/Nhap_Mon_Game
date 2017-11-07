#include "Sprite.h"
#include "GameTime.h"

Sprite::Sprite()
{
}


Sprite::~Sprite()
{
}

void Sprite::render(int x, int y, int action, int frameIndex)
{
	img->RenderTexture(x, y, &anims[action].frames[frameIndex]);
}

void Sprite::update(int action, int &frameIndex)
{
	anims[action].next(frameIndex);
}

void Sprite::ReadFromFile(char * infopath, char * imagepath)
{
	int r, g, b;

	ifstream fs(infopath);
	ignoreLineIfstream(fs, 1);
	fs >> r >> g >> b;

	ignoreLineIfstream(fs, 2);
	fs >> animCount;

	int frameCount;
	float x, y, w, h;
	anims = new Animation[animCount];
	ignoreLineIfstream(fs, 3);
	for (int i = 0; i < animCount; i++)
	{
		ignoreLineIfstream(fs, 4);
		fs >> frameCount;
		anims[i].frameCount = frameCount;
		anims[i].frames = new RECT[frameCount];
		ignoreLineIfstream(fs, 4);
		for (int j = 0; j < frameCount; j++)
		{
			fs >> x >> y >> w >> h;
			anims[i].frames[j].left = x;
			anims[i].frames[j].top = y;
			anims[i].frames[j].right = x + w;
			anims[i].frames[j].bottom = y + h;
		}

		ignoreLineIfstream(fs, 3);
	}

	img = new Texture();
	img->Init(imagepath, D3DCOLOR_XRGB(r, g, b));
}

void Sprite::readInfo(const char * infoPath)
{

	int r, g, b;

	ifstream fs(infoPath);
	ignoreLineIfstream(fs, 1);
	fs >> r >> g >> b;

	ignoreLineIfstream(fs, 2);
	fs >> animCount;

	int frameCount;
	float x, y, w, h;
	anims = new Animation[animCount];
	ignoreLineIfstream(fs, 3);
	for (int i = 0; i < animCount; i++)
	{
		ignoreLineIfstream(fs, 4);
		fs >> frameCount;
		anims[i].frameCount = frameCount;
		anims[i].frames = new RECT[frameCount];
		ignoreLineIfstream(fs, 4);
		for (int j = 0; j < frameCount; j++)
		{
			fs >> x >> y >> w >> h;
			anims[i].frames[j].left = x;
			anims[i].frames[j].top = y;
			anims[i].frames[j].right = x + w;
			anims[i].frames[j].bottom = y + h;
		}

		ignoreLineIfstream(fs, 3);
	}
}
