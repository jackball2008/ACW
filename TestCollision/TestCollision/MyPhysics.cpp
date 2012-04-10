#include "MyPhysics.h"
#include <memory.h>

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
		body->vVelocity.x = 0.0f;
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
		body->fMass = 1.0f;
		body->fInertia = 383320;
		body->fInertiaInverse = 1.0f / body->fInertia;

		// Set the initial orientation
		body->fOrientation = 0.0;
		// Set width and length
		body->fLength = 0.04f;
		body->fWidth = 0.04f;
}

void MyPhysics::SetPosititon(_RigidBody *body1,_RigidBody *body2){
	_RigidBody *square1,*square2;
	square1=body1;
	square2=body2;

	square1->vPosition.x= -0.5f;
	square1->vPosition.y= -0.9f;

	square1->vFirstpoint.x= square1->vPosition.x-0.02f;
	square1->vFirstpoint.y= square1->vPosition.y+0.02f;

	square1->vSecondpoint.x= square1->vPosition.x+0.02f;
	square1->vSecondpoint.y= square1->vPosition.y+0.02f;

	square1->vThirdpoint.x= square1->vPosition.x+0.02f;
	square1->vThirdpoint.y= square1->vPosition.y-0.02f;

	square1->vFourthpoint.x= square1->vPosition.x-0.02f;
	square1->vFourthpoint.y= square1->vPosition.y-0.02f;




	square2->vPosition.x= -0.45f;
	square2->vPosition.y= -0.9f;

	square2->vFirstpoint.x= square2->vPosition.x-0.02f;
	square2->vFirstpoint.y= square2->vPosition.y+0.02f;

	square2->vSecondpoint.x= square2->vPosition.x+0.02f;
	square2->vSecondpoint.y= square2->vPosition.y+0.02f;

	square2->vThirdpoint.x= square2->vPosition.x+0.02f;
	square2->vThirdpoint.y= square2->vPosition.y-0.02f;

	square2->vFourthpoint.x= square2->vPosition.x-0.02f;
	square2->vFourthpoint.y= square2->vPosition.y-0.02f;




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
			triangle.vFirstpoint.x = -0.34f;
			triangle.vFirstpoint.y = -0.74f;

			triangle.vSecondpoint.x = triangle.vFirstpoint.x+0.04f;
			triangle.vSecondpoint.y = triangle.vFirstpoint.y;

			triangle.vThirdpoint.x= triangle.vFirstpoint.x+0.02f;
			triangle.vThirdpoint.y= triangle.vFirstpoint.y+h;

			triangle.vPosition.x= triangle.vThirdpoint.x;
			triangle.vPosition.y= triangle.vThirdpoint.y/3;
		}
	}
}

void MyPhysics::UpdatePosition(_RigidBody *square1,_RigidBody *square2){




	square1->vFirstpoint.x= square1->vPosition.x-0.02f;
	square1->vFirstpoint.y= square1->vPosition.y+0.02f;

	square1->vSecondpoint.x= square1->vPosition.x+0.02f;
	square1->vSecondpoint.y= square1->vPosition.y+0.02f;

	square1->vThirdpoint.x= square1->vPosition.x+0.02f;
	square1->vThirdpoint.y= square1->vPosition.y-0.02f;

	square1->vFourthpoint.x= square1->vPosition.x-0.02f;
	square1->vFourthpoint.y= square1->vPosition.y-0.02f;






	square2->vFirstpoint.x= square2->vPosition.x-0.02f;
	square2->vFirstpoint.y= square2->vPosition.y+0.02f;

	square2->vSecondpoint.x= square2->vPosition.x+0.02f;
	square2->vSecondpoint.y= square2->vPosition.y+0.02f;

	square2->vThirdpoint.x= square2->vPosition.x+0.02f;
	square2->vThirdpoint.y= square2->vPosition.y-0.02f;

	square2->vFourthpoint.x= square2->vPosition.x-0.02f;
	square2->vFourthpoint.y= square2->vPosition.y-0.02f;

}

void MyPhysics::UpdateBody(_RigidBody *body, float dtime){
	Vector Ae;            //accelerate
	float  Aa;

	Vector k1;

	float  k1a;
	float  dt = dtime;

	Vector test;
	test.x=0.00004f;
	test.y=0.0f;
    
	// linear velocity
	Ae = body->vForces / body->fMass;
	k1 = Ae*dt;

	Aa = body->vMoment.z / body->fInertia;
	k1a = Aa* dt;

	// add the k1 terms to the respective initial velocities
	// vt = vo+at
	body->vVelocity += k1;
	body->vAngularVelocity.z += k1a;

	// update position
	body->vPosition += body->vVelocity*dt;
	/*body->vPosition +=test;*/
	
	// calculate the new orientation
	body->fOrientation += RadiansToDegrees(body->vAngularVelocity.z*dt);
	

}

