#include "bee.h"
#include "Game.h"
#include "MovingBeeBehaviour.h"

//Bee::Bee(Game* game): GameObject(game)
//{
//	//_color = color;
//	this->SetTexture(mApplication->LoadTexture("bee.png"));
//	this->mHeight = 21;
//	this->mWidth = 25;
//	mApplication->AddRenderable(this);
//}

Bee::Bee(Game* game, Vector2D position,double rotation, Vector2D velocity, double mass, 
		double max_force, double max_speed, double max_turn_rate, 
			double scale, double detection) : GameObject(game), ForceDrivenEntity(position,
				scale, velocity, max_speed, Vector2D(sin(rotation), -cos(rotation)),
				mass, Vector2D(scale, scale), max_turn_rate, max_force)
{
	this->SetTexture(mApplication->LoadTexture("bee.png"));
	this->mHeight = 21;
	this->mWidth = 25;
	this->location = position;
	this->detectionRadius = detection;
	mApplication->AddRenderable(this);
	this->behaviour = new MovingBeeBehaviour();
	this->behaviour->Inject(this);


}

Bee::~Bee()
{
}

void Bee::Move(float delta)
{

	m_dTimeElapsed = delta;

	Vector2D OldPos = GetPos();

	Vector2D SteeringForce;

	SteeringForce = behaviour->Calculate();

	Vector2D acceleration = SteeringForce / m_dMass;

	m_vVelocity += acceleration * delta;

	m_vVelocity.Truncate(m_dMaxSpeed);

	m_vPos += m_vVelocity * delta;

	if (m_vVelocity.LengthSq() > 0.00000001)
	{
		m_vHeading = m_vVelocity.Vec2DNormalize(m_vVelocity);

		m_vSide = m_vHeading.Perp();
	}

	m_vPos.WrapAround(mApplication->getWidth(), mApplication->getHeight());
	
	this->location.x = m_vPos.x;
	this->location.y = m_vPos.y;

}

