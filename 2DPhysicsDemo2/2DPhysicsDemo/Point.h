#include <math.h>



const float ptol = 0.00000001f;
//save 
struct YPoint{
public:
	float x;
	float y;
	float z;

	YPoint(){
		x=0;
		y=0;
		z=0;
	};

	YPoint(const float& _x, const float& _y,const float& _z){
		x = _x;
		y = _y;
		z = _z;
	};


	inline float Magnitude()
	{
		return (float)sqrt(x*x+y*y + z*z);
	}

	inline void Normalize(){
		float m = (float)sqrt(x*x+y*y+z*z);
		if(m<= ptol)m =1;
		x/= m;
		y/= m;
		z/= m;
		
		if (fabs(x) < ptol) x =0.0f;
		if (fabs(x) < ptol) y =0.0f;
		if (fabs(x) < ptol) z =0.0f;
	}
	inline void Reverse(){
		x =-x;
		y =-y;
		z = -z;
	}
	inline void Left2D(){
		float _x = y;
		float _y = -x;
		x =_x;
		y =_y;

	}
	inline void Right2D(){
		float _x = -y;
		float _y = x;
		x =_x;
		y =_y;

	}
	inline void Right2D( YPoint &lhs){
		float _x = -y;
		float _y = x;
		lhs.x =_x;
		lhs.y =_y;

	}



	friend YPoint & operator += ( YPoint &lhs, const YPoint & rhs ) {
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		lhs.z += rhs.z;
		return lhs;
	}

	friend YPoint & operator -= ( YPoint &lhs, const YPoint & rhs ) {
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		lhs.z -= rhs.z;
		return lhs;
	}

	//dot
	friend YPoint & operator *= ( YPoint &lhs, const YPoint & rhs ) {
		lhs.x *= rhs.x;
		lhs.y *= rhs.y;
		lhs.z *= rhs.z;
		return lhs;
	}

	friend YPoint & operator *= ( YPoint &lhs, const float & rhs ) {
		lhs.x *= rhs;
		lhs.y *= rhs;
		lhs.z *= rhs;
		return lhs;
	}

	friend YPoint & operator /= ( YPoint &lhs, const YPoint & rhs ) {
		lhs.x /= rhs.x;
		lhs.y /= rhs.y;
		lhs.z /= rhs.z;
		return lhs;
	}

	friend YPoint & operator /= ( YPoint &lhs, const float & d ) {
		if(d == 0) return lhs;
		lhs.x /= d;
		lhs.y /= d;
		lhs.z /= d;
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

