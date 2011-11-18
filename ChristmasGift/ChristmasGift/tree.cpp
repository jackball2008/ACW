//
//  tree.cpp
//
//   This class provides a set of functions for creating and rendering a fractal
//  Christmas stree. 
//
// Author: Evan Hart
// Email: sdkfeedback@nvidia.com
//
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#include <GL/glew.h>

#include <math.h>
#include <stdlib.h>



#include "tree.h"


using std::vector;
using nv::vec3f;
using nv::matrix4f;

////////////////////////////////////////////////////////////////////////////////
//
//  Helper functions
//
////////////////////////////////////////////////////////////////////////////////

//
// Random floating point number [0-1]
//
//////////////////////////////////////////////////////////////////////
static float randfPos() {
    return float(rand()) /float(RAND_MAX);
}

//
// Random floating point number [-1 - 1]
//
//////////////////////////////////////////////////////////////////////
static float randf() {
    return randfPos() * 2.0f - 1.0f;
}

//
//  Random floating point number [-1 - 1] with the distribution
// clustered toward 0
//
//////////////////////////////////////////////////////////////////////
static float rand2f() {
    float val = randf();

    return (val >0.0f) ? val*val : -(val*val);
}

////////////////////////////////////////////////////////////////////////////////
//
// Tree constants
//
////////////////////////////////////////////////////////////////////////////////
const int Tree::trunkVertexSize = 6;
const int Tree::frondVertexSize = 14;
const int Tree::lightVertexSize = 6;
const int Tree::ornamentVertexSize = 7;

////////////////////////////////////////////////////////////////////////////////
//
// Tree functions
//
////////////////////////////////////////////////////////////////////////////////

//
//
//////////////////////////////////////////////////////////////////////
Tree::Tree() : _numLights(1200), _numSegments(40), _height(16.0f), _radius(6.0f), _branchSides(6), _branchesPerSegment(7), _branchGenerations(5), _branchGenerationDecayRate(1.0f/7.0f) {
}

//
//
//////////////////////////////////////////////////////////////////////
Tree::~Tree() {
}

