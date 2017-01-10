#include "PowerUpState.h"
#include "AStar.h"

PowerUpState::PowerUpState()
{
}

void PowerUpState::handle(GameObject* beekeeper, Map* graph, GameObject* powerup)
{
	AStar(beekeeper, graph, powerup);
}

void PowerUpState::changeState(Beekeeper * beekeeper)
{
}

string PowerUpState::getStateName()
{
	return "PowerUpState";
}

