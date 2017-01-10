#include "SuperState.h"
#include "Game.h"
#include "AStar.h"
#include "BaseState.h"
using namespace kmint;

SuperState::SuperState()
{
}

void SuperState::handle(GameObject * keeper, Map * graph, GameObject * bee)
{
	AStar(keeper, graph, bee);
}

void SuperState::changeState()
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
