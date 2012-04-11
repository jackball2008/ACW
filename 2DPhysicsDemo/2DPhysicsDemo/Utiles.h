#include <math.h>
#include <vector>
#include "Point.h"

using namespace std;

class Utiles{
public:
	static float Mul(const Point& p1, const Point& p2, const Point& p0){
		return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y)); 
	};
	static float Dis(const Point& p, const float& x, const float& y){
		return sqrt((p.x - x)*(p.x-1)+(p.y-y)*(p.y-y));
	};
};

/**

*/

//////////////////////////////////////////////////////////////////////////
// 	static float Area(const Point& p1, const Point& p2, const Point& p3){
// 		return fabs((p1.x-p3.x)*(p2.y-p3.y)-(p2.x-p3.x)*(p1.y-p3.y));
// 	};
// 	
// 	static float Mul(const Point& p1, const Point& p2, const Point& p0){
// 		return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y)); 
// 	};