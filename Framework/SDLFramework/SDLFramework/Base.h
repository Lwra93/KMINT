#pragma once
#include "GameObject.h"


class Base : public GameObject
{
public:
	Base(const Game* game);
	void emptyNet(int bees);
	int getBees();
	~Base();

private:
	int bees;
};

