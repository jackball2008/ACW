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

struct _RigidBody{
public:
	float     fMass;                // total mass (constant)
	float     fInertia;             // mass moment of inertia in body coordinates (constant)
	float     fInertiaInverse;      // inverse of mass moment of inertia (constant)

	Vector    vPosition;            // position in earth coordinates
	Vector    vVelocity;            // velocity in earth coordinates
	Vector    vVelocityBody;        // velocity in body coordinates
	Vector    vAngularVelocity;     // angular velocity in body coordinates

	Vector    vFirstpoint;          
	Vector    vSecondpoint;
	Vector    vThirdpoint;
	Vector    vFourthpoint;


	float	fWidth;	                // bounding dimensions
	float	fLength;

	float     fSpeed;               // speed (magnitude of the velocity)

	float     fOrientation;         // orientation

	Vector    vForces;              // total force on body
	Vector    vMoment;              // total moment (torque) on body (2D: about z-axis only)

	Vector    vGravity;             // gravity

	Vector    vSupport;             // support force

	Vector    vCollisionPoint;       // point of impact in local coordinates
};

#define	ANGULARDRAGCOEFFICIENT	100.25f
#define LINEARDRAGCOEFFICIENT	0.25f
#define	COEFFICIENTOFRESTITUTION	0.5f
#define COLLISIONTOLERANCE		0.001f
#define	COLLISION				1
#define NOCOLLISION				0
#define	PENETRATING				-1
#define FRICTIONCOEFFICIENT		0.35f



