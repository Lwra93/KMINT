#include "PanicState.h"
#include "Game.h"
#include "BaseState.h"
#include "Util.h"
#include "Beekeeper.h"

PanicState::PanicState()
{
}

void PanicState::handle()
{
	auto loc = beekeeper->getCurrentVertex();
	auto connections = loc->getConnections();

	auto newloc = connections.at(Util::randomInt(0,connections.size()-1));

	beekeeper->setCurrentVertex(newloc);

	auto rand = Util::randomInt(0, 1);
	if(rand == 1)
	{
		beekeeper->removeBee();
	}
}

void PanicState::changeState()
{
	if (beekeeper->getBees() == 0)
	{
		BaseState* baseState = new BaseState();
		beekeeper->setState(baseState);
		baseState->setBeekeeper(beekeeper);
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
