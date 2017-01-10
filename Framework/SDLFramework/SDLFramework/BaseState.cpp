#include "BaseState.h"
#include "AStar.h"

BaseState::BaseState()
{
}

void BaseState::handle(GameObject* beekeeper, Map* graph, GameObject* base)
{
	AStar(beekeeper, graph, base);
}

void BaseState::changeState(Beekeeper* beekeeper)
{
}

string BaseState::getStateName()
{
	return "BaseState";
}
