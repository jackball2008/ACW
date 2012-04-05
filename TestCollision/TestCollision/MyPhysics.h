#pragma once
#include "RigidBody.h"

class MyPhysics
{
public:
	MyPhysics(void);
	~MyPhysics(void);

	_RigidBody Square1,Square2;

	Vector      vCollisionNormal;           // the collision normal returned by our collision detection routine
	Vector		vCollisionTangent;			// the collision tangent returned by our collision detection routine
	Vector		vCollisionPoint;			// the world space point of collision
	Vector		vRelativeVelocity;			// the world space relative velocity of the two bodies at the point of collision


	void  InitializeElement(_RigidBody *body);

	void  CreateSquare(_RigidBody *body);

	void  CreateTriangle(_RigidBody *body);
	 
	void  SetPosititon();

	void  CalcLoads(_RigidBody *body);
	void  UpdateBody(_RigidBody craft, float dtime);


	int	  CheckForCollision(_RigidBody body1, _RigidBody body2);

	Vector VRotate2D(float angle, Vector u);
};
