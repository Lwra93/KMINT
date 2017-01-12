#pragma once
#include "Vector2D.h"
#include "C2DMatrix.h"
#include "GameObject.h"

class ForceDrivenEntity
{
protected:
	bool        m_bTag;
	Vector2D	m_vPos;
	Vector2D    m_vVelocity;

	Vector2D	m_vBaseVelocity;

	//a normalized vector pointing in the direction the entity is heading. 
	Vector2D    m_vHeading;

	//a vector perpendicular to the heading vector
	Vector2D    m_vSide;
	double    m_dBoundingRadius;

	double m_dMass;
	//the maximum speed at which this entity may travel.
	double m_dMaxSpeed;
	//the maximum force this entity can produce to power itself
	//(think rockets and thrust)
	double m_dMaxForce;
	//the maximum rate (radians per second) at which this vehicle can rotate
	double m_dMaxTurnRate;
public:

	bool         IsTagged()const { return m_bTag; }
	void         Tag() { m_bTag = true; }
	void         UnTag() { m_bTag = false; }

	ForceDrivenEntity(Vector2D position,
		double    radius,
		Vector2D velocity,
		double    max_speed,
		Vector2D heading,
		double    mass,
		Vector2D scale,
		double    turn_rate,
		double    max_force);
	~ForceDrivenEntity();

	Vector2D  BaseVelocity()const { return m_vBaseVelocity; }
	void      SetBaseVelocity(const Vector2D& NewVel) { m_vBaseVelocity = NewVel; }
	Vector2D  Velocity()const { return m_vVelocity; }
	void      SetVelocity(const Vector2D& NewVel) { m_vVelocity = NewVel; }

	double     Mass()const { return m_dMass; }

	Vector2D  Side()const { return m_vSide; }

	double     MaxSpeed()const { return m_dMaxSpeed; }
	void      SetMaxSpeed(double new_speed) { m_dMaxSpeed = new_speed; }

	double     MaxForce()const { return m_dMaxForce; }
	void      SetMaxForce(double mf) { m_dMaxForce = mf; }

	bool      IsSpeedMaxedOut()const { return m_dMaxSpeed*m_dMaxSpeed >= m_vVelocity.LengthSq(); }
	double     Speed()const { return m_vVelocity.Length(); }
	double     SpeedSq()const { return m_vVelocity.LengthSq(); }

	Vector2D  Heading()const { return m_vHeading; }
	void      SetHeading(Vector2D new_heading);
	bool      RotateHeadingToFacePosition(Vector2D target);

	double     MaxTurnRate()const { return m_dMaxTurnRate; }
	void      SetMaxTurnRate(double val) { m_dMaxTurnRate = val; }

	template <class T, class conT>
	void TagNeighbors(T* entity, conT& ContainerOfEntities, double radius)
	{
		//iterate through all entities checking for range
		for (typename conT::iterator curEntity = ContainerOfEntities.begin();
			curEntity != ContainerOfEntities.end();
			++curEntity)
		{
			//first clear any current tag
			(*curEntity)->UnTag();
			Vector2D to = (*curEntity)->GetPos() - entity->GetPos();
			//the bounding radius of the other is taken into account by adding it
			//to the range
			double range = radius + (*curEntity)->m_dBoundingRadius;
			//if entity within range, tag for further consideration. (working in
			//distance-squared space to avoid sqrts)
			if (((*curEntity) != entity) && (to.LengthSq() < range*range))
			{
				(*curEntity)->Tag();
			}
		}//next entity
	}

	template <class T, class conT>
	void EnforceNonPenetrationConstraint(const T& entity,
		const conT& ContainerOfEntities)
	{
		//iterate through all entities checking for any overlap of bounding radii
		for (typename conT::const_iterator curEntity = ContainerOfEntities.begin();
			curEntity != ContainerOfEntities.end();
			++curEntity)
		{
			//make sure we don't check against the individual
			if (*curEntity == entity) continue;
			//calculate the distance between the positions of the entities
			Vector2D ToEntity = entity->GetPos() - (*curEntity)->GetPos();
			double DistFromEachOther = ToEntity.Length();
			//if this distance is smaller than the sum of their radii then this
			//entity must be moved away in the direction parallel to the
			//ToEntity vector
			double AmountOfOverLap = (*curEntity)->m_dBoundingRadius + entity->m_dBoundingRadius -
				DistFromEachOther;
			if (AmountOfOverLap >= 0)
			{
				//move the entity a distance away equivalent to the amount of overlap.
				entity->SetPos(entity->GetPos() + (ToEntity / DistFromEachOther) *
					AmountOfOverLap);
			}
		}//next entity



	}



};