int MyPhysics::CheckForCollisionSimple(_RigidBody *body1, _RigidBody *body2){

	Vector d;
	float  r;
	int    retval = 0;
	float  s;
	Vector v1,v2;
	float  Vrn;

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

	// test:
	if((fabs(s) <= ctol) && (Vrn < 0.0))
	{
		retval = COLLISION;
		//CollisionBody1 = body1;
		//CollisionBody2 = body2;
	}
	else 	if(s < -ctol) 
	{
		retval = PENETRATING;
	} 
	else 
		retval = NOCOLLISION;

	return retval;


}

int MyPhysics::CheckForCollisionP(_RigidBody *body1, _RigidBody *body2){

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

// vertex-vertex or vertex-edge collisions
int MyPhysics::CheckForCollision(_RigidBody *body1, _RigidBody *body2){
	Vector	d, vList1[4], vList2[4], v1, v2, u, edge, p, proj;
	float	r, wd, lg, s, dist, dot, Vrn;
	int		i, j, retval = 0;
	bool	interpenetrating = false;
	bool	haveNodeEdge = false;	

	// First check to see if the bounding circles are colliding
	r = body1->fLength/2 + body2->fLength/2;
	d = body1->vPosition - body2->vPosition;
	s = d.Magnitude() - r;
	if(s <= ctol)
	{   // We have a possible collision, check further
		// build vertex lists for each hovercraft
		wd = body1->fWidth;
		lg = body1->fLength;
		vList1[0].y = body1->vFirstpoint.y;		vList1[0].x = body1->vFirstpoint.x;
		vList1[1].y = body1->vSecondpoint.y;	vList1[1].x = body1->vSecondpoint.x;
		vList1[2].y = body1->vThirdpoint.y;	    vList1[2].x = body1->vThirdpoint.x;
		vList1[3].y = body1->vFourthpoint.y;	vList1[3].x = body1->vFirstpoint.x;		
		for(i=0; i<4; i++)
		{
			/*v1 = VRotate2D(body1->fOrientation, vList1[i]);*/
			vList1[i] += body1->vPosition;			
		}

		wd = body2->fWidth;
		lg = body2->fLength;
		vList2[0].y = body2->vFirstpoint.y;		vList2[0].x = body2->vFirstpoint.x;
		vList2[1].y = body2->vSecondpoint.y;	vList2[1].x = body2->vSecondpoint.x;
		vList2[2].y = body2->vThirdpoint.y;	    vList2[2].x = body2->vThirdpoint.x;
		vList2[3].y = body2->vFourthpoint.y;	vList2[3].x = body2->vFirstpoint.x;		
		for(i=0; i<4; i++)
		{
			/*v2 = VRotate2D(body2->fOrientation, vList2[i]);*/
			vList2[i] += body2->vPosition;			
		}

		// Check for vertex-edge collision		
		for(i=0; i<4 && !haveNodeEdge; i++)
		{
			for(j=0; j<4 && !haveNodeEdge; j++)
			{							
				if(j==3)
					edge = vList2[j/*0*/] - vList2[0/*j*/];
				else
					edge = vList2[j+1] - vList2[j];				
				u = edge;
				u.Normalize();

				p = vList1[i] - vList2[j];					
				proj = (p * u) * u;

				d = p^u;					
				dist = d.Magnitude();

				dot = p * edge;
				if(dot > 0)
					dist = -dist; // point is on inside

				vCollisionPoint = vList1[i];
				body1->vCollisionPoint = vCollisionPoint - body1->vPosition;
				body2->vCollisionPoint = vCollisionPoint - body2->vPosition;


				vCollisionNormal = ((u^p)^u);
				vCollisionNormal.Normalize();

				v1 = body1->vVelocity + (body1->vAngularVelocity^body1->vCollisionPoint);
				v2 = body2->vVelocity + (body2->vAngularVelocity^body2->vCollisionPoint);


				vRelativeVelocity = (v1 - v2);
				Vrn = vRelativeVelocity * vCollisionNormal;

				vCollisionTangent = (vCollisionNormal^vRelativeVelocity)^vCollisionNormal;
				vCollisionTangent.Normalize();

				if( (proj.Magnitude() > tol) && 
					(proj.Magnitude() <= edge.Magnitude()) && 
					(dist <= ctol) && 
					(Vrn < 0.0f)						
					)
				{
					haveNodeEdge = true;
					CollisionBody1 = body1;
					CollisionBody2 = body2;

				}
			}
		}			

		for(i=0; i<4 && !haveNodeEdge; i++)
		{
			for(j=0; j<4 && !haveNodeEdge; j++)
			{							
				if(j==3)
					edge = vList1[j/*0*/] - vList1[0/*j*/];
				else
					edge = vList1[j+1] - vList1[j];				
				u = edge;
				u.Normalize();

				p = vList2[i] - vList1[j];					
				proj = (p * u) * u;

				d = p^u;					
				dist = d.Magnitude();

				dot = p * edge;
				if(dot > 0)
					dist = -dist; // point is on inside

				vCollisionPoint = vList2[i];
				body1->vCollisionPoint = vCollisionPoint - body1->vPosition;
				body2->vCollisionPoint = vCollisionPoint - body2->vPosition;


				vCollisionNormal = ((u^p)^u);
				vCollisionNormal.Normalize();

				v1 = body1->vVelocity + (body1->vAngularVelocity^body1->vCollisionPoint);
				v2 = body2->vVelocity + (body2->vAngularVelocity^body2->vCollisionPoint);


				vRelativeVelocity = (v1 - v2);
				Vrn = vRelativeVelocity * vCollisionNormal;

				vCollisionTangent = (vCollisionNormal^vRelativeVelocity)^vCollisionNormal;
				vCollisionTangent.Normalize();

				if( (proj.Magnitude() > tol) && 
					(proj.Magnitude() <= edge.Magnitude()) && 
					(dist <= ctol) && 
					(Vrn < 0.0f)						
					)
				{
					haveNodeEdge = true;
					CollisionBody1 = body2;
					CollisionBody2 = body1;
				}
			}
		}		
		if(!haveNodeEdge)
		{
			for(i=0; i<4 && !interpenetrating; i++)
			{
				if(pnpoly(4, vList2, vList1[i]) == 1)
					interpenetrating = true;

				if(pnpoly(4, vList1, vList2[i]) == 1)
					interpenetrating = true;
			}
		}
		

		if(interpenetrating)
			retval = PENETRATING;					
		else if(haveNodeEdge)
			retval = COLLISION;
		else
			retval = NOCOLLISION;		

	} else
	{
		retval = NOCOLLISION;	
	}

	return retval;

}

void MyPhysics::ApplyImpulse(_RigidBody *body1,_RigidBody *body2){
	
	double j,Vrt;
	double mu = FRICTIONCOEFFICIENT;
	Vector n;

	// calculate the impulse:
	j = (-(1+fCr) * (vRelativeVelocity*vCollisionNormal)) /
		((1/body1->fMass + 1/body2->fMass));

	Impulse = j;

	// calculate the new velocity after impact
	body1->vVelocity += (j * vCollisionNormal) / body1->fMass;	
	body2->vVelocity -= (j * vCollisionNormal) / body2->fMass;	
}

void MyPhysics::ApplyImpulseP(_RigidBody *body1,_RigidBody *body2){

	Vector d;
	float  r;
	int    retval = 0;
	float  s;
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
	j = (-(1+fCr) * (vRelativeVelocity*vCollisionNormal)) /
		((1/body1->fMass + 1/body2->fMass));

	Impulse = j;

	// calculate the new velocity after impact
	body1->vVelocity += (j * vCollisionNormal) / body1->fMass;	
	body2->vVelocity -= (j * vCollisionNormal) / body2->fMass;
}


Vector MyPhysics::VRotate2D( float angle, Vector u)
{
	float	x,y;

	x = u.x * cos(DegreesToRadians(-angle)) + u.y * sin(DegreesToRadians(-angle));
	y = -u.x * sin(DegreesToRadians(-angle)) + u.y * cos(DegreesToRadians(-angle));

	return Vector( x, y, 0);
}

void MyPhysics::StepSimulation(float dt,_RigidBody *rigidcopy1,_RigidBody *rigidcopy2){

	float      dtime = dt;
	bool       tryAgain = true;
	int        check = 0;


	//while(tryAgain&& (dtime>tol))
	//{
	//tryAgain = false;
		
	UpdateBody(rigidcopy1,dtime);
	UpdateBody(rigidcopy2,dtime);

	UpdatePosition(rigidcopy1,rigidcopy2);


		CollisionBody1 = 0;
		CollisionBody2 = 0;
		check = CheckForCollisionP(rigidcopy1,rigidcopy2);

		//if (check == PENETRATING)
		//{					
		//	dtime = dtime/2;
		//    tryAgain = true;
		//

		//} 
		//else 
		if(check == COLLISION)
		{

			ApplyImpulseP(rigidcopy1, rigidcopy2);
		}
	/*}*/



}

void MyPhysics::Initialize(void){
	
	 
	 InitializeElement(&_rigidbody1);
	 InitializeElement(&_rigidbody2);
	 _rigidbody1.vVelocity.x=0.2f;
	 /*_rigidbody1.vVelocity.y=0.2f;*/
	 SetPosititon(&_rigidbody1,&_rigidbody2);

}

int	MyPhysics::pnpoly(int	npol, Vector *vlist, Vector p)
{
	int	i, j, c = 0;

	for (i = 0, j = npol-1; i<npol; j = i++) {
		if ((((vlist[i].y<=p.y) && (p.y<vlist[j].y)) ||
			((vlist[j].y<=p.y) && (p.y<vlist[i].y))) &&
			(p.x < (vlist[j].x - vlist[i].x) * (p.y - vlist[i].y) / (vlist[j].y - vlist[i].y) + vlist[i].x))

			c = !c;
	}
	return c;
}