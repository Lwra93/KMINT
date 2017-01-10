#include <cassert>
#include "ForceDrivenEntity.h"


ForceDrivenEntity::ForceDrivenEntity(Vector2D position,
	double    radius,
	Vector2D velocity,
	double    max_speed,
	Vector2D heading,
	double    mass,
	Vector2D scale,
	double    turn_rate,
	double    max_force)
{
	m_dBoundingRadius = radius;
	m_vPos = position;
	m_vVelocity = velocity;
	m_vHeading = heading;
	m_dMass = mass;
	m_vSide = Vector2D(-m_vHeading.x, m_vHeading.y);
	m_dMaxSpeed = max_speed;
	m_dMaxTurnRate = turn_rate;
	m_dMaxForce = max_force;
	m_vBaseVelocity = m_vVelocity;
}

bool ForceDrivenEntity::RotateHeadingToFacePosition(Vector2D target)
{
	Vector2D toTarget = target.Vec2DNormalize(target - m_vPos);

	//first determine the angle between the heading vector and the target
	double angle = acos(m_vHeading.Dot(toTarget));

	//return true if the player is facing the target
	if (angle < 0.00001) return true;

	//clamp the amount to turn to the max turn rate
	if (angle > m_dMaxTurnRate) angle = m_dMaxTurnRate;

	//The next few lines use a rotation matrix to rotate the player's heading
	//vector accordingly
	C2DMatrix RotationMatrix;

	//notice how the direction of rotation has to be determined when creating
	//the rotation matrix
	RotationMatrix.Rotate(angle * m_vHeading.Sign(toTarget));
	RotationMatrix.TransformVector2Ds(m_vHeading);
	RotationMatrix.TransformVector2Ds(m_vVelocity);

	//finally recreate m_vSide
	m_vSide = m_vHeading.Perp();

	return false;
}

void ForceDrivenEntity::SetHeading(Vector2D new_heading)
{
	assert((new_heading.LengthSq() - 1.0) < 0.00001);

	m_vHeading = new_heading;

	//the side vector must always be perpendicular to the heading
	m_vSide = m_vHeading.Perp();
}


ForceDrivenEntity::~ForceDrivenEntity()
{
}
