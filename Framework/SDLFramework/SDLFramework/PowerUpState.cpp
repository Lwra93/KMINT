#include "PowerUpState.h"
#include "AStar.h"
#include "SuperState.h"
#include "Beekeeper.h"
#include "Game.h"
using namespace kmint;

PowerUpState::PowerUpState()
{
}

void PowerUpState::handle(GameObject* beekeeper, Map* graph, GameObject* powerup)
{
	AStar(beekeeper, graph, powerup);
}

void PowerUpState::changeState()
{
	base->emptyNet(beekeeper->removeBees());
	SuperState* super = new SuperState();
	beekeeper->setState(super);
	beekeeper->setMaxBees(beekeeper->getMaxBees() * 3);
	//snelheid lopen x3
}

string PowerUpState::getStateName()
{
	return "PowerUpState";
}

