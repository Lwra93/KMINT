#pragma once
#include "ChaseState.h"
#include <queue>
#include "Map.h"
#include <list>
#include <map>
#include "AStar.h"
#include "Game.h"
#include "Util.h"
#include "PowerUpState.h"
#include "BaseState.h"
#include "PanicState.h"
#include "MoveState.h"

ChaseState::ChaseState()
{
}

void ChaseState::handle()
{
	AStar(beekeeper, beekeeper->getGame()->getGraph(), beekeeper->getGame()->getBee());
	State* state = nullptr;
	state = new MoveState();
	beekeeper->setState(state);
	if (state != nullptr)
		state->setBeekeeper(beekeeper);
}

void ChaseState::changeState()
{
	

	beekeeper->addBee();

	if(beekeeper->getBees() < beekeeper->getMaxBees())
		return;

	auto randomNr = Util::randomDouble(1, 100);
	State* state = nullptr;
	//state = new MoveState();
	//beekeeper->setState(state);
	if(randomNr >= 0 && randomNr < beekeeper->getPowerupChance())
	{
		state = new PowerUpState();
		beekeeper->setState(state);
	}
	else if(randomNr >= beekeeper->getPowerupChance() && randomNr < beekeeper->getPowerupChance()+beekeeper->getBaseChance())
	{
		state = new BaseState();
		beekeeper->setState(state);
	}
	else if(randomNr >= beekeeper->getBaseChance() && randomNr <= beekeeper->getPowerupChance() + beekeeper->getBaseChance()+beekeeper->getPanicChance())
	{
		state = new PanicState();
		beekeeper->setState(state);
		beekeeper->changeTexture("beekeeper_panic.png");
	}
	if(state != nullptr)
		state->setBeekeeper(beekeeper);
}

string ChaseState::getStateName()
{
	return "ChaseState";
}

void ChaseState::update()
{
	if(beekeeper->collides(beekeeper->getGame()->getBase()/*eigenlijk bee!!!*/))
	{
		beekeeper->getGame()->getBee()->setCurrentVertex(beekeeper->getGame()->getGraph()->randomVertex(beekeeper->getGame()->getBee()->getCurrentVertex()));
		beekeeper->getState()->changeState();
	}
}
