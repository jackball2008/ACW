#pragma once
#include <GXBase.h>
using namespace gxbase;


class TreeElement{
public:
	TreeElement(void);
	~TreeElement(void);

	void Update(const float& t);

	void Draw();

	bool Create(GLfloat topradius,GLfloat bottomradius, GLfloat height, int slices, int stacks, bool texture=false);

	void DeallocateMemory();

	void UpdateData(const float& height_inc_percent, const float& tr_inc_percent, const float& br_inc_percent);

	void UpdateData2(float p);


	GLfloat _h;
	GLfloat _tr;
	GLfloat _br;


	GLfloat _rx,_rz;
	GLfloat _moveheight;
	

private:

	float (*_vertexarrayTop)[3];	// contains the vertices
	float (*_vertexarrayBody)[3];	// contains the vertices
	float (*_vertexarrayBottom)[3];	// contains the vertices
	float (*_normalarrayTop)[3];	// contains the normals to each top and bottom vertex
	float (*_normalarrayBody)[3];	// contains the normals to each top and bottom vertex
	float (*_normalarrayBottom)[3];	// contains the normals to each top and bottom vertex
	GLuint *_indexarrayTop;			// index array that defines the polygons
	GLuint *_indexarrayBody;			// index array that defines the polygons
	GLuint *_indexarrayBottom;			// index array that defines the polygons
	float (*_texarrayTop)[2];	// texture coordinates for each vertex
	float (*_texarrayBody)[2];		// texture coordinates for each vertex
	float (*_texarrayBottom)[2];	// texture coordinates for each vertex
	int _slices;
	int _stacks;

	
};

