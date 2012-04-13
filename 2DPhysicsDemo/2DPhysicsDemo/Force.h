#include <GXBase.h>

using namespace gxbase;

struct Force{
	//dir
	float dir_x;
	float dir_y;
	
	//position
	float workposition_x;
	float workposition_y;

	//force
	float force_x;
	float force_y;

	//floa

	float length;
	float allforce;
	


public:
	Force(){
		dir_x = 0;
		dir_y = 0;
		allforce = 0;

		workposition_x = 0;
		workposition_y = 0;

		length = 0;

		force_x = 0;
		force_y = 0;
	}
};