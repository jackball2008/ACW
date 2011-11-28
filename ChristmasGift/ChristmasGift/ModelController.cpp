#include "ModelController.h"


ModelController ModelController::_modelController;


ModelController::ModelController(void)
{
	
}


ModelController::~ModelController(void)
{
}

ModelController* ModelController::GetInstance(){
	return &_modelController;
}

/************************************************************************/
/* Read a 3Dmodel file, and transfer data to model instance                                                                       */
/************************************************************************/
void ModelController::AssemblyModelFromFile(IDisplayObject* model, const char* path, GLuint texarr)
{
	ifstream fin(path);
	if(!fin){
		cout<<"file open error\n";
		return;
	}
	else{
		cout<<"read ok"<<endl;
	}

	char buffer[100];
	int rA,rB,rv,rn,ru,rc;

	int numofvertex;

	float tempfloat;

	int tempindex;

	bool hasuv,hascol;
	hasuv = false;
	hascol = false;

	Vertex (*_vertices);
	
	GLuint *_indices;

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

	if(model->getEnableTransparency()){
		for(int i = 0; i<numofvertex;i++){
			_vertices[i].colour[A_POS] =model->getColorApalha();;
		}
	}
	
	_indices = new GLuint[numofvertex];
	for(int i = 0; i<numofvertex;i++){
		_indices[i] =  i;
	}

	model->setVertexes((_vertices),(_indices), numofvertex, numofvertex ,texarr,GL_TRIANGLES);
	model->Initialize();
	

}


