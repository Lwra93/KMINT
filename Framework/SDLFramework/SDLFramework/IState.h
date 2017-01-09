#pragma once
#include "GameObject.h"
#include "Map.h"

class GameObject;

class IState
{
public:
	~IState();
	virtual void handle(GameObject *object1, Map *graph, GameObject *object2 = nullptr) = 0;
};
