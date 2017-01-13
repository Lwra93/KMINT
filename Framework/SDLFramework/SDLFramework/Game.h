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
	Bee* createBee(Vector2D SpawnPos, double force, double detection, double speed);
	Game(FWApplication* app, Map *graph);
	~Game();
	Map* getGraph() const;
	Base* getBase() const;

	Beekeeper* getBeekeeper() const;
	vector<Bee*> getBees() const;
	void createBees();
	void addBee(Bee*);
	PowerUp* getPowerUp() const;
	int getSpeed() const;
	void setSpeed(int amount);

	CellSpacePartition<Bee*>* CellSpace() { return m_pCellSpace; }

	void StartTime() { beekeeper->STime(app->mTimeMS); }
	
	void nextGen();

private:
	FWApplication* app;
	Beekeeper* beekeeper;
	vector<Bee*> bees;
	Base* base;
	PowerUp* powerup;
	Map* graph;
	int gameSpeed;

	CellSpacePartition<Bee*>* m_pCellSpace;
};

