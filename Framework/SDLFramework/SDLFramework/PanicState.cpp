#include "PanicState.h"
#include "Game.h"
#include "BaseState.h"
#include "Util.h"
#include "Beekeeper.h"
#include "StateFactory.h"

PanicState::PanicState()
{
}

void PanicState::handle()
{
	auto loc = beekeeper->getCurrentVertex();
	auto connections = loc->getConnections();

	auto newloc = connections.at(Util::randomInt(0,connections.size()-1));

	beekeeper->setGoalVertex(newloc);

	auto rand = Util::randomInt(0, 1);
	if(rand == 1)
	{
		auto bee = beekeeper->getBees()[0];
		beekeeper->Release(bee);
		beekeeper->getGame()->addBee(bee);
	}

	beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "MoveState"));

}

void PanicState::changeState()
{
	if (beekeeper->getBees().size() == 0)
	{
		beekeeper->setSpecialState(getStateName());
		beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, "BaseState"));
	}
}

string PanicState::getStateName()
{
	return "PanicState";
}

void PanicState::update()
{
	beekeeper->getState()->changeState();
}
