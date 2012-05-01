#include "RigidBody.h"


_RigidBody::_RigidBody(){
	//set initial velocity
	vVelocity.x = 0.0f;
	vVelocity.y = 0.0f;
	vVelocity.z = 0.0f;  // set all z's to zero b/c this is a 2D example
	fSpeed = 0.0f;

	// Set initial angular velocity
	vAngularVelocity.x = 0.0f;	// will always be zero in 2D
	vAngularVelocity.y = 0.0f;	// will always be zero in 2D
	vAngularVelocity.z = 0.0f;	// in 2D only this component with be used

	// Set the initial thrust, forces and moments
	vForces.x = 0.0f;
	vForces.y = 0.0f;
	vForces.z = 0.0f;		// set all z's to zero b/c this is a 2D example

	vGravity.x =0.0f;
	vGravity.y =-0.098f;
	vGravity.z =0.0f;

	vSupport.x = 0.0f;
	vSupport.y = 0.098f;
	vSupport.z = 0.0f;

	vMoment.x = 0.0f;		// will always be zero in 2D
	vMoment.y = 0.0f;		// will always be zero in 2D
	vMoment.z = 0.0f;		// in 2D only this component with be used

	// Zero the velocity in body space coordinates
	vVelocityBody.x = 0.0f;
	vVelocityBody.y = 0.0f;
	vVelocityBody.z = 0.0f;

	// Now define the mass properties
	fMass = 1.0f;
	fInertia = 383320;
	fInertiaInverse = 1.0f / fInertia;

	// Set the initial orientation
	fOrientation = 0.0;
	// Set width and length
	fLength = 0.04f;
	fWidth = 0.04f;


}
void _RigidBody::SetData(const Vector &p0,const Vector &p1,const Vector &p2,const Vector &p3,const Vector &p4){

   PiontPostion[0]=p0;
   PiontPostion[1]=p1;
   PiontPostion[2]=p2;
   PiontPostion[3]=p3;
   
 
}