#include "SnowFlakeParticles.h"

/************************************************************************/
/* static utils                                                                     */
/************************************************************************/
// Random floating [0-1]
static float randfPos1() {	return float(rand()) /float(RAND_MAX);}
// Random floating [-1 - 1]
static float randf1() {return randfPos1() * 2.0f - 1.0f;}
//  Random floating [-1 ,0 , 1]
static float rand2f1() {
	float val = randf1();
	return (val >0.0f) ? val*val : -(val*val);
}
SnowFlakeParticles::SnowFlakeParticles(void)
{
}


SnowFlakeParticles::~SnowFlakeParticles(void)
{
}


void SnowFlakeParticles::Initialize(){
	for(int loop  =0; loop< MAXPOINTPARTICLES;loop++){

	}
}

void SnowFlakeParticles::Update(const float& t){
	intervaltime = t;
}
void SnowFlakeParticles::Draw(){
	for(int loop  =0; loop< MAXPOINTPARTICLES;loop++){
		float matrix[16];
		vec3f campos(camx,camy,camz);





	}
}

void SnowFlakeParticles::setTexture(GLuint &t){
	texture = t;
}
void SnowFlakeParticles::setHeight(const float &h){
	hight = h;
}
void SnowFlakeParticles::setRaius(const float &r){
	radius = r;
}

void SnowFlakeParticles::setCameraPos(const float& x,const float& y,const float& z){
	camx = x;
	camy = y;
	camz = z;
}