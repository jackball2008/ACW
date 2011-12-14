#include "DisplayObjectModel.h"

#define USEVBOEX1

DisplayObjectModel::DisplayObjectModel(void)//:useShader(false),_enableCullBack(false),_enableCullFront(false)/*,currentSeason(Spring)*/
{
	glex::Load();

	translatex=translatey=translatez=0;
	rotaterangle=rotatex=rotatey=rotatez=0;
	scalex=scaley=scalez=0;

// 	_renderTextures = false;
// 	_renderMaterials = false;
// 	_enableTransparency = false;
}


DisplayObjectModel::~DisplayObjectModel(void)
{
	delete [] _vertices;
	delete [] _indices;	
	_vertices = NULL;
	_indices = NULL;

	unsigned int nBuffers[2] = { vboID, iboID };
	glDeleteBuffers( 2, nBuffers );      

}

/************************************************************************/
/* main method                                                                     */
/************************************************************************/
void DisplayObjectModel::Initialize(){
	//create VBO
	/*VBO*/
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*numberOfVertices, 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Vertex)*numberOfVertices, _vertices);
	
	
	/*IBO*/
	glGenBuffers(1, &iboID); // Generate buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID); // Bind the element array buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numberOfIndices * sizeof(GLuint), _indices, GL_STATIC_DRAW);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(GLuint)*numberOfIndices, _indices);

	/*release bind*/
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}
void DisplayObjectModel::Initialize(const char* fpath){
	/************************************************************************/
	/* load model from .MXY model file                                                                     */
	/************************************************************************/
	ifstream fin(fpath);
	if(!fin){
		cout<<"file open error\n";
		return;
	}
	else{
		cout<<"read model file ok : "<<fpath<<endl;
	}

	char buffer[100];
	int rA,rB,rv,rn,ru,rc;

	int numofvertex;

	float tempfloat;

	int tempindex;

	bool hasuv,hascol;
	hasuv = false;
	hascol = false;

// 	Vertex (*_vertices);
// 
// 	GLuint *_indices;

	while(!fin.eof()){
		//analyze each line
		fin.getline(buffer, sizeof(buffer));
		int lengthOfLine = fin.gcount();
		istrstream sin (buffer, lengthOfLine-1);
		string word;
		sin>>word;

		rA = rB = rv = rn = ru = rc = -2;
		rA = word.compare("A");
		rB = word.compare("B");
		rv = word.compare("v");
		rn = word.compare("n");
		ru = word.compare("u");
		rc = word.compare("c");

		if(rA == 0){
			sin>>word;
			numofvertex = (int)atof(word.c_str());
			_vertices = new Vertex[numofvertex];

		}
		if(rB == 0){
			sin>>word;
			cout<<"fn = "<<atof(word.c_str())<<endl;
		}
		if(rv == 0){
			sin>>word;
			tempindex = (int)atof(word.c_str());

			//x
			sin>>word;
			tempfloat = atof(word.c_str());
			_vertices[tempindex].position[X_POS] = tempfloat;
			//y
			sin>>word;
			tempfloat = atof(word.c_str());
			_vertices[tempindex].position[Y_POS] = tempfloat;
			//z
			sin>>word;
			tempfloat = atof(word.c_str());
			_vertices[tempindex].position[Z_POS] = tempfloat;



		}
		if(rn == 0){
			sin>>word;
			tempindex = (int)atof(word.c_str());

			sin>>word;
			tempfloat = atof(word.c_str());
			_vertices[tempindex].normal[X_POS] = tempfloat;
			sin>>word;
			tempfloat = atof(word.c_str());
			_vertices[tempindex].normal[Y_POS] = tempfloat;
			sin>>word;
			tempfloat = atof(word.c_str());
			_vertices[tempindex].normal[Z_POS] = tempfloat;
		}
		if(ru == 0){
			sin>>word;
			tempindex = (int)atof(word.c_str());

			sin>>word;
			tempfloat = atof(word.c_str());
			_vertices[tempindex].texture[U_POS] = tempfloat;
			sin>>word;
			tempfloat = atof(word.c_str());
			_vertices[tempindex].texture[V_POS] = tempfloat;

			hasuv = true;
		}
		if(rc == 0){
			sin>>word;
			tempindex = (int)atof(word.c_str());

			sin>>word;
			tempfloat = atof(word.c_str());
			_vertices[tempindex].colour[R_POS] = tempfloat;
			sin>>word;
			tempfloat = atof(word.c_str());
			_vertices[tempindex].colour[G_POS] = tempfloat;
			sin>>word;
			tempfloat = atof(word.c_str());
			_vertices[tempindex].colour[B_POS] = tempfloat;
			sin>>word;
			tempfloat = atof(word.c_str());
			_vertices[tempindex].colour[A_POS] = tempfloat;

			hascol = true;
		}

	}
	fin.close();

	if(!hasuv){
		for(int i = 0; i<numofvertex;i++)
		{
			_vertices[i].texture[U_POS] = 0.0;
			_vertices[i].texture[V_POS] = 0.0;
		}
	}

	if(!hascol){
		for(int i = 0; i<numofvertex;i++){
			_vertices[i].colour[R_POS] = 0.5;
			_vertices[i].colour[G_POS] = 0.5;
			_vertices[i].colour[B_POS] = 0.5;
			_vertices[i].colour[A_POS] = 1.0;

		}

	}

	_indices = new GLuint[numofvertex];
	for(int i = 0; i<numofvertex;i++){
		_indices[i] =  i;
	}


	numberOfVertices = numofvertex;
	numberOfIndices = numofvertex;

	drawType = GL_TRIANGLES;
	//initialize VBO
	Initialize();

	
}
void DisplayObjectModel::Draw(){
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);


	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));
	glNormalPointer(GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(20));
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(32));

	if(GL_TRIANGLES == drawType)
		glDrawElements(GL_TRIANGLES, numberOfIndices, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

	if(GL_TRIANGLE_STRIP == drawType)
		glDrawElements(GL_TRIANGLE_STRIP, numberOfIndices, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void DisplayObjectModel::DrawReflection(){

}




/************************************************************************/
/* main method end                                                                     */
/************************************************************************/
/*
void DisplayObjectModel::setVertexes(Vertex (*_veres), GLuint (*_indicesarr),const int& numofvertex,const int& numofindex,const GLuint& texarr,const GLenum& drawtype){
	(_vertices) = (_veres);
	_indices = _indicesarr;
	_numberOfVertices = numofvertex;
	_numberOfIndices = numofindex;
	_textures = texarr;	
	_drawtype = drawtype;

}
*/


/**
void DisplayObjectModel::Draw()
{
	
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
	
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	
	if(_renderTextures){
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textures);
	}
	
	// Resetup our pointers.  This doesn't reinitialise any data, only how we walk through it
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));
	glNormalPointer(GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(20));
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(32));
	
	if(_enableTransparency){
		glDisable( GL_CULL_FACE );
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
	}	
	
	if(_renderMaterials){
		_materials.apply();
	}

	if(_enableCullFront){
		glEnable(GL_CULL_FACE);
	}

	if(_enableCullBack){
		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);
	}

	
	
// 	if(useShader){
// 		glEnableVertexAttribArray(0);
// 		glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(Vertex), BUFFER_OFFSET(0));
// 
// 		glEnableVertexAttribArray(1);
// 		glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,sizeof(Vertex), BUFFER_OFFSET(32));
// 
// 		glUseProgram(_shaderID);
// }


	// work for model from blender
	if(GL_TRIANGLES == _drawtype)
	glDrawElements(GL_TRIANGLES, _numberOfIndices, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

	if(GL_TRIANGLE_STRIP == _drawtype)
	glDrawElements(GL_TRIANGLE_STRIP, _numberOfIndices, GL_UNSIGNED_INT, BUFFER_OFFSET(0));
	

// 	if(useShader){
// 		glUseProgram(NULL);
//  		glDisableVertexAttribArray(0);
//  		glDisableVertexAttribArray(1);
// 	}

	if(_enableCullBack){
		glDisable(GL_CULL_FACE);
	}

	if(_enableCullFront){
		glDisable(GL_CULL_FACE);
	}
	if(_enableTransparency){
		glDisable(GL_BLEND);
		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);
		
	}
	
	// Disable our client state back to normal drawing
	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}
*/



/**
void DisplayObjectModel::setRenderTexture(bool v){
	_renderTextures = v;
}

void DisplayObjectModel::setRenderMaterials(bool v){
	_renderMaterials = v;
}

void DisplayObjectModel::setMaterials(Materials& m){
	_materials = m;
	
}

Materials* DisplayObjectModel::getMaterials(){
	return &_materials;
}

void DisplayObjectModel::setEnableTransparency(bool en){
	_enableTransparency = en;
}

bool DisplayObjectModel::getEnableTransparency(){
	return _enableTransparency;
}

void DisplayObjectModel::setColorApalha(float v){
	_colorapalha = v;
}

float DisplayObjectModel::getColorApalha(){
	return _colorapalha;
}

void DisplayObjectModel::setEnableCullFront(bool v){
	_enableCullFront = v;
}

void DisplayObjectModel::setEnableCullBack(bool v){
	_enableCullBack = v;
}

void DisplayObjectModel::setEnableShaderProgram(bool b){
	useShader = b;
}
void DisplayObjectModel::setShaderProgramID(GLuint id){
	if(useShader){
		_shaderID = id;
	}
}
*/


/************************************************************************/
/* shader operaion                                                                     */
/************************************************************************/
/**
void DisplayObjectModel::Initialize2(){

	glGenBuffers(1, &iboID); // Generate buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID); // Bind the element array buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _numberOfIndices * sizeof(GLuint), _indices, GL_STATIC_DRAW);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(GLuint)*_numberOfIndices, _indices);


	glGenBuffers(1, &_vpid);
	glBindBuffer(GL_ARRAY_BUFFER, _vpid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex)*_numberOfVertices, 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertex)*_numberOfVertices, _vp);

	glGenBuffers(1, &_vnid);
	glBindBuffer(GL_ARRAY_BUFFER, _vnid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex)*_numberOfVertices, 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertex)*_numberOfVertices, _vn);

	glGenBuffers(1, &_vcid);
	glBindBuffer(GL_ARRAY_BUFFER, _vcid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color)*_numberOfVertices, 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(color)*_numberOfVertices, _vc);

	glGenBuffers(1, &_vtid);
	glBindBuffer(GL_ARRAY_BUFFER, _vtid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvcoord)*_numberOfVertices, 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(uvcoord)*_numberOfVertices, _vt);

	
}
void DisplayObjectModel::ShaderDraw(){
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);

	glBindBuffer(GL_ARRAY_BUFFER, _vpid);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof(vertex),0);

	glBindBuffer(GL_ARRAY_BUFFER, _vcid);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_FLOAT, sizeof(color),0);

	glBindBuffer(GL_ARRAY_BUFFER, _vnid);
	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, sizeof(vertex),0);

	glUseProgram(_shaderID);

	glDrawElements(GL_TRIANGLES, _numberOfIndices, GL_UNSIGNED_INT, 0);

	glUseProgram(NULL);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER,NULL);
}

void DisplayObjectModel::SetVBOData(vertex* vp, vertex* vn,color* vc, uvcoord* vt, GLuint* idx, int numofv, int numofidx ){
	_indices = idx;
	_numberOfVertices = numofv;
	_numberOfIndices = numofidx;
	
	_vp = vp ;
	_vn = vn;
	_vc = vc;
	_vt = vt;

}
*/