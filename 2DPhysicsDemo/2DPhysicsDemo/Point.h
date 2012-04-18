#include <GXBase.h>
#include <math.h>
using namespace gxbase;
// #include <vector>
// using namespace std;

/*const float ptol = 0.00000001f;*/

struct YPoint{
public:
	float x;
	float y;

	YPoint(){
		x=0;
		y=0;
	};

	YPoint(const float& _x, const float& _y){
		x = _x;
		y = _y;
	};


	inline float Magnitude()
	{
		return (float)sqrt(x*x+y*y);
	}

	inline void Normalize(){
		float m = (float)sqrt(x*x+y*y);
		if(m<= 0.00000001f)m =1;
		x/= m;
		y/= m;
		
		if (fabs(x) < 0.00000001f) x =0.0f;
		if (fabs(x) < 0.00000001f) y =0.0f;
	}
	inline void Reverse(){
		x =-x;
		y =-y;
	}
	
};
struct   YLineSeg{   
	YPoint   a,b;   
}; 

struct Velocity{
	float Vx;
	float Vy;
public:
	Velocity()
	{
		Vx = 0;
		Vy = 0;
	}
};

