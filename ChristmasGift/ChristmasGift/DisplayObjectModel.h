#pragma once

#include "IDisplayObject.h"



#define BUFFER_OFFSET(i) ((char *)NULL + (i))


enum seasons {Spring,Summer,Autumn,Winter};

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
	~DisplayObjectModel(void);

	/************************************************************************/
	/* logic                                                                     */
	/************************************************************************/
	seasons currentSeason;
	//////////////////////////////////////////////////////////////////////////
	GLuint _vboID;

	GLuint _iboID;   
	GLuint _vaoID;

	
	bool _renderTextures;
	bool _renderMaterials;
	bool _enableTransparency;
	


	int _numberOfVertices;
	int _numberOfIndices;

	GLuint _textures;

	Materials _materials;

	GLenum _drawtype;
	//////////////////////////////////////////////////////////////////////////
	Vertex (*_vertices);
	GLuint	*_indices;
	//////////////////////////////////////////////////////////////////////////

	virtual void Initialize();

	//update and draw are the most important method
	virtual void Update(const float& t);
	//draw, be called in every render
	virtual void Draw();

	virtual void setVertexes(Vertex (*_vertices), GLuint (*_indicesaddr),const int& numofvertex,const int& numofindex, const GLuint& texarr, const GLenum& drawtype);
	
	/*virtual void setTreeParameter();*/
	
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

	/************************************************************************/
	/* For Test                                                                     */
	/************************************************************************/
	void ShaderDraw();
	void Initialize2();
	void SetVBOData(vertex* vp, vertex* vn,color* vc, uvcoord* vt, GLuint* idx, int numofv, int numofidx );
	//////////////////////////////////////////////////////////////////////////
	bool	useShader;
private:
	float _colorapalha;
	bool _enableCullFront;
	bool _enableCullBack;

	/************************************************************************/
	/* important shader atribute                                                                     */
	/************************************************************************/
	GLuint _shaderID;


	vertex* _vp;
	vertex* _vn;
	color* _vc;
	uvcoord* _vt;

	GLuint _vpid;
	GLuint _vnid;
	GLuint _vcid;
	GLuint _vtid;
	
};

