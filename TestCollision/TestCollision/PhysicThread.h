#pragma once
#include "MyThread.h"
#include <iostream>
#include "ShareMem.h"
#include <Windows.h>
using std::iostream;


const float SPRING_FACTOR = 5.0f;
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
		
	
	bool DetectCollisionL(_RigidBody *body);

	bool DetectCollisionR(_RigidBody *body);

	int DetectCollisionG( _RigidBody *body);

	int CheckforCollision(_RigidBody *body1, _RigidBody *body2);

	void ApplyImpulseP(_RigidBody *body1,_RigidBody *body2);

	void Updateposition(_RigidBody *body, float dtime);

	void SetPosition(_RigidBody *body);
	
	void  StepSimulation();

	void PhysicApply();

	HANDLE thread;

	_RigidBody * Rigidsquare;

	//////////////////////
	void SpringOperation(_RigidBody &body);
	bool DetectPointInShape(const _RigidBody &body,const float&x,const float&y);
	bool shapelocked;
	
	///////////////////


};

