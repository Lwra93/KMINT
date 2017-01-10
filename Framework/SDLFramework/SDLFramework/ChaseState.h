#pragma once
#include "IState.h"
#include <queue>
#include <map>

class ChaseState : public IState
{
public:
	ChaseState();
	void handle(GameObject *object1, Map *graph, GameObject *object2) override;
};