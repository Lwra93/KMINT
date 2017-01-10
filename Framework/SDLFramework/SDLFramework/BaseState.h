#pragma once
#include "IState.h"

class BaseState : public IState
{
public:
	BaseState();
	void handle(GameObject *object1, Map *graph, GameObject *object2) override;
	void changeState() override;
	string getStateName() override;
};

