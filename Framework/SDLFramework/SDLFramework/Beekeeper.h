#pragma once
#include "GameObject.h"

class Beekeeper : public GameObject
{
public:
	Beekeeper();
	void increaseNetSize();
	int getNetSize();
	~Beekeeper();

private:
	int netSize;
};

