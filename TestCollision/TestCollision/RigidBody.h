#include "mymath.h"

//------------------------------------------------------------------------//
// Notes:
//------------------------------------------------------------------------//

//distance	--> feet
//	time		-->	seconds
//	mass		--> slugs
//	force		--> pounds
//	moment		--> foot-pounds
//	velocity	--> feet-per-second
//	acceleration-->	feet-per-second^2
//	density		--> slugs-per-feet^3

//------------------------------------------------------------------------//
// 2D rigid body
//------------------------------------------------------------------------//

class _RigidBody{
public:
	float     fMass;                // total mass (constant)
	float     fInertia;             // mass moment of inertia in body coordinates (constant)
	float     fInertiaInverse;      // inverse of mass moment of inertia (constant)

	Vector    vPosition;            // position in earth coordinates
	Vector    vVelocity;            // velocity in earth coordinates
	Vector    vVelocityBody;        // velocity in body coordinates
	Vector    vAngularVelocity;     // angular velocity in body coordinates

	float     fSpeed;               // speed (magnitude of the velocity)

	float     fOrientation;         // orientation

	Vector    vForces;              // total force on body
	Vector    vMoment;              // total moment (torque) on body (2D: about z-axis only)


	Vector    CP;                   
	Vector	  CD;                   //  friction center base on center of gravity
	Vector	  CT;                   //  force center base on center of gravity
	Vector	  CPT;
	Vector	  CST;

	float     CushionArea;
	float     ProjectedArea;          

	float     ThrustForce;           // Magnitude of the thrust force
	Vector    PThrust, SThrust;

	float     fWidth;                //bounding dimensions
	float     fLength;

	Vector    vCollisionPoint;       // point of impact in local coordinates
};

#define	ANGULARDRAGCOEFFICIENT	100.25f
#define LINEARDRAGCOEFFICIENT	0.25f
#define	COEFFICIENTOFRESTITUTION	0.5f
#define COLLISIONTOLERANCE		0.1f
#define	COLLISION				1
#define NOCOLLISION				0
#define	PENETRATING				-1
#define FRICTIONCOEFFICIENT		0.35f


//------------------------------------------------------------------------//
// Function headers
//------------------------------------------------------------------------//

//void  InitializeSquare(pRigidBody2D body);
//void  CalcLoads(pRigidBody2D body);
//
//void  UpdateBody(pRigidBody2D craft, float dtime);
//void  UpdateBodyEuler(pRigidBody2D craft, float dt);
//
//Vector	GetBodyZAxisVector(void);
//Vector	GetBodyXAxisVector(int craft);
//
//void	IncThrust(int craft);
//void	DecThrust(int craft);
//void	PortThruster(int craft);
//void	STBDThruster(int craft);
//void	ZeroThrusters(int craft);
//
//void  Initialize(void);
//void  StepSimulation(float dt);
//void  ApplyImpulse(pRigidBody2D body1,pRigidBody2D body2);
//void  ApplyLinearImpulse(pRigidBody2D body1, pRigidBody2D body2);
//int	  CheckForCollisionSimple(pRigidBody2D body1, pRigidBody2D body2);
//int	  CheckForCollision(pRigidBody2D body1, pRigidBody2D body2);
//bool  ArePointsEqual(Vector p1, Vector p2);
//
//int	pnpoly(int	npol, Vector *vlist, Vector p);
//
//Vector VRotate2D(float angle, Vector u);};
