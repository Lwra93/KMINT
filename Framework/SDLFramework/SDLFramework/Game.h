#pragma once
#include "FWApplication.h"
#include "IState.h"
#include "Beekeeper.h"

class Map;

class Game
{
public:
	Game(FWApplication* app, Map *graph);
	~Game();

private:
	Beekeeper* beekeeper;
};

