#pragma once
#include "GameObject.h"

class Beekeeper : public GameObject
{
public:
	Beekeeper(const Game* game);
	void increaseNetSize();
	int getNetSize();
	void resetNet();
	void addBee();
	void removeBee();
	int getBees();
	int removeBees();
	int getMaxBees();
	void setMaxBees(int amount);
	void changeTexture(string name);

	double getPowerupChance();
	double getPanicChance();
	double getBaseChance();

	~Beekeeper();
	const Game* getGame();
private:
	int netSize;
	int beesInNet;
	int maxBees;

	//chances for state changing
	double powerupChance;
	double panicChance;
	double baseChance;
};

