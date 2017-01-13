#pragma once
#include "GameObject.h"
#include "ForceDrivenEntity.h"
#include "MovingBeeBehaviour.h"

class Bee : public GameObject, public ForceDrivenEntity
{
public:
	Bee(Game* game, Vector2D position, double rotation, Vector2D velocity, double mass, double max_force, double max_speed, double max_turn_rate, double scale, double detection);
	~Bee();

	void Move(float delta);
	Vector2D const GetPos() { return m_vPos; };

	double TimeElapsed()const { return m_dTimeElapsed; }
	const int DetectionRadius() { return detectionRadius; }
	void SetDetectionRadius(int value) { detectionRadius = value; }

	const int getForce() { return this->m_dMaxForce; }
	const int getTopSpeed() { return this->m_dMaxSpeed; }

	void SetPos(int x, int y) { m_vPos.x = x; m_vPos.y = y; }

private:
	int detectionRadius;

	MovingBeeBehaviour* behaviour;
	double m_dTimeElapsed;

};
