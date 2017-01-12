#pragma once
#include "State.h"

class PowerUpState : public State
{
public:
	PowerUpState();
	void handle() override;
	void changeState() override;
	string getStateName() override;
	void update() override;
};

