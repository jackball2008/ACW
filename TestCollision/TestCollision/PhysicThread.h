#pragma once
#include "MyThread.h"
#include <iostream>
#include "ShareMem.h"
#include <Windows.h>
#include "RigidBody.h"
using std::iostream;

class PhysicThread :
	MyThread
{
public:
	PhysicThread(void);
	~PhysicThread(void);
	ShareMem* _shareobject;


	Vector      vCollisionNormal;           // the collision normal returned by our collision detection routine
	Vector		vCollisionTangent;			// the collision tangent returned by our collision detection routine
	Vector		vCollisionPoint;			// the world space point of collision
	Vector		vRelativeVelocity;			// the world space relative velocity of the two bodies at the point of collision

	
private:


	HANDLE thread;
};

