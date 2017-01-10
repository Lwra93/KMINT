#pragma once
#include "IState.h"

class ChaseState : public IState
{
public:
	ChaseState();
	void handle(GameObject *object1, Map *graph, GameObject *object2) override;
	void changeState() override;
	string getStateName() override;
};
