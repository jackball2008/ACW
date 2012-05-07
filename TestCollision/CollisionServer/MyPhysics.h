#pragma once
#include "RigidBody.h"


class MyPhysics
{
public:
	MyPhysics(void);
	~MyPhysics(void);

	vector<_RigidBody>squarel;

	_RigidBody _rigidbody1,_rigidbody2,square[40][20],triangle[20][10];

	_RigidBody *CollisionBody1,*CollisionBody2;

	Vector      vCollisionNormal;           // the collision normal returned by our collision detection routine
	Vector		vCollisionTangent;			// the collision tangent returned by our collision detection routine
	Vector		vCollisionPoint;			// the world space point of collision
	Vector		vRelativeVelocity;			// the world space relative velocity of the two bodies at the point of collision




	void  InitializeElement(_RigidBody *body);

	void  InitializeElement(vector<_RigidBody>&squarel);

	void  InitializeElement(_RigidBody square[][20]);


	void  CreateSquare(_RigidBody *body);

	void  CreateTriangle(_RigidBody *body);
	
	//set position
	 
	void  SetPosititon(_RigidBody square[][20]);

	void  SetPosititon(_RigidBody *body1,_RigidBody *body2);

	//update position
	void UpdatePosition(_RigidBody *square1,_RigidBody *square2);

	void UpdatePosition(_RigidBody square[][20]);

	//apply impulse
	void  ApplyImpulse(_RigidBody *body1,_RigidBody *body2);

	void ApplyImpulseP(_RigidBody *body1,_RigidBody *body2);

	//update body

	void  UpdateBody(_RigidBody *Upbody, float dtime);

	void  UpdateBody(_RigidBody square[][20],float dtime);
	
	//check for collision

	int	  CheckForCollisionSimple(_RigidBody *body1, _RigidBody *body2);

	int   CheckForCollision(_RigidBody *body1, _RigidBody *body2);

	int   CheckForCollisionP(_RigidBody *body1, _RigidBody *body2);


	Vector VRotate2D(float angle, Vector u);

	//step simulation
	
	void  StepSimulation(float dt,_RigidBody *rigidcopy1,_RigidBody *rigidcopy2);

	void StepSimulation(float dt,_RigidBody square[][20]);

	void Initialize(void);

	int	pnpoly(int	npol, Vector *vlist, Vector p);


};

