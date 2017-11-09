#include "Collision.h"
#include<iostream>
#include<string>

using namespace std;

double collisionTime = 0;
float nx, ny;

FBox * Collision::GetSweptBroadPhaseBox(FBox * box)
{
	FBox* bigBox = new FBox();
	bigBox->x = box->getDx() > 0 ? box->x : (box->x + box->getDx());
	bigBox->y = box->getDy() > 0 ? (box->y + box->getDy()) : box->y;
	bigBox->width = box->getDx() > 0 ? (box->width + box->getDx()) : (box->width - box->getDx());
	bigBox->height = box->getDy() > 0 ? (box->height + box->getDy()) : (box->height - box->getDy());
	return bigBox;
}

bool Collision::AABBCheck(FRectangle * M, FRectangle * S)
{
	return ((M->x < S->x + S->width && M->x + M->width > S->x) &&
		(M->y - M->height < S->y && M->y > S->y - S->height));
}

float Collision::SweptAABB(FBox* M, FBox* S, float & normalx, float & normaly)
{
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	// Tính khoảng cách cần để xảy ra va chạm (InvEntry) và khoảng cách để ra khỏi va chạm (InvExit):
	if (M->getDx() > 0.0f)
	{
		xInvEntry = S->x - (M->x + M->width);
		xInvExit = (S->x + S->width) - M->x;
	}
	else
	{
		xInvEntry = (S->x + S->width) - M->x;
		xInvExit = S->x - (M->x + M->width);
	}

	if (M->getDy() > 0.0f)
	{
		yInvEntry = S->y - S->height - M->y;
		yInvExit = S->y - (M->y - M->height);
	}
	else
	{
		yInvEntry = S->y - (M->y - M->height);
		yInvExit = (S->y - S->height) - M->y;
	}

	// Tính thời gian để bắt đầu và chạm và thời gian để kết thúc va chạm theo mỗi phương:
	float xEntry, yEntry;
	float xExit, yExit;

	if (M->getDx() == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / (float)M->getDx();
		xExit = xInvExit / (float)M->getDx();
	}

	if (M->getDy() == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / (float)M->getDy();
		yExit = yInvExit / (float)M->getDy();
	}

	// Thời gian để Box bắt đầu va chạm và thời gian để kết thúc va chạm:
	float entryTime = MAX(xEntry, yEntry);
	float exitTime = MIN(xExit, yExit);

	// Trường hợp không xảy ra va chạm:
	//Logger::getInstance()->write_text_to_log_file(std::to_string(GetVy()));
	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}

	else // Trường hợp xảy ra va chạm:
	{
		// Xác định hướng của pháp tuyến khi va chạm:
		if (xEntry > yEntry)
		{
			if (M->getDx() < 0.0f) // Chạm vào bề mặt bên phải của block:
			{
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else					// Chạm vào bề mặt bên trái của block:
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}
		}
		else
		{
			if (M->getDy() < 0.0f) // Chạm vào bề mặt phía trên của block:
			{
				normalx = 0.0f;
				normaly = 1.0f;
			}
			else					// Chạm vào bề mặt phía dưới của block:
			{
				normalx = 0.0f;
				normaly = -1.0f;
			}
		}

		// Trả về khoảng thời gian cần thiết để bắt đầu xảy ra va chạm:
		return entryTime;
	}
}

void Collision::CheckCollision(FBox * M, FBox * S)
{
	if (M->alive == false || S->alive == false)
		return;
	FBox* broadPhaseBox = GetSweptBroadPhaseBox(M);
	if (AABBCheck(broadPhaseBox, S))
	{
		delete broadPhaseBox; //*********************
		if (AABBCheck(M, S))
		{
			M->onIntersect(S);
			S->onIntersect(M);
			return;
		}
		float normalX = 0, normalY = 0;
		collisionTime = SweptAABB(M, S, nx, ny);
		if (collisionTime < 1)
		{
			if (M->x < S->x + S->width && M->x + M->width > S->x)
			{
				if (M->getDy() > 0)
					normalY = -1;
				else
					normalY = 1;
			}
			else if (M->y - M->height < S->y && M->y > S->y - S->height)
			{
				if (M->getDx() > 0)
					normalX = -1;
				else
					normalX = 1;
			}

			//chac chan co va cham
			M->isCollision = true;
			//xu ly va cham
			M->onCollision(S, normalX, normalY);
			S->onCollision(M, normalX, normalY);
		}

		return;
	}
	delete broadPhaseBox;
}

Collision::Collision()
{
}

Collision::~Collision()
{
}