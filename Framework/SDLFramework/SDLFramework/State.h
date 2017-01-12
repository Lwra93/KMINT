#pragma once
#include "IState.h"

class Beekeeper;

class State :
	public IState
{
public:
	State();
	~State();
	void setBeekeeper(Beekeeper*);
protected:
	Beekeeper* beekeeper;
};

