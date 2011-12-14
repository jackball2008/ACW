#pragma once

#include "IDisplayObject.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <strstream>
#include <math.h>





using namespace std;

#define BUFFER_OFFSET(i) ((char *)NULL + (i))


struct vertex{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};
struct color{
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;
};
struct uvcoord{
	GLfloat x;
	GLfloat y;
};


class DisplayObjectModel :
	public IDisplayObject
{
public:
	DisplayObjectModel(void);
	virtual ~DisplayObjectModel(void);

	/************************************************************************/
	/* main method                                                                     */
	/************************************************************************/
	virtual void Initialize();
	virtual void Initialize(const char* fpath);
	//virtual void Update(const float& t);
	virtual void Draw();
	
	/************************************************************************/
	/* main varible                                                                     */
	/************************************************************************/
	Vertex (*_vertices);
	GLuint	*_indices;

	GLuint vboID;
	GLuint iboID; 

	int numberOfVertices;
	int numberOfIndices;

	GLuint textureID;
	Materials material;
	GLenum drawType;


	float tx,ty,tz;
//	float 

	/************************************************************************/
	/* logic                                                                     */
	/************************************************************************/
	/*seasons currentSeason;*/
	//////////////////////////////////////////////////////////////////////////
	/**
	bool _renderTextures;
	bool _renderMaterials;
	bool _enableTransparency;
	float _colorapalha;
	bool _enableCullFront;
	bool _enableCullBack;


	

	
	*/
	//////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////////////

	

	//update and draw are the most important method
	
	//draw, be called in every render
	
	/**
	virtual void setVertexes(Vertex (*_vertices), GLuint (*_indicesaddr),const int& numofvertex,const int& numofindex, const GLuint& texarr, const GLenum& drawtype);
	
	
	
	virtual void setRenderTexture(bool v);

	virtual void setRenderMaterials(bool v);

	virtual void setMaterials(Materials& m);

	virtual Materials* getMaterials();

	virtual void setEnableTransparency(bool en=false);


	virtual bool getEnableTransparency();

	virtual void setColorApalha(float v);

	virtual float getColorApalha();

	virtual void setEnableCullFront(bool v);
	
	virtual void setEnableCullBack(bool v);

	virtual void setEnableShaderProgram(bool b);
	virtual void setShaderProgramID(GLuint id);
	*/
	/************************************************************************/
	/* For Test                                                                     */
	/************************************************************************/
// 	void ShaderDraw();
// 	void Initialize2();
// 	void SetVBOData(vertex* vp, vertex* vn,color* vc, uvcoord* vt, GLuint* idx, int numofv, int numofidx );
	//////////////////////////////////////////////////////////////////////////
	/*bool	useShader;*/
private:
	

	/************************************************************************/
	/* important shader atribute                                                                     */
	/************************************************************************/
// 	GLuint _shaderID;
// 
// 
// 	vertex* _vp;
// 	vertex* _vn;
// 	color* _vc;
// 	uvcoord* _vt;
// 
// 	GLuint _vpid;
// 	GLuint _vnid;
// 	GLuint _vcid;
// 	GLuint _vtid;
	
};

