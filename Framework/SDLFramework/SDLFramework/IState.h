#pragma once
#include "GameObject.h"
#include "Map.h"

class GameObject;

class IState
{
public:
	~IState();
	virtual void handle(GameObject *object1, Map *graph, GameObject *object2 = nullptr) = 0;
	virtual void changeState() = 0;
	virtual string getStateName() = 0;
};
