#include "State.h"
#include "Beekeeper.h"


State::State()
{
}


State::~State()
{
}

void State::setBeekeeper(Beekeeper* beekeeper)
{
	this->beekeeper = beekeeper;
}
