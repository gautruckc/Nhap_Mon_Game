#pragma once
#include "List.h"
#include "FRectangle.h"
#include <fstream>
using namespace std;

class StageView : public FRectangle
{
public:
	int index;
	static StageView* curStageView;
	StageView(ifstream &fs);

	~StageView();
};
