#pragma once
#include "MyThread.h"
#include <iostream>
#include "ShareMem.h"
#include <Windows.h>
using std::iostream;

class PhysicThread :
	public MyThread
{
public:
	PhysicThread(void);
	~PhysicThread(void);
	void SetShapeObject(ShareMem *p){_shareobject=p;};
	int run();
	ShareMem* _shareobject;


	Vector      vCollisionNormal;           // the collision normal returned by our collision detection routine
	Vector		vCollisionTangent;			// the collision tangent returned by our collision detection routine
	Vector		vCollisionPoint;			// the world space point of collision
	Vector		vRelativeVelocity;			// the world space relative velocity of the two bodies at the point of collision




private:
		
	
	int CheckforCollision(_RigidBody *body1, _RigidBody *body2);

	void ApplyImpulseP(_RigidBody *body1,_RigidBody *body2);

	HANDLE thread;
};

