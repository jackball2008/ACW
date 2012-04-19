#include <GXBase.h>
#include <math.h>
using namespace gxbase;
// #include <vector>
// using namespace std;

const float ptol = 0.00000001f;

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
		if(m<= ptol)m =1;
		x/= m;
		y/= m;
		
		if (fabs(x) < ptol) x =0.0f;
		if (fabs(x) < ptol) y =0.0f;
	}
	inline void Reverse(){
		x =-x;
		y =-y;
	}

	friend YPoint & operator += ( YPoint &lhs, const YPoint & rhs ) {
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		return lhs;
	}

	friend YPoint & operator -= ( YPoint &lhs, const YPoint & rhs ) {
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		return lhs;
	}

	//dot
	friend YPoint & operator *= ( YPoint &lhs, const YPoint & rhs ) {
		lhs.x *= rhs.x;
		lhs.y *= rhs.y;
		return lhs;
	}

	friend YPoint & operator *= ( YPoint &lhs, const float & rhs ) {
		lhs.x *= rhs;
		lhs.y *= rhs;
		return lhs;
	}

	friend YPoint & operator /= ( YPoint &lhs, const YPoint & rhs ) {
		lhs.x /= rhs.x;
		lhs.y /= rhs.y;
		return lhs;
	}

	friend YPoint & operator /= ( YPoint &lhs, const float & d ) {
		if(d == 0) return lhs;
		lhs.x /= d;
		lhs.y /= d;
		return lhs;
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

