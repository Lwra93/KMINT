#include "SuperState.h"
#include "Game.h"
#include "AStar.h"
#include "BaseState.h"
#include "Beekeeper.h"

SuperState::SuperState()
{
}

void SuperState::handle()
{
	AStar(beekeeper, beekeeper->getGame()->getGraph(), beekeeper->getGame()->getBee());
}

void SuperState::changeState()
{
	beekeeper->addBee();

	if (beekeeper->getBees() < beekeeper->getMaxBees())
		return;

	BaseState* baseState = new BaseState();
	beekeeper->setState(baseState);
	baseState->setBeekeeper(beekeeper);
}

string SuperState::getStateName()
{
	return "SuperState";
}

void SuperState::update()
{
	if (beekeeper->collides(beekeeper->getGame()->getBase()/*eigenlijk bee!!!*/))//TODO
	{
		beekeeper->getGame()->getBee()->setCurrentVertex(beekeeper->getGame()->getGraph()->randomVertex(beekeeper->getGame()->getBee()->getCurrentVertex()));
		beekeeper->getState()->changeState();
	}
}
