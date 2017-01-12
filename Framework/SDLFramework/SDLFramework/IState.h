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
	virtual void handle() = 0;
	virtual void changeState() = 0;
	virtual string getStateName() = 0;
	virtual void update() = 0;
};