//
// Fractal function used to create branches and fronds
//
//  The branches on the tree are all self similar, so simple
// fractal with random perturbations. For each generation of the
// branch, it will grow out by 'size', then fork three ways,
// with the central branch continuing furthest, and closest to
// the original direction. The children will go off to the left
// and right.
//
//////////////////////////////////////////////////////////////////////
void Tree::growBranch( vec3f dir, vec3f root, float size, int gen) {
    vec3f up( 0.0f, 1.0f, 0.0f);
    vec3f out = nv::normalize(cross( dir, up));
    up = normalize( cross( out, dir));
    vec3f pos = root + dir * size;

    
    if (gen > 0) {
        // if this is not the end of the branch lenghten it

        //save the current position in the vertex list
        GLuint baseIdx = (GLuint)_trunkVertices.size() / trunkVertexSize;

        // Compute random factors used to control how far out the next
        // genration will go. The power function is used to concentrate
        // the distribution.
        float outVal1 = 1.0f - powf( randfPos(), 4.0f);
        float outVal2 = 1.0f - powf( randfPos(), 4.0f);
        float outVal3 = 1.0f - powf( randfPos(), 4.0f);

        // create the vertices for this segment of the branch
        for (int ii = 0; ii < _branchSides; ii++) {
            float x = sinf( float(ii)/float(_branchSides) * 2.0f * 3.1415927f); 
            float y = cosf( float(ii)/float(_branchSides) * 2.0f * 3.1415927f); 
            vec3f dir = normalize( x * out + y * up);
            vec3f base = root + dir * size * 0.035f;
            vec3f tip = pos + dir * size * 0.015f;

            _trunkVertices.push_back( base.x);
            _trunkVertices.push_back( base.y);
            _trunkVertices.push_back( base.z);
            _trunkVertices.push_back( dir.x);
            _trunkVertices.push_back( dir.y);
            _trunkVertices.push_back( dir.z);
            _trunkVertices.push_back( tip.x);
            _trunkVertices.push_back( tip.y);
            _trunkVertices.push_back( tip.z);
            _trunkVertices.push_back( dir.x);
            _trunkVertices.push_back( dir.y);
            _trunkVertices.push_back( dir.z);

        }

        // add the indices for this portion of the branch
        for (int ii = 0; ii < _branchSides; ii++) {
            _trunkIndices.push_back( baseIdx + ii * 2);
            _trunkIndices.push_back( baseIdx + ii * 2 + 1);
            _trunkIndices.push_back( baseIdx + (ii * 2 + 2) % (_branchSides * 2));
            _trunkIndices.push_back( baseIdx + (ii * 2 + 2) % (_branchSides * 2));
            _trunkIndices.push_back( baseIdx + ii * 2 + 1);
            _trunkIndices.push_back( baseIdx + (ii * 2 + 3) % (_branchSides * 2));

        }

        float dirFactor = 1.0f;

        //this makes the fronds stick up a bit more
        if (gen == 1)
            dirFactor = 0.7f;

        // continue to grow the branch
        growBranch( nv::normalize( dir * dirFactor + 0.9f*out + 0.30f *up),  pos, size * 0.5f * outVal1, gen-1);
        growBranch( nv::normalize( dir * dirFactor + -0.9f*out + 0.22f *up), pos, size * 0.5f * outVal2, gen-1);
        growBranch( nv::normalize( dir * dirFactor + 0.2f *up),              pos, size * 0.6f * outVal3, gen-1);
    }
    else {
        //
        // end of the branch, grow the frond
        //

        // save the current vertex position
        GLuint baseFrondIndex = (GLuint)_frondVertices.size() / frondVertexSize;

        // scale up the size for the frond
        size *= 6.0f;

        // frond is between 1 3/4 foot and 1/2 foot per side
        if ( size > 1.75f)
            size = 1.75f;

        if ( size < 0.5f)
            size = 0.5f;

        
        pos = root + dir * size; // scale by length
        float scale =  size * 0.5f; // width scale is 1/2 length scale, because it is +/-

        // compute vectors needed to generate vertex and store
        vec3f offset = normalize( out * randf() + up * randf() * 0.5f);
        vec3f n = normalize( cross( dir, offset));
        vec3f sTan = offset;
        vec3f tTan = dir;

        vec3f vtx;

        // Compute the 4 vertices of the frond geometry and store them, along with
        // normal, texcoord, and tangents
        vtx = root - offset * scale;
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( vtx[ii]);
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( n[ii]);
        _frondVertices.push_back( 0.0f);
        _frondVertices.push_back( 0.0f);
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( sTan[ii]);
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( tTan[ii]);

        vtx = root + offset * scale;
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( vtx[ii]);
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( n[ii]);
        _frondVertices.push_back( 1.0f);
        _frondVertices.push_back( 0.0f);
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( sTan[ii]);
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( tTan[ii]);

        vtx = pos + offset * scale;
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( vtx[ii]);
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( n[ii]);
        _frondVertices.push_back( 1.0f);
        _frondVertices.push_back( 1.0f);
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( sTan[ii]);
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( tTan[ii]);

        vtx = pos - offset * scale;
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( vtx[ii]);
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( n[ii]);
        _frondVertices.push_back( 0.0f);
        _frondVertices.push_back( 1.0f);
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( sTan[ii]);
        for (int ii = 0; ii < 3; ii++) _frondVertices.push_back( tTan[ii]);

        // add the indices for this frond to the index list
        _frondIndices.push_back( baseFrondIndex + 0);
        _frondIndices.push_back( baseFrondIndex + 1);
        _frondIndices.push_back( baseFrondIndex + 2);
        _frondIndices.push_back( baseFrondIndex + 0);
        _frondIndices.push_back( baseFrondIndex + 2);
        _frondIndices.push_back( baseFrondIndex + 3);

        //
        // randomly place an ornament at the end of the frond
        //
        const float materialCount = (float)_ornamentColors.size() * 0.25f;

        if (randfPos() < 0.15f * _ornamentFreqAdjust) {
            //add an ornament
            vec3f oPos = root * 0.2f + pos * 0.8f + vec3f( 0.0f, -1.0f, 0.0f) * (size * 0.05f + 2.0f / 12.0f);
            int which = int( materialCount * randfPos());
            _ornamentVertices.push_back( oPos.x);
            _ornamentVertices.push_back( oPos.y);
            _ornamentVertices.push_back( oPos.z);
            _ornamentVertices.push_back( _ornamentColors[4*which]);
            _ornamentVertices.push_back( _ornamentColors[4*which + 1]);
            _ornamentVertices.push_back( _ornamentColors[4*which + 2]);
            _ornamentVertices.push_back( _ornamentColors[4*which + 3]);

        }
    }

    
}

