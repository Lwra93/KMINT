#pragma once
#include "IState.h"

class SuperState : public IState
{
public:
	SuperState();
	void handle(GameObject *object1, Map *graph, GameObject *object2) override;
	void changeState() override;
	string getStateName() override;
};

