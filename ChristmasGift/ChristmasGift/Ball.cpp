#include "Ball.h"


Ball::Ball(void)
{
}


Ball::~Ball(void)
{
}
#define PI  (float)3.1415926
void Ball::Initialize(){
	float (*_vertexarray)[3];	// contains the vertices
	float (*_normalarray)[3];	// contains the normals to each vertex
	GLuint *_indexarray;		// index array that defines the polygons
	float (*_texarray)[2];		// texture coordinates for each vertex
	int _stacks, _slices;
	//////////////////////////////

	int array_size;
	float stack_inc;
	float slice_inc;
	float x, y , z;
	int vertex_count;
	int index_count;
	int temp_vc;
	float temp_tex;
	float temp_rad;

	int stacks = 80;
	int slices = 80;
	GLfloat radius = 1.0;

	_slices = 40;
	//////////////////////////////
	array_size = (slices+1)*(stacks-1)+2;	// +2 is for the top and bottom vertex

	_vertexarray = new float[array_size][3];
	_normalarray = new float[array_size][3];
	_indexarray = new GLuint[2+(stacks-1)*(slices+1)*2];
	_texarray = new float[array_size][2];


	stack_inc = 1.0f/(float)stacks;
	slice_inc = PI*2.0f/slices;

	// define the vertex array

	// top point
	vertex_count = 0;
	_vertexarray[vertex_count][0] = 0.0f; 
	_vertexarray[vertex_count][1] = radius; 
	_vertexarray[vertex_count][2] = 0.0f; 

	_normalarray[vertex_count][0] = 0.0f; 
	_normalarray[vertex_count][1] = 1.0f; 
	_normalarray[vertex_count][2] = 0.0f;

	_texarray[vertex_count][0] = 0; 
	_texarray[vertex_count++][1] = 1; 

	// bottom point
	_vertexarray[vertex_count][0] = 0.0f; 
	_vertexarray[vertex_count][1] = -radius; 
	_vertexarray[vertex_count][2] = 0.0f;

	_normalarray[vertex_count][0] = 0.0f; 
	_normalarray[vertex_count][1] = -1.0f; 
	_normalarray[vertex_count][2] = 0.0f;

	_texarray[vertex_count][0] = 0; 
	_texarray[vertex_count++][1] = 0; 



	for (int i = 1; i < stacks; i++) {
		y = sin(PI*(1/2.0f - stack_inc*(float)i));
		temp_rad = cos(PI*(1/2.0f - stack_inc*(float)i));
		temp_vc = vertex_count;
		temp_tex = 1.0f - stack_inc*(float)i;
		for(int j = 0; j < slices; j++) {
			x = cos((float)j*slice_inc); 
			z = -sin((float)j*slice_inc);  
			_vertexarray[vertex_count][0] = radius*temp_rad*x;
			_vertexarray[vertex_count][1] = radius*y;
			_vertexarray[vertex_count][2] = radius*temp_rad*z;
			_normalarray[vertex_count][0] = temp_rad*x;
			_normalarray[vertex_count][1] = y;
			_normalarray[vertex_count][2] = temp_rad*z;
			_texarray[vertex_count][0] = (float)j/(float)slices;
			_texarray[vertex_count++][1] = temp_tex;
		};
		_vertexarray[vertex_count][0] = _vertexarray[temp_vc][0];
		_vertexarray[vertex_count][1] = _vertexarray[temp_vc][1];
		_vertexarray[vertex_count][2] = _vertexarray[temp_vc][2];
		_normalarray[vertex_count][0] = _normalarray[temp_vc][0];
		_normalarray[vertex_count][1] = _normalarray[temp_vc][1];
		_normalarray[vertex_count][2] = _normalarray[temp_vc][2];
		_texarray[vertex_count][0] = 1;
		_texarray[vertex_count++][1] = temp_tex;
	};

	// now generate the index array
	// start with triangle fans for the top
	index_count = 0;
	vertex_count =2;
	_indexarray[index_count++] = 0; // very top vertex
	for(int j = 0; j<= slices; j++) {
		_indexarray[index_count++] = vertex_count++;
	};
	vertex_count -= (slices+1);
	// now do the main strips
	for(int i = 0; i< (stacks-2-8-10); i++) {
		for(int j = 0; j<= slices; j++) {
			_indexarray[index_count++] = vertex_count++;
			_indexarray[index_count++] = slices+vertex_count;
		};
	};

	// very bottom vertex
	/**
	_indexarray[index_count++] = 1; 
	for(int j = 0; j<= slices; j++) {
		_indexarray[index_count++] = vertex_count+slices-j;
	};
	*/


	//copy data
	//vertex array
	//Vertex (*_vertices);
	//index array
	//GLuint (*_indices);
	
	int numofvertex = array_size;
	_vertices = new Vertex[numofvertex];
	for(int i = 0; i< numofvertex; i++){
		//veretx
		_vertices[i].position[X_POS] = _vertexarray[i][0];
		_vertices[i].position[Y_POS] = _vertexarray[i][1];
		_vertices[i].position[Z_POS] = _vertexarray[i][2];

		//normal
		_vertices[i].normal[X_POS] = _normalarray[i][0];
		_vertices[i].normal[Y_POS] = _normalarray[i][1];
		_vertices[i].normal[Z_POS] = _normalarray[i][2];

		//uv
		_vertices[i].texture[U_POS] = _texarray[i][0];
		_vertices[i].texture[V_POS] = _texarray[i][1];

		_vertices[i].colour[R_POS] = 0.5;
		_vertices[i].colour[G_POS] = 0.5;
		_vertices[i].colour[B_POS] = 0.5;
		_vertices[i].colour[A_POS] = 0.02;


	}

	//index
	//copy index array
	int numofindex = index_count;
	_indices = new GLuint[numofindex];
	for(int i = 0;i<numofindex;i++){
		_indices[i] = _indexarray[i];
	}

	delete [] _vertexarray;
	delete [] _normalarray;
	delete [] _indexarray;
	delete [] _texarray;

	numberOfVertices = numofvertex;
	numberOfIndices = numofindex;


	


	DisplayObjectModel::Initialize();
	
}

void Ball::Update(const float& t){

}
void Ball::Draw(){
	glUseProgram(shaderProgramID);

	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);


	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));
	glNormalPointer(GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(20));
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(32));

	glDisable( GL_CULL_FACE );
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDrawElements(GL_TRIANGLE_FAN, 82, GL_UNSIGNED_INT, BUFFER_OFFSET(0));
	glDrawElements(GL_TRIANGLE_STRIP, numberOfIndices-82, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

	glDisable(GL_BLEND);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glUseProgram(0);
}


