#pragma once
#include "GameObject.h"
#include "State.h"

class GameObject;

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

	string getPrevState();
	void setPrevState(string state);

	double getPowerupChance();
	double getPanicChance();
	double getBaseChance();

	~Beekeeper();
	const Game* getGame();
private:
	int netSize;
	int beesInNet;
	int maxBees;

	string prevState;

	//chances for state changing
	double powerupChance;
	double panicChance;
	double baseChance;
};

