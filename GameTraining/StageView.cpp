#include "StageView.h"

StageView* StageView::curStageView = 0;

StageView::StageView(ifstream &fs)
{
	fs >> index >> x >> y >> width >> height;
}

StageView::~StageView()
{
}