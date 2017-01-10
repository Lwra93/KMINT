#pragma once
#include "GameObject.h"

class Beekeeper : public GameObject
{
public:
	Beekeeper();
	void increaseNetSize();
	int getNetSize();
	void addBee();
	int getBees();
	int removeBees();
	int getMaxBees();

	double getPowerupChance();
	double getPanicChance();
	double getBaseChance();

	~Beekeeper();

private:
	int netSize;
	int beesInNet;
	int maxBees;

	//chances for state changing
	double powerupChance;
	double panicChance;
	double baseChance;
};

