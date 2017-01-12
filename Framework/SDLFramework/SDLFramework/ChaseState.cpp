#pragma once
#include "ChaseState.h"
#include "Map.h"
#include <list>
#include "AStar.h"
#include "Game.h"
#include "Util.h"
#include "PowerUpState.h"
#include "BaseState.h"
#include "PanicState.h"
#include "MoveState.h"
#include "StateFactory.h"
#include "Beekeeper.h"

ChaseState::ChaseState()
{
}

void ChaseState::handle()
{
	AStar(beekeeper, beekeeper->getGame()->getGraph(), beekeeper->getGame()->getBee());
	beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "MoveState"));
}

void ChaseState::changeState()
{
	beekeeper->addBee();

	if(beekeeper->getBees() < beekeeper->getMaxBees())
		return;

	auto randomNr = Util::randomDouble(1, 100);
	State* state = nullptr;
	if(randomNr >= 0 && randomNr < beekeeper->getPowerupChance())
	{
		beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "PowerUpState"));
	}
	else if(randomNr >= beekeeper->getPowerupChance() && randomNr < beekeeper->getPowerupChance()+beekeeper->getBaseChance())
	{
		beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "BaseState"));
	}
	else if(randomNr >= beekeeper->getBaseChance() && randomNr <= beekeeper->getPowerupChance() + beekeeper->getBaseChance()+beekeeper->getPanicChance())
	{
		beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "PanicState"));
		beekeeper->changeTexture("beekeeper_panic.png");
	}
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
