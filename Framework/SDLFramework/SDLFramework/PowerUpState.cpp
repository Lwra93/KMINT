#include "PowerUpState.h"
#include "AStar.h"
#include "SuperState.h"
#include "Beekeeper.h"
#include "Game.h"

PowerUpState::PowerUpState()
{
}

void PowerUpState::handle(Beekeeper *beekeeper, Map* graph, GameObject* powerup)
{
	AStar(beekeeper, graph, powerup);
}

void PowerUpState::changeState(Beekeeper* beekeeper, Base* base, PowerUp* powerup)
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

