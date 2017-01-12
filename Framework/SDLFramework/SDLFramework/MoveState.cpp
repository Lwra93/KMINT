#include "MoveState.h"
#include "Game.h"
#include "AStar.h"
#include "ChaseState.h"
#include "Beekeeper.h"
#include "StateFactory.h"


MoveState::MoveState()
{
}

void MoveState::handle()
{

	goalX = beekeeper->getGoalVertex()->getX();
	goalY = beekeeper->getGoalVertex()->getY();

	beekeeperX = this->beekeeper->getLocation().x;
	beekeeperY = this->beekeeper->getLocation().y;

	deltaX = goalX - beekeeperX;
	deltaY = goalY - beekeeperY;

	moveUp = deltaY >= 0 ? true : false;
	moveRight = deltaX >= 0 ? true : false;

	unitVector = Vector2D(deltaX, deltaY);
	unitVector.Normalize();

	beekeeperX += (unitVector.x * beekeeper->getGame()->getSpeed());
	beekeeperY += (unitVector.y * beekeeper->getGame()->getSpeed());

	this->beekeeper->setLocation(beekeeperX, beekeeperY);

	if (moveUp && moveRight)
	{
		if (beekeeperX >= goalX && beekeeperY >= goalY)
			this->changeState();
	}
	else if (!moveUp && !moveRight)
	{
		if (beekeeperX <= goalX && beekeeperY <= goalY)
			this->changeState();
	}
	else if (moveUp && !moveRight)
	{
		if (beekeeperX <= goalX && beekeeperY >= goalY)
			this->changeState();
	}
	else if (!moveUp && moveRight)
	{
		if (beekeeperX >= goalX && beekeeperY <= goalY)
			this->changeState();
	}
}

void MoveState::changeState()
{
	beekeeper->setCurrentVertex(beekeeper->getGoalVertex());

	beekeeper->setState(StateFactory::getInstance()->getNextBeekeeperState(beekeeper, beekeeper->getPrevState()));

}

string MoveState::getStateName()
{
	return "MoveState";
}

void MoveState::update()
{
	
}

