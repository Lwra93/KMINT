#pragma once
#include "GameObject.h"

class Base : public GameObject
{
public:
	Base();
	void emptyNet(int bees);
	int getBees();
	~Base();

private:
	int bees;
};

