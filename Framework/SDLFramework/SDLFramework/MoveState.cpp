#include "MoveState.h"
#include "Game.h"
#include "AStar.h"
#include "ChaseState.h"
#include "Beekeeper.h"


MoveState::MoveState()
{
}

void MoveState::handle()
{
	double x = beekeeper->getGoalVertex()->getX();
	double y = beekeeper->getGoalVertex()->getY();
	Vector2D goalLocation = Vector2D(x, y);

	bool goalreached = false;
	double tempX = this->beekeeper->getLocation()->x;
	double tempY = this->beekeeper->getLocation()->y;

	double deltaX = x - tempX;
	double deltaY = y - tempY;

	bool moveUp = deltaY >= 0 ? true : false;
	bool moveRight = deltaX >= 0 ? true : false;

	Vector2D vector = Vector2D(deltaX, deltaY);
	vector.Normalize();

	tempX += (vector.x /** beekeeper->getGame()->getSpeed()*/);
	tempY += (vector.y /** beekeeper->getGame()->getSpeed()*/);

	this->beekeeper->setLocation(tempX, tempY);

	if (moveUp && moveRight)
	{
		if (tempX >= x && tempY >= y)
			this->changeState();
			
	}
	else if (!moveUp && !moveRight)
	{
		if (tempX <= x && tempY <= y)
			this->changeState();
	}
	else if (moveUp && !moveRight)
	{
		if (tempX <= x && tempY >= y)
			this->changeState();
	}
	else if (!moveUp && moveRight)
	{
		if (tempX >= x && tempY <= y)
			this->changeState();
	}
}

void MoveState::changeState()
{
	beekeeper->setCurrentVertex(beekeeper->getGoalVertex());
	ChaseState* state = new ChaseState();
	beekeeper->setState(state);
	state->setBeekeeper(beekeeper);
}

string MoveState::getStateName()
{
	return "MoveState";
}

void MoveState::update()
{
}

