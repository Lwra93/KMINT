#pragma once
#include "State.h"
#include <map>

class StateFactory
{
public:
	StateFactory();
	State* getNextBeekeeperState(Beekeeper *beekeeper, string nextState);
	~StateFactory();
	static StateFactory* getInstance();

private:
	map<string, std::function<State*()>> BeekeeperMap;
};

