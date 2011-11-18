#include "Terrain.h"
#include <math.h>

Terrain::Terrain(){

}

Terrain::~Terrain(){
	delete [] _vertexarray;
	delete [] _normalarray;
	delete [] _indexarray;
	delete [] _texarray;
}

void Terrain::OnCreate(){
	int bitsperpixel;
	unsigned char* rowpointer;
	int vertex_index;
	int current_vertex;

	_heightfield.Load("ground.bmp");

	// now need to build the vertex array
	// first some basic information about the image
	_height =_heightfield.Height();
	_width = _heightfield.Width();

	bitsperpixel = _heightfield.GetPixelSize();
	_vertexarray = new float[_width*_height][3];
	_normalarray = new float[_width*_height][3];
	_indexarray = new GLuint[_width*_height*2];
	_texarray = new float[_width*_height][2];

	// now need to produce the vertexarray from this
	vertex_index = 0;
	for(int j=0;j<_height;j++) {
		rowpointer =_heightfield.GetRowData(j);
		for(int i = 0; i <_width; i++) {
			//generate texture x, y
			_texarray[vertex_index][0] = (float)i/(_width-1);
			_texarray[vertex_index][1] = (float)j/(_height-1);
			//vertex x,y,z  a pix  = x,y,z
			_vertexarray[vertex_index][0] = -2.0f + 4.0f*_texarray[vertex_index][0];
			_vertexarray[vertex_index][1] =  -2.0f + 4.0f*_texarray[vertex_index][1];
			_vertexarray[vertex_index][2] =  (float)rowpointer[i*bitsperpixel]/255.0f;
			vertex_index++;

		};
	};

	//generate the index array
	vertex_index = 0;
	for(int j=0;j<_height-1;j++) {
		for(int i = 0; i<_width;i++) {
			current_vertex = j*_width+i;
			_indexarray[vertex_index++] = current_vertex + _width;
			_indexarray[vertex_index++] = current_vertex;
		};
	};

	_gen_normals();

	_heightfield.Free();

	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, _texarray);
	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, _normalarray);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, _vertexarray);


}

void Terrain::Draw() {
	if(true) 
		glEnable(GL_TEXTURE_2D);
	for(int j=0;j<_height-1;j++) {
		glDrawElements(GL_TRIANGLE_STRIP, _width*2, GL_UNSIGNED_INT, &_indexarray[j*_width*2]);
	}
	glDisable(GL_TEXTURE_2D);
}

void Terrain::_gen_normals(){

	int vertex_index;

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
	_normalize();

	
}


void Terrain::_normalize() {
	float temp;

	for(int j=0;j<_height*_width;j++) {
		temp = _normalarray[j][0]*_normalarray[j][0]+_normalarray[j][1]*_normalarray[j][1]+_normalarray[j][2]*_normalarray[j][2];
		temp = sqrt(temp);
		_normalarray[j][0] /= temp;
		_normalarray[j][1] /= temp;
		_normalarray[j][2] /= temp;
	};
}


