#include "RigidBody.h"
#include <memory.h>
#include <assert.h>


#define	_DTHRUST	1.0f
#define	_MAXTHRUST	2000.0f

extern	void	MyBeep();
int	pnpoly(int	npol, Vector *vlist, Vector p);

//------------------------------------------------------------------------//
// Global variables
//------------------------------------------------------------------------//

RigidBody2D Square1,Square2;        // two rigid bodies
Vector      vCollisionNormal;       // the collision normal returned by our collision detection routine
Vector		vCollisionTangent;			// the collision tangent returned by our collision detection routine
Vector		vCollisionPoint;			// the world space point of collision
Vector		vRelativeVelocity;			// the world space relative velocity of the two bodies at the point of collision
float		fCr = COEFFICIENTOFRESTITUTION;				// the coefficient of restitution
float	const	ctol = COLLISIONTOLERANCE;			// the collision tolerance

int			CountDo;

float		Impulse;

pRigidBody2D CollisionBody1;
pRigidBody2D CollisionBody2;

//------------------------------------------------------------------------//
// Initial square
// 
//------------------------------------------------------------------------//

void InitializeSquare(pRigidBody2D body)
{
	// set initial position
	body->vPosition.x = 0.0f;
	body->vPosition.y = 0.0f;
	body->vPosition.z = 0.0f;    //set all z's to zero b/c this is a 2D example

	//set initial velocity
	body->vVelocity.x =0.0f;
	body->vVelocity.y = 0.0f;
	body->vVelocity.z = 0.0f;  // set all z's to zero b/c this is a 2D example
	body->fSpeed = 0.0f;

	// Set initial angular velocity
	body->vAngularVelocity.x = 0.0f;	// will always be zero in 2D
	body->vAngularVelocity.y = 0.0f;	// will always be zero in 2D
	body->vAngularVelocity.z = 0.0f;	// in 2D only this component with be used

	// Set the initial thrust, forces and moments
	body->vForces.x = 0.0f;
	body->vForces.y = 0.0f;
	body->vForces.z = 0.0f;		// set all z's to zero b/c this is a 2D example

	body->vMoment.x = 0.0f;		// will always be zero in 2D
	body->vMoment.y = 0.0f;		// will always be zero in 2D
	body->vMoment.z = 0.0f;		// in 2D only this component with be used

	// Zero the velocity in body space coordinates
	body->vVelocityBody.x = 0.0f;
	body->vVelocityBody.y = 0.0f;
	body->vVelocityBody.z = 0.0f;

	// Set the initial orientation
	body->fOrientation = 0.0;

	// Now define the mass properties
	body->fMass = 621.6;
	body->fInertia = 383320;
	body->fInertiaInverse = 1.0f / body->fInertia;

	body->CP.x = -0.0f;		body->CP.y = 0.0f;		// coordinates of the cushion center of pressure
	body->CD.x = -2.5f;		body->CD.y = 0.0f;		// coordinates of the body center of drag
	body->CT.x = -30.0f;	body->CT.y = 0.0f;		// coordinates of the propeller thrust vector

	body->CPT.x = 30.0f;	body->CPT.y = 25.0f;	// coordinates of the port bow thruster
	body->CST.x = 30.0f;	body->CST.y = -25.0f;	// coordinates of the starboard bow thruster

	body->CushionArea = 3325.0f;					// planform area of the cushion
	body->ProjectedArea = 1500.0f;					// mean projected area of the entire body
	body->ThrustForce = 0;							// initial thrust force

	body->fWidth = 50;								// width of the body (measured along y-axis)
	body->fLength = 70;							    // length of the body (measured along x-axis)

}

//------------------------------------------------------------------------//
// This function calculates all of the forces and moments acting on the 
// plane at any given time.
//------------------------------------------------------------------------//

