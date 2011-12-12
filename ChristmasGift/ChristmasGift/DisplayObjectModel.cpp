#include "DisplayObjectModel.h"

#define USEVBOEX1

DisplayObjectModel::DisplayObjectModel(void)//:useShader(false),_enableCullBack(false),_enableCullFront(false)/*,currentSeason(Spring)*/
{
	glex::Load();

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
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*_numberOfVertices, 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Vertex)*_numberOfVertices, _vertices);
	
	
	/*IBO*/
	glGenBuffers(1, &iboID); // Generate buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID); // Bind the element array buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _numberOfIndices * sizeof(GLuint), _indices, GL_STATIC_DRAW);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(GLuint)*_numberOfIndices, _indices);

	/*release bind*/
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}
void DisplayObjectModel::Initialize(const char* fpath){

}





void DisplayObjectModel::CheckShaderEnvironment(){
	const GLubyte *render = glGetString(GL_RENDER);
	const GLubyte *vender = glGetString(GL_VENDOR);
	const GLubyte *version = glGetString(GL_VERSION);
	const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);
	printf("GL Vendor    : %s\n", vender);
	printf("GL Renderer  : %s\n", render);
	printf("GL Version (string)  : %s\n", version);
	printf("GL Version (integer) : %d.%d\n", major, minor);
	printf("GLSL Version : %s\n", glslVersion);  
}

GLuint DisplayObjectModel::LoadShaderFromFile(const char* vPath,const char* fPath){
	GLuint programID;
	programID = glCreateProgram();
	GLuint vID;
	GLuint fID;
	try
	{
		vID = GenerateShaderObject(vPath, GL_VERTEX_SHADER);
		fID = GenerateShaderObject(fPath, GL_FRAGMENT_SHADER);

		glAttachShader(programID, vID);
		glAttachShader(programID, fID);

		glLinkProgram(programID);

		/************************************************************************/
		/* list shader active attributes                                                                     */
		/************************************************************************/
		GLint maxLength, nAttribs;
		glGetProgramiv(programID, GL_ACTIVE_ATTRIBUTES, &nAttribs);
		glGetProgramiv(programID, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxLength);

		GLchar* name = (GLchar*)malloc(maxLength);

		GLint written, size, location;
		GLenum type;
		printf(" Index | Name\n");
		printf("----------------------------\n");
		for(int i = 0; i<nAttribs; i++){
			glGetActiveAttrib( programID, i, maxLength, &written, &size, &type, name);
			location = glGetAttribLocation(programID, name);
		}
		free(name);
	}
	catch(exception& e)
	{
		cerr << e.what() << endl;
	}

	return programID;
}
GLuint DisplayObjectModel::GenerateShaderObject(std::string filename, GLenum shaderType){
	// Attempt to load filename
	ifstream file;
	file.open(filename, ios::in);
	if (!file)
	{
		cerr << "Error loading " << filename << " - file not found" << endl;
		throw exception("Error loading shader");
	}

	stringstream srcBuilder;
	while (!file.eof())
	{
		unsigned char in = file.get();
		srcBuilder << in;
	}
	file.close();
	string shaderSrc = srcBuilder.str();
	// Remove EOF char
	shaderSrc = shaderSrc.substr(0, shaderSrc.size()-1);

	file.close();


	GLuint id = glCreateShader(shaderType);
	if (id == 0)
	{
		cerr << "Could not create shader object" << endl;
		throw exception("Could not create shader object");
	}

	// Assign source
	GLint len[1];
	len[0] = shaderSrc.size();
	GLchar** src = new GLchar*[1];
	src[0] = new GLchar[len[0]];
	for (int i = 0; i < len[0]; i++) src[0][i] = shaderSrc[i];
	glShaderSource(id, 1, (const GLchar**) src, len);

	// Compile shader
	glCompileShader(id);

	//verify
	GLint result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if(GL_FALSE == result){
		printf(" shader compilaion failed!\n ");
		GLint logLen;
		glGetShaderiv(id,GL_INFO_LOG_LENGTH, &logLen);
		if(logLen>0){

			char* log = (char*)malloc(logLen);
			GLsizei written;
			glGetShaderInfoLog(id,logLen,&written,log);

			printf("rewrite shader log: \n%s",log);
			free(log);
		}
	}else{
		printf("shader compilation right\n");
	}

	return id;
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