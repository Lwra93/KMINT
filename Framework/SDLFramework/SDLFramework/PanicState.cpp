#include "PanicState.h"
#include "Game.h"
#include "BaseState.h"
#include "Util.h"

PanicState::PanicState()
{
}

void PanicState::handle(Beekeeper *beekeeper, Map *graph, GameObject *object2)
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

void PanicState::changeState(Beekeeper* beekeeper, Base* base, PowerUp* powerup)
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
