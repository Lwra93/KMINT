#pragma once
#include "State.h"

class ChaseState : public State
{
public:
	ChaseState();
	void handle() override;
	void changeState() override;
	string getStateName() override;
	void update() override;
};
