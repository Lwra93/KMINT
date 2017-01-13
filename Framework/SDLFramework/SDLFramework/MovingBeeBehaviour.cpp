#include "MovingBeeBehaviour.h"
#include "Game.h"
#include "Util.h"
#include <cassert>


MovingBeeBehaviour::MovingBeeBehaviour()
{
	m_iFlags = 0;
	m_dWeightCohesion = 5.0 * SteeringFoceTweaker;
	m_dWeightAlignment = 5.0 * SteeringFoceTweaker;
	m_dWeightSeparation = 5.0 * SteeringFoceTweaker;
	m_dViewDistance = 50.0;
	m_dWeightArrive = 1.0 * SteeringFoceTweaker;
	m_bCellSpaceOn = true;
	m_dWanderDistance = WanderDist;
	m_dWanderJitter = WanderJitterPerSec;
	m_dWanderRadius = WanderRad;
	m_dWeightFlee = 1.0 * SteeringFoceTweaker;

	FlockingOn();

}


MovingBeeBehaviour::~MovingBeeBehaviour()
{
}

void MovingBeeBehaviour::Inject(Bee* bee)
{
	this->bee = bee;
}

Vector2D MovingBeeBehaviour::Calculate()
{
	//reset the steering force
	m_vSteeringForce.Zero();

	//use space partitioning to calculate the neighbours of this vehicle
	//if switched on. If not, use the standard tagging system
	if (!isSpacePartitioningOn())
	{
		//tag neighbors if any of the following 3 group behaviors are switched on
		if (On(separation) || On(allignment) || On(cohesion))
		{
			bee->TagNeighbors(bee, bee->getGame()->getBees(), m_dViewDistance);
		}
	}
	else
	{
		//calculate neighbours in cell-space if any of the following 3 group
		//behaviors are switched on
		if (On(separation) || On(allignment) || On(cohesion))
		{
			bee->getGame()->CellSpace()->CalculateNeighbors(bee->GetPos(), m_dViewDistance);
		}
	}

	m_vSteeringForce = CalculateWeightedSum();

	return m_vSteeringForce;
}


//---------------------- CalculateWeightedSum ----------------------------
//
//  this simply sums up all the active behaviors X their weights and 
//  truncates the result to the max available steering force before 
//  returning
//------------------------------------------------------------------------
Vector2D MovingBeeBehaviour::CalculateWeightedSum()
{

	//these next three can be combined for flocking behavior (wander is
	//also a good behavior to add into this mix)
	if (!isSpacePartitioningOn())
	{
		if (On(separation))
		{
			m_vSteeringForce += Separation(bee->getGame()->getBees()) * m_dWeightSeparation;
		}

		if (On(allignment))
		{
			m_vSteeringForce += Alignment(bee->getGame()->getBees()) * m_dWeightAlignment;
		}

		if (On(cohesion))
		{
			m_vSteeringForce += Cohesion(bee->getGame()->getBees()) * m_dWeightCohesion;
		}
	}
	else
	{
		if (On(separation))
		{
			m_vSteeringForce += SeparationPlus(bee->getGame()->getBees()) * m_dWeightSeparation;
		}

		if (On(allignment))
		{
			m_vSteeringForce += AlignmentPlus(bee->getGame()->getBees()) * m_dWeightAlignment;
		}

		if (On(cohesion))
		{
			m_vSteeringForce += CohesionPlus(bee->getGame()->getBees()) * m_dWeightCohesion;
		}
	}


	if (On(wander))
	{
		m_vSteeringForce += Wander() * m_dWeightWander;
	}

	if (On(flee))
	{
		m_vSteeringForce += Flee(bee->getGame()->getBeekeeper()->getLocation()) * m_dWeightFlee;
	}

	m_vSteeringForce.Truncate(bee->MaxForce());

	return m_vSteeringForce;
}

