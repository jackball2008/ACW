#pragma once
#include "IDisplayObject.h"
class ShaderDisplayObjectModel: public IDisplayObject
{
public:
	ShaderDisplayObjectModel(void);
	~ShaderDisplayObjectModel(void);


	virtual void Initialize();


	virtual void Update(const float& t);

	virtual void Draw();

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

private:
	Materials _material;
	bool _enabletransparency;
	float _alpha;

	GLfloat *vertexPos;
	
};

