#pragma once
#include "GameObject.h"
#include "ForceDrivenEntity.h"
#include "MovingBeeBehaviour.h"

class Bee : public GameObject, public ForceDrivenEntity
{
public:
	Bee(Game* game, Vector2D position, double rotation, Vector2D velocity, double mass, double max_force, double max_speed, double max_turn_rate, double scale);
	//Bee(Game* game);
	~Bee();

	void Move(float delta);
	Vector2D const GetPos() { return m_vPos; };

	double TimeElapsed()const { return m_dTimeElapsed; }
	const int DetectionRadius() { return detectionRadius; }
	void SetDetectionRadius(int value) { detectionRadius = value; }


private:
	int topspeed;
	int detectionRadius;
	int force;

	MovingBeeBehaviour* behaviour;
	double m_dTimeElapsed;

};
