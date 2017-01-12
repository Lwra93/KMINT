#pragma once
#include "State.h"

class MoveState :
	public State
{
public:
	MoveState();

	void handle() override;
	void changeState() override;
	string getStateName() override;
	void update() override;
};