//
//  Function used to grow the trunk and fractal branches off of it
//
//////////////////////////////////////////////////////////////////////
void Tree::grow() {
    vec3f segmentBase;
    float radius = _radius;

    //make sure we have an ornament color
    if (_ornamentColors.size() == 0) {
        //red 
        _ornamentColors.push_back( 0.8f);
        _ornamentColors.push_back( 0.0f);
        _ornamentColors.push_back( 0.0f);
        _ornamentColors.push_back( 32.0f);

        //green
        _ornamentColors.push_back( 0.0f);
        _ornamentColors.push_back( 0.8f);
        _ornamentColors.push_back( 0.0f);
        _ornamentColors.push_back( 32.0f);

        //gold
        _ornamentColors.push_back( 0.8f);
        _ornamentColors.push_back( 0.8f);
        _ornamentColors.push_back( 0.0f);
        _ornamentColors.push_back( 4.0f);
    }

    //grow the segments of the trunk
    for (int ii = 0; ii < _numSegments; ii++) {
        vec3f segmentTop = segmentBase + vec3f( 0.0f, _height / float(_numSegments), 0.0f);

        //save the present vertex index
        GLuint baseIndex = (GLuint)_trunkVertices.size() / trunkVertexSize;

        // add the vertices for the trunk segment
        for ( int jj = 0; jj < _branchSides; jj++) {
            float x = sinf( float(jj)/float(_branchSides) * 2.0f * 3.1415927f);
            float z = cosf( float(jj)/float(_branchSides) * 2.0f * 3.1415927f);
            vec3f dir( x, 0.0f, z);

            vec3f upper = segmentTop + dir * (radius - _radius/float(_numSegments - 2)) * 0.05f;
            vec3f lower = segmentBase + dir * radius * 0.05f;

            _trunkVertices.push_back( lower.x);
            _trunkVertices.push_back( lower.y);
            _trunkVertices.push_back( lower.z);
            _trunkVertices.push_back( dir.x);
            _trunkVertices.push_back( dir.y);
            _trunkVertices.push_back( dir.z);
            _trunkVertices.push_back( upper.x);
            _trunkVertices.push_back( upper.y);
            _trunkVertices.push_back( upper.z);
            _trunkVertices.push_back( dir.x);
            _trunkVertices.push_back( dir.y);
            _trunkVertices.push_back( dir.z);
        }

        //
        // add the branches
        //

        // bias the rotation to void the limbs all lining up directly over one another
        float rotBias = randf();

        //create the individual branches
        for ( int jj = 0; jj < _branchesPerSegment; jj++) {
            float x = sinf( float(jj)/float(_branchesPerSegment) * 2.0f * 3.1415927f + rotBias);
            float z = cosf( float(jj)/float(_branchesPerSegment) * 2.0f * 3.1415927f + rotBias);

            // direction of growth
            vec3f dir( x, 0.0f, z);

            // values used to add some random behavior to the branches
            vec3f tweak( rand2f(), randfPos() + 0.25f * (ii/float(_numSegments - 1)), rand2f());
            float val = randfPos();
            vec3f tweakUp( 0.0f, val*val, 0.0f);

            // place a scale factor on ornament count to account for the varying number of branches
            _ornamentFreqAdjust = sqrtf(1.0f / powf( 3.0, (float)int(_branchGenerations - ii * _branchGenerationDecayRate + 0.5f)));

            //grow the fractal branch
            growBranch( dir + tweak * 0.1f, segmentBase + tweakUp, radius/2.25f, int(_branchGenerations - ii * _branchGenerationDecayRate + 0.5f));
        }

        // add the indices for the trunk
        for (int jj = 0; jj < _branchSides; jj++) {
            _trunkIndices.push_back( baseIndex + jj * 2);
            _trunkIndices.push_back( baseIndex + jj * 2 + 1);
            _trunkIndices.push_back( baseIndex + (jj * 2 + 2) % (_branchSides * 2));
            _trunkIndices.push_back( baseIndex + (jj * 2 + 2) % (_branchSides * 2));
            _trunkIndices.push_back( baseIndex + jj * 2 + 1);
            _trunkIndices.push_back( baseIndex + (jj * 2 + 3) % (_branchSides * 2));

        }

        // update values for the next iteration
        segmentBase = segmentTop;

        radius -= _radius/float(_numSegments - 1);
    }

	glGenBuffers( 1, &_frondVBO);
	glBindBuffer( GL_ARRAY_BUFFER, _frondVBO);
	glBufferData( GL_ARRAY_BUFFER, _frondVertices.size() * sizeof(float), &_frondVertices[0], GL_STATIC_DRAW);

	glGenBuffers( 1, &_trunkVBO);
	glBindBuffer( GL_ARRAY_BUFFER, _trunkVBO);
	glBufferData( GL_ARRAY_BUFFER, _trunkVertices.size() * sizeof(float), &_trunkVertices[0], GL_STATIC_DRAW);

	glBindBuffer( GL_ARRAY_BUFFER, 0);
}

