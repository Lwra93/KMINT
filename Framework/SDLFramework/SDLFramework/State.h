#pragma once
#include "IState.h"
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

