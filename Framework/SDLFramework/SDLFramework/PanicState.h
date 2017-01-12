#pragma once
#include "State.h"

class PanicState : public State
{
public:
	PanicState();
	void handle() override;
	void changeState() override;
	string getStateName() override;
	void update() override;
};

