#pragma once
#include "GameObject.h"
#include "Beekeeper.h"


class Base : public GameObject
{
public:
	Base(Game* game);
	void emptyNet(int bees);
	vector<Bee*> getBees();
	~Base();

	void AddBee(Bee*);
	void RemoveAll();

private:
	int bees;
	vector<Bee*> beesInBase;
};

