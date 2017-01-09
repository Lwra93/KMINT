#pragma once
#include "IState.h"

class EnergeticState : public IState
{
public:
	EnergeticState();
	void handle(GameObject *object1, GameObject *object2) override;
};
