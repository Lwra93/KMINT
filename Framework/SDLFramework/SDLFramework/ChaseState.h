#pragma once
#include "IState.h"

class ChaseState : public IState
{
public:
	ChaseState();
	void handle(GameObject *object1, GameObject *object2) override;
};

struct Heuristic
{

	bool operator()(const Vertex *v1, const Vertex *v2) const
	{
		return (v1->getCost() + v1->getPriority()) < (v2->getCost() + v2->getPriority());
	}

};