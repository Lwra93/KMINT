#pragma once
#include "State.h"

class MoveState :
	public State
{
public:
	MoveState();

	void handle() override;
	void changeState() override;
	string getStateName() override;
	void update() override;

private:
	double goalX;
	double goalY;
	double beekeeperX;
	double beekeeperY;
	double deltaX;
	double deltaY;
	bool moveUp;
	bool moveRight;
	Vector2D unitVector;
};

