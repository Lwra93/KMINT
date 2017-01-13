#include "PowerUpState.h"
#include "AStar.h"
#include "SuperState.h"
#include "Beekeeper.h"
#include "Game.h"
#include "StateFactory.h"

PowerUpState::PowerUpState()
{
}

void PowerUpState::handle()
{
	AStar(beekeeper, beekeeper->getGame()->getGraph(), beekeeper->getGame()->getPowerUp()->getCurrentVertex());
	beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "MoveState"));
}

void PowerUpState::changeState()
{

	auto bees = beekeeper->getBees();
	
	for(auto bee : bees)
	{
		
		beekeeper->Release(bee);
		beekeeper->getGame()->getBase()->AddBee(bee);

	}

	beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "SuperState"));

	beekeeper->setMaxBees(beekeeper->getMaxBees() * 3);
	beekeeper->changeTexture("beekeeper_super.png");
	
	beekeeper->getGame()->setSpeed(beekeeper->getGame()->getSpeed() * 3);
}

string PowerUpState::getStateName()
{
	return "PowerUpState";
}

void PowerUpState::update()
{
	if (beekeeper->collides(beekeeper->getGame()->getPowerUp()))
	{
		beekeeper->getGame()->getPowerUp()->setCurrentVertex(beekeeper->getGame()->getGraph()->randomVertex(beekeeper->getGame()->getPowerUp()->getCurrentVertex()));
		beekeeper->getState()->changeState();
	}
}
