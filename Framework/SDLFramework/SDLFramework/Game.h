#pragma once
#include "FWApplication.h"
#include "State.h"
#include "Beekeeper.h"
#include "Base.h"
#include "PowerUp.h"
#include "bee.h"
#include "StateFactory.h"

class ChaseState;
class Map;

class Game
{
public:
	Bee* createBee(Vector2D SpawnPos, std::string color);
	Game(FWApplication* app, Map *graph);
	~Game();
	Map* getGraph() const;
	Base* getBase() const;
	Bee* getBee() const;
	PowerUp* getPowerUp() const;
	int getSpeed() const;
	void setSpeed(int amount);
private:
	Beekeeper* beekeeper;
	Bee* bee;
	Base* base;
	PowerUp* powerup;
	Map* graph;
	int gameSpeed;
};

