#include "Shape.h"


Shape::Shape(void)
{

	mgh_power = 0;
	erfenzhiyimvfang_x = 0;
	erfenzhiyimvfang_y = 0;
	mv_x = 0;
	mv_y = 0;

	hitsometing = false;
	hitground = false;
	cantransferpower_y = false;
	cantransferpower_x = false;
	//power
	force_all_x = 0;
	force_all_y = 0;
	//work and receive force on X
	force_out_x = 0.0f;
	force_in_x = 0.0f;
	force_out_dir_x = 0;
	force_in_dir_x = 0;
	velocity_x = 0.0f;
	old_velocity_x = 0.0f;
	acceleration_x = 0.0f;

	//work and receive force on Y
	force_out_y = 0.0f;
	force_in_y = 0.0f;
	force_out_dir_y = 0;
	force_in_dir_y = 0;
	velocity_y = 0.0f;
	old_velocity_y = 0.0f;
	acceleration_y = 0.0f;
	//
	isrigibody = true;
// 	isground = false;
// 	iscommonshape = true;
// 	isspring = false;

	r=1.0f;
	g=1.0f;
	b=0.0f;

	isvisiable = true;
	
	
	id = 0;

	
}


Shape::~Shape(void)
{
}
