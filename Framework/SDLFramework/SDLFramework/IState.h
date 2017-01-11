#pragma once
#include "GameObject.h"
#include "Map.h"

class PowerUp;
class Base;
class Beekeeper;
class GameObject;

class IState
{
public:
	~IState();
	virtual void handle(Beekeeper *beekeeper, Map *graph, GameObject *object2 = nullptr) = 0;
	virtual void changeState(Beekeeper* beekeeper, Base* base, PowerUp* powerup) = 0;
	virtual string getStateName() = 0;
};
