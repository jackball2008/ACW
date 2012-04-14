#include "Shape.h"


Shape::Shape(void)
{
	//power
	//work and receive force on X
	work_force_x = 0.0f;
	receive_force_x = 0.0f;
	work_force_dir_x = 0;
	receive_force_dir_x = 0;
	velocity_x = 0.0f;
	old_velocity_x = 0.0f;
	acceleration_x = 0.0f;

	//work and receive force on Y
	work_force_y = 0.0f;
	receive_force_y = 0.0f;
	work_force_dir_y = 0;
	receive_force_dir_y = 0;
	velocity_y = 0.0f;
	old_velocity_y = 0.0f;
	acceleration_y = 0.0f;
	//
	isrigibody = true;
	isground = false;
	iscommonshape = true;
	isspring = false;

	r=1.0f;
	g=1.0f;
	b=0.0f;

	isvisiable = true;
	
	
	id = 0;

	
}


Shape::~Shape(void)
{
}
