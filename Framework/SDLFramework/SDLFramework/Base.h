#pragma once
#include "GameObject.h"


class Base : public GameObject
{
public:
	Base(Game* game);
	void emptyNet(int bees);
	int getBees();
	~Base();

private:
	int bees;
};

