#include "BaseState.h"
#include "AStar.h"
#include "Beekeeper.h"
#include "ChaseState.h"
#include "Game.h"
#include "StateFactory.h"
#include <iostream>
#include <string>

BaseState::BaseState()
{
}

void BaseState::handle()
{
	AStar(beekeeper, beekeeper->getGame()->getGraph(), beekeeper->getGame()->getBase()->getCurrentVertex());
	beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "MoveState"));
}



void BaseState::changeState()
{


	auto bees = beekeeper->getBees();

	for (auto bee : bees)
	{

		beekeeper->Release(bee);
		beekeeper->getGame()->getBase()->AddBee(bee);

	}

	beekeeper->resetNet();

	beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "ChaseState"));

	beekeeper->getGame()->StartTime();

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

		auto x = (beekeeper->EndTime() - beekeeper->StartTime()) / 1000;
		auto ratio = (beekeeper->getBees().size() + 1) / x;

		if(beekeeper->GetSpecialState() == "ChaseState")
		{
			auto newChance = beekeeper->getBaseChance() * ratio;
			auto toSubtract = newChance - beekeeper->getBaseChance();
			beekeeper->setBaseChance(newChance);
			beekeeper->setPanicChance(beekeeper->getPanicChance() - (toSubtract / 2));
			beekeeper->setPowerupChance(beekeeper->getPowerupChance() - (toSubtract / 2));
		}
		else if(beekeeper->GetSpecialState() == "SuperState")
		{
			auto newChance = beekeeper->getPowerupChance() * ratio;
			auto toSubtract = newChance - beekeeper->getPowerupChance();
			beekeeper->setPowerupChance(newChance);
			beekeeper->setBaseChance(beekeeper->getBaseChance() - (toSubtract / 2));
			beekeeper->setPanicChance(beekeeper->getPanicChance() - (toSubtract / 2));
		}
		else
		{
			auto newChance = beekeeper->getPanicChance() * ratio;
			auto toSubtract = newChance - beekeeper->getPanicChance();
			beekeeper->setPanicChance(newChance);
			beekeeper->setBaseChance(beekeeper->getBaseChance() - (toSubtract / 2));
			beekeeper->setPowerupChance(beekeeper->getPowerupChance() - (toSubtract / 2));
		}


		beekeeper->getState()->changeState();
	}
}

