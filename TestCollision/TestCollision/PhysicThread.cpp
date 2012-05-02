#include "PhysicThread.h"
#include <iostream>
using namespace std;

float   fCrN     = COEFFICIENTOFRESTITUTION;				// the coefficient of restitution
float	const	ctolN = COLLISIONTOLERANCE;			// the collision tolerance

int			CountDoN;
float		ImpulseN;
PhysicThread::PhysicThread(void)
{
}


PhysicThread::~PhysicThread(void)
{
}

int PhysicThread::run(){
	thread =GetCurrentThread();

	while(!_terminate){
		Sleep(2);
		if (_shareobject->Acquire())
		{ __try{
			cout<<"1";

		}__finally{
			_shareobject->Release();
		}

		}
		

	}
	return 0;
}

void PhysicThread::ApplyImpulseP(_RigidBody *body1,_RigidBody *body2)
{
	Vector d;
	float r;
	float s;
	Vector v1,v2;
	float  Vrn;
	double j,Vrt;
	// calculate distance
	r= 0.04f;
	d= body1->vPosition-body2->vPosition;
	s =d.Magnitude()-r;

	// get collision normal vector
	d.Normalize();
	vCollisionNormal =d;

	//calculate relative normal velocity:
	v1 = body1->vVelocity;
	v2 = body2->vVelocity;

	vRelativeVelocity =v1 -v2;
	Vrn = vRelativeVelocity*vCollisionNormal;

	// calculate the impulse:
	j = (-(1+fCrN) * (vRelativeVelocity*vCollisionNormal)) /
		((1/body1->fMass + 1/body2->fMass));

	ImpulseN = j;

	// calculate the new velocity after impact
	body1->vVelocity += (j * vCollisionNormal) / body1->fMass;	
	body2->vVelocity -= (j * vCollisionNormal) / body2->fMass;
}

int PhysicThread::CheckforCollision(_RigidBody *body1, _RigidBody *body2){
	float Max_1x,Max_1y,Min_1x,Min_1y,Max_2x,Max_2y,Min_2x,Min_2y,a=0,b=0,c=0,d=0;
	int    retval = 0;
	//body1
	Max_1x=CompareValueMax(CompareValueMax(body1->vFirstpoint.x,body1->vSecondpoint.x),CompareValueMax(body1->vThirdpoint.x,body1->vFourthpoint.x));
	Max_1y=CompareValueMax(CompareValueMax(body1->vFirstpoint.y,body1->vSecondpoint.y),CompareValueMax(body1->vThirdpoint.y,body1->vFourthpoint.y));

	Min_1x=CompareValueMin(CompareValueMax(body1->vFirstpoint.x,body1->vSecondpoint.x),CompareValueMin(body1->vThirdpoint.x,body1->vFourthpoint.x));
	Min_1y=CompareValueMin(CompareValueMax(body1->vFirstpoint.y,body1->vSecondpoint.y),CompareValueMin(body1->vThirdpoint.y,body1->vFourthpoint.y));

	//body2

	Max_2x=CompareValueMax(CompareValueMax(body2->vFirstpoint.x,body2->vSecondpoint.x),CompareValueMax(body2->vThirdpoint.x,body2->vFourthpoint.x));
	Max_2y=CompareValueMax(CompareValueMax(body2->vFirstpoint.y,body2->vSecondpoint.y),CompareValueMax(body2->vThirdpoint.y,body2->vFourthpoint.y));

	Min_2x=CompareValueMin(CompareValueMax(body2->vFirstpoint.x,body2->vSecondpoint.x),CompareValueMin(body2->vThirdpoint.x,body2->vFourthpoint.x));
	Min_2y=CompareValueMin(CompareValueMax(body2->vFirstpoint.y,body2->vSecondpoint.y),CompareValueMin(body2->vThirdpoint.y,body2->vFourthpoint.y));

	// compare projection from x axis
	if (Min_1x<Min_2x)
	{
		a=Min_2x-Max_1x;

	} 
	else
	{
		b=Min_1x-Max_2x;
	}

	//compare projection from y axis
	if (Min_1y<Min_2y)
	{
		c=Min_2y-Max_1y;
	}
	else
	{
		d=Min_1y-Max_2y;
	}


	//test collision
	if ((a<0)&&(c<0))
	{
		return retval=COLLISION;
	} 
	else if ((a<0)&&(d<0))
	{
		return retval=COLLISION;
	} 
	else if((b<0)&&(c<0))
	{
		return retval=COLLISION;
	}
	else if((b<0)&&(d<0)){
		return retval=COLLISION;
	}
	else{
		return retval=NOCOLLISION;
	}
	return retval;
}

void PhysicThread::Updateposition(_RigidBody *body, float dtime){

	Vector Ae,k1;
	float dt = dtime;
	// linear velocity
	Ae = body->vForces/body->fMass;
	k1 = Ae*dt;

	body->vVelocity += k1;

	body->vPosition += body->vVelocity*dt;

	body->vFirstpoint.x= body->vPosition.x-0.02f;
	body->vFirstpoint.y= body->vPosition.y+0.02f;

	body->vSecondpoint.x= body->vPosition.x+0.02f;
	body->vSecondpoint.y= body->vPosition.y+0.02f;

	body->vThirdpoint.x= body->vPosition.x+0.02f;
	body->vThirdpoint.y= body->vPosition.y-0.02f;

	body->vFourthpoint.x= body->vPosition.x-0.02f;
	body->vFourthpoint.y= body->vPosition.y-0.02f;
}