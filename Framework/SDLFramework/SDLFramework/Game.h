#pragma once
#include "FWApplication.h"
#include "State.h"
#include "Beekeeper.h"
#include "Base.h"
#include "PowerUp.h"
#include "bee.h"
#include "StateFactory.h"
#include "CellSpacePartition.h"

class ChaseState;
class Map;

class Game
{
public:
	Bee* createBee(Vector2D SpawnPos);
	Game(FWApplication* app, Map *graph);
	~Game();
	Map* getGraph() const;
	Base* getBase() const;
	Bee* getBee() const;
	Beekeeper* getBeekeeper() const;
	vector<Bee*> getBees() const;
	void createBees();
	PowerUp* getPowerUp() const;
	int getSpeed() const;
	void setSpeed(int amount);

	CellSpacePartition<Bee*>* CellSpace() { return m_pCellSpace; }

private:
	Beekeeper* beekeeper;
	vector<Bee*> bees;
	Base* base;
	PowerUp* powerup;
	Map* graph;
	int gameSpeed;

	CellSpacePartition<Bee*>* m_pCellSpace;
};