void  CalcLoads(pRigidBody2D body)
{
	Vector	Fb;				// stores the sum of forces
	Vector	Mb;				// stores the sum of moments
	Vector	Thrust;			// thrust vector

    //reset forces and moments:
	body->vForces.x=0.0f;
	body->vForces.y = 0.0f;
	body->vForces.z = 0.0f;	// always zero in 2D

	body->vMoment.x = 0.0f;	// always zero in 2D
	body->vMoment.y = 0.0f;	// always zero in 2D
	body->vMoment.z = 0.0f;

	Fb.x = 0.0f;	
	Fb.y = 0.0f;	
	Fb.z = 0.0f;	

	Mb.x = 0.0f;
	Mb.y = 0.0f;
	Mb.z = 0.0f;

    // Define the thrust vector, which acts through the craft's CG
	Thrust.x = 1.0f;
	Thrust.y = 0.0f;
	Thrust.z = 0.0f;  // zero in 2D
	Thrust *= body->ThrustForce;

	// Calculate forces and moments in body space:
	Vector	vLocalVelocity;
	float	fLocalSpeed;
	Vector	vDragVector;	
	float	tmp;
	Vector	vResultant;	
	Vector	vtmp;	

	// Calculate the aerodynamic drag force:
	// Calculate local velocity:
	// The local velocity includes the velocity due to linear motion of the craft, 
	// plus the velocity at each element due to the rotation of the craft.
	vtmp = body->vAngularVelocity^body->CD; // rotational part
	vLocalVelocity = body->vVelocityBody + vtmp; 

	// Calculate local air speed
	fLocalSpeed = vLocalVelocity.Magnitude();

	// Find the direction in which drag will act.
	// Drag always acts inline with the relative velocity but in the opposing direction

	if(fLocalSpeed> tol)
	{
		vLocalVelocity.Normalize();
		vDragVector = -vLocalVelocity;

		// Determine the resultant force on the element.
		tmp = 0.5f * rho * fLocalSpeed*fLocalSpeed * body->ProjectedArea;		
		vResultant = vDragVector * LINEARDRAGCOEFFICIENT * tmp; // simulate fuselage drag

		// Keep a running total of these resultant forces (total force)
		Fb += vResultant;

		// Calculate the moment about the CG of this element's force
		// and keep a running total of these moments (total moment)
		vtmp = body->CD^vResultant; 
		Mb += vtmp;

	}

	// Calculate the Port & Starboard bow thruster forces:
	// Keep a running total of these resultant forces (total force)
	Fb += body->PThrust;

	// Calculate the moment about the CG of this element's force
	// and keep a running total of these moments (total moment)
	vtmp = body->CPT^body->PThrust; 
	Mb += vtmp;

	// Keep a running total of these resultant forces (total force)
	Fb += body->SThrust;

	// Calculate the moment about the CG of this element's force
	// and keep a running total of these moments (total moment)
	vtmp = body->CST^body->SThrust; 		
	Mb += vtmp;

	// Calculate rotational drag
	if(body->vAngularVelocity.Magnitude() > tol)
	{
		vtmp.x = 0;
		vtmp.y = 0;
		tmp = 0.5f * rho * body->vAngularVelocity.z*body->vAngularVelocity.z * body->ProjectedArea;
		if(body->vAngularVelocity.z > 0.0)
			vtmp.z = -ANGULARDRAGCOEFFICIENT * tmp;		
		else
			vtmp.z = ANGULARDRAGCOEFFICIENT * tmp;		

		Mb += vtmp;
	}

	// Now add the propulsion thrust
	Fb += Thrust; // no moment since line of action is through CG

	// Convert forces from model space to earth space
	body->vForces = VRotate2D(body->fOrientation, Fb);

	body->vMoment += Mb;
}
//------------------------------------------------------------------------//
//
//------------------------------------------------------------------------//
Vector	GetBodyZAxisVector(void)
{

	Vector	v;

	v.x = 0.0f;
	v.y = 0.0f;
	v.z = 1.0f;

	return v;
}

//------------------------------------------------------------------------//
//
//------------------------------------------------------------------------//
Vector	GetBodyXAxisVector(int	craft)
{
	Vector v;

	v.x = 1.0f;
	v.y = 0.0f;
	v.z = 0.0f;

	if(craft == 1)	
		return VRotate2D(Square1.fOrientation, v);
	else
		return VRotate2D(Square2.fOrientation, v);
}

void Initialize(void)
{
	InitializeSquare(&Square1);
	InitializeSquare(&Square2);

	Square2.vPosition.y = 60;
	Square2.vPosition.x = 500;
	Square2.fOrientation = 0;


}

void StepSimulation(float dt)
{
	float           dtime= dt;
	bool            tryAgain = true;
	int             check = 0;
	RigidBody2D     Square1Copy,Square2Copy;
	bool            didPen = false;

	while (tryAgain&&(dtime>tol))
	{
		tryAgain = false;
		memcpy(&Square1Copy,&Square1,sizeof(RigidBody2D));
		memcpy(&Square2Copy,&Square2,sizeof(RigidBody2D));

		UpdateBody(&Square1Copy,dtime);
		UpdateBody(&Square2Copy,dtime);

		CollisionBody1= 0;
		CollisionBody2= 0;
		check = CheckForCollision(&Square1Copy,&Square2Copy);

		if(check == PENETRATING )
		{
			dtime = dtime/2;
			tryAgain = true;
			didPen = true;
		}
		else if (check == COLLISION)
		{
			if(CollisionBody1 !=0&& CollisionBody2 != 0)
				ApplyImpulse(CollisionBody1, CollisionBody2);
		}

	}
	if (!didPen)
	{
		memcpy(&Square1, &Square1Copy, sizeof(RigidBody2D));
		memcpy(&Square2, &Square2Copy, sizeof(RigidBody2D));
	}

}
