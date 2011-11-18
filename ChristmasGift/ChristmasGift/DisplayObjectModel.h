#pragma once

#include "IDisplayObject.h"



#define BUFFER_OFFSET(i) ((char *)NULL + (i))

enum seasons {Spring,Summer,Autumn,Winter};

class DisplayObjectModel :
	public IDisplayObject
{
public:
	DisplayObjectModel(void);
	~DisplayObjectModel(void);

	/************************************************************************/
	/* logic                                                                     */
	/************************************************************************/
	seasons _currentSeason;
	//////////////////////////////////////////////////////////////////////////
	GLuint _vboids;

	GLuint _indexVboId;    

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
	
	virtual void setTreeParameter();
	
	virtual void setRenderTexture(bool &v);

	virtual void setRenderMaterials(bool &v);

	virtual void setMaterials(Materials& m);

	virtual Materials* getMaterials();

	virtual void setEnableTransparency(const bool& en=false);


	virtual bool getEnableTransparency();

	virtual void setColorApalha(float v);

	virtual float getColorApalha();

	virtual void setEnableCullFront(bool v);
	
	virtual void setEnableCullBack(bool v);
private:
	float _colorapalha;
	bool _enableCullFront;
	bool _enableCullBack;
};

