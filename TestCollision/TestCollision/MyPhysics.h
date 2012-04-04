#pragma once
#include "RigidBody.h"

class MyPhysics
{
public:
	MyPhysics(void);
	~MyPhysics(void);

	_RigidBody Square1,Square2;

	Vector      vCollisionNormal;       // the collision normal returned by our collision detection routine
	Vector		vCollisionTangent;			// the collision tangent returned by our collision detection routine
	Vector		vCollisionPoint;			// the world space point of collision
	Vector		vRelativeVelocity;			// the world space relative velocity of the two bodies at the point of collision


	void  InitializeSquare(_RigidBody *body);
	void  CalcLoads(_RigidBody *body);
	void  UpdateBody(_RigidBody craft, float dtime);
	void  UpdateBodyEuler(_RigidBody craft, float dt);

	Vector	GetBodyZAxisVector(void);
	Vector	GetBodyXAxisVector(int craft);

	void  Initialize(void);
	void  StepSimulation(float dt);
	void  ApplyImpulse(_RigidBody body1,_RigidBody body2);
	void  ApplyLinearImpulse(_RigidBody body1, _RigidBody body2);
	int	  CheckForCollisionSimple(_RigidBody body1, _RigidBody body2);
	int	  CheckForCollision(_RigidBody body1, _RigidBody body2);
	bool  ArePointsEqual(Vector p1, Vector p2);
	int	pnpoly(int	npol, Vector *vlist, Vector p);

	Vector VRotate2D(float angle, Vector u);
};