//---------------------------- Separation --------------------------------
//
// this calculates a force repelling from the other neighbors
//------------------------------------------------------------------------
Vector2D MovingBeeBehaviour::Separation(const vector<Bee*> &neighbors)
{
	Vector2D SteeringForce;

	for (unsigned int a = 0; a<neighbors.size(); ++a)
	{
		//make sure this agent isn't included in the calculations and that
		//the agent being examined is close enough. ***also make sure it doesn't
		//include the evade target ***
		if ((neighbors[a] != bee) && neighbors[a]->IsTagged())
		{
			Vector2D ToAgent = bee->GetPos() - neighbors[a]->GetPos();

			//scale the force inversely proportional to the agents distance  
			//from its neighbor.
			SteeringForce += ToAgent.Vec2DNormalize(ToAgent) / ToAgent.Length();
		}
	}

	return SteeringForce;
}


//---------------------------- Alignment ---------------------------------
//
//  returns a force that attempts to align this agents heading with that
//  of its neighbors
//------------------------------------------------------------------------
Vector2D MovingBeeBehaviour::Alignment(const vector<Bee*>& neighbors)
{
	//used to record the average heading of the neighbors
	Vector2D AverageHeading;

	//used to count the number of vehicles in the neighborhood
	int    NeighborCount = 0;

	//iterate through all the tagged vehicles and sum their heading vectors  
	for (unsigned int a = 0; a<neighbors.size(); ++a)
	{
		//make sure *this* agent isn't included in the calculations and that
		//the agent being examined  is close enough ***also make sure it doesn't
		if ((neighbors[a] != bee) && neighbors[a]->IsTagged())
		{
			AverageHeading += neighbors[a]->Heading();

			++NeighborCount;
		}
	}

	//if the neighborhood contained one or more vehicles, average their
	//heading vectors.
	if (NeighborCount > 0)
	{
		AverageHeading /= (double)NeighborCount;

		AverageHeading -= bee->Heading();
	}

	return AverageHeading;
}

//-------------------------------- Cohesion ------------------------------
//
//  returns a steering force that attempts to move the agent towards the
//  center of mass of the agents in its immediate area
//------------------------------------------------------------------------
Vector2D MovingBeeBehaviour::Cohesion(const vector<Bee*> &neighbors)
{
	//first find the center of mass of all the agents
	Vector2D CenterOfMass, SteeringForce;

	int NeighborCount = 0;

	//iterate through the neighbors and sum up all the position vectors
	for (unsigned int a = 0; a<neighbors.size(); ++a)
	{
		//make sure *this* agent isn't included in the calculations and that
		//the agent being examined is close enough ***also make sure it doesn't
		if ((neighbors[a] != bee) && neighbors[a]->IsTagged())
		{
			CenterOfMass += neighbors[a]->GetPos();

			++NeighborCount;
		}
	}

	if (NeighborCount > 0)
	{
		//the center of mass is the average of the sum of positions
		CenterOfMass /= (double)NeighborCount;

		//now seek towards that position
		SteeringForce = Seek(CenterOfMass);
	}

	//the magnitude of cohesion is usually much larger than separation or
	//allignment so it usually helps to normalize it.
	return SteeringForce.Vec2DNormalize(SteeringForce);
}

Vector2D MovingBeeBehaviour::Seek(Vector2D TargetPos)
{
	Vector2D DesiredVelocity = TargetPos.Vec2DNormalize(TargetPos - bee->GetPos())
		* bee->MaxSpeed();

	return (DesiredVelocity - bee->Velocity());
}


/* NOTE: the next three behaviors are the same as the above three, except
that they use a cell-space partition to find the neighbors
*/


