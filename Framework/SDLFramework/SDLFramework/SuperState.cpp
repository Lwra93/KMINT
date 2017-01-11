#include "SuperState.h"
#include "Game.h"
#include "AStar.h"
#include "BaseState.h"

SuperState::SuperState()
{
}

void SuperState::handle(Beekeeper *beekeeper, Map * graph, GameObject * bee)
{
	AStar(beekeeper, graph, bee);
}

void SuperState::changeState(Beekeeper* beekeeper, Base* base, PowerUp* powerup)
{
	beekeeper->addBee();

	if (beekeeper->getBees() < beekeeper->getMaxBees())
		return;

	BaseState* baseState = new BaseState();
	beekeeper->setState(baseState);
}

string SuperState::getStateName()
{
	return "SuperState";
}
