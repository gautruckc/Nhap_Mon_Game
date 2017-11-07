#pragma once
#include "List.h"
#include "FRectangle.h"
#include <fstream>
using namespace std;

class MapView : public FRectangle
{
public:
	int index;
	static MapView* curMapView;
	MapView(ifstream &fs);

	~MapView();
};
