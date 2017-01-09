#pragma once
#include "IState.h"

class DeadState : public IState
{
public:
	DeadState();
	void handle(GameObject *object1, GameObject *object2) override;
};
