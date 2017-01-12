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
#include <iostream>
#include <string>

ChaseState::ChaseState()
{
}

void ChaseState::handle()
{

	int distance = INT_MAX;
	Vector2D location;

	for (auto bee : beekeeper->getGame()->getBees())
	{
		if (beekeeper->getLocation().Distance(bee->GetPos()) < distance)
		{
			distance = beekeeper->getLocation().Distance(bee->GetPos());
			location = bee->GetPos();
		}
	}

	int num = INT_MAX;
	Vertex* loc = nullptr;

	for(auto vertex : beekeeper->getGame()->getGraph()->getVertexes())
	{
		auto x = location.x - vertex->getX();
		auto y = location.y - vertex->getY();
		if(abs(x) + abs(y) < num)
		{
			num = abs(x) + abs(y);
			loc = vertex;
		}
	}

	AStar(beekeeper, beekeeper->getGame()->getGraph(), loc);
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

	if(beekeeper->getBees() >= 10)
	{
		beekeeper->setSpecialState(getStateName());
		beekeeper->getState()->changeState();
	}

}
