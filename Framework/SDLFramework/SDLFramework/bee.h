#pragma once
#include "GameObject.h"
#include "ForceDrivenEntity.h"

class Bee : public GameObject, public ForceDrivenEntity
{
public:
	//Bee();
	Bee(SDL_Texture * img, FWApplication * app, Vector2D position, double rotation, Vector2D velocity, double mass, double max_force, double max_speed, double max_turn_rate, double scale, std::string color);
	~Bee();

private:
	int topspeed;
	int detectionRadius;
	int force;

	std::string _color;
};
