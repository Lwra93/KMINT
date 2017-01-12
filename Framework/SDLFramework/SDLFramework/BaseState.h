#pragma once
#include "State.h"

class BaseState : public State
{
public:
	BaseState();
	void handle() override;
	void changeState() override;
	string getStateName() override;
	void update() override;
};

