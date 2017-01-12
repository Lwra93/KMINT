#include "PowerUpState.h"
#include "AStar.h"
#include "SuperState.h"
#include "Beekeeper.h"
#include "Game.h"

PowerUpState::PowerUpState()
{
}

void PowerUpState::handle()
{
	AStar(beekeeper, beekeeper->getGame()->getGraph(), beekeeper->getGame()->getPowerUp());
}

void PowerUpState::changeState()
{
	beekeeper->getGame()->getBase()->emptyNet(beekeeper->removeBees());
	SuperState* super = new SuperState();
	beekeeper->setState(super);
	beekeeper->setMaxBees(beekeeper->getMaxBees() * 3);
	beekeeper->changeTexture("beekeeper_super.png");
	super->setBeekeeper(beekeeper);
	//auto newSpeed = beekeeper->getGame()->getSpeed() * 3;
	//beekeeper->getGame()->setSpeed(newSpeed);
	//snelheid lopen x3
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
