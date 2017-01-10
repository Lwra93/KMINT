#include "PanicState.h"
#include "Game.h"
#include "BaseState.h"
#include "Util.h"
using namespace kmint;

PanicState::PanicState()
{
}

void PanicState::handle(GameObject *object1, Map *graph, GameObject *object2)
{
	auto loc = beekeeper->getLocation();
	auto connections = loc->getConnections();

	auto newloc = connections.at(Util::randomInt(0,connections.size()-1));

	beekeeper->setLocation(newloc);

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
	}
}

string PanicState::getStateName()
{
	return "PanicState";
}
