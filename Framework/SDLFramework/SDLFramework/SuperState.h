#pragma once
#include "IState.h"

class SuperState : public IState
{
public:
	SuperState();
	void handle(Beekeeper *beekeeper, Map *graph, GameObject *object2) override;
	void changeState(Beekeeper* beekeeper, Base* base, PowerUp* powerup) override;
	string getStateName() override;
};

