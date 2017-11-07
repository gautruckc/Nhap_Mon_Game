#pragma once
class ActionLoop
{
	int action, loop;
public:
	void setLoop(int loop);
	bool decreaseLoop();
	bool isForeverLoop();
	ActionLoop();
	~ActionLoop();
};

