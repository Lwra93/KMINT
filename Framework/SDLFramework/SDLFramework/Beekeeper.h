#pragma once
#include "GameObject.h"
#include "State.h"
#include "bee.h"

class GameObject;

class Beekeeper : public GameObject
{
public:
	Beekeeper(Game* game);
	void increaseNetSize();
	int getNetSize();
	void resetNet();
	void addBee();
	void removeBee();
	vector<Bee*> getBees();
	void removeBees();
	int getMaxBees();
	void setMaxBees(int amount);
	void changeTexture(string name);

	string getPrevState();
	void setPrevState(string state);

	double getPowerupChance();
	double getPanicChance();
	double getBaseChance();

	void setPowerupChance(double chance) { powerupChance = chance; }
	void setPanicChance(double chance) { panicChance = chance; }
	void setBaseChance(double chance) { baseChance = chance; }

	double StartTime() { return startTime; }
	double EndTime() { return endTime; }
	void Time(float delta) { endTime = delta; }
	void STime(float delta) { startTime = delta; }

	string GetSpecialState() { return specialState; }
	void setSpecialState(string state) { specialState = state; }

	void Catch(Bee*);
	void Release(Bee*);


	~Beekeeper();
private:
	int netSize;
	int maxBees;

	string prevState;
	string specialState;

	//chances for state changing
	double powerupChance;
	double panicChance;
	double baseChance;

	double startTime, endTime;

	vector<Bee*> caughtBees;
};

