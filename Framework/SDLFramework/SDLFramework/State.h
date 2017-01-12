#pragma once
#include "IState.h"
#include "Beekeeper.h"

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

