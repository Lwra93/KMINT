#pragma once
#include "IState.h"

class WanderingState : public IState
{
public:
	WanderingState();
	void handle(GameObject *object1, GameObject *object2) override;
};
