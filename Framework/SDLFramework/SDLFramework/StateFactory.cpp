#include "StateFactory.h"
#include "BaseState.h"
#include "ChaseState.h"
#include "MoveState.h"
#include "PowerUpState.h"
#include "PanicState.h"
#include "SuperState.h"
#include "Beekeeper.h"

StateFactory::StateFactory()
{
	BeekeeperMap.emplace("ChaseState", []()->State* { return new ChaseState(); });
	BeekeeperMap.emplace("MoveState", []()->State* { return new MoveState(); });
	BeekeeperMap.emplace("BaseState", []()->State* { return new BaseState(); });
	BeekeeperMap.emplace("PowerUpState", []()->State* { return new PowerUpState(); });
	BeekeeperMap.emplace("PanicState", []()->State* { return new PanicState(); });
	BeekeeperMap.emplace("SuperState", []()->State* { return new SuperState(); });
}

State* StateFactory::getNextBeekeeperState(Beekeeper* beekeeper, string nextState)
{
	State* returnState = nullptr;

	if (beekeeper->getState() != nullptr && beekeeper->getPrevState() != beekeeper->getState()->getStateName()) //ithink.
	{
		beekeeper->setPrevState(beekeeper->getState()->getStateName());
	}

	/*auto function = BeekeeperMap[nextState];
	returnState = function();*/

	auto it = BeekeeperMap.find(nextState);
	if( it != BeekeeperMap.end())
	{
		if(it->second() != nullptr)
		{
			returnState = it->second();
			returnState->setBeekeeper(beekeeper);
			return returnState;
		}
	}

	return beekeeper->getState();
}

StateFactory::~StateFactory()
{
}

StateFactory* StateFactory::getInstance()
{
	static StateFactory* instance;
	if (instance == nullptr)
		instance = new StateFactory();
	return instance;
}
