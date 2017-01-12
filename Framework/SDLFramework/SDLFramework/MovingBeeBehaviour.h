#pragma once
#include "Vector2D.h"
#include <vector>
#include "C2DMatrix.h"

class Bee;

class MovingBeeBehaviour
{

private:
	enum behavior_type
	{
		none = 0x00000,
		seek = 0x00002,
		flee = 0x00004,
		arrive = 0x00008,
		wander = 0x00010,
		cohesion = 0x00020,
		separation = 0x00040,
		allignment = 0x00080,
		obstacle_avoidance = 0x00100,
		wall_avoidance = 0x00200,
		follow_path = 0x00400,
		pursuit = 0x00800,
		evade = 0x01000,
		interpose = 0x02000,
		hide = 0x04000,
		flock = 0x08000,
		offset_pursuit = 0x10000,
	};

	Bee* bee;
	Vector2D m_vSteeringForce;
	bool m_bCellSpaceOn;
	int m_iFlags;

	const double SteeringFoceTweaker = 100;
	//the radius of the constraining circle for the wander behavior
	const double WanderRad = 1.2;
	//distance the wander circle is projected in front of the agent
	const double WanderDist = 2.0;
	//the maximum amount of displacement along the circle each frame
	const double WanderJitterPerSec = 80.0;

	//the current position on the wander circle the agent is
	//attempting to steer towards
	Vector2D     m_vWanderTarget;

	//explained above
	double        m_dWanderJitter;
	double        m_dWanderRadius;
	double        m_dWanderDistance;

	//multipliers. These can be adjusted to effect strength of the  
	//appropriate behavior. Useful to get flocking the way you require
	//for example.
	double        m_dWeightSeparation;
	double        m_dWeightCohesion;
	double        m_dWeightAlignment;
	double        m_dWeightWander;
	double        m_dWeightObstacleAvoidance;
	double        m_dWeightWallAvoidance;
	double        m_dWeightSeek;
	double        m_dWeightFlee;
	double        m_dWeightArrive;
	double        m_dWeightPursuit;
	double        m_dWeightOffsetPursuit;
	double        m_dWeightInterpose;
	double        m_dWeightHide;
	double        m_dWeightEvade;
	double        m_dWeightFollowPath;

	//how far the agent can 'see'
	double        m_dViewDistance;

public:

	MovingBeeBehaviour();
	~MovingBeeBehaviour();

	void Inject(Bee* bee);
	Vector2D CalculateWeightedSum();
	Vector2D Calculate();

	Vector2D Separation(const std::vector<Bee*> &neighbors);
	Vector2D Alignment(const std::vector<Bee*>& neighbors);
	Vector2D Cohesion(const std::vector<Bee*> &neighbors);

	Vector2D SeparationPlus(const std::vector<Bee*> &neighbors);
	Vector2D AlignmentPlus(const std::vector<Bee*> &neighbors);
	Vector2D CohesionPlus(const std::vector<Bee*> &neighbors);

	Vector2D MovingBeeBehaviour::Seek(Vector2D TargetPos);
	Vector2D MovingBeeBehaviour::Wander();
	Vector2D Flee(Vector2D TargetPos);

	void AlignmentOn() { m_iFlags |= allignment; }
	void SeparationOn() { m_iFlags |= separation; }
	void CohesionOn() { m_iFlags |= cohesion; }
	void WanderOn() { m_iFlags |= wander; }
	void FleeOn() { m_iFlags |= flee; }
	void FlockingOn() { CohesionOn(); AlignmentOn(); SeparationOn(); WanderOn(); FleeOn(); }

	void AlignmentOff() { if (On(allignment)) m_iFlags ^= allignment; }
	void SeparationOff() { if (On(separation)) m_iFlags ^= separation; }
	void CohesionOff() { if (On(cohesion)) m_iFlags ^= cohesion; }
	void FlockingOff() { CohesionOff(); AlignmentOff(); SeparationOff(); }

	bool      isSpacePartitioningOn()const { return m_bCellSpaceOn; }
	bool      On(behavior_type bt) { return (m_iFlags & bt) == bt; }
	
	Vector2D PointToWorldSpace(const Vector2D &point,
		const Vector2D &AgentHeading,
		const Vector2D &AgentSide,
		const Vector2D &AgentPosition)
	{
		//make a copy of the point
		Vector2D TransPoint = point;

		//create a transformation matrix
		C2DMatrix matTransform;

		//rotate
		matTransform.Rotate(AgentHeading, AgentSide);

		//and translate
		matTransform.Translate(AgentPosition.x, AgentPosition.y);

		//now transform the vertices
		matTransform.TransformVector2Ds(TransPoint);

		return TransPoint;
	}


};

