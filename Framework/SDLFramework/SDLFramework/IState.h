#pragma once
#include "GameObject.h"

class GameObject;

class IState
{
public:
	~IState();
	virtual void handle(GameObject *object1, GameObject *object2 = nullptr) = 0;
};
