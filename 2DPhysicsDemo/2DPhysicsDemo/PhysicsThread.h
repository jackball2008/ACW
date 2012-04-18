#pragma once
#include "mythread.h"
#include <iostream>
#include <math.h>
#include "ShapeShareObject.h"
using namespace std;
#include <Windows.h>
#include "Force.h"
#include "Point.h"

const float SPRING_FACTOR = 2.5f/1000;
const YPoint ORIGIN_P_PHYSICS;
const float G_ACCERLATION = -1.8f/10000000000;
const float GROUND_Y = -0.9f;

const float skin = 0.000001f;

class PhysicsThread :
	public MyThread
{
private:
	ShapeShareObject* _shapeShareObject;

	/*vec2f ORIGIN_P_PHYSICS;*/

	YPoint measureP;

	//ms
	float _delta_time;

	LARGE_INTEGER _ticksPerSecond, _consumedCount, _currentCount, _lastCount;
	DWORD procMask, sysMask;

	HANDLE thread;

	//Force
	Force _springforce;

	//functions
	void CalculateDeltaTime();

	void CalculatePyhsics5();

	void CheckHitGround(Shape* p);
	void CheckCollision(Shape* A, Shape* B);
	void Rotate(const float&x, const float&y, const float&sinv, const float&cosv, const bool&reserve , YPoint&p);

	/*bool DectecHit(const Shape&s1, const Shape&s2);*/

	YPoint _springforceworkposition;

	bool _isspringforcegenerated;



public:
	PhysicsThread(void);
	~PhysicsThread(void);

	void SetShapeShareObject(ShapeShareObject* p){ _shapeShareObject = p; };

	static float Dis(const YPoint& p1, const YPoint& p2){
		return sqrt((p1.x - p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
	};

	

	int run();

	/**
	void ApplyImpulseP(_RigidBody *body1,_RigidBody *body2){

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
	*/

	static bool JudgeBrightA(const Shape &shapeA, const Shape &shapeB)
	{
		float Max_1x,Max_1y,Min_1x,Min_1y,Max_2x,Max_2y,Min_2x,Min_2y,a=0,b=0,c=0,d=0;
		int body1size = shapeA.points.size();
		int body2size = shapeB.points.size();

		if(body1size == 2)
		{
			Max_1x=max(shapeA.points.at(0).x,shapeA.points.at(1).x);
			Max_1y=max(shapeA.points.at(0).y,shapeA.points.at(1).y);

			Min_1x=min(shapeA.points.at(0).x,shapeA.points.at(1).x);
			Min_1y=min(shapeA.points.at(0).y,shapeA.points.at(1).y);
		}
		if(body1size == 3)
		{
			Max_1x=max(max(shapeA.points.at(0).x,shapeA.points.at(1).x),shapeA.points.at(2).x);
			Max_1y=max(max(shapeA.points.at(0).y,shapeA.points.at(1).y),shapeA.points.at(2).y);

			Min_1x=min(min(shapeA.points.at(0).x,shapeA.points.at(1).x),shapeA.points.at(2).x);
			Min_1y=min(min(shapeA.points.at(0).y,shapeA.points.at(1).y),shapeA.points.at(2).y);
		}
		if(body1size == 4)
		{
			Max_1x=max(max(shapeA.points.at(0).x,shapeA.points.at(1).x),max(shapeA.points.at(2).x,shapeA.points.at(3).x));
			Max_1y=max(max(shapeA.points.at(0).y,shapeA.points.at(1).y),max(shapeA.points.at(2).y,shapeA.points.at(3).y));

			Min_1x=min(min(shapeA.points.at(0).x,shapeA.points.at(1).x),min(shapeA.points.at(2).x,shapeA.points.at(3).x));
			Min_1y=min(min(shapeA.points.at(0).y,shapeA.points.at(1).y),min(shapeA.points.at(2).y,shapeA.points.at(3).y));
		}

		if(body2size == 2)
		{
			Max_2x=max(shapeB.points.at(0).x,shapeB.points.at(1).x);
			Max_2y=max(shapeB.points.at(0).y,shapeB.points.at(1).y);

			Min_2x=min(shapeB.points.at(0).x,shapeB.points.at(1).x);
			Min_2y=min(shapeB.points.at(0).y,shapeB.points.at(1).y);
		}
		if(body2size == 3)
		{
			Max_2x=max(max(shapeB.points.at(0).x,shapeB.points.at(1).x),shapeB.points.at(2).x);
			Max_2y=max(max(shapeB.points.at(0).y,shapeB.points.at(1).y),shapeB.points.at(2).y);

			Min_2x=min(min(shapeB.points.at(0).x,shapeB.points.at(1).x),shapeB.points.at(2).x);
			Min_2y=min(min(shapeB.points.at(0).y,shapeB.points.at(1).y),shapeB.points.at(2).y);
		}
		if(body2size == 4)
		{
			Max_2x=max(max(shapeB.points.at(0).x,shapeB.points.at(1).x),max(shapeB.points.at(2).x,shapeB.points.at(3).x));
			Max_2y=max(max(shapeB.points.at(0).y,shapeB.points.at(1).y),max(shapeB.points.at(2).y,shapeB.points.at(3).y));

			Min_2x=min(min(shapeB.points.at(0).x,shapeB.points.at(1).x),min(shapeB.points.at(2).x,shapeB.points.at(3).x));
			Min_2y=min(min(shapeB.points.at(0).y,shapeB.points.at(1).y),min(shapeB.points.at(2).y,shapeB.points.at(3).y));
		}

		if(shapeB.middlepoint.x > Max_1x && Max_2y>Min_1y)
			return true;
		return false;

	}
	static bool JudgeBleftA(const Shape &shapeA, const Shape &shapeB)
	{
		float Max_1x,Max_1y,Min_1x,Min_1y,Max_2x,Max_2y,Min_2x,Min_2y,a=0,b=0,c=0,d=0;
		int body1size = shapeA.points.size();
		int body2size = shapeB.points.size();

		if(body1size == 2)
		{
			Max_1x=max(shapeA.points.at(0).x,shapeA.points.at(1).x);
			Max_1y=max(shapeA.points.at(0).y,shapeA.points.at(1).y);

			Min_1x=min(shapeA.points.at(0).x,shapeA.points.at(1).x);
			Min_1y=min(shapeA.points.at(0).y,shapeA.points.at(1).y);
		}
		if(body1size == 3)
		{
			Max_1x=max(max(shapeA.points.at(0).x,shapeA.points.at(1).x),shapeA.points.at(2).x);
			Max_1y=max(max(shapeA.points.at(0).y,shapeA.points.at(1).y),shapeA.points.at(2).y);

			Min_1x=min(min(shapeA.points.at(0).x,shapeA.points.at(1).x),shapeA.points.at(2).x);
			Min_1y=min(min(shapeA.points.at(0).y,shapeA.points.at(1).y),shapeA.points.at(2).y);
		}
		if(body1size == 4)
		{
			Max_1x=max(max(shapeA.points.at(0).x,shapeA.points.at(1).x),max(shapeA.points.at(2).x,shapeA.points.at(3).x));
			Max_1y=max(max(shapeA.points.at(0).y,shapeA.points.at(1).y),max(shapeA.points.at(2).y,shapeA.points.at(3).y));

			Min_1x=min(min(shapeA.points.at(0).x,shapeA.points.at(1).x),min(shapeA.points.at(2).x,shapeA.points.at(3).x));
			Min_1y=min(min(shapeA.points.at(0).y,shapeA.points.at(1).y),min(shapeA.points.at(2).y,shapeA.points.at(3).y));
		}

		if(body2size == 2)
		{
			Max_2x=max(shapeB.points.at(0).x,shapeB.points.at(1).x);
			Max_2y=max(shapeB.points.at(0).y,shapeB.points.at(1).y);

			Min_2x=min(shapeB.points.at(0).x,shapeB.points.at(1).x);
			Min_2y=min(shapeB.points.at(0).y,shapeB.points.at(1).y);
		}
		if(body2size == 3)
		{
			Max_2x=max(max(shapeB.points.at(0).x,shapeB.points.at(1).x),shapeB.points.at(2).x);
			Max_2y=max(max(shapeB.points.at(0).y,shapeB.points.at(1).y),shapeB.points.at(2).y);

			Min_2x=min(min(shapeB.points.at(0).x,shapeB.points.at(1).x),shapeB.points.at(2).x);
			Min_2y=min(min(shapeB.points.at(0).y,shapeB.points.at(1).y),shapeB.points.at(2).y);
		}
		if(body2size == 4)
		{
			Max_2x=max(max(shapeB.points.at(0).x,shapeB.points.at(1).x),max(shapeB.points.at(2).x,shapeB.points.at(3).x));
			Max_2y=max(max(shapeB.points.at(0).y,shapeB.points.at(1).y),max(shapeB.points.at(2).y,shapeB.points.at(3).y));

			Min_2x=min(min(shapeB.points.at(0).x,shapeB.points.at(1).x),min(shapeB.points.at(2).x,shapeB.points.at(3).x));
			Min_2y=min(min(shapeB.points.at(0).y,shapeB.points.at(1).y),min(shapeB.points.at(2).y,shapeB.points.at(3).y));
		}

		if(shapeB.middlepoint.x< Min_1x && Max_2y>Min_1y)
			return true;
		return false;

	}
	static bool JudgeBunderA(const Shape &shapeA, const Shape &shapeB)
	{
		float Max_1x,Max_1y,Min_1x,Min_1y,Max_2x,Max_2y,Min_2x,Min_2y,a=0,b=0,c=0,d=0;
		int body1size = shapeA.points.size();
		int body2size = shapeB.points.size();

		if(body1size == 2)
		{
			Max_1x=max(shapeA.points.at(0).x,shapeA.points.at(1).x);
			Max_1y=max(shapeA.points.at(0).y,shapeA.points.at(1).y);

			Min_1x=min(shapeA.points.at(0).x,shapeA.points.at(1).x);
			Min_1y=min(shapeA.points.at(0).y,shapeA.points.at(1).y);
		}
		if(body1size == 3)
		{
			Max_1x=max(max(shapeA.points.at(0).x,shapeA.points.at(1).x),shapeA.points.at(2).x);
			Max_1y=max(max(shapeA.points.at(0).y,shapeA.points.at(1).y),shapeA.points.at(2).y);

			Min_1x=min(min(shapeA.points.at(0).x,shapeA.points.at(1).x),shapeA.points.at(2).x);
			Min_1y=min(min(shapeA.points.at(0).y,shapeA.points.at(1).y),shapeA.points.at(2).y);
		}
		if(body1size == 4)
		{
			Max_1x=max(max(shapeA.points.at(0).x,shapeA.points.at(1).x),max(shapeA.points.at(2).x,shapeA.points.at(3).x));
			Max_1y=max(max(shapeA.points.at(0).y,shapeA.points.at(1).y),max(shapeA.points.at(2).y,shapeA.points.at(3).y));

			Min_1x=min(min(shapeA.points.at(0).x,shapeA.points.at(1).x),min(shapeA.points.at(2).x,shapeA.points.at(3).x));
			Min_1y=min(min(shapeA.points.at(0).y,shapeA.points.at(1).y),min(shapeA.points.at(2).y,shapeA.points.at(3).y));
		}

		if(body2size == 2)
		{
			Max_2x=max(shapeB.points.at(0).x,shapeB.points.at(1).x);
			Max_2y=max(shapeB.points.at(0).y,shapeB.points.at(1).y);

			Min_2x=min(shapeB.points.at(0).x,shapeB.points.at(1).x);
			Min_2y=min(shapeB.points.at(0).y,shapeB.points.at(1).y);
		}
		if(body2size == 3)
		{
			Max_2x=max(max(shapeB.points.at(0).x,shapeB.points.at(1).x),shapeB.points.at(2).x);
			Max_2y=max(max(shapeB.points.at(0).y,shapeB.points.at(1).y),shapeB.points.at(2).y);

			Min_2x=min(min(shapeB.points.at(0).x,shapeB.points.at(1).x),shapeB.points.at(2).x);
			Min_2y=min(min(shapeB.points.at(0).y,shapeB.points.at(1).y),shapeB.points.at(2).y);
		}
		if(body2size == 4)
		{
			Max_2x=max(max(shapeB.points.at(0).x,shapeB.points.at(1).x),max(shapeB.points.at(2).x,shapeB.points.at(3).x));
			Max_2y=max(max(shapeB.points.at(0).y,shapeB.points.at(1).y),max(shapeB.points.at(2).y,shapeB.points.at(3).y));

			Min_2x=min(min(shapeB.points.at(0).x,shapeB.points.at(1).x),min(shapeB.points.at(2).x,shapeB.points.at(3).x));
			Min_2y=min(min(shapeB.points.at(0).y,shapeB.points.at(1).y),min(shapeB.points.at(2).y,shapeB.points.at(3).y));
		}


		if(shapeB.middlepoint.x>= Min_1x && shapeB.middlepoint.x<=Max_1x && shapeB.middlepoint.y < Min_1y)
			return true;
		return false;


	}
	
	static bool ProjectGroundCollisionDetect(const Shape &body1, const Shape &body2)
	{
		float Max_1x,Max_1y,Min_1x,Min_1y,Max_2x,Max_2y,Min_2x,Min_2y,a=0,b=0,c=0,d=0;
		/*int    retval = 0;*/
		//body1
		int body1size = body1.points.size();
		int body2size = body2.points.size();



		if(body1size == 2)
		{
			Max_1x=max(body1.points.at(0).x,body1.points.at(1).x);
			Max_1y=max(body1.points.at(0).y,body1.points.at(1).y);

			Min_1x=min(body1.points.at(0).x,body1.points.at(1).x);
			Min_1y=min(body1.points.at(0).y,body1.points.at(1).y);
		}
		if(body1size == 3)
		{
			Max_1x=max(max(body1.points.at(0).x,body1.points.at(1).x),body1.points.at(2).x);
			Max_1y=max(max(body1.points.at(0).y,body1.points.at(1).y),body1.points.at(2).y);

			Min_1x=min(min(body1.points.at(0).x,body1.points.at(1).x),body1.points.at(2).x);
			Min_1y=min(min(body1.points.at(0).y,body1.points.at(1).y),body1.points.at(2).y);
		}
		if(body1size == 4)
		{
			Max_1x=max(max(body1.points.at(0).x,body1.points.at(1).x),max(body1.points.at(2).x,body1.points.at(3).x));
			Max_1y=max(max(body1.points.at(0).y,body1.points.at(1).y),max(body1.points.at(2).y,body1.points.at(3).y));

			Min_1x=min(min(body1.points.at(0).x,body1.points.at(1).x),min(body1.points.at(2).x,body1.points.at(3).x));
			Min_1y=min(min(body1.points.at(0).y,body1.points.at(1).y),min(body1.points.at(2).y,body1.points.at(3).y));
		}

		if(body2size == 2)
		{
			Max_2x=max(body2.points.at(0).x,body2.points.at(1).x);
			Max_2y=max(body2.points.at(0).y,body2.points.at(1).y);

			Min_2x=min(body2.points.at(0).x,body2.points.at(1).x);
			Min_2y=min(body2.points.at(0).y,body2.points.at(1).y);
		}
		if(body2size == 3)
		{
			Max_2x=max(max(body2.points.at(0).x,body2.points.at(1).x),body2.points.at(2).x);
			Max_2y=max(max(body2.points.at(0).y,body2.points.at(1).y),body2.points.at(2).y);

			Min_2x=min(min(body2.points.at(0).x,body2.points.at(1).x),body2.points.at(2).x);
			Min_2y=min(min(body2.points.at(0).y,body2.points.at(1).y),body2.points.at(2).y);
		}
		if(body2size == 4)
		{
			Max_2x=max(max(body2.points.at(0).x,body2.points.at(1).x),max(body2.points.at(2).x,body2.points.at(3).x));
			Max_2y=max(max(body2.points.at(0).y,body2.points.at(1).y),max(body2.points.at(2).y,body2.points.at(3).y));

			Min_2x=min(min(body2.points.at(0).x,body2.points.at(1).x),min(body2.points.at(2).x,body2.points.at(3).x));
			Min_2y=min(min(body2.points.at(0).y,body2.points.at(1).y),min(body2.points.at(2).y,body2.points.at(3).y));
		}


		if(Min_1y <= Max_2y || Min_1y <= Min_2y)
			return true;
		else
			return false;

	
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
		bool res;
		if ((a<0)&&(c<=0))
		{
			/*return true;*/
			res = true;
		} 
		else if ((a<0)&&(d<=0))
		{
			/*return true;*/
			res = true;
		} 
		else if((b<0)&&(c<=0))
		{
			/*return true;*/
			res = true;
		}
		else if((b<0)&&(d<=0)){
			/*return true;*/
			res = true;
		}
		else{
			/*return false;*/
			res = false;
		}
		return res;
	}
	static bool ProjectCollisionDetect2(const Shape &body1, const Shape &body2){

		float Max_1x,Max_1y,Min_1x,Min_1y,Max_2x,Max_2y,Min_2x,Min_2y,a=0,b=0,c=0,d=0;
		/*int    retval = 0;*/
		//body1
		int body1size = body1.points.size();
		int body2size = body2.points.size();



		if(body1size == 2)
		{
			Max_1x=max(body1.points.at(0).x,body1.points.at(1).x);
			Max_1y=max(body1.points.at(0).y,body1.points.at(1).y);

			Min_1x=min(body1.points.at(0).x,body1.points.at(1).x);
			Min_1y=min(body1.points.at(0).y,body1.points.at(1).y);
		}
		if(body1size == 3)
		{
			Max_1x=max(max(body1.points.at(0).x,body1.points.at(1).x),body1.points.at(2).x);
			Max_1y=max(max(body1.points.at(0).y,body1.points.at(1).y),body1.points.at(2).y);

			Min_1x=min(min(body1.points.at(0).x,body1.points.at(1).x),body1.points.at(2).x);
			Min_1y=min(min(body1.points.at(0).y,body1.points.at(1).y),body1.points.at(2).y);
		}
		if(body1size == 4)
		{
			Max_1x=max(max(body1.points.at(0).x,body1.points.at(1).x),max(body1.points.at(2).x,body1.points.at(3).x));
			Max_1y=max(max(body1.points.at(0).y,body1.points.at(1).y),max(body1.points.at(2).y,body1.points.at(3).y));

			Min_1x=min(min(body1.points.at(0).x,body1.points.at(1).x),min(body1.points.at(2).x,body1.points.at(3).x));
			Min_1y=min(min(body1.points.at(0).y,body1.points.at(1).y),min(body1.points.at(2).y,body1.points.at(3).y));
		}

		if(body2size == 2)
		{
			Max_2x=max(body2.points.at(0).x,body2.points.at(1).x);
			Max_2y=max(body2.points.at(0).y,body2.points.at(1).y);

			Min_2x=min(body2.points.at(0).x,body2.points.at(1).x);
			Min_2y=min(body2.points.at(0).y,body2.points.at(1).y);
		}
		if(body2size == 3)
		{
			Max_2x=max(max(body2.points.at(0).x,body2.points.at(1).x),body2.points.at(2).x);
			Max_2y=max(max(body2.points.at(0).y,body2.points.at(1).y),body2.points.at(2).y);

			Min_2x=min(min(body2.points.at(0).x,body2.points.at(1).x),body2.points.at(2).x);
			Min_2y=min(min(body2.points.at(0).y,body2.points.at(1).y),body2.points.at(2).y);
		}
		if(body2size == 4)
		{
			Max_2x=max(max(body2.points.at(0).x,body2.points.at(1).x),max(body2.points.at(2).x,body2.points.at(3).x));
			Max_2y=max(max(body2.points.at(0).y,body2.points.at(1).y),max(body2.points.at(2).y,body2.points.at(3).y));

			Min_2x=min(min(body2.points.at(0).x,body2.points.at(1).x),min(body2.points.at(2).x,body2.points.at(3).x));
			Min_2y=min(min(body2.points.at(0).y,body2.points.at(1).y),min(body2.points.at(2).y,body2.points.at(3).y));
		}
		//Max_1x Max_1y Min_1x  Min_1y
		//Max_2x  Max_2y Min_2x  Min_2y
		
		Max_1x = Max_1x + skin;
		Max_1y = Max_1y + skin;
		Min_1x = Min_1x - skin;
		Min_1y = Min_1y - skin;
		Max_2x = Max_2x + skin;
		Max_2y = Max_2y + skin;
		Min_2x = Min_2x - skin;
		Min_2y = Min_2y - skin;

		

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
		/*bool res;*/
		if ((a<0)&&(c<0))
		{
			return true;
			/*res = true;*/
		} 
		else if ((a<0)&&(d<0))
		{
			return true;
			/*res = true;*/
		} 
		else if((b<0)&&(c<0))
		{
			return true;
			/*res = true;*/
		}
		else if((b<0)&&(d<0)){
			return true;
			/*res = true;*/
		}
		else{
			return false;
			/*res = false;*/
		}
		/*return res;*/
		return false;
	}
	static bool ProjectCollisionDetect(const Shape &body1, const Shape &body2){

		float Max_1x,Max_1y,Min_1x,Min_1y,Max_2x,Max_2y,Min_2x,Min_2y,a=0,b=0,c=0,d=0;
		/*int    retval = 0;*/
		//body1
		int body1size = body1.points.size();
		int body2size = body2.points.size();



		if(body1size == 2)
		{
			Max_1x=max(body1.points.at(0).x,body1.points.at(1).x);
			Max_1y=max(body1.points.at(0).y,body1.points.at(1).y);

			Min_1x=min(body1.points.at(0).x,body1.points.at(1).x);
			Min_1y=min(body1.points.at(0).y,body1.points.at(1).y);
		}
		if(body1size == 3)
		{
			Max_1x=max(max(body1.points.at(0).x,body1.points.at(1).x),body1.points.at(2).x);
			Max_1y=max(max(body1.points.at(0).y,body1.points.at(1).y),body1.points.at(2).y);

			Min_1x=min(min(body1.points.at(0).x,body1.points.at(1).x),body1.points.at(2).x);
			Min_1y=min(min(body1.points.at(0).y,body1.points.at(1).y),body1.points.at(2).y);
		}
		if(body1size == 4)
		{
			Max_1x=max(max(body1.points.at(0).x,body1.points.at(1).x),max(body1.points.at(2).x,body1.points.at(3).x));
			Max_1y=max(max(body1.points.at(0).y,body1.points.at(1).y),max(body1.points.at(2).y,body1.points.at(3).y));

			Min_1x=min(min(body1.points.at(0).x,body1.points.at(1).x),min(body1.points.at(2).x,body1.points.at(3).x));
			Min_1y=min(min(body1.points.at(0).y,body1.points.at(1).y),min(body1.points.at(2).y,body1.points.at(3).y));
		}

		if(body2size == 2)
		{
			Max_2x=max(body2.points.at(0).x,body2.points.at(1).x);
			Max_2y=max(body2.points.at(0).y,body2.points.at(1).y);

			Min_2x=min(body2.points.at(0).x,body2.points.at(1).x);
			Min_2y=min(body2.points.at(0).y,body2.points.at(1).y);
		}
		if(body2size == 3)
		{
			Max_2x=max(max(body2.points.at(0).x,body2.points.at(1).x),body2.points.at(2).x);
			Max_2y=max(max(body2.points.at(0).y,body2.points.at(1).y),body2.points.at(2).y);

			Min_2x=min(min(body2.points.at(0).x,body2.points.at(1).x),body2.points.at(2).x);
			Min_2y=min(min(body2.points.at(0).y,body2.points.at(1).y),body2.points.at(2).y);
		}
		if(body2size == 4)
		{
			Max_2x=max(max(body2.points.at(0).x,body2.points.at(1).x),max(body2.points.at(2).x,body2.points.at(3).x));
			Max_2y=max(max(body2.points.at(0).y,body2.points.at(1).y),max(body2.points.at(2).y,body2.points.at(3).y));

			Min_2x=min(min(body2.points.at(0).x,body2.points.at(1).x),min(body2.points.at(2).x,body2.points.at(3).x));
			Min_2y=min(min(body2.points.at(0).y,body2.points.at(1).y),min(body2.points.at(2).y,body2.points.at(3).y));
		}


// 		Max_1x=CompareValueMax(CompareValueMax(body1->vFirstpoint.x,body1->vSecondpoint.x),CompareValueMax(body1->vThirdpoint.x,body1->vFourthpoint.x));
// 		Max_1y=CompareValueMax(CompareValueMax(body1->vFirstpoint.y,body1->vSecondpoint.y),CompareValueMax(body1->vThirdpoint.y,body1->vFourthpoint.y));
// 
// 		Min_1x=CompareValueMin(CompareValueMax(body1->vFirstpoint.x,body1->vSecondpoint.x),CompareValueMin(body1->vThirdpoint.x,body1->vFourthpoint.x));
// 		Min_1y=CompareValueMin(CompareValueMax(body1->vFirstpoint.y,body1->vSecondpoint.y),CompareValueMin(body1->vThirdpoint.y,body1->vFourthpoint.y));
// 
// 		//body2
// 
// 		Max_2x=CompareValueMax(CompareValueMax(body2->vFirstpoint.x,body2->vSecondpoint.x),CompareValueMax(body2->vThirdpoint.x,body2->vFourthpoint.x));
// 		Max_2y=CompareValueMax(CompareValueMax(body2->vFirstpoint.y,body2->vSecondpoint.y),CompareValueMax(body2->vThirdpoint.y,body2->vFourthpoint.y));
// 
// 		Min_2x=CompareValueMin(CompareValueMax(body2->vFirstpoint.x,body2->vSecondpoint.x),CompareValueMin(body2->vThirdpoint.x,body2->vFourthpoint.x));
// 		Min_2y=CompareValueMin(CompareValueMax(body2->vFirstpoint.y,body2->vSecondpoint.y),CompareValueMin(body2->vThirdpoint.y,body2->vFourthpoint.y));

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
		bool res;
		if ((a<0)&&(c<0))
		{
			/*return true;*/
			res = true;
		} 
		else if ((a<0)&&(d<0))
		{
			/*return true;*/
			res = true;
		} 
		else if((b<0)&&(c<0))
		{
			/*return true;*/
			res = true;
		}
		else if((b<0)&&(d<0)){
			/*return true;*/
			res = true;
		}
		else{
			/*return false;*/
			res = false;
		}
		return res;
	}
	//////////////////////////////////////////////////////////////////////////
	static bool JudgePointInTriangle(const vector<YPoint>& pa,const YPoint& mp,const YPoint& ori){
		int numofacroess = 0;
		if(JudgeTwoLineAcroess(ori,mp,pa.at(0),pa.at(1)))
			numofacroess++;
		if(JudgeTwoLineAcroess(ori,mp,pa.at(1),pa.at(2)))
			numofacroess++;
		if(JudgeTwoLineAcroess(ori,mp,pa.at(2),pa.at(0)))
			numofacroess++;
		if(!(numofacroess%2==0))
			return true;
		else
			return false;
	}

	static bool JudgePointInPologon(const vector<YPoint>& pa,const YPoint& mp,const YPoint& ori){
		int numofacroess = 0;
		int nsize = pa.size();
		for(int i=0; i<nsize;i++){
			if((i+1)<nsize){
				if(JudgeTwoLineAcroess(ori,mp,pa.at(i),pa.at(i+1)))
					numofacroess++;
			}else{
				if(JudgeTwoLineAcroess(ori,mp,pa.at(i),pa.at(0)))
					numofacroess++;
			}
		}
		if(!(numofacroess%2==0))
			return true;
		else
			return false;
	}

	static bool JudgeTwoLineAcroess(const YPoint&L1p1, const YPoint&L1p2,const YPoint&L2p1, const YPoint&L2p2){
		float v1 = (L1p2.x - L1p1.x)*(L2p2.y-L1p1.y) - (L1p2.y-L1p1.y)*(L2p2.x-L1p1.x);
		float v2 = (L1p2.x-L1p1.x)*(L2p1.y-L1p1.y)-(L1p2.y-L1p1.y)*(L2p1.x-L1p1.x);
		if(v1*v2 >= 0) { 
			return false; 
		}
		float v3 = (L2p2.x-L2p1.x)*(L1p2.y-L2p1.y)-(L2p2.y-L2p1.y)*(L1p2.x-L2p1.x);
		float v4 = (L2p2.x-L2p1.x)*(L1p1.y-L2p1.y)-(L2p2.y-L2p1.y)*(L1p1.x-L2p1.x);
		if(v3*v4 >= 0) { 
			return false; 
		} 
		return true; 
	}

	static bool JudgePointInSquare(const vector<YPoint>& pa,const YPoint& mp,const YPoint& ori){
		int numofacroess = 0;

		if( 
			JudgeTwoLineAcroess(ori,mp,pa.at(0),pa.at(1))
			)
			numofacroess++;
		if( 
			JudgeTwoLineAcroess(ori,mp,pa.at(1),pa.at(2))
			)
			numofacroess++;
		if( 
			JudgeTwoLineAcroess(ori,mp,pa.at(2),pa.at(3))
			)
			numofacroess++;
		if( 
			JudgeTwoLineAcroess(ori,mp,pa.at(3),pa.at(0))
			)
			numofacroess++;


		if(!(numofacroess%2==0))
			return true;
		else
			return false;

	}


	static bool JudgePolygonNearGround(const Shape& shape, const float& lv){
		int s1size = shape.points.size();
		int k = 0;
		for(int i=0; i<s1size;i++)
		{
			if(shape.points.at(i).y <= lv)
				k++;
			if(k>=2)
				return true;

		}
		return false;
	}


	//////////////////////////////////////////////////////////////////////////
	static bool TwoLineIsIntersect(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3/*, float &InterX, float &InterY*/)
	{ //
		float x, y;
		float Minx01 = min(x0, x1);
		float Miny01 = min(y0, y1);
		float Minx23 = min(x2, x3);
		float Miny23 = min(y2, y3);
		float Maxx01 = max(x0, x1);
		float Maxy01 = max(y0, y1);
		float Maxx23 = max(x2, x3);
		float Maxy23 = max(y2, y3);

		if(x1!=x0 && x2!=x3)
		{
			float k1 = (y1-y0)/(x1-x0);
			float k2 = (y3-y2)/(x3-x2);
			float Den = (y1-y0)*(x3-x2) - (y3-y2)*(x1-x0);
			if(k1==k2)
			{ //平行不相交
				float d1 = abs(y0*(x1-x0)-x0*(y1-y0)-y2*(x3-x2)+x2*(y3-y2)); //距离公式d = abs(c1-c2) / sqrt(a*a+b*b)
				if(d1==0)
				{//直线重合
					if((x2>Minx01 && x2<Maxy01 && y2>Miny01 && y2<Maxy01) || (x3>Minx01 && x3<Maxy01 && y3>Miny01 && y3<Maxy01)
						|| (x0>Minx23 && x0<Maxy23 && y0>Miny23 && y0<Maxy23) || (x1>Minx23 && x1<Maxy23 && y1>Miny23 && y1<Maxy23))
					{  //实际碰撞问题线段重合认为相交了
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}   
			}
			x = ((y2-y0)*(x1-x0)*(x3-x2)+(y1-y0)*(x3-x2)*x0-(y3-y2)*(x1-x0)*x2)/Den;
			y = ((y1-y0)*(x-x0))/(x1-x0) + y0;

			if(Minx01<=x && x<=Maxx01 && Miny01<=y && y<=Maxy01 && Minx23<=x && x<=Maxx23 && Miny23<=y && y<=Maxy23)
			{
				// 				InterX = x;
				// 				InterY = y;
				return true;
			}
		}
		else if(x1==x0 && x2!=x3)
		{
			x = x0;
			y = ((y3-y2)*(x0-x2))/(x3-x2) + y2;
			if(Minx01<=x && x<=Maxx01 && Miny01<=y && y<=Maxy01 && Minx23<=x && x<=Maxx23 && Miny23<=y && y<=Maxy23)
			{
				// 				InterX = x;
				// 				InterY = y;
				return true;
			}
		}
		else if(x1!=x0 && x2==x3)
		{
			x = x2;
			y = ((y1-y0)*(x2-x0))/(x1-x0) + y0;
			if(Minx01<=x && x<=Maxx01 && Miny01<=y && y<=Maxy01 && Minx23<=x && x<=Maxx23 && Miny23<=y && y<=Maxy23)
			{
				// 				InterX = x;
				// 				InterY = y;
				return true;
			}       
		}
		return false;
	}
	//

};