void ModelController::AssemblyModelFromHeightFieldFile(IDisplayObject* model, const char* mappath,GLuint texarr){
	
	//1. generate vertex array
	//vertex array
	Vertex (*_vertices);
	//index array
	GLuint (*_indices);
	//////////////////////////////////////////////////////////////////////////
	float (*_vertexarray)[3];
	float (*_normalarray)[3];
	//GLuint
	GLuint *_indexarray;
	float (*_texarray)[2];
	//////////////////////////////////////////////////////////////////////////
	int bitsperpixel;
	unsigned char* rowpointer;
	int vertex_index;
	int current_vertex;
	//////////////////////////////////////////////////////////////////////////	
	Image _heightfield;
	int _width,_height,numofvertex,numofindex;

	_heightfield.Load(mappath);

	_height =_heightfield.Height();
	_width = _heightfield.Width();
	
	/************************************************************************/
	/* generate vertex array, used later                                    */
	/************************************************************************/
	numofvertex = _height*_width;
	//////////////////////////////////////////////////////////////////////////
	bitsperpixel = _heightfield.GetPixelSize();
	_vertexarray = new float[_height*_width][3];
	_normalarray = new float[_height*_width][3];
	_indexarray = new GLuint[_height*_width*2];
	_texarray = new float[_height*_width][2];

	//generate veretx data
	
	vertex_index = 0;

	for(int j=0;j<_height;j++) {
		rowpointer =_heightfield.GetRowData(j);

// 		if(j == 100){
// 			cout<<""<<endl;
// 		}

		for(int i = 0; i <_width; i++) {
			_texarray[vertex_index][0] = (float)i/(_width-1);
			_texarray[vertex_index][1] = (float)j/(_height-1);
			_vertexarray[vertex_index][0] = -2.0f + 4.0f*_texarray[vertex_index][0];
			_vertexarray[vertex_index][1] =  -2.0f + 4.0f*_texarray[vertex_index][1];
			_vertexarray[vertex_index][2] =  (float)rowpointer[i*bitsperpixel]/255.0f;
			vertex_index++;
		};
	};
	
	//cout<<""<<endl;
	//copy vertex and uv
	_vertices = new Vertex[numofvertex];
	for(int i = 0; i< numofvertex; i++){
		//veretx
		_vertices[i].position[X_POS] = _vertexarray[i][0];
		_vertices[i].position[Y_POS] = _vertexarray[i][1];
		_vertices[i].position[Z_POS] = _vertexarray[i][2];
		//uv
		_vertices[i].texture[U_POS] = _texarray[i][0];
		_vertices[i].texture[V_POS] = _texarray[i][1];
	}
	// need to generate the index array
	vertex_index = 0;
	for(int j=0;j<_height-1;j++) {
		for(int i = 0; i<_width;i++) {
			current_vertex = j*_width+i;
			_indexarray[vertex_index++] = current_vertex + _width;
			_indexarray[vertex_index++] = current_vertex;
		};
	};
	//copy index array
	numofindex = vertex_index;
	_indices = new GLuint[numofindex];
	for(int i = 0;i<numofindex;i++){
		_indices[i] = _indexarray[i];
	}
	//here , it is the hardest part of this program
	//generate the normal of each vertex
	vertex_index = 0;
	_normalarray[vertex_index][0] = -_vertexarray[vertex_index][2];
	_normalarray[vertex_index][1] = -_vertexarray[vertex_index+_width][2];
	_normalarray[vertex_index][2] = 8.0f/(_width-1);
	vertex_index++;
	for(int i = 1; i<_width-1;i++) {
		_normalarray[vertex_index][0] = _vertexarray[vertex_index-1][2]-_vertexarray[vertex_index+1][2];
		_normalarray[vertex_index][1] = -_vertexarray[vertex_index+_width][2];
		_normalarray[vertex_index][2] = 8.0f/(_width-1);
		vertex_index++;
	};
	_normalarray[vertex_index][0] = _vertexarray[vertex_index-1][2];
	_normalarray[vertex_index][1] = -_vertexarray[vertex_index+_width][2];
	_normalarray[vertex_index][2] = 8.0f/(_width-1);
	vertex_index++;

	for(int j=1;j<_height-1;j++) {
		_normalarray[vertex_index][0] = -_vertexarray[vertex_index][2];
		_normalarray[vertex_index][1] = -_vertexarray[vertex_index+_width][2];
		_normalarray[vertex_index][2] = 8.0f/(_width-1);
		vertex_index++;
		for(int i=1;i<_width-1;i++) {
			_normalarray[vertex_index][0] = _vertexarray[vertex_index-1][2]-_vertexarray[vertex_index+1][2];
			_normalarray[vertex_index][1] = _vertexarray[vertex_index-_width][2]-_vertexarray[vertex_index+_width][2];
			_normalarray[vertex_index][2] = 8.0f/(_width-1);
			vertex_index++;
		}
		_normalarray[vertex_index][0] = _vertexarray[vertex_index-1][2];
		_normalarray[vertex_index][1] = -_vertexarray[vertex_index+_width][2];
		_normalarray[vertex_index][2] = 8.0f/(_width-1);
		vertex_index++;
	}
	_normalarray[vertex_index][0] = -_vertexarray[vertex_index][2];
	_normalarray[vertex_index][1] = _vertexarray[vertex_index-_width][2];
	_normalarray[vertex_index][2] = 8.0f/(_width-1);
	vertex_index++;
	for(int i = 1; i<_width-1;i++) {
		_normalarray[vertex_index][0] = _vertexarray[vertex_index-1][2]-_vertexarray[vertex_index+1][2];
		_normalarray[vertex_index][1] = _vertexarray[vertex_index-_width][2];
		_normalarray[vertex_index][2] = 8.0f/(_width-1);
		vertex_index++;
	};
	_normalarray[vertex_index][0] = _vertexarray[vertex_index-1][2];
	_normalarray[vertex_index][1] = -_vertexarray[vertex_index-_width][2];
	_normalarray[vertex_index][2] = 8.0f/(_width-1);

	// make normals unit
	float temp;
	for(int j=0;j<_height*_width;j++) {
		temp = _normalarray[j][0]*_normalarray[j][0]+_normalarray[j][1]*_normalarray[j][1]+_normalarray[j][2]*_normalarray[j][2];
		temp = sqrt(temp);
		_normalarray[j][0] /= temp;
		_normalarray[j][1] /= temp;
		_normalarray[j][2] /= temp;
	};
	//copy normal data
	
	for(int i = 0;i<numofvertex;i++){
		_vertices[i].normal[X_POS] = _normalarray[i][0];
		_vertices[i].normal[Y_POS] = _normalarray[i][1];
		_vertices[i].normal[Z_POS] = _normalarray[i][2];
	}
	
	//delete 
	delete [] _normalarray;
	//free old data
	delete [] _indexarray;
	//free old data
	delete [] _vertexarray;
	delete [] _texarray;

	_heightfield.Free();

	//assembly vertex color
	for(int i = 0; i<numofvertex;i++){
		_vertices[i].colour[R_POS] = 0.5;
		_vertices[i].colour[G_POS] = 0.5;
		_vertices[i].colour[B_POS] = 0.5;
		_vertices[i].colour[A_POS] = 1.0;

		if(model->getEnableTransparency()){
			_vertices[i].colour[A_POS] = model->getColorApalha();
		}

	}
	//_indexarray
	//model->setVertexes((_vertices),(_indices), numofvertex,numofindex, texarr);
	model->setVertexes((_vertices),(_indices), numofvertex,numofindex, texarr,GL_TRIANGLE_STRIP);
	model->Initialize();
	
}


