#include "BaseState.h"
#include "AStar.h"
#include "Beekeeper.h"
#include "ChaseState.h"
#include "Game.h"

BaseState::BaseState()
{
}

void BaseState::handle(Beekeeper *beekeeper, Map* graph, GameObject* base)
{
	AStar(beekeeper, graph, base);
}

void BaseState::changeState(Beekeeper* beekeeper, Base* base, PowerUp* powerup)
{
	base->emptyNet(beekeeper->removeBees());
	beekeeper->resetNet();
	ChaseState* chase = new ChaseState();
	beekeeper->setState(chase);
	beekeeper->setMaxBees(10);
	beekeeper->changeTexture("beekeeper.png");
}

string BaseState::getStateName()
{
	return "BaseState";
}
