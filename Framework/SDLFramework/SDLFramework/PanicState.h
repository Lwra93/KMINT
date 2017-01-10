#pragma once
#include "IState.h"

class PanicState : public IState
{
public:
	PanicState();
	void handle(GameObject *object1, Map *graph, GameObject *object2) override;
	void changeState() override;
	string getStateName() override;
};