//
// Function for generating tree lights
//
//  This function places lights randomly in the cone of the tree.
// The lights are generated within a prism, and culled if they are
// not in the are of interest to ensure equal spacing. Finally,
// lights that are too far into the tree are culled. 
//
//////////////////////////////////////////////////////////////////////
void Tree::genLights() {

    // 
    // if no lights are set, default to white lights (not pure white, but warmer)
    //
    if ( _lightColors.size() == 0 ) {
        _lightColors.push_back( 1.0f);
        _lightColors.push_back( 0.98f);
        _lightColors.push_back( 0.90f);
    }

    for (int ii = 0; ii < _numLights; ii++) {
        float x = randfPos() * _radius * 2.0f - _radius;
        float y = randfPos() * _height;
        float z = randfPos() * _radius * 2.0f  - _radius;

        float h = y;
        float r = sqrtf( x*x + z*z);

        // make sure is is within a reasonable distance of the surface of the tree
        if (  h < 1.1f || r > ((_height - h)/_height * _radius * 1.02f) || r < ((_height - h)/_height * _radius - 2.0f) ){
            ii -= 1;
            continue;
        }

        int color = ii % int(_lightColors.size() / 3); 
        _lightVertices.push_back( x);
        _lightVertices.push_back( y);
        _lightVertices.push_back( z);
        _lightVertices.push_back( _lightColors[ color*3]);
        _lightVertices.push_back( _lightColors[ color*3 + 1]);
        _lightVertices.push_back( _lightColors[ color*3 + 2]);
    }
}

//
//
//////////////////////////////////////////////////////////////////////
void Tree::drawBranches() {

    float brown[] = { 0.5f, 0.5f, 0.0f, 1.0f};
    glColor3f( 0.5f, 0.5f, 0.0f);

    glBindBuffer( GL_ARRAY_BUFFER, _trunkVBO);

    glEnable(GL_LIGHTING);
    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, brown);
    glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, 32.0f);
    //draw trunk and branches
    //glVertexPointer( 3, GL_FLOAT, sizeof(float)*trunkVertexSize, &_trunkVertices[0]);
    glVertexPointer( 3, GL_FLOAT, sizeof(float)*trunkVertexSize, 0);
    glEnableClientState( GL_VERTEX_ARRAY);

    //glNormalPointer( GL_FLOAT, sizeof(float)*trunkVertexSize, &_trunkVertices[3]);
    glNormalPointer( GL_FLOAT, sizeof(float)*trunkVertexSize, (float*)(0) + 3);
    glEnableClientState( GL_NORMAL_ARRAY);

    glDrawElements( GL_TRIANGLES, (GLsizei)_trunkIndices.size(), GL_UNSIGNED_INT, &_trunkIndices[0]);

    glDisableClientState( GL_VERTEX_ARRAY);
    glDisableClientState( GL_NORMAL_ARRAY);

    glBindBuffer( GL_ARRAY_BUFFER, 0);

    glDisable(GL_LIGHTING);
}

