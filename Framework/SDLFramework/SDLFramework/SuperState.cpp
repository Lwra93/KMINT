#include "SuperState.h"
#include "Game.h"
#include "AStar.h"
#include "BaseState.h"
#include "Beekeeper.h"
#include "StateFactory.h"

SuperState::SuperState()
{
}

void SuperState::handle()
{

	AStar(beekeeper, beekeeper->getGame()->getGraph(), beekeeper->getGame()->getBee());
	beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "MoveState"));

}

void SuperState::changeState()
{
	beekeeper->addBee();

	if (beekeeper->getBees() < beekeeper->getMaxBees())
		return;

	beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "BaseState"));
}

string SuperState::getStateName()
{
	return "SuperState";
}

void SuperState::update()
{
	if (beekeeper->collides(beekeeper->getGame()->getBee()/*eigenlijk bee!!!*/))//TODO
	{
		beekeeper->getGame()->getBee()->setCurrentVertex(beekeeper->getGame()->getGraph()->randomVertex(beekeeper->getGame()->getBee()->getCurrentVertex()));
		beekeeper->getState()->changeState();
	}
}
