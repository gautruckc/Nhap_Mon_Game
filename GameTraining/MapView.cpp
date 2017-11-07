#include "MapView.h"

MapView* MapView::curMapView = 0;

MapView::MapView(ifstream &fs)
{
	fs >> index >> x >> y >> width >> height;
}

MapView::~MapView()
{
}