void ModelController::LoadTexture(){
	_images[0].Load("house2.jpg");
	_images[1].Load("seattexture.jpg");
	_images[2].Load("seattexture_grass.jpg");
	_images[3].Load("seattexture2.jpg");
	_images[4].Load("SnowFlake2.tga");
	_images[5].Load("leaf_texture.tga");
	_images[6].Load("leaf_nor_texture.tga");

	glGenTextures(7, &_textures[0]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	// build 2D mip-maps from image
	for (int i = 0; i<7; i++) {
		glBindTexture(GL_TEXTURE_2D, _textures[i]);
		_images[i].gluBuild2DMipmaps();
		_images[i].Free();
	};
	
	

}



void ModelController::AssemblyModelFromHeightFieldFile2(IDisplayObject* model, const char* mappath,GLuint texarr){


	//1. generate vertex array
	//vertex array
	Vertex (*_vertices);
	//index array
	GLuint (*_indices);
	//////////////////////////////////////////////////////////////////////////
	float (*_vertexarray)[3];
	float (*_normalarray)[3];
	//GLuint
	GLuint *_indexarray;
	float (*_texarray)[2];
	//////////////////////////////////////////////////////////////////////////
	int (*_incycle)[1];
	//////////////////////////////////////////////////////////////////////////
	int bitsperpixel;
	unsigned char* rowpointer;
	int vertex_index;
	int current_vertex;
	//////////////////////////////////////////////////////////////////////////	
	Image _heightfield;
	int _width,_height,numofvertex,numofindex;

	_heightfield.Load(mappath);

	_height =_heightfield.Height();
	_width = _heightfield.Width();

	/************************************************************************/
	/* generate vertex array, used later                                    */
	/************************************************************************/
	numofvertex = _height*_width;
	//////////////////////////////////////////////////////////////////////////
	bitsperpixel = _heightfield.GetPixelSize();
	_vertexarray = new float[_height*_width][3];
	_normalarray = new float[_height*_width][3];
	_indexarray = new GLuint[_height*_width*2];
	_texarray = new float[_height*_width][2];

	
	_incycle = new int[_width*_height][1];

	//generate veretx data

	vertex_index = 0;

	for(int j=0;j<_height;j++) {
		rowpointer =_heightfield.GetRowData(j);
		for(int i = 0; i <_width; i++) {
				_texarray[vertex_index][0] = (float)i/(_width-1);
				_texarray[vertex_index][1] = (float)j/(_height-1);
				_vertexarray[vertex_index][0] = -2.0f + 4.0f*_texarray[vertex_index][0];
				_vertexarray[vertex_index][1] =  -2.0f + 4.0f*_texarray[vertex_index][1];
				_vertexarray[vertex_index][2] =  (float)rowpointer[i*bitsperpixel]/255.0f;
				vertex_index++;
		};
	};

	//cout<<""<<endl;
	//copy vertex and uv
	_vertices = new Vertex[numofvertex];
	for(int i = 0; i< numofvertex; i++){
		//veretx
		_vertices[i].position[X_POS] = _vertexarray[i][0];
		_vertices[i].position[Y_POS] = _vertexarray[i][1];
		_vertices[i].position[Z_POS] = _vertexarray[i][2];
		//uv
		_vertices[i].texture[U_POS] = _texarray[i][0];
		_vertices[i].texture[V_POS] = _texarray[i][1];
	}



	// need to generate the index array

	vertex_index = 0;
	for(int j=0;j<_height-1;j++) {
		for(int i = 0; i<_width;i++) {
			current_vertex = j*_width+i;
			_indexarray[vertex_index++] = current_vertex + _width;
			_indexarray[vertex_index++] = current_vertex;
		};
	};
	//copy index array
	numofindex = vertex_index;
	_indices = new GLuint[numofindex];
	for(int i = 0;i<numofindex;i++){
		
		_indices[i] = _indexarray[i];
	}


	//here , it is the hardest part of this program
	//generate the normal of each vertex
	vertex_index = 0;
	_normalarray[vertex_index][0] = -_vertexarray[vertex_index][2];
	_normalarray[vertex_index][1] = -_vertexarray[vertex_index+_width][2];
	_normalarray[vertex_index][2] = 8.0f/(_width-1);
	vertex_index++;
	for(int i = 1; i<_width-1;i++) {
		_normalarray[vertex_index][0] = _vertexarray[vertex_index-1][2]-_vertexarray[vertex_index+1][2];
		_normalarray[vertex_index][1] = -_vertexarray[vertex_index+_width][2];
		_normalarray[vertex_index][2] = 8.0f/(_width-1);
		vertex_index++;
	};
	_normalarray[vertex_index][0] = _vertexarray[vertex_index-1][2];
	_normalarray[vertex_index][1] = -_vertexarray[vertex_index+_width][2];
	_normalarray[vertex_index][2] = 8.0f/(_width-1);
	vertex_index++;

	for(int j=1;j<_height-1;j++) {
		_normalarray[vertex_index][0] = -_vertexarray[vertex_index][2];
		_normalarray[vertex_index][1] = -_vertexarray[vertex_index+_width][2];
		_normalarray[vertex_index][2] = 8.0f/(_width-1);
		vertex_index++;
		for(int i=1;i<_width-1;i++) {
			_normalarray[vertex_index][0] = _vertexarray[vertex_index-1][2]-_vertexarray[vertex_index+1][2];
			_normalarray[vertex_index][1] = _vertexarray[vertex_index-_width][2]-_vertexarray[vertex_index+_width][2];
			_normalarray[vertex_index][2] = 8.0f/(_width-1);
			vertex_index++;
		}
		_normalarray[vertex_index][0] = _vertexarray[vertex_index-1][2];
		_normalarray[vertex_index][1] = -_vertexarray[vertex_index+_width][2];
		_normalarray[vertex_index][2] = 8.0f/(_width-1);
		vertex_index++;
	}
	_normalarray[vertex_index][0] = -_vertexarray[vertex_index][2];
	_normalarray[vertex_index][1] = _vertexarray[vertex_index-_width][2];
	_normalarray[vertex_index][2] = 8.0f/(_width-1);
	vertex_index++;
	for(int i = 1; i<_width-1;i++) {
		_normalarray[vertex_index][0] = _vertexarray[vertex_index-1][2]-_vertexarray[vertex_index+1][2];
		_normalarray[vertex_index][1] = _vertexarray[vertex_index-_width][2];
		_normalarray[vertex_index][2] = 8.0f/(_width-1);
		vertex_index++;
	};
	_normalarray[vertex_index][0] = _vertexarray[vertex_index-1][2];
	_normalarray[vertex_index][1] = -_vertexarray[vertex_index-_width][2];
	_normalarray[vertex_index][2] = 8.0f/(_width-1);

	// make normals unit
	float temp;

	for(int j=0;j<_height*_width;j++) {
		temp = _normalarray[j][0]*_normalarray[j][0]+_normalarray[j][1]*_normalarray[j][1]+_normalarray[j][2]*_normalarray[j][2];
		temp = sqrt(temp);
		_normalarray[j][0] /= temp;
		_normalarray[j][1] /= temp;
		_normalarray[j][2] /= temp;
	};
	//copy normal data

	for(int i = 0;i<numofvertex;i++){
		_vertices[i].normal[X_POS] = _normalarray[i][0];
		_vertices[i].normal[Y_POS] = _normalarray[i][1];
		_vertices[i].normal[Z_POS] = _normalarray[i][2];
	}

	//delete 
	delete [] _normalarray;
	//free old data
	delete [] _indexarray;
	//free old data
	delete [] _vertexarray;
	delete [] _texarray;

	_heightfield.Free();

	//assembly vertex color
	for(int i = 0; i<numofvertex;i++){
		_vertices[i].colour[R_POS] = 0.5;
		_vertices[i].colour[G_POS] = 0.5;
		_vertices[i].colour[B_POS] = 0.5;
		_vertices[i].colour[A_POS] = 1.0;

		if(model->getEnableTransparency()){
			_vertices[i].colour[A_POS] = model->getColorApalha();
		}

	}

	//_indexarray
	//model->setVertexes((_vertices),(_indices), numofvertex,numofindex, texarr);
	model->setVertexes((_vertices),(_indices), numofvertex,numofindex, texarr,GL_TRIANGLE_STRIP);

	model->Initialize();



}

#define PI  (float)3.1415926
void ModelController::AssemblyTransparencyPartSphere(IDisplayObject* model,GLfloat radius, int slices, int stacks, GLuint texarr){
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

	stacks = stacks;
	_slices = slices;
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
	for(int i = 0; i< (stacks-2-8); i++) {
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
	Vertex (*_vertices);
	//index array
	GLuint (*_indices);

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
		_vertices[i].colour[A_POS] = 1.0;

		if(model->getEnableTransparency()){
			_vertices[i].colour[A_POS] = model->getColorApalha();
		}

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
	
	model->setVertexes((_vertices),(_indices), numofvertex,numofindex, texarr,GL_TRIANGLE_STRIP);
	model->Initialize();

}



void ModelController::AssemblyBasicTreeData(IDisplayObject*,GLfloat radius, int slices, int stacks){

	float (*_vertexarray)[3];	// contains the vertices
	float (*_normalarray)[3];	// contains the normals to each vertex
	GLuint *_indexarray;		// index array that defines the polygons
	float (*_texarray)[2];		// texture coordinates for each vertex
	int _stacks, _slices;


	int array_size;
	float stack_inc;
	float slice_inc;
	int vertex_count;
	float x, y , z;
	int index_count;
	int temp_vc;
	float temp_tex;
	float temp_rad;

	_stacks = stacks;
	_slices = slices;


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
	for(int i = 0; i< (stacks-2); i++) {
		for(int j = 0; j<= slices; j++) {
			_indexarray[index_count++] = vertex_count++;
			_indexarray[index_count++] = slices+vertex_count;
		};
	};

	_indexarray[index_count++] = 1; // very bottom vertex
	for(int j = 0; j<= slices; j++) {
		_indexarray[index_count++] = vertex_count+slices-j;
	};


}


void ModelController::AssemblyModelFromFile2(DisplayObjectModel* model, const char* path, GLuint texarr){
	ifstream fin(path);
	if(!fin){
		cout<<"file open error\n";
		return;
	}
	else{
		cout<<"read ok"<<endl;
	}

	char buffer[100];
	int rA,rB,rv,rn,ru,rc;

	int numofvertex;

	float tempfloat;

	int tempindex;

	bool hasuv,hascol;
	hasuv = false;
	hascol = false;

	Vertex (*_vertices);

	GLuint *_indices;

	vertex* vp;
	vertex* vn;
	color* vc;
	uvcoord* vt;




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

	if(model->getEnableTransparency()){
		for(int i = 0; i<numofvertex;i++){
			_vertices[i].colour[A_POS] =model->getColorApalha();;
		}
	}

	_indices = new GLuint[numofvertex];
	for(int i = 0; i<numofvertex;i++){
		_indices[i] =  i;
	}

	vp = new vertex[numofvertex];
	vn = new vertex[numofvertex];
	vc = new color[numofvertex];
	vt = new uvcoord[numofvertex];
	for(int i = 0; i< numofvertex; i++){
		vp[i].x = _vertices[i].position[X_POS];
		vp[i].y = _vertices[i].position[Y_POS];
		vp[i].z = _vertices[i].position[Z_POS];

		vn[i].x =  _vertices[i].normal[X_POS];
		vn[i].y =  _vertices[i].normal[Y_POS];
		vn[i].z =  _vertices[i].normal[Z_POS];

		vc[i].r = _vertices[i].colour[R_POS];
		vc[i].g = _vertices[i].colour[G_POS];
		vc[i].b = _vertices[i].colour[B_POS];
		vc[i].a = _vertices[i].colour[A_POS];

		vt[i].x = _vertices[i].texture[X_POS];
		vt[i].y = _vertices[i].texture[Y_POS];

	}

	/*delete [] _vertices;*/

	model->setVertexes((_vertices),(_indices), numofvertex, numofvertex ,texarr,GL_TRIANGLES);
	model->Initialize();
// 	model->SetVBOData(vp,vn,vc,vt,(_indices),numofvertex,numofvertex);
// 	model->Initialize2();
}