//
//
//////////////////////////////////////////////////////////////////////
void Tree::drawFronds() {

    //draw the fronds
    float green[] = { 0.0f, 0.7f, 0.0f, 1.0f};

    glEnable(GL_LIGHTING);
    glColor3f( 0.0f, 0.7f, 0.0f);
    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, green);
    glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, 32.0f);

    glBindBuffer( GL_ARRAY_BUFFER, _frondVBO);
    //glVertexPointer( 3, GL_FLOAT, sizeof(float)*frondVertexSize, &_frondVertices[0]);
    glVertexPointer( 3, GL_FLOAT, sizeof(float)*frondVertexSize, 0);
    //glNormalPointer( GL_FLOAT, sizeof(float)*frondVertexSize, &_frondVertices[3]);
    glNormalPointer( GL_FLOAT, sizeof(float)*frondVertexSize, (float*)(0) + 3);

    //glTexCoordPointer( 2, GL_FLOAT, sizeof(float)*frondVertexSize, &_frondVertices[6]);
    glTexCoordPointer( 2, GL_FLOAT, sizeof(float)*frondVertexSize, (float*)(0) + 6);
    glEnableClientState( GL_TEXTURE_COORD_ARRAY);

    glClientActiveTexture( GL_TEXTURE1);
    //glTexCoordPointer( 3, GL_FLOAT, sizeof(float)*frondVertexSize, &_frondVertices[8]);
    glTexCoordPointer( 3, GL_FLOAT, sizeof(float)*frondVertexSize, (float*)(0) + 8);
    glEnableClientState( GL_TEXTURE_COORD_ARRAY);
    glClientActiveTexture( GL_TEXTURE2);
    //glTexCoordPointer( 3, GL_FLOAT, sizeof(float)*frondVertexSize, &_frondVertices[11]);
    glTexCoordPointer( 3, GL_FLOAT, sizeof(float)*frondVertexSize, (float*)(0) + 11);
    glEnableClientState( GL_TEXTURE_COORD_ARRAY);
    

    glEnableClientState( GL_VERTEX_ARRAY);
    glEnableClientState( GL_NORMAL_ARRAY);

    glDrawElements( GL_TRIANGLES, (GLsizei)_frondIndices.size(), GL_UNSIGNED_INT, &_frondIndices[0]);

    glDisable(GL_LIGHTING);

    glDisableClientState( GL_VERTEX_ARRAY);
    glDisableClientState( GL_NORMAL_ARRAY);

    glClientActiveTexture( GL_TEXTURE1);
    glDisableClientState( GL_TEXTURE_COORD_ARRAY);
    glClientActiveTexture( GL_TEXTURE2);
    glDisableClientState( GL_TEXTURE_COORD_ARRAY);

    glClientActiveTexture( GL_TEXTURE0);
    glDisableClientState( GL_TEXTURE_COORD_ARRAY);
    
    glBindBuffer( GL_ARRAY_BUFFER, 0);
}

//
//
//////////////////////////////////////////////////////////////////////
void Tree::drawLights() {

    //draw the fronds
    glColor3f( 1.0f, 0.0f, 0.0f);
    glVertexPointer( 3, GL_FLOAT, sizeof(float)*lightVertexSize, &_lightVertices[0]);
    glColorPointer( 3, GL_FLOAT, sizeof(float)*lightVertexSize, &_lightVertices[3]);

    glPointSize( 3.0f);

    glEnableClientState( GL_VERTEX_ARRAY);
    glEnableClientState( GL_COLOR_ARRAY);

    glDrawArrays( GL_POINTS, 0, (GLsizei)_lightVertices.size() / lightVertexSize);

    glDisableClientState( GL_VERTEX_ARRAY);
    glDisableClientState( GL_COLOR_ARRAY);
    
}

//
//
//////////////////////////////////////////////////////////////////////
void Tree::drawOrnaments() {

    //draw the ornaments
    glVertexPointer( 3, GL_FLOAT, sizeof(float)*ornamentVertexSize, &_ornamentVertices[0]);
    glColorPointer( 4, GL_FLOAT, sizeof(float)*ornamentVertexSize, &_ornamentVertices[3]);

    glPointSize( 5.0f);

    glEnableClientState( GL_VERTEX_ARRAY);
    glEnableClientState( GL_COLOR_ARRAY);

    glDrawArrays( GL_POINTS, 0, (GLsizei)_ornamentVertices.size() / ornamentVertexSize);


    glDisableClientState( GL_VERTEX_ARRAY);
    glDisableClientState( GL_COLOR_ARRAY);
    
}