#pragma once
#include "GameObject.h"

class Bee : public GameObject //forcedriven entities NIET OP DE GRAPH.
{
public:
	Bee();
	~Bee();

private:
	int topspeed;
	int detectionRadius;
	int force;
};
