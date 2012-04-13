#include <GXBase.h>
using namespace gxbase;

struct Force{
	//dir
	float dx;
	float dy;
	
	//position
	float sx;
	float sy;

	//floa

	float length;
	float allforce;
	float force_x;
	float force_y;


public:
	Force(){
		dx = 0;
		dy = 0;
		allforce = 0;

		sx = 0;
		sy = 0;

		length = 0;

		force_x = 0;
		force_y = 0;
	}
};