#pragma once
#include "DisplayObjectModel.h"
#include "noise/noise.h"
#include <ctime>
class Seat :
	public DisplayObjectModel
{
public:
	Seat(void);
	~Seat(void);

	void Update(const float& t);
	void Draw();

	void MakeNoiseTexture();
	void UpdateNoise();

	GLuint seat_shader_program_ID;

	GLuint seat_texture_ID;
	GLuint seat_snow_texture_ID;
	
};

