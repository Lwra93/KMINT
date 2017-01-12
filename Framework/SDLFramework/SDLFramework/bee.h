#pragma once
#include "GameObject.h"
#include "ForceDrivenEntity.h"

class Bee : public GameObject//, public ForceDrivenEntity
{
public:
	//Bee(const Game* game, Vector2D position, double rotation, Vector2D velocity, double mass, double max_force, double max_speed, double max_turn_rate, double scale, std::string color);
	Bee(const Game* game);
	~Bee();

private:
	int topspeed;
	int detectionRadius;
	int force;

	std::string _color;
};
