#pragma once
#include "State.h"

class SuperState : public State
{
public:
	SuperState();
	void handle() override;
	void changeState() override;
	string getStateName() override;
	void update() override;
};

