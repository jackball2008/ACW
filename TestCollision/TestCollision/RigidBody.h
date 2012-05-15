#include "mymath.h"
#include <vector>
using std::vector;
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

	_RigidBody(void);
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

	vector<Vector>PiontPostion;

	//void SetData(const Vector &p0,const Vector &p1,const Vector &p2,const Vector &p3,const Vector &p4);
	//void SetData(const Vector &p0,const Vector &p1,const Vector &p2,const Vector &p3);
//////////////////////////////////////////////////

	//spring lock
	bool springlocked;
	float lockspringep_dx,lockspringep_dy;
	//color
	float r,g,b;
	int type;
	bool isvisiable;
	int id;
////////////////////////////////////////////////////
};

#define	ANGULARDRAGCOEFFICIENT	100.25f
#define LINEARDRAGCOEFFICIENT	0.25f
#define	COEFFICIENTOFRESTITUTION	0.5f
#define COLLISIONTOLERANCE		0.001f
#define	COLLISION				1
#define NOCOLLISION				0
#define	PENETRATING				-1
#define FRICTIONCOEFFICIENT		0.35f



