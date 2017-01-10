#include "BaseState.h"
#include "AStar.h"
#include "Beekeeper.h"
#include "ChaseState.h"
#include "Game.h"
using namespace kmint;

BaseState::BaseState()
{
}

void BaseState::handle(GameObject* beekeeper, Map* graph, GameObject* base)
{
	AStar(beekeeper, graph, base);
}

void BaseState::changeState()
{
	base->emptyNet(beekeeper->removeBees());
	ChaseState* chase = new ChaseState();
	beekeeper->setState(chase);
}

string BaseState::getStateName()
{
	return "BaseState";
}
