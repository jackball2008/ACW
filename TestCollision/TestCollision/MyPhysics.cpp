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

void MyPhysics::InitializeElement(_RigidBody *body){

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
				
					// Now define the mass properties
		body->fMass = 621.6;
		body->fInertia = 383320;
		body->fInertiaInverse = 1.0f / body->fInertia;


}

void MyPhysics::SetPosititon(){
	//set squares
	//25*4
	_RigidBody square;
	for(int i = 0; i< 4; i ++){
		for( int j =0; j < 25 ; j ++){
		square.vFirstpoint.x= -0.5f + j * 0.04f;
		square.vFirstpoint.y= -0.9f + i * 0.04f;

		square.vSecondpoint.x= square.vFirstpoint.x+0.04f;
		square.vSecondpoint.y= square.vFirstpoint.y;

		square.vThirdpoint.x= square.vSecondpoint.x;
		square.vThirdpoint.y= square.vSecondpoint.y+0.04f;

		square.vFourthpoint.x= square.vFirstpoint.x;
		square.vFourthpoint.y= square.vThirdpoint.y;

		square.vPosition.x= (float)(square.vFirstpoint.x+square.vSecondpoint.x)/2;
		square.vPosition.y= (float)(square.vFirstpoint.y+square.vThirdpoint.y)/2;

		

		}
	}
	//set triangles
	float h = 0.03464101615f;
	_RigidBody triangle;
	for(int i=5; i >0; i--){
		for(int j=0; j<i;j++){
			triangle.vFirstpoint = square.vFourthpoint;

			triangle.vSecondpoint.x = triangle.vFirstpoint.x+0.04f;
			triangle.vSecondpoint.y = triangle.vFirstpoint.y;

			triangle.vThirdpoint.x= triangle.vFirstpoint.x+0.02f;
			triangle.vThirdpoint.y= triangle.vFirstpoint.y+h;

			triangle.vPosition.x= triangle.vThirdpoint.x;
			triangle.vPosition.y= triangle.vThirdpoint.y/3;
		}
	}
}

Vector MyPhysics::VRotate2D( float angle, Vector u)
{
	float	x,y;

	x = u.x * cos(DegreesToRadians(-angle)) + u.y * sin(DegreesToRadians(-angle));
	y = -u.x * sin(DegreesToRadians(-angle)) + u.y * cos(DegreesToRadians(-angle));

	return Vector( x, y, 0);
}