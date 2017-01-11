#pragma once
#include "GameObject.h"

class Bee : public GameObject
{
public:
	Bee();
	~Bee();

private:
	int topspeed;
	int detectionRadius;
	int force;

	std::string _color;
};