//---------------------------- Separation --------------------------------
//
// this calculates a force repelling from the other neighbors
//
//  USES SPACIAL PARTITIONING
//------------------------------------------------------------------------
Vector2D MovingBeeBehaviour::SeparationPlus(const vector<Bee*> &neighbors)
{
	Vector2D SteeringForce;

	//iterate through the neighbors and sum up all the position vectors
	for (Bee* pV = bee->getGame()->CellSpace()->begin();
		!bee->getGame()->CellSpace()->end();
		pV = bee->getGame()->CellSpace()->next())
	{
		//make sure this agent isn't included in the calculations and that
		//the agent being examined is close enough
		if (pV != bee)
		{
			Vector2D ToAgent = bee->GetPos() - pV->GetPos();

			//scale the force inversely proportional to the agents distance  
			//from its neighbor.
			SteeringForce += ToAgent.Vec2DNormalize(ToAgent) / ToAgent.Length();
		}

	}

	return SteeringForce;
}
//---------------------------- Alignment ---------------------------------
//
//  returns a force that attempts to align this agents heading with that
//  of its neighbors
//
//  USES SPACIAL PARTITIONING
//------------------------------------------------------------------------
Vector2D MovingBeeBehaviour::AlignmentPlus(const vector<Bee*> &neighbors)
{
	//This will record the average heading of the neighbors
	Vector2D AverageHeading;

	//This count the number of vehicles in the neighborhood
	double    NeighborCount = 0.0;

	//iterate through the neighbors and sum up all the position vectors
	for (Bee* pV = bee->getGame()->CellSpace()->begin();
		!bee->getGame()->CellSpace()->end();
		pV = bee->getGame()->CellSpace()->next())
	{
		//make sure *this* agent isn't included in the calculations and that
		//the agent being examined  is close enough
		if (pV != bee)
		{
			AverageHeading += pV->Heading();

			++NeighborCount;
		}

	}

	//if the neighborhood contained one or more vehicles, average their
	//heading vectors.
	if (NeighborCount > 0.0)
	{
		AverageHeading /= NeighborCount;

		AverageHeading -= bee->Heading();
	}

	return AverageHeading;
}


//-------------------------------- Cohesion ------------------------------
//
//  returns a steering force that attempts to move the agent towards the
//  center of mass of the agents in its immediate area
//
//  USES SPACIAL PARTITIONING
//------------------------------------------------------------------------
Vector2D MovingBeeBehaviour::CohesionPlus(const vector<Bee*> &neighbors)
{
	//first find the center of mass of all the agents
	Vector2D CenterOfMass, SteeringForce;

	int NeighborCount = 0;

	//iterate through the neighbors and sum up all the position vectors
	for (Bee* pV = bee->getGame()->CellSpace()->begin();
		!bee->getGame()->CellSpace()->end();
		pV = bee->getGame()->CellSpace()->next())
	{
		//make sure *this* agent isn't included in the calculations and that
		//the agent being examined is close enough
		if (pV != bee)
		{
			CenterOfMass += pV->GetPos();

			++NeighborCount;
		}
	}

	if (NeighborCount > 0)
	{
		//the center of mass is the average of the sum of positions
		CenterOfMass /= (double)NeighborCount;

		//now seek towards that position
		SteeringForce = Seek(CenterOfMass);
	}

	//the magnitude of cohesion is usually much larger than separation or
	//allignment so it usually helps to normalize it.
	return SteeringForce.Vec2DNormalize(SteeringForce);
}

//--------------------------- Wander -------------------------------------
//
//  This behavior makes the agent wander about randomly
//------------------------------------------------------------------------
Vector2D MovingBeeBehaviour::Wander()
{
	//this behavior is dependent on the update rate, so this line must
	//be included when using time independent framerate.
	double JitterThisTimeSlice = m_dWanderJitter * bee->TimeElapsed();

	//first, add a small random vector to the target's position
	m_vWanderTarget += Vector2D(Util::RandomClamped() * JitterThisTimeSlice,
		Util::RandomClamped() * JitterThisTimeSlice);

	//reproject this new vector back on to a unit circle
	m_vWanderTarget.Normalize();

	//increase the length of the vector to the same as the radius
	//of the wander circle
	m_vWanderTarget *= m_dWanderRadius;

	//move the target into a position WanderDist in front of the agent
	Vector2D target = m_vWanderTarget + Vector2D(m_dWanderDistance, 0);

	//project the target into world space
	Vector2D Target = PointToWorldSpace(target,
		bee->Heading(),
		bee->Side(),
		bee->GetPos());

	//and steer towards it
	return Target - bee->GetPos();
}

//----------------------------- Flee -------------------------------------
//
//  Does the opposite of Seek
//------------------------------------------------------------------------
Vector2D MovingBeeBehaviour::Flee(Vector2D TargetPos)
{

	const int PanicDistanceSq = bee->DetectionRadius();
	const int distance = bee->GetPos().Distance(TargetPos);
	if (abs(distance) > PanicDistanceSq)
	{
		return Vector2D(0,0);
	}
	
	Vector2D DesiredVelocity = TargetPos.Vec2DNormalize(bee->GetPos() - TargetPos)
		* bee->MaxSpeed();
	
	return (DesiredVelocity - bee->Velocity());
}