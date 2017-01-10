#pragma once
#include "ChaseState.h"
#include <queue>
#include "Map.h"
#include <list>
#include <map>
#include "AStar.h"
#include "Util.h"
#include "PowerUpState.h"
#include "BaseState.h"
#include "PanicState.h"

ChaseState::ChaseState()
{
}

void ChaseState::handle(GameObject *beekeeper, Map *graph, GameObject *bee)
{
	AStar(beekeeper, graph, bee);
}

void ChaseState::changeState(Beekeeper *beekeeper)
{
	if(beekeeper->getBees() <= beekeeper->getMaxBees())
		return;

	auto randomNr = Util::randomDouble(1, 100);

	if(randomNr >= 0 && randomNr < beekeeper->getPowerupChance())
	{
		PowerUpState* powerUpState = new PowerUpState();
		beekeeper->setState(powerUpState);
	}
	else if(randomNr >= beekeeper->getPowerupChance() && randomNr < beekeeper->getPowerupChance()+beekeeper->getBaseChance())
	{
		BaseState* baseState = new BaseState();
		beekeeper->setState(baseState);
	}
	else if(randomNr >= beekeeper->getBaseChance() && randomNr <= beekeeper->getPowerupChance() + beekeeper->getBaseChance()+beekeeper->getPanicChance())
	{
		PanicState* panicState = new PanicState();
		beekeeper->setState(panicState);
	}
}

string ChaseState::getStateName()
{
	return "ChaseState";
}
