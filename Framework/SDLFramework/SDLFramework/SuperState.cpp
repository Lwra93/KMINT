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

	for (auto vertex : beekeeper->getGame()->getGraph()->getVertexes())
	{
		auto x = location.x - vertex->getX();
		auto y = location.y - vertex->getY();
		if (abs(x) + abs(y) < num)
		{
			num = abs(x) + abs(y);
			loc = vertex;
		}
	}

	AStar(beekeeper, beekeeper->getGame()->getGraph(), loc);
	beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "MoveState"));

}

void SuperState::changeState()
{

	if (beekeeper->getBees().size() < beekeeper->getMaxBees())
		return;

	beekeeper->getGame()->setSpeed(beekeeper->getGame()->getSpeed() / 3);
	beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "BaseState"));
}

string SuperState::getStateName()
{
	return "SuperState";
}

void SuperState::update()
{

	if(beekeeper->getBees().size() >= 30)
	{
		beekeeper->setSpecialState(getStateName());
		beekeeper->getState()->changeState();
	}

}
