#pragma once
#include "IState.h"

class PowerUpState : public IState
{
public:
	PowerUpState();
	void handle(Beekeeper *beekeeper, Map *graph, GameObject *object2) override;
	void changeState(Beekeeper* beekeeper, Base* base, PowerUp* powerup) override;
	string getStateName() override;
};

