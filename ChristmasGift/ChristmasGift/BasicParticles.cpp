#include "BasicParticles.h"


BasicPaticles::BasicPaticles(void):working(false)
{
}


BasicPaticles::~BasicPaticles(void)
{
}

void BasicPaticles::Initialize(){
	for(int i  =0; i< MAXPARTICLES;i++){

	}
}
void BasicPaticles::Update(){
	if(working)
	for(int i  =0; i< MAXPARTICLES;i++){

	}
}
void BasicPaticles::Draw(){
	if(working)
	for(int i  =0; i< MAXPARTICLES;i++){

	}
}
void BasicPaticles::Start(){
	working = true;
}
void BasicPaticles::Stop(){
	working = false;
}

void BasicPaticles::SetParticlesType(const ParticlesType& t){
	type = t;
}



