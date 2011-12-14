#pragma once
#include "DisplayObjectModel.h"
class Seat :
	public DisplayObjectModel
{
public:
	Seat(void);
	~Seat(void);

	void Update(const float& t);
	void Draw();

	GLuint seat_texture_ID;
	GLuint seat_shader_program_ID;
	
};

