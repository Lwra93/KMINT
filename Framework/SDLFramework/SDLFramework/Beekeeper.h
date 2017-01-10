#pragma once
#include "GameObject.h"

class Beekeeper : public GameObject
{
public:
	Beekeeper();
	void increaseNetSize();
	int getNetSize();
	void addBee();
	void removeBee();
	int getBees();
	int removeBees();
	int getMaxBees();
	void setMaxBees(int amount);

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

