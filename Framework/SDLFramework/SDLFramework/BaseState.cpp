#include "BaseState.h"
#include "AStar.h"
#include "Beekeeper.h"
#include "ChaseState.h"
#include "Game.h"
#include "StateFactory.h"

BaseState::BaseState()
{
}

void BaseState::handle()
{
	AStar(beekeeper, beekeeper->getGame()->getGraph(), beekeeper->getGame()->getBase());
	beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "MoveState"));
}



void BaseState::changeState()
{
	beekeeper->getGame()->getBase()->emptyNet(beekeeper->removeBees());
	beekeeper->resetNet();

	beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "ChaseState"));

	beekeeper->setMaxBees(10);
	beekeeper->changeTexture("beekeeper.png");
}


string BaseState::getStateName()
{
	return "BaseState";
}

void BaseState::update()
{
	if (beekeeper->collides(beekeeper->getGame()->getBase()))
	{
		beekeeper->getState()->changeState();
	}
}

