#include "MyPhysics.h"


float   fCr     = COEFFICIENTOFRESTITUTION;				// the coefficient of restitution
float	const	ctol = COLLISIONTOLERANCE;			// the collision tolerance

int			CountDo;
float		Impulse;

MyPhysics::MyPhysics(void)
{
}


MyPhysics::~MyPhysics(void)
{
}

void MyPhysics::InitializeSquare(_RigidBody *body){

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

			body->fWidth = 50;								// width of the body (measured along y-axis)
			body->fLength = 70;							    // length of the body (measured along x-axis)
}

////------------------------------------------------------------------------//
//// This function calculates all of the forces and moments acting on the 
//// plane at any given time.
////------------------------------------------------------------------------//

void MyPhysics::CalcLoads(_RigidBody *body){

		Vector	Fb;				// stores the sum of forces
		Vector	Mb;				// stores the sum of moments
		Vector	Thrust;			// thrust vector

		    //reset forces and moments:
			body->vForces.x= 0.0f;
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

Vector MyPhysics::VRotate2D( float angle, Vector u)
{
	float	x,y;

	x = u.x * cos(DegreesToRadians(-angle)) + u.y * sin(DegreesToRadians(-angle));
	y = -u.x * sin(DegreesToRadians(-angle)) + u.y * cos(DegreesToRadians(-angle));

	return Vector( x, y, 0);
}