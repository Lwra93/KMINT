#include "BaseState.h"
#include "AStar.h"
#include "Beekeeper.h"
#include "ChaseState.h"
#include "Game.h"

BaseState::BaseState()
{
}

void BaseState::handle()
{
	AStar(beekeeper, beekeeper->getGame()->getGraph(), beekeeper->getGame()->getBase());
}



void BaseState::changeState()
{
	beekeeper->getGame()->getBase()->emptyNet(beekeeper->removeBees());
	beekeeper->resetNet();
	ChaseState* chase = new ChaseState();
	chase->setBeekeeper(beekeeper);
	beekeeper->setState(chase);
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

