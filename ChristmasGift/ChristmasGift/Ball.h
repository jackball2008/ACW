#pragma once
#include "displayobjectmodel.h"

class Ball :
	public DisplayObjectModel
{
public:
	Ball(void);
	~Ball(void);

	void Initialize();

	void Update(const float& t);
	void Draw();

	
	
// 	GLuint vboID;
// 	GLuint iboID;
};

