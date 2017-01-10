#pragma once
#include "FWApplication.h"
#include "IState.h"
#include "Beekeeper.h"
#include "Base.h"
#include "PowerUp.h"

class Map;

namespace kmint
{
	extern Beekeeper* beekeeper;
	extern Base* base;
	extern PowerUp* powerup;
}


class Game
{
public:
	Game(FWApplication* app, Map *graph);
	~Game();

};

