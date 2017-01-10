#pragma once
#include "IState.h"

class PowerUpState : public IState
{
public:
	PowerUpState();
	void handle(GameObject *object1, Map *graph, GameObject *object2) override;
	void changeState(Beekeeper *beekeeper) override;
	string getStateName() override;
};

