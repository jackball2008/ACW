#include "PhysicThread.h"

float   fCrN     = COEFFICIENTOFRESTITUTION;				// the coefficient of restitution
float	const	ctolN = COLLISIONTOLERANCE;			// the collision tolerance

int			CountDoN;
float		ImpulseN;
PhysicThread::PhysicThread(void)
{

	shapelocked = false;
}


PhysicThread::~PhysicThread(void)
{
}

int PhysicThread::run(){
	thread =GetCurrentThread();
	while(!_terminate){	
		Sleep(2);
		if(_shareobject->Acquire()){
			__try{

   /*    #ifdef _OPENMP
			cout << "OpenMP enabled" << endl;
       #endif*/
			
			StepSimulation();}
			__finally{
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
	float	r, Vrn, s;	
	Vector	D, v1, v2;
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

	//

	// calculate separation:
	r = body1->fLength/2 + body2->fLength/2;
	D = body1->vPosition - body2->vPosition;
	s = D.Magnitude() - r;

	// set collision normal vector:
	D.Normalize();		
	vCollisionNormal = D;

	// calculate relative normal velocity:
	v1 = body1->vVelocity;
	v2 = body2->vVelocity;					
	vRelativeVelocity = v1 - v2;
	Vrn = vRelativeVelocity * vCollisionNormal;

	//test collision
	if ((a<0)&&(c<0)&&(Vrn < 0.0))
	{
		return retval=COLLISION;
	} 
	else if ((a<0)&&(d<0)&&(Vrn < 0.0))
	{
		return retval=COLLISION;
	} 
	else if((b<0)&&(c<0)&&(Vrn < 0.0))
	{
		return retval=COLLISION;
	}
	else if((b<0)&&(d<0)&&(Vrn < 0.0)){
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

void PhysicThread::StepSimulation(){
	int        check = 0;
	int objnum = _shareobject->renderObjects.size();


	for (int i=0;i<objnum;i++)
	{  
		_RigidBody* Rigidsquare1 =_shareobject->renderObjects.at(i);
		for (int j=0; j<objnum;j++)
		{
			_RigidBody *Rigidsquare2 = _shareobject->renderObjects.at(j);
			if (i!=j)
			{
			
			check=CheckforCollision(Rigidsquare1,Rigidsquare2);
			if (check==COLLISION)
			{
				ApplyImpulseP(Rigidsquare1,Rigidsquare2);

			}
			}
		}

		SpringOperation(*Rigidsquare1);
	}

	for (int a=0; a<objnum;a++)
	{
		
		
				Rigidsquare =_shareobject->renderObjects.at(a);
				
				Updateposition(Rigidsquare,0.1);
			
		}
	

	
}

void PhysicThread::PhysicApply(){

}

void PhysicThread::SetPosition(_RigidBody *body){
	/*if (_shareobject->Acquire())
	{__try{

	body =_shareobject->renderObjects.at(i);

	}
	__finally{
	_shareobject->Release();

	}
	}*/

}

void PhysicThread::SpringOperation(_RigidBody &body){

	if(_shareobject->left_hold){
		if(!body.springlocked&&DetectPointInShape(body,_shareobject->springLine->sp.x,_shareobject->springLine->sp.y)&&!shapelocked){

			body.springlocked = true;
			shapelocked = true;

			body.lockspringep_dx= _shareobject->springLine->sp.x-body.vPosition.x;
			body.lockspringep_dy= _shareobject->springLine->sp.y-body.vPosition.y;

		}
		if (body.springlocked&&shapelocked)
		{
			_shareobject->springLine->ep.x=body.vPosition.x+body.lockspringep_dx;
			_shareobject->springLine->ep.y=body.vPosition.y+body.lockspringep_dy;
		}
		else{
			body.lockspringep_dx = 0;
			body.lockspringep_dy= 0;
		}

	}
	else{
		shapelocked = false;
		body.springlocked =false;
		body.lockspringep_dx=0;
		body.lockspringep_dy=0;

		_shareobject->springLine->ep.x = _shareobject->springLine->sp.x;
		_shareobject->springLine->ep.y = _shareobject->springLine->sp.y;


	}

	if (body.springlocked)
	{
		body.g= 0.0f;
	}
	else{
		body.g = 1.0f;
	}

	if (body.springlocked)
	{
		float springlength = _shareobject->springLine->Length();
		if (springlength>0.05)
		{
			float force_all = springlength*SPRING_FACTOR;

			float dx = _shareobject->springLine->sp.x - _shareobject->springLine->ep.x;
			float dy = _shareobject->springLine->sp.y - _shareobject->springLine->ep.y;
			float len = sqrt(dx*dx+dy*dy);
			dx = dx/len;
			dy = dy/len;

			float force_y = force_all*dy;
			float force_x = force_all*dx;

			body.vForces.x=force_x;
			body.vForces.y=force_y;

			Vector Aa,k2;
			Aa=body.vForces/body.fMass;
			float dT;
			dT=0.01f;

			k2=Aa*dT;

			body.vVelocity+=k2;
			body.vPosition+=body.vVelocity*dT;
			body.vFirstpoint.x= body.vPosition.x-0.02f;
			body.vFirstpoint.y= body.vPosition.y+0.02f;

			body.vSecondpoint.x= body.vPosition.x+0.02f;
			body.vSecondpoint.y= body.vPosition.y+0.02f;

			body.vThirdpoint.x= body.vPosition.x+0.02f;
			body.vThirdpoint.y= body.vPosition.y-0.02f;

			body.vFourthpoint.x= body.vPosition.x-0.02f;
			body.vFourthpoint.y= body.vPosition.y-0.02f;

			body.vForces.Clear();
		}

	}

}

bool PhysicThread::DetectPointInShape(const _RigidBody &body,const float&x,const float&y){

	float Max_x,Max_y,Min_x,Min_y;
	Max_x=CompareValueMax(CompareValueMax(body.vFirstpoint.x,body.vSecondpoint.x),CompareValueMax(body.vThirdpoint.x,body.vFourthpoint.x));
	Max_y=CompareValueMax(CompareValueMax(body.vFirstpoint.y,body.vSecondpoint.y),CompareValueMax(body.vThirdpoint.y,body.vFourthpoint.y));

	Min_x=CompareValueMin(CompareValueMax(body.vFirstpoint.x,body.vSecondpoint.x),CompareValueMin(body.vThirdpoint.x,body.vFourthpoint.x));
	Min_y=CompareValueMin(CompareValueMax(body.vFirstpoint.y,body.vSecondpoint.y),CompareValueMin(body.vThirdpoint.y,body.vFourthpoint.y));
	
	if ((x<Max_x)&&(y<Max_y)&&(x>Min_x)&&(y>Min_y))
	{
		return true;
	}
	else{
		return false;
	}
}