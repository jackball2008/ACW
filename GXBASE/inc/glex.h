#pragma once
#ifndef __glex_h
#define __glex_h

/**
 * This is an automatically generated header file: do not edit
 * Generated 1668 functions on Fri Sep 04 15:13:03 2009
 * J.Ward, Computer Science, University of Hull, UK
 * Visit the OpenGL Extensions Registry for detailed
 * extension specifications:
 *   http://www.opengl.org/registry
 */

#include <assert.h>
#include "glexfp.h"

class glex {
public:
	glex();
	virtual ~glex();
	bool Load();
	long Count() const;
	long Known() const;
	bool Supports(const char *) const;
public:
	// GL extension functions

	void glBlendColor(GLclampf, GLclampf, GLclampf, GLclampf);
	void glBlendEquation(GLenum);
	void glDrawRangeElements(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *);
	void glTexImage3D(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
	void glTexSubImage3D(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
	void glCopyTexSubImage3D(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
	void glColorTable(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *);
	void glColorTableParameterfv(GLenum, GLenum, const GLfloat *);
	void glColorTableParameteriv(GLenum, GLenum, const GLint *);
	void glCopyColorTable(GLenum, GLenum, GLint, GLint, GLsizei);
	void glGetColorTable(GLenum, GLenum, GLenum, GLvoid *);
	void glGetColorTableParameterfv(GLenum, GLenum, GLfloat *);
	void glGetColorTableParameteriv(GLenum, GLenum, GLint *);
	void glColorSubTable(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
	void glCopyColorSubTable(GLenum, GLsizei, GLint, GLint, GLsizei);
	void glConvolutionFilter1D(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *);
	void glConvolutionFilter2D(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
	void glConvolutionParameterf(GLenum, GLenum, GLfloat);
	void glConvolutionParameterfv(GLenum, GLenum, const GLfloat *);
	void glConvolutionParameteri(GLenum, GLenum, GLint);
	void glConvolutionParameteriv(GLenum, GLenum, const GLint *);
	void glCopyConvolutionFilter1D(GLenum, GLenum, GLint, GLint, GLsizei);
	void glCopyConvolutionFilter2D(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei);
	void glGetConvolutionFilter(GLenum, GLenum, GLenum, GLvoid *);
	void glGetConvolutionParameterfv(GLenum, GLenum, GLfloat *);
	void glGetConvolutionParameteriv(GLenum, GLenum, GLint *);
	void glGetSeparableFilter(GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *);
	void glSeparableFilter2D(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *);
	void glGetHistogram(GLenum, GLboolean, GLenum, GLenum, GLvoid *);
	void glGetHistogramParameterfv(GLenum, GLenum, GLfloat *);
	void glGetHistogramParameteriv(GLenum, GLenum, GLint *);
	void glGetMinmax(GLenum, GLboolean, GLenum, GLenum, GLvoid *);
	void glGetMinmaxParameterfv(GLenum, GLenum, GLfloat *);
	void glGetMinmaxParameteriv(GLenum, GLenum, GLint *);
	void glHistogram(GLenum, GLsizei, GLenum, GLboolean);
	void glMinmax(GLenum, GLenum, GLboolean);
	void glResetHistogram(GLenum);
	void glResetMinmax(GLenum);
	void glActiveTexture(GLenum);
	void glSampleCoverage(GLclampf, GLboolean);
	void glCompressedTexImage3D(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
	void glCompressedTexImage2D(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
	void glCompressedTexImage1D(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *);
	void glCompressedTexSubImage3D(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
	void glCompressedTexSubImage2D(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
	void glCompressedTexSubImage1D(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *);
	void glGetCompressedTexImage(GLenum, GLint, GLvoid *);
	void glClientActiveTexture(GLenum);
	void glMultiTexCoord1d(GLenum, GLdouble);
	void glMultiTexCoord1dv(GLenum, const GLdouble *);
	void glMultiTexCoord1f(GLenum, GLfloat);
	void glMultiTexCoord1fv(GLenum, const GLfloat *);
	void glMultiTexCoord1i(GLenum, GLint);
	void glMultiTexCoord1iv(GLenum, const GLint *);
	void glMultiTexCoord1s(GLenum, GLshort);
	void glMultiTexCoord1sv(GLenum, const GLshort *);
	void glMultiTexCoord2d(GLenum, GLdouble, GLdouble);
	void glMultiTexCoord2dv(GLenum, const GLdouble *);
	void glMultiTexCoord2f(GLenum, GLfloat, GLfloat);
	void glMultiTexCoord2fv(GLenum, const GLfloat *);
	void glMultiTexCoord2i(GLenum, GLint, GLint);
	void glMultiTexCoord2iv(GLenum, const GLint *);
	void glMultiTexCoord2s(GLenum, GLshort, GLshort);
	void glMultiTexCoord2sv(GLenum, const GLshort *);
	void glMultiTexCoord3d(GLenum, GLdouble, GLdouble, GLdouble);
	void glMultiTexCoord3dv(GLenum, const GLdouble *);
	void glMultiTexCoord3f(GLenum, GLfloat, GLfloat, GLfloat);
	void glMultiTexCoord3fv(GLenum, const GLfloat *);
	void glMultiTexCoord3i(GLenum, GLint, GLint, GLint);
	void glMultiTexCoord3iv(GLenum, const GLint *);
	void glMultiTexCoord3s(GLenum, GLshort, GLshort, GLshort);
	void glMultiTexCoord3sv(GLenum, const GLshort *);
	void glMultiTexCoord4d(GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
	void glMultiTexCoord4dv(GLenum, const GLdouble *);
	void glMultiTexCoord4f(GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
	void glMultiTexCoord4fv(GLenum, const GLfloat *);
	void glMultiTexCoord4i(GLenum, GLint, GLint, GLint, GLint);
	void glMultiTexCoord4iv(GLenum, const GLint *);
	void glMultiTexCoord4s(GLenum, GLshort, GLshort, GLshort, GLshort);
	void glMultiTexCoord4sv(GLenum, const GLshort *);
	void glLoadTransposeMatrixf(const GLfloat *);
	void glLoadTransposeMatrixd(const GLdouble *);
	void glMultTransposeMatrixf(const GLfloat *);
	void glMultTransposeMatrixd(const GLdouble *);
	void glBlendFuncSeparate(GLenum, GLenum, GLenum, GLenum);
	void glMultiDrawArrays(GLenum, GLint *, GLsizei *, GLsizei);
	void glMultiDrawElements(GLenum, const GLsizei *, GLenum, const GLvoid* *, GLsizei);
	void glPointParameterf(GLenum, GLfloat);
	void glPointParameterfv(GLenum, const GLfloat *);
	void glPointParameteri(GLenum, GLint);
	void glPointParameteriv(GLenum, const GLint *);
	void glFogCoordf(GLfloat);
	void glFogCoordfv(const GLfloat *);
	void glFogCoordd(GLdouble);
	void glFogCoorddv(const GLdouble *);
	void glFogCoordPointer(GLenum, GLsizei, const GLvoid *);
	void glSecondaryColor3b(GLbyte, GLbyte, GLbyte);
	void glSecondaryColor3bv(const GLbyte *);
	void glSecondaryColor3d(GLdouble, GLdouble, GLdouble);
	void glSecondaryColor3dv(const GLdouble *);
	void glSecondaryColor3f(GLfloat, GLfloat, GLfloat);
	void glSecondaryColor3fv(const GLfloat *);
	void glSecondaryColor3i(GLint, GLint, GLint);
	void glSecondaryColor3iv(const GLint *);
	void glSecondaryColor3s(GLshort, GLshort, GLshort);
	void glSecondaryColor3sv(const GLshort *);
	void glSecondaryColor3ub(GLubyte, GLubyte, GLubyte);
	void glSecondaryColor3ubv(const GLubyte *);
	void glSecondaryColor3ui(GLuint, GLuint, GLuint);
	void glSecondaryColor3uiv(const GLuint *);
	void glSecondaryColor3us(GLushort, GLushort, GLushort);
	void glSecondaryColor3usv(const GLushort *);
	void glSecondaryColorPointer(GLint, GLenum, GLsizei, const GLvoid *);
	void glWindowPos2d(GLdouble, GLdouble);
	void glWindowPos2dv(const GLdouble *);
	void glWindowPos2f(GLfloat, GLfloat);
	void glWindowPos2fv(const GLfloat *);
	void glWindowPos2i(GLint, GLint);
	void glWindowPos2iv(const GLint *);
	void glWindowPos2s(GLshort, GLshort);
	void glWindowPos2sv(const GLshort *);
	void glWindowPos3d(GLdouble, GLdouble, GLdouble);
	void glWindowPos3dv(const GLdouble *);
	void glWindowPos3f(GLfloat, GLfloat, GLfloat);
	void glWindowPos3fv(const GLfloat *);
	void glWindowPos3i(GLint, GLint, GLint);
	void glWindowPos3iv(const GLint *);
	void glWindowPos3s(GLshort, GLshort, GLshort);
	void glWindowPos3sv(const GLshort *);
	void glGenQueries(GLsizei, GLuint *);
	void glDeleteQueries(GLsizei, const GLuint *);
	GLboolean glIsQuery(GLuint);
	void glBeginQuery(GLenum, GLuint);
	void glEndQuery(GLenum);
	void glGetQueryiv(GLenum, GLenum, GLint *);
	void glGetQueryObjectiv(GLuint, GLenum, GLint *);
	void glGetQueryObjectuiv(GLuint, GLenum, GLuint *);
	void glBindBuffer(GLenum, GLuint);
	void glDeleteBuffers(GLsizei, const GLuint *);
	void glGenBuffers(GLsizei, GLuint *);
	GLboolean glIsBuffer(GLuint);
	void glBufferData(GLenum, GLsizeiptr, const GLvoid *, GLenum);
	void glBufferSubData(GLenum, GLintptr, GLsizeiptr, const GLvoid *);
	void glGetBufferSubData(GLenum, GLintptr, GLsizeiptr, GLvoid *);
	GLvoid* glMapBuffer(GLenum, GLenum);
	GLboolean glUnmapBuffer(GLenum);
	void glGetBufferParameteriv(GLenum, GLenum, GLint *);
	void glGetBufferPointerv(GLenum, GLenum, GLvoid* *);
	void glBlendEquationSeparate(GLenum, GLenum);
	void glDrawBuffers(GLsizei, const GLenum *);
	void glStencilOpSeparate(GLenum, GLenum, GLenum, GLenum);
	void glStencilFuncSeparate(GLenum, GLenum, GLint, GLuint);
	void glStencilMaskSeparate(GLenum, GLuint);
	void glAttachShader(GLuint, GLuint);
	void glBindAttribLocation(GLuint, GLuint, const GLchar *);
	void glCompileShader(GLuint);
	GLuint glCreateProgram(void);
	GLuint glCreateShader(GLenum);
	void glDeleteProgram(GLuint);
	void glDeleteShader(GLuint);
	void glDetachShader(GLuint, GLuint);
	void glDisableVertexAttribArray(GLuint);
	void glEnableVertexAttribArray(GLuint);
	void glGetActiveAttrib(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *);
	void glGetActiveUniform(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *);
	void glGetAttachedShaders(GLuint, GLsizei, GLsizei *, GLuint *);
	GLint glGetAttribLocation(GLuint, const GLchar *);
	void glGetProgramiv(GLuint, GLenum, GLint *);
	void glGetProgramInfoLog(GLuint, GLsizei, GLsizei *, GLchar *);
	void glGetShaderiv(GLuint, GLenum, GLint *);
	void glGetShaderInfoLog(GLuint, GLsizei, GLsizei *, GLchar *);
	void glGetShaderSource(GLuint, GLsizei, GLsizei *, GLchar *);
	GLint glGetUniformLocation(GLuint, const GLchar *);
	void glGetUniformfv(GLuint, GLint, GLfloat *);
	void glGetUniformiv(GLuint, GLint, GLint *);
	void glGetVertexAttribdv(GLuint, GLenum, GLdouble *);
	void glGetVertexAttribfv(GLuint, GLenum, GLfloat *);
	void glGetVertexAttribiv(GLuint, GLenum, GLint *);
	void glGetVertexAttribPointerv(GLuint, GLenum, GLvoid* *);
	GLboolean glIsProgram(GLuint);
	GLboolean glIsShader(GLuint);
	void glLinkProgram(GLuint);
	void glShaderSource(GLuint, GLsizei, const GLchar* *, const GLint *);
	void glUseProgram(GLuint);
	void glUniform1f(GLint, GLfloat);
	void glUniform2f(GLint, GLfloat, GLfloat);
	void glUniform3f(GLint, GLfloat, GLfloat, GLfloat);
	void glUniform4f(GLint, GLfloat, GLfloat, GLfloat, GLfloat);
	void glUniform1i(GLint, GLint);
	void glUniform2i(GLint, GLint, GLint);
	void glUniform3i(GLint, GLint, GLint, GLint);
	void glUniform4i(GLint, GLint, GLint, GLint, GLint);
	void glUniform1fv(GLint, GLsizei, const GLfloat *);
	void glUniform2fv(GLint, GLsizei, const GLfloat *);
	void glUniform3fv(GLint, GLsizei, const GLfloat *);
	void glUniform4fv(GLint, GLsizei, const GLfloat *);
	void glUniform1iv(GLint, GLsizei, const GLint *);
	void glUniform2iv(GLint, GLsizei, const GLint *);
	void glUniform3iv(GLint, GLsizei, const GLint *);
	void glUniform4iv(GLint, GLsizei, const GLint *);
	void glUniformMatrix2fv(GLint, GLsizei, GLboolean, const GLfloat *);
	void glUniformMatrix3fv(GLint, GLsizei, GLboolean, const GLfloat *);
	void glUniformMatrix4fv(GLint, GLsizei, GLboolean, const GLfloat *);
	void glValidateProgram(GLuint);
	void glVertexAttrib1d(GLuint, GLdouble);
	void glVertexAttrib1dv(GLuint, const GLdouble *);
	void glVertexAttrib1f(GLuint, GLfloat);
	void glVertexAttrib1fv(GLuint, const GLfloat *);
	void glVertexAttrib1s(GLuint, GLshort);
	void glVertexAttrib1sv(GLuint, const GLshort *);
	void glVertexAttrib2d(GLuint, GLdouble, GLdouble);
	void glVertexAttrib2dv(GLuint, const GLdouble *);
	void glVertexAttrib2f(GLuint, GLfloat, GLfloat);
	void glVertexAttrib2fv(GLuint, const GLfloat *);
	void glVertexAttrib2s(GLuint, GLshort, GLshort);
	void glVertexAttrib2sv(GLuint, const GLshort *);
	void glVertexAttrib3d(GLuint, GLdouble, GLdouble, GLdouble);
	void glVertexAttrib3dv(GLuint, const GLdouble *);
	void glVertexAttrib3f(GLuint, GLfloat, GLfloat, GLfloat);
	void glVertexAttrib3fv(GLuint, const GLfloat *);
	void glVertexAttrib3s(GLuint, GLshort, GLshort, GLshort);
	void glVertexAttrib3sv(GLuint, const GLshort *);
	void glVertexAttrib4Nbv(GLuint, const GLbyte *);
	void glVertexAttrib4Niv(GLuint, const GLint *);
	void glVertexAttrib4Nsv(GLuint, const GLshort *);
	void glVertexAttrib4Nub(GLuint, GLubyte, GLubyte, GLubyte, GLubyte);
	void glVertexAttrib4Nubv(GLuint, const GLubyte *);
	void glVertexAttrib4Nuiv(GLuint, const GLuint *);
	void glVertexAttrib4Nusv(GLuint, const GLushort *);
	void glVertexAttrib4bv(GLuint, const GLbyte *);
	void glVertexAttrib4d(GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
	void glVertexAttrib4dv(GLuint, const GLdouble *);
	void glVertexAttrib4f(GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
	void glVertexAttrib4fv(GLuint, const GLfloat *);
	void glVertexAttrib4iv(GLuint, const GLint *);
	void glVertexAttrib4s(GLuint, GLshort, GLshort, GLshort, GLshort);
	void glVertexAttrib4sv(GLuint, const GLshort *);
	void glVertexAttrib4ubv(GLuint, const GLubyte *);
	void glVertexAttrib4uiv(GLuint, const GLuint *);
	void glVertexAttrib4usv(GLuint, const GLushort *);
	void glVertexAttribPointer(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *);
	void glUniformMatrix2x3fv(GLint, GLsizei, GLboolean, const GLfloat *);
	void glUniformMatrix3x2fv(GLint, GLsizei, GLboolean, const GLfloat *);
	void glUniformMatrix2x4fv(GLint, GLsizei, GLboolean, const GLfloat *);
	void glUniformMatrix4x2fv(GLint, GLsizei, GLboolean, const GLfloat *);
	void glUniformMatrix3x4fv(GLint, GLsizei, GLboolean, const GLfloat *);
	void glUniformMatrix4x3fv(GLint, GLsizei, GLboolean, const GLfloat *);
	void glColorMaski(GLuint, GLboolean, GLboolean, GLboolean, GLboolean);
	void glGetBooleani_v(GLenum, GLuint, GLboolean *);
	void glGetIntegeri_v(GLenum, GLuint, GLint *);
	void glEnablei(GLenum, GLuint);
	void glDisablei(GLenum, GLuint);
	GLboolean glIsEnabledi(GLenum, GLuint);
	void glBeginTransformFeedback(GLenum);
	void glEndTransformFeedback(void);
	void glBindBufferRange(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr);
	void glBindBufferBase(GLenum, GLuint, GLuint);
	void glTransformFeedbackVaryings(GLuint, GLsizei, const GLchar* *, GLenum);
	void glGetTransformFeedbackVarying(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *);
	void glClampColor(GLenum, GLenum);
	void glBeginConditionalRender(GLuint, GLenum);
	void glEndConditionalRender(void);
	void glVertexAttribIPointer(GLuint, GLint, GLenum, GLsizei, const GLvoid *);
	void glGetVertexAttribIiv(GLuint, GLenum, GLint *);
	void glGetVertexAttribIuiv(GLuint, GLenum, GLuint *);
	void glVertexAttribI1i(GLuint, GLint);
	void glVertexAttribI2i(GLuint, GLint, GLint);
	void glVertexAttribI3i(GLuint, GLint, GLint, GLint);
	void glVertexAttribI4i(GLuint, GLint, GLint, GLint, GLint);
	void glVertexAttribI1ui(GLuint, GLuint);
	void glVertexAttribI2ui(GLuint, GLuint, GLuint);
	void glVertexAttribI3ui(GLuint, GLuint, GLuint, GLuint);
	void glVertexAttribI4ui(GLuint, GLuint, GLuint, GLuint, GLuint);
	void glVertexAttribI1iv(GLuint, const GLint *);
	void glVertexAttribI2iv(GLuint, const GLint *);
	void glVertexAttribI3iv(GLuint, const GLint *);
	void glVertexAttribI4iv(GLuint, const GLint *);
	void glVertexAttribI1uiv(GLuint, const GLuint *);
	void glVertexAttribI2uiv(GLuint, const GLuint *);
	void glVertexAttribI3uiv(GLuint, const GLuint *);
	void glVertexAttribI4uiv(GLuint, const GLuint *);
	void glVertexAttribI4bv(GLuint, const GLbyte *);
	void glVertexAttribI4sv(GLuint, const GLshort *);
	void glVertexAttribI4ubv(GLuint, const GLubyte *);
	void glVertexAttribI4usv(GLuint, const GLushort *);
	void glGetUniformuiv(GLuint, GLint, GLuint *);
	void glBindFragDataLocation(GLuint, GLuint, const GLchar *);
	GLint glGetFragDataLocation(GLuint, const GLchar *);
	void glUniform1ui(GLint, GLuint);
	void glUniform2ui(GLint, GLuint, GLuint);
	void glUniform3ui(GLint, GLuint, GLuint, GLuint);
	void glUniform4ui(GLint, GLuint, GLuint, GLuint, GLuint);
	void glUniform1uiv(GLint, GLsizei, const GLuint *);
	void glUniform2uiv(GLint, GLsizei, const GLuint *);
	void glUniform3uiv(GLint, GLsizei, const GLuint *);
	void glUniform4uiv(GLint, GLsizei, const GLuint *);
	void glTexParameterIiv(GLenum, GLenum, const GLint *);
	void glTexParameterIuiv(GLenum, GLenum, const GLuint *);
	void glGetTexParameterIiv(GLenum, GLenum, GLint *);
	void glGetTexParameterIuiv(GLenum, GLenum, GLuint *);
	void glClearBufferiv(GLenum, GLint, const GLint *);
	void glClearBufferuiv(GLenum, GLint, const GLuint *);
	void glClearBufferfv(GLenum, GLint, const GLfloat *);
	void glClearBufferfi(GLenum, GLint, GLfloat, GLint);
	const GLubyte * glGetStringi(GLenum, GLuint);
	void glDrawArraysInstanced(GLenum, GLint, GLsizei, GLsizei);
	void glDrawElementsInstanced(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei);
	void glTexBuffer(GLenum, GLenum, GLuint);
	void glPrimitiveRestartIndex(GLuint);
	void glGetInteger64i_v(GLenum, GLuint, GLint64 *);
	void glGetBufferParameteri64v(GLenum, GLenum, GLint64 *);
	void glProgramParameteri(GLuint, GLenum, GLint);
	void glFramebufferTexture(GLenum, GLenum, GLuint, GLint);
	void glFramebufferTextureFace(GLenum, GLenum, GLuint, GLint, GLenum);
	void glActiveTextureARB(GLenum);
	void glClientActiveTextureARB(GLenum);
	void glMultiTexCoord1dARB(GLenum, GLdouble);
	void glMultiTexCoord1dvARB(GLenum, const GLdouble *);
	void glMultiTexCoord1fARB(GLenum, GLfloat);
	void glMultiTexCoord1fvARB(GLenum, const GLfloat *);
	void glMultiTexCoord1iARB(GLenum, GLint);
	void glMultiTexCoord1ivARB(GLenum, const GLint *);
	void glMultiTexCoord1sARB(GLenum, GLshort);
	void glMultiTexCoord1svARB(GLenum, const GLshort *);
	void glMultiTexCoord2dARB(GLenum, GLdouble, GLdouble);
	void glMultiTexCoord2dvARB(GLenum, const GLdouble *);
	void glMultiTexCoord2fARB(GLenum, GLfloat, GLfloat);
	void glMultiTexCoord2fvARB(GLenum, const GLfloat *);
	void glMultiTexCoord2iARB(GLenum, GLint, GLint);
	void glMultiTexCoord2ivARB(GLenum, const GLint *);
	void glMultiTexCoord2sARB(GLenum, GLshort, GLshort);
	void glMultiTexCoord2svARB(GLenum, const GLshort *);
	void glMultiTexCoord3dARB(GLenum, GLdouble, GLdouble, GLdouble);
	void glMultiTexCoord3dvARB(GLenum, const GLdouble *);
	void glMultiTexCoord3fARB(GLenum, GLfloat, GLfloat, GLfloat);
	void glMultiTexCoord3fvARB(GLenum, const GLfloat *);
	void glMultiTexCoord3iARB(GLenum, GLint, GLint, GLint);
	void glMultiTexCoord3ivARB(GLenum, const GLint *);
	void glMultiTexCoord3sARB(GLenum, GLshort, GLshort, GLshort);
	void glMultiTexCoord3svARB(GLenum, const GLshort *);
	void glMultiTexCoord4dARB(GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
	void glMultiTexCoord4dvARB(GLenum, const GLdouble *);
	void glMultiTexCoord4fARB(GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
	void glMultiTexCoord4fvARB(GLenum, const GLfloat *);
	void glMultiTexCoord4iARB(GLenum, GLint, GLint, GLint, GLint);
	void glMultiTexCoord4ivARB(GLenum, const GLint *);
	void glMultiTexCoord4sARB(GLenum, GLshort, GLshort, GLshort, GLshort);
	void glMultiTexCoord4svARB(GLenum, const GLshort *);
	void glLoadTransposeMatrixfARB(const GLfloat *);
	void glLoadTransposeMatrixdARB(const GLdouble *);
	void glMultTransposeMatrixfARB(const GLfloat *);
	void glMultTransposeMatrixdARB(const GLdouble *);
	void glSampleCoverageARB(GLclampf, GLboolean);
	void glCompressedTexImage3DARB(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
	void glCompressedTexImage2DARB(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
	void glCompressedTexImage1DARB(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *);
	void glCompressedTexSubImage3DARB(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
	void glCompressedTexSubImage2DARB(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
	void glCompressedTexSubImage1DARB(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *);
	void glGetCompressedTexImageARB(GLenum, GLint, GLvoid *);
	void glPointParameterfARB(GLenum, GLfloat);
	void glPointParameterfvARB(GLenum, const GLfloat *);
	void glWeightbvARB(GLint, const GLbyte *);
	void glWeightsvARB(GLint, const GLshort *);
	void glWeightivARB(GLint, const GLint *);
	void glWeightfvARB(GLint, const GLfloat *);
	void glWeightdvARB(GLint, const GLdouble *);
	void glWeightubvARB(GLint, const GLubyte *);
	void glWeightusvARB(GLint, const GLushort *);
	void glWeightuivARB(GLint, const GLuint *);
	void glWeightPointerARB(GLint, GLenum, GLsizei, const GLvoid *);
	void glVertexBlendARB(GLint);
	void glCurrentPaletteMatrixARB(GLint);
	void glMatrixIndexubvARB(GLint, const GLubyte *);
	void glMatrixIndexusvARB(GLint, const GLushort *);
	void glMatrixIndexuivARB(GLint, const GLuint *);
	void glMatrixIndexPointerARB(GLint, GLenum, GLsizei, const GLvoid *);
	void glWindowPos2dARB(GLdouble, GLdouble);
	void glWindowPos2dvARB(const GLdouble *);
	void glWindowPos2fARB(GLfloat, GLfloat);
	void glWindowPos2fvARB(const GLfloat *);
	void glWindowPos2iARB(GLint, GLint);
	void glWindowPos2ivARB(const GLint *);
	void glWindowPos2sARB(GLshort, GLshort);
	void glWindowPos2svARB(const GLshort *);
	void glWindowPos3dARB(GLdouble, GLdouble, GLdouble);
	void glWindowPos3dvARB(const GLdouble *);
	void glWindowPos3fARB(GLfloat, GLfloat, GLfloat);
	void glWindowPos3fvARB(const GLfloat *);
	void glWindowPos3iARB(GLint, GLint, GLint);
	void glWindowPos3ivARB(const GLint *);
	void glWindowPos3sARB(GLshort, GLshort, GLshort);
	void glWindowPos3svARB(const GLshort *);
	void glVertexAttrib1dARB(GLuint, GLdouble);
	void glVertexAttrib1dvARB(GLuint, const GLdouble *);
	void glVertexAttrib1fARB(GLuint, GLfloat);
	void glVertexAttrib1fvARB(GLuint, const GLfloat *);
	void glVertexAttrib1sARB(GLuint, GLshort);
	void glVertexAttrib1svARB(GLuint, const GLshort *);
	void glVertexAttrib2dARB(GLuint, GLdouble, GLdouble);
	void glVertexAttrib2dvARB(GLuint, const GLdouble *);
	void glVertexAttrib2fARB(GLuint, GLfloat, GLfloat);
	void glVertexAttrib2fvARB(GLuint, const GLfloat *);
	void glVertexAttrib2sARB(GLuint, GLshort, GLshort);
	void glVertexAttrib2svARB(GLuint, const GLshort *);
	void glVertexAttrib3dARB(GLuint, GLdouble, GLdouble, GLdouble);
	void glVertexAttrib3dvARB(GLuint, const GLdouble *);
	void glVertexAttrib3fARB(GLuint, GLfloat, GLfloat, GLfloat);
	void glVertexAttrib3fvARB(GLuint, const GLfloat *);
	void glVertexAttrib3sARB(GLuint, GLshort, GLshort, GLshort);
	void glVertexAttrib3svARB(GLuint, const GLshort *);
	void glVertexAttrib4NbvARB(GLuint, const GLbyte *);
	void glVertexAttrib4NivARB(GLuint, const GLint *);
	void glVertexAttrib4NsvARB(GLuint, const GLshort *);
	void glVertexAttrib4NubARB(GLuint, GLubyte, GLubyte, GLubyte, GLubyte);
	void glVertexAttrib4NubvARB(GLuint, const GLubyte *);
	void glVertexAttrib4NuivARB(GLuint, const GLuint *);
	void glVertexAttrib4NusvARB(GLuint, const GLushort *);
	void glVertexAttrib4bvARB(GLuint, const GLbyte *);
	void glVertexAttrib4dARB(GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
	void glVertexAttrib4dvARB(GLuint, const GLdouble *);
	void glVertexAttrib4fARB(GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
	void glVertexAttrib4fvARB(GLuint, const GLfloat *);
	void glVertexAttrib4ivARB(GLuint, const GLint *);
	void glVertexAttrib4sARB(GLuint, GLshort, GLshort, GLshort, GLshort);
	void glVertexAttrib4svARB(GLuint, const GLshort *);
	void glVertexAttrib4ubvARB(GLuint, const GLubyte *);
	void glVertexAttrib4uivARB(GLuint, const GLuint *);
	void glVertexAttrib4usvARB(GLuint, const GLushort *);
	void glVertexAttribPointerARB(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *);
	void glEnableVertexAttribArrayARB(GLuint);
	void glDisableVertexAttribArrayARB(GLuint);
	void glProgramStringARB(GLenum, GLenum, GLsizei, const GLvoid *);
	void glBindProgramARB(GLenum, GLuint);
	void glDeleteProgramsARB(GLsizei, const GLuint *);
	void glGenProgramsARB(GLsizei, GLuint *);
	void glProgramEnvParameter4dARB(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
	void glProgramEnvParameter4dvARB(GLenum, GLuint, const GLdouble *);
	void glProgramEnvParameter4fARB(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
	void glProgramEnvParameter4fvARB(GLenum, GLuint, const GLfloat *);
	void glProgramLocalParameter4dARB(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
	void glProgramLocalParameter4dvARB(GLenum, GLuint, const GLdouble *);
	void glProgramLocalParameter4fARB(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
	void glProgramLocalParameter4fvARB(GLenum, GLuint, const GLfloat *);
	void glGetProgramEnvParameterdvARB(GLenum, GLuint, GLdouble *);
	void glGetProgramEnvParameterfvARB(GLenum, GLuint, GLfloat *);
	void glGetProgramLocalParameterdvARB(GLenum, GLuint, GLdouble *);
	void glGetProgramLocalParameterfvARB(GLenum, GLuint, GLfloat *);
	void glGetProgramivARB(GLenum, GLenum, GLint *);
	void glGetProgramStringARB(GLenum, GLenum, GLvoid *);
	void glGetVertexAttribdvARB(GLuint, GLenum, GLdouble *);
	void glGetVertexAttribfvARB(GLuint, GLenum, GLfloat *);
	void glGetVertexAttribivARB(GLuint, GLenum, GLint *);
	void glGetVertexAttribPointervARB(GLuint, GLenum, GLvoid* *);
	GLboolean glIsProgramARB(GLuint);
	void glBindBufferARB(GLenum, GLuint);
	void glDeleteBuffersARB(GLsizei, const GLuint *);
	void glGenBuffersARB(GLsizei, GLuint *);
	GLboolean glIsBufferARB(GLuint);
	void glBufferDataARB(GLenum, GLsizeiptrARB, const GLvoid *, GLenum);
	void glBufferSubDataARB(GLenum, GLintptrARB, GLsizeiptrARB, const GLvoid *);
	void glGetBufferSubDataARB(GLenum, GLintptrARB, GLsizeiptrARB, GLvoid *);
	GLvoid* glMapBufferARB(GLenum, GLenum);
	GLboolean glUnmapBufferARB(GLenum);
	void glGetBufferParameterivARB(GLenum, GLenum, GLint *);
	void glGetBufferPointervARB(GLenum, GLenum, GLvoid* *);
	void glGenQueriesARB(GLsizei, GLuint *);
	void glDeleteQueriesARB(GLsizei, const GLuint *);
	GLboolean glIsQueryARB(GLuint);
	void glBeginQueryARB(GLenum, GLuint);
	void glEndQueryARB(GLenum);
	void glGetQueryivARB(GLenum, GLenum, GLint *);
	void glGetQueryObjectivARB(GLuint, GLenum, GLint *);
	void glGetQueryObjectuivARB(GLuint, GLenum, GLuint *);
	void glDeleteObjectARB(GLhandleARB);
	GLhandleARB glGetHandleARB(GLenum);
	void glDetachObjectARB(GLhandleARB, GLhandleARB);
	GLhandleARB glCreateShaderObjectARB(GLenum);
	void glShaderSourceARB(GLhandleARB, GLsizei, const GLcharARB* *, const GLint *);
	void glCompileShaderARB(GLhandleARB);
	GLhandleARB glCreateProgramObjectARB(void);
	void glAttachObjectARB(GLhandleARB, GLhandleARB);
	void glLinkProgramARB(GLhandleARB);
	void glUseProgramObjectARB(GLhandleARB);
	void glValidateProgramARB(GLhandleARB);
	void glUniform1fARB(GLint, GLfloat);
	void glUniform2fARB(GLint, GLfloat, GLfloat);
	void glUniform3fARB(GLint, GLfloat, GLfloat, GLfloat);
	void glUniform4fARB(GLint, GLfloat, GLfloat, GLfloat, GLfloat);
	void glUniform1iARB(GLint, GLint);
	void glUniform2iARB(GLint, GLint, GLint);
	void glUniform3iARB(GLint, GLint, GLint, GLint);
	void glUniform4iARB(GLint, GLint, GLint, GLint, GLint);
	void glUniform1fvARB(GLint, GLsizei, const GLfloat *);
	void glUniform2fvARB(GLint, GLsizei, const GLfloat *);
	void glUniform3fvARB(GLint, GLsizei, const GLfloat *);
	void glUniform4fvARB(GLint, GLsizei, const GLfloat *);
	void glUniform1ivARB(GLint, GLsizei, const GLint *);
	void glUniform2ivARB(GLint, GLsizei, const GLint *);
	void glUniform3ivARB(GLint, GLsizei, const GLint *);
	void glUniform4ivARB(GLint, GLsizei, const GLint *);
	void glUniformMatrix2fvARB(GLint, GLsizei, GLboolean, const GLfloat *);
	void glUniformMatrix3fvARB(GLint, GLsizei, GLboolean, const GLfloat *);
	void glUniformMatrix4fvARB(GLint, GLsizei, GLboolean, const GLfloat *);
	void glGetObjectParameterfvARB(GLhandleARB, GLenum, GLfloat *);
	void glGetObjectParameterivARB(GLhandleARB, GLenum, GLint *);
	void glGetInfoLogARB(GLhandleARB, GLsizei, GLsizei *, GLcharARB *);
	void glGetAttachedObjectsARB(GLhandleARB, GLsizei, GLsizei *, GLhandleARB *);
	GLint glGetUniformLocationARB(GLhandleARB, const GLcharARB *);
	void glGetActiveUniformARB(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *);
	void glGetUniformfvARB(GLhandleARB, GLint, GLfloat *);
	void glGetUniformivARB(GLhandleARB, GLint, GLint *);
	void glGetShaderSourceARB(GLhandleARB, GLsizei, GLsizei *, GLcharARB *);
	void glBindAttribLocationARB(GLhandleARB, GLuint, const GLcharARB *);
	void glGetActiveAttribARB(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *);
	GLint glGetAttribLocationARB(GLhandleARB, const GLcharARB *);
	void glDrawBuffersARB(GLsizei, const GLenum *);
	void glClampColorARB(GLenum, GLenum);
	void glDrawArraysInstancedARB(GLenum, GLint, GLsizei, GLsizei);
	void glDrawElementsInstancedARB(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei);
	GLboolean glIsRenderbuffer(GLuint);
	void glBindRenderbuffer(GLenum, GLuint);
	void glDeleteRenderbuffers(GLsizei, const GLuint *);
	void glGenRenderbuffers(GLsizei, GLuint *);
	void glRenderbufferStorage(GLenum, GLenum, GLsizei, GLsizei);
	void glGetRenderbufferParameteriv(GLenum, GLenum, GLint *);
	GLboolean glIsFramebuffer(GLuint);
	void glBindFramebuffer(GLenum, GLuint);
	void glDeleteFramebuffers(GLsizei, const GLuint *);
	void glGenFramebuffers(GLsizei, GLuint *);
	GLenum glCheckFramebufferStatus(GLenum);
	void glFramebufferTexture1D(GLenum, GLenum, GLenum, GLuint, GLint);
	void glFramebufferTexture2D(GLenum, GLenum, GLenum, GLuint, GLint);
	void glFramebufferTexture3D(GLenum, GLenum, GLenum, GLuint, GLint, GLint);
	void glFramebufferRenderbuffer(GLenum, GLenum, GLenum, GLuint);
	void glGetFramebufferAttachmentParameteriv(GLenum, GLenum, GLenum, GLint *);
	void glGenerateMipmap(GLenum);
	void glBlitFramebuffer(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum);
	void glRenderbufferStorageMultisample(GLenum, GLsizei, GLenum, GLsizei, GLsizei);
	void glFramebufferTextureLayer(GLenum, GLenum, GLuint, GLint, GLint);
	void glProgramParameteriARB(GLuint, GLenum, GLint);
	void glFramebufferTextureARB(GLenum, GLenum, GLuint, GLint);
	void glFramebufferTextureLayerARB(GLenum, GLenum, GLuint, GLint, GLint);
	void glFramebufferTextureFaceARB(GLenum, GLenum, GLuint, GLint, GLenum);
	void glVertexAttribDivisorARB(GLuint, GLuint);
	GLvoid* glMapBufferRange(GLenum, GLintptr, GLsizeiptr, GLbitfield);
	void glFlushMappedBufferRange(GLenum, GLintptr, GLsizeiptr);
	void glTexBufferARB(GLenum, GLenum, GLuint);
	void glBindVertexArray(GLuint);
	void glDeleteVertexArrays(GLsizei, const GLuint *);
	void glGenVertexArrays(GLsizei, GLuint *);
	GLboolean glIsVertexArray(GLuint);
	void glGetUniformIndices(GLuint, GLsizei, const GLchar* *, GLuint *);
	void glGetActiveUniformsiv(GLuint, GLsizei, const GLuint *, GLenum, GLint *);
	void glGetActiveUniformName(GLuint, GLuint, GLsizei, GLsizei *, GLchar *);
	GLuint glGetUniformBlockIndex(GLuint, const GLchar *);
	void glGetActiveUniformBlockiv(GLuint, GLuint, GLenum, GLint *);
	void glGetActiveUniformBlockName(GLuint, GLuint, GLsizei, GLsizei *, GLchar *);
	void glUniformBlockBinding(GLuint, GLuint, GLuint);
	void glCopyBufferSubData(GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr);
	void glDrawElementsBaseVertex(GLenum, GLsizei, GLenum, const GLvoid *, GLint);
	void glDrawRangeElementsBaseVertex(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *, GLint);
	void glDrawElementsInstancedBaseVertex(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei, GLint);
	void glMultiDrawElementsBaseVertex(GLenum, const GLsizei *, GLenum, const GLvoid* *, GLsizei, const GLint *);
	void glProvokingVertex(GLenum);
	GLsync glFenceSync(GLenum, GLbitfield);
	GLboolean glIsSync(GLsync);
	void glDeleteSync(GLsync);
	GLenum glClientWaitSync(GLsync, GLbitfield, GLuint64);
	void glWaitSync(GLsync, GLbitfield, GLuint64);
	void glGetInteger64v(GLenum, GLint64 *);
	void glGetSynciv(GLsync, GLenum, GLsizei, GLsizei *, GLint *);
	void glTexImage2DMultisample(GLenum, GLsizei, GLint, GLsizei, GLsizei, GLboolean);
	void glTexImage3DMultisample(GLenum, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean);
	void glGetMultisamplefv(GLenum, GLuint, GLfloat *);
	void glSampleMaski(GLuint, GLbitfield);
	void glBlendEquationi(GLuint, GLenum);
	void glBlendEquationSeparatei(GLuint, GLenum, GLenum);
	void glBlendFunci(GLuint, GLenum, GLenum);
	void glBlendFuncSeparatei(GLuint, GLenum, GLenum, GLenum, GLenum);
	void glMinSampleShading(GLclampf);
	void glBlendColorEXT(GLclampf, GLclampf, GLclampf, GLclampf);
	void glPolygonOffsetEXT(GLfloat, GLfloat);
	void glTexImage3DEXT(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
	void glTexSubImage3DEXT(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
	void glGetTexFilterFuncSGIS(GLenum, GLenum, GLfloat *);
	void glTexFilterFuncSGIS(GLenum, GLenum, GLsizei, const GLfloat *);
	void glTexSubImage1DEXT(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *);
	void glTexSubImage2DEXT(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
	void glCopyTexImage1DEXT(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
	void glCopyTexImage2DEXT(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
	void glCopyTexSubImage1DEXT(GLenum, GLint, GLint, GLint, GLint, GLsizei);
	void glCopyTexSubImage2DEXT(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
	void glCopyTexSubImage3DEXT(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
	void glGetHistogramEXT(GLenum, GLboolean, GLenum, GLenum, GLvoid *);
	void glGetHistogramParameterfvEXT(GLenum, GLenum, GLfloat *);
	void glGetHistogramParameterivEXT(GLenum, GLenum, GLint *);
	void glGetMinmaxEXT(GLenum, GLboolean, GLenum, GLenum, GLvoid *);
	void glGetMinmaxParameterfvEXT(GLenum, GLenum, GLfloat *);
	void glGetMinmaxParameterivEXT(GLenum, GLenum, GLint *);
	void glHistogramEXT(GLenum, GLsizei, GLenum, GLboolean);
	void glMinmaxEXT(GLenum, GLenum, GLboolean);
	void glResetHistogramEXT(GLenum);
	void glResetMinmaxEXT(GLenum);
	void glConvolutionFilter1DEXT(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *);
	void glConvolutionFilter2DEXT(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
	void glConvolutionParameterfEXT(GLenum, GLenum, GLfloat);
	void glConvolutionParameterfvEXT(GLenum, GLenum, const GLfloat *);
	void glConvolutionParameteriEXT(GLenum, GLenum, GLint);
	void glConvolutionParameterivEXT(GLenum, GLenum, const GLint *);
	void glCopyConvolutionFilter1DEXT(GLenum, GLenum, GLint, GLint, GLsizei);
	void glCopyConvolutionFilter2DEXT(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei);
	void glGetConvolutionFilterEXT(GLenum, GLenum, GLenum, GLvoid *);
	void glGetConvolutionParameterfvEXT(GLenum, GLenum, GLfloat *);
	void glGetConvolutionParameterivEXT(GLenum, GLenum, GLint *);
	void glGetSeparableFilterEXT(GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *);
	void glSeparableFilter2DEXT(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *);
	void glColorTableSGI(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *);
	void glColorTableParameterfvSGI(GLenum, GLenum, const GLfloat *);
	void glColorTableParameterivSGI(GLenum, GLenum, const GLint *);
	void glCopyColorTableSGI(GLenum, GLenum, GLint, GLint, GLsizei);
	void glGetColorTableSGI(GLenum, GLenum, GLenum, GLvoid *);
	void glGetColorTableParameterfvSGI(GLenum, GLenum, GLfloat *);
	void glGetColorTableParameterivSGI(GLenum, GLenum, GLint *);
	void glPixelTexGenSGIX(GLenum);
	void glPixelTexGenParameteriSGIS(GLenum, GLint);
	void glPixelTexGenParameterivSGIS(GLenum, const GLint *);
	void glPixelTexGenParameterfSGIS(GLenum, GLfloat);
	void glPixelTexGenParameterfvSGIS(GLenum, const GLfloat *);
	void glGetPixelTexGenParameterivSGIS(GLenum, GLint *);
	void glGetPixelTexGenParameterfvSGIS(GLenum, GLfloat *);
	void glTexImage4DSGIS(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
	void glTexSubImage4DSGIS(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
	GLboolean glAreTexturesResidentEXT(GLsizei, const GLuint *, GLboolean *);
	void glBindTextureEXT(GLenum, GLuint);
	void glDeleteTexturesEXT(GLsizei, const GLuint *);
	void glGenTexturesEXT(GLsizei, GLuint *);
	GLboolean glIsTextureEXT(GLuint);
	void glPrioritizeTexturesEXT(GLsizei, const GLuint *, const GLclampf *);
	void glDetailTexFuncSGIS(GLenum, GLsizei, const GLfloat *);
	void glGetDetailTexFuncSGIS(GLenum, GLfloat *);
	void glSharpenTexFuncSGIS(GLenum, GLsizei, const GLfloat *);
	void glGetSharpenTexFuncSGIS(GLenum, GLfloat *);
	void glSampleMaskSGIS(GLclampf, GLboolean);
	void glSamplePatternSGIS(GLenum);
	void glArrayElementEXT(GLint);
	void glColorPointerEXT(GLint, GLenum, GLsizei, GLsizei, const GLvoid *);
	void glDrawArraysEXT(GLenum, GLint, GLsizei);
	void glEdgeFlagPointerEXT(GLsizei, GLsizei, const GLboolean *);
	void glGetPointervEXT(GLenum, GLvoid* *);
	void glIndexPointerEXT(GLenum, GLsizei, GLsizei, const GLvoid *);
	void glNormalPointerEXT(GLenum, GLsizei, GLsizei, const GLvoid *);
	void glTexCoordPointerEXT(GLint, GLenum, GLsizei, GLsizei, const GLvoid *);
	void glVertexPointerEXT(GLint, GLenum, GLsizei, GLsizei, const GLvoid *);
	void glBlendEquationEXT(GLenum);
	void glSpriteParameterfSGIX(GLenum, GLfloat);
	void glSpriteParameterfvSGIX(GLenum, const GLfloat *);
	void glSpriteParameteriSGIX(GLenum, GLint);
	void glSpriteParameterivSGIX(GLenum, const GLint *);
	void glPointParameterfEXT(GLenum, GLfloat);
	void glPointParameterfvEXT(GLenum, const GLfloat *);
	void glPointParameterfSGIS(GLenum, GLfloat);
	void glPointParameterfvSGIS(GLenum, const GLfloat *);
	GLint glGetInstrumentsSGIX(void);
	void glInstrumentsBufferSGIX(GLsizei, GLint *);
	GLint glPollInstrumentsSGIX(GLint *);
	void glReadInstrumentsSGIX(GLint);
	void glStartInstrumentsSGIX(void);
	void glStopInstrumentsSGIX(GLint);
	void glFrameZoomSGIX(GLint);
	void glTagSampleBufferSGIX(void);
	void glDeformationMap3dSGIX(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
	void glDeformationMap3fSGIX(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
	void glDeformSGIX(GLbitfield);
	void glLoadIdentityDeformationMapSGIX(GLbitfield);
	void glReferencePlaneSGIX(const GLdouble *);
	void glFlushRasterSGIX(void);
	void glFogFuncSGIS(GLsizei, const GLfloat *);
	void glGetFogFuncSGIS(GLfloat *);
	void glImageTransformParameteriHP(GLenum, GLenum, GLint);
	void glImageTransformParameterfHP(GLenum, GLenum, GLfloat);
	void glImageTransformParameterivHP(GLenum, GLenum, const GLint *);
	void glImageTransformParameterfvHP(GLenum, GLenum, const GLfloat *);
	void glGetImageTransformParameterivHP(GLenum, GLenum, GLint *);
	void glGetImageTransformParameterfvHP(GLenum, GLenum, GLfloat *);
	void glColorSubTableEXT(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
	void glCopyColorSubTableEXT(GLenum, GLsizei, GLint, GLint, GLsizei);
	void glHintPGI(GLenum, GLint);
	void glColorTableEXT(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *);
	void glGetColorTableEXT(GLenum, GLenum, GLenum, GLvoid *);
	void glGetColorTableParameterivEXT(GLenum, GLenum, GLint *);
	void glGetColorTableParameterfvEXT(GLenum, GLenum, GLfloat *);
	void glGetListParameterfvSGIX(GLuint, GLenum, GLfloat *);
	void glGetListParameterivSGIX(GLuint, GLenum, GLint *);
	void glListParameterfSGIX(GLuint, GLenum, GLfloat);
	void glListParameterfvSGIX(GLuint, GLenum, const GLfloat *);
	void glListParameteriSGIX(GLuint, GLenum, GLint);
	void glListParameterivSGIX(GLuint, GLenum, const GLint *);
	void glIndexMaterialEXT(GLenum, GLenum);
	void glIndexFuncEXT(GLenum, GLclampf);
	void glLockArraysEXT(GLint, GLsizei);
	void glUnlockArraysEXT(void);
	void glCullParameterdvEXT(GLenum, GLdouble *);
	void glCullParameterfvEXT(GLenum, GLfloat *);
	void glFragmentColorMaterialSGIX(GLenum, GLenum);
	void glFragmentLightfSGIX(GLenum, GLenum, GLfloat);
	void glFragmentLightfvSGIX(GLenum, GLenum, const GLfloat *);
	void glFragmentLightiSGIX(GLenum, GLenum, GLint);
	void glFragmentLightivSGIX(GLenum, GLenum, const GLint *);
	void glFragmentLightModelfSGIX(GLenum, GLfloat);
	void glFragmentLightModelfvSGIX(GLenum, const GLfloat *);
	void glFragmentLightModeliSGIX(GLenum, GLint);
	void glFragmentLightModelivSGIX(GLenum, const GLint *);
	void glFragmentMaterialfSGIX(GLenum, GLenum, GLfloat);
	void glFragmentMaterialfvSGIX(GLenum, GLenum, const GLfloat *);
	void glFragmentMaterialiSGIX(GLenum, GLenum, GLint);
	void glFragmentMaterialivSGIX(GLenum, GLenum, const GLint *);
	void glGetFragmentLightfvSGIX(GLenum, GLenum, GLfloat *);
	void glGetFragmentLightivSGIX(GLenum, GLenum, GLint *);
	void glGetFragmentMaterialfvSGIX(GLenum, GLenum, GLfloat *);
	void glGetFragmentMaterialivSGIX(GLenum, GLenum, GLint *);
	void glLightEnviSGIX(GLenum, GLint);
	void glDrawRangeElementsEXT(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *);
	void glApplyTextureEXT(GLenum);
	void glTextureLightEXT(GLenum);
	void glTextureMaterialEXT(GLenum, GLenum);
	void glAsyncMarkerSGIX(GLuint);
	GLint glFinishAsyncSGIX(GLuint *);
	GLint glPollAsyncSGIX(GLuint *);
	GLuint glGenAsyncMarkersSGIX(GLsizei);
	void glDeleteAsyncMarkersSGIX(GLuint, GLsizei);
	GLboolean glIsAsyncMarkerSGIX(GLuint);
	void glVertexPointervINTEL(GLint, GLenum, const GLvoid* *);
	void glNormalPointervINTEL(GLenum, const GLvoid* *);
	void glColorPointervINTEL(GLint, GLenum, const GLvoid* *);
	void glTexCoordPointervINTEL(GLint, GLenum, const GLvoid* *);
	void glPixelTransformParameteriEXT(GLenum, GLenum, GLint);
	void glPixelTransformParameterfEXT(GLenum, GLenum, GLfloat);
	void glPixelTransformParameterivEXT(GLenum, GLenum, const GLint *);
	void glPixelTransformParameterfvEXT(GLenum, GLenum, const GLfloat *);
	void glSecondaryColor3bEXT(GLbyte, GLbyte, GLbyte);
	void glSecondaryColor3bvEXT(const GLbyte *);
	void glSecondaryColor3dEXT(GLdouble, GLdouble, GLdouble);
	void glSecondaryColor3dvEXT(const GLdouble *);
	void glSecondaryColor3fEXT(GLfloat, GLfloat, GLfloat);
	void glSecondaryColor3fvEXT(const GLfloat *);
	void glSecondaryColor3iEXT(GLint, GLint, GLint);
	void glSecondaryColor3ivEXT(const GLint *);
	void glSecondaryColor3sEXT(GLshort, GLshort, GLshort);
	void glSecondaryColor3svEXT(const GLshort *);
	void glSecondaryColor3ubEXT(GLubyte, GLubyte, GLubyte);
	void glSecondaryColor3ubvEXT(const GLubyte *);
	void glSecondaryColor3uiEXT(GLuint, GLuint, GLuint);
	void glSecondaryColor3uivEXT(const GLuint *);
	void glSecondaryColor3usEXT(GLushort, GLushort, GLushort);
	void glSecondaryColor3usvEXT(const GLushort *);
	void glSecondaryColorPointerEXT(GLint, GLenum, GLsizei, const GLvoid *);
	void glTextureNormalEXT(GLenum);
	void glMultiDrawArraysEXT(GLenum, GLint *, GLsizei *, GLsizei);
	void glMultiDrawElementsEXT(GLenum, const GLsizei *, GLenum, const GLvoid* *, GLsizei);
	void glFogCoordfEXT(GLfloat);
	void glFogCoordfvEXT(const GLfloat *);
	void glFogCoorddEXT(GLdouble);
	void glFogCoorddvEXT(const GLdouble *);
	void glFogCoordPointerEXT(GLenum, GLsizei, const GLvoid *);
	void glTangent3bEXT(GLbyte, GLbyte, GLbyte);
	void glTangent3bvEXT(const GLbyte *);
	void glTangent3dEXT(GLdouble, GLdouble, GLdouble);
	void glTangent3dvEXT(const GLdouble *);
	void glTangent3fEXT(GLfloat, GLfloat, GLfloat);
	void glTangent3fvEXT(const GLfloat *);
	void glTangent3iEXT(GLint, GLint, GLint);
	void glTangent3ivEXT(const GLint *);
	void glTangent3sEXT(GLshort, GLshort, GLshort);
	void glTangent3svEXT(const GLshort *);
	void glBinormal3bEXT(GLbyte, GLbyte, GLbyte);
	void glBinormal3bvEXT(const GLbyte *);
	void glBinormal3dEXT(GLdouble, GLdouble, GLdouble);
	void glBinormal3dvEXT(const GLdouble *);
	void glBinormal3fEXT(GLfloat, GLfloat, GLfloat);
	void glBinormal3fvEXT(const GLfloat *);
	void glBinormal3iEXT(GLint, GLint, GLint);
	void glBinormal3ivEXT(const GLint *);
	void glBinormal3sEXT(GLshort, GLshort, GLshort);
	void glBinormal3svEXT(const GLshort *);
	void glTangentPointerEXT(GLenum, GLsizei, const GLvoid *);
	void glBinormalPointerEXT(GLenum, GLsizei, const GLvoid *);
	void glFinishTextureSUNX(void);
	void glGlobalAlphaFactorbSUN(GLbyte);
	void glGlobalAlphaFactorsSUN(GLshort);
	void glGlobalAlphaFactoriSUN(GLint);
	void glGlobalAlphaFactorfSUN(GLfloat);
	void glGlobalAlphaFactordSUN(GLdouble);
	void glGlobalAlphaFactorubSUN(GLubyte);
	void glGlobalAlphaFactorusSUN(GLushort);
	void glGlobalAlphaFactoruiSUN(GLuint);
	void glReplacementCodeuiSUN(GLuint);
	void glReplacementCodeusSUN(GLushort);
	void glReplacementCodeubSUN(GLubyte);
	void glReplacementCodeuivSUN(const GLuint *);
	void glReplacementCodeusvSUN(const GLushort *);
	void glReplacementCodeubvSUN(const GLubyte *);
	void glReplacementCodePointerSUN(GLenum, GLsizei, const GLvoid* *);
	void glColor4ubVertex2fSUN(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat);
	void glColor4ubVertex2fvSUN(const GLubyte *, const GLfloat *);
	void glColor4ubVertex3fSUN(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat);
	void glColor4ubVertex3fvSUN(const GLubyte *, const GLfloat *);
	void glColor3fVertex3fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void glColor3fVertex3fvSUN(const GLfloat *, const GLfloat *);
	void glNormal3fVertex3fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void glNormal3fVertex3fvSUN(const GLfloat *, const GLfloat *);
	void glColor4fNormal3fVertex3fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void glColor4fNormal3fVertex3fvSUN(const GLfloat *, const GLfloat *, const GLfloat *);
	void glTexCoord2fVertex3fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void glTexCoord2fVertex3fvSUN(const GLfloat *, const GLfloat *);
	void glTexCoord4fVertex4fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void glTexCoord4fVertex4fvSUN(const GLfloat *, const GLfloat *);
	void glTexCoord2fColor4ubVertex3fSUN(GLfloat, GLfloat, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat);
	void glTexCoord2fColor4ubVertex3fvSUN(const GLfloat *, const GLubyte *, const GLfloat *);
	void glTexCoord2fColor3fVertex3fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void glTexCoord2fColor3fVertex3fvSUN(const GLfloat *, const GLfloat *, const GLfloat *);
	void glTexCoord2fNormal3fVertex3fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void glTexCoord2fNormal3fVertex3fvSUN(const GLfloat *, const GLfloat *, const GLfloat *);
	void glTexCoord2fColor4fNormal3fVertex3fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void glTexCoord2fColor4fNormal3fVertex3fvSUN(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *);
	void glTexCoord4fColor4fNormal3fVertex4fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void glTexCoord4fColor4fNormal3fVertex4fvSUN(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *);
	void glReplacementCodeuiVertex3fSUN(GLuint, GLfloat, GLfloat, GLfloat);
	void glReplacementCodeuiVertex3fvSUN(const GLuint *, const GLfloat *);
	void glReplacementCodeuiColor4ubVertex3fSUN(GLuint, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat);
	void glReplacementCodeuiColor4ubVertex3fvSUN(const GLuint *, const GLubyte *, const GLfloat *);
	void glReplacementCodeuiColor3fVertex3fSUN(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void glReplacementCodeuiColor3fVertex3fvSUN(const GLuint *, const GLfloat *, const GLfloat *);
	void glReplacementCodeuiNormal3fVertex3fSUN(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void glReplacementCodeuiNormal3fVertex3fvSUN(const GLuint *, const GLfloat *, const GLfloat *);
	void glReplacementCodeuiColor4fNormal3fVertex3fSUN(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void glReplacementCodeuiColor4fNormal3fVertex3fvSUN(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *);
	void glReplacementCodeuiTexCoord2fVertex3fSUN(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void glReplacementCodeuiTexCoord2fVertex3fvSUN(const GLuint *, const GLfloat *, const GLfloat *);
	void glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *);
	void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *);
	void glBlendFuncSeparateEXT(GLenum, GLenum, GLenum, GLenum);
	void glBlendFuncSeparateINGR(GLenum, GLenum, GLenum, GLenum);
	void glVertexWeightfEXT(GLfloat);
	void glVertexWeightfvEXT(const GLfloat *);
	void glVertexWeightPointerEXT(GLsizei, GLenum, GLsizei, const GLvoid *);
	void glFlushVertexArrayRangeNV(void);
	void glVertexArrayRangeNV(GLsizei, const GLvoid *);
	void glCombinerParameterfvNV(GLenum, const GLfloat *);
	void glCombinerParameterfNV(GLenum, GLfloat);
	void glCombinerParameterivNV(GLenum, const GLint *);
	void glCombinerParameteriNV(GLenum, GLint);
	void glCombinerInputNV(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum);
	void glCombinerOutputNV(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLboolean, GLboolean, GLboolean);
	void glFinalCombinerInputNV(GLenum, GLenum, GLenum, GLenum);
	void glGetCombinerInputParameterfvNV(GLenum, GLenum, GLenum, GLenum, GLfloat *);
	void glGetCombinerInputParameterivNV(GLenum, GLenum, GLenum, GLenum, GLint *);
	void glGetCombinerOutputParameterfvNV(GLenum, GLenum, GLenum, GLfloat *);
	void glGetCombinerOutputParameterivNV(GLenum, GLenum, GLenum, GLint *);
	void glGetFinalCombinerInputParameterfvNV(GLenum, GLenum, GLfloat *);
	void glGetFinalCombinerInputParameterivNV(GLenum, GLenum, GLint *);
	void glResizeBuffersMESA(void);
	void glWindowPos2dMESA(GLdouble, GLdouble);
	void glWindowPos2dvMESA(const GLdouble *);
	void glWindowPos2fMESA(GLfloat, GLfloat);
	void glWindowPos2fvMESA(const GLfloat *);
	void glWindowPos2iMESA(GLint, GLint);
	void glWindowPos2ivMESA(const GLint *);
	void glWindowPos2sMESA(GLshort, GLshort);
	void glWindowPos2svMESA(const GLshort *);
	void glWindowPos3dMESA(GLdouble, GLdouble, GLdouble);
	void glWindowPos3dvMESA(const GLdouble *);
	void glWindowPos3fMESA(GLfloat, GLfloat, GLfloat);
	void glWindowPos3fvMESA(const GLfloat *);
	void glWindowPos3iMESA(GLint, GLint, GLint);
	void glWindowPos3ivMESA(const GLint *);
	void glWindowPos3sMESA(GLshort, GLshort, GLshort);
	void glWindowPos3svMESA(const GLshort *);
	void glWindowPos4dMESA(GLdouble, GLdouble, GLdouble, GLdouble);
	void glWindowPos4dvMESA(const GLdouble *);
	void glWindowPos4fMESA(GLfloat, GLfloat, GLfloat, GLfloat);
	void glWindowPos4fvMESA(const GLfloat *);
	void glWindowPos4iMESA(GLint, GLint, GLint, GLint);
	void glWindowPos4ivMESA(const GLint *);
	void glWindowPos4sMESA(GLshort, GLshort, GLshort, GLshort);
	void glWindowPos4svMESA(const GLshort *);
	void glMultiModeDrawArraysIBM(const GLenum *, const GLint *, const GLsizei *, GLsizei, GLint);
	void glMultiModeDrawElementsIBM(const GLenum *, const GLsizei *, GLenum, const GLvoid* const *, GLsizei, GLint);
	void glColorPointerListIBM(GLint, GLenum, GLint, const GLvoid* *, GLint);
	void glSecondaryColorPointerListIBM(GLint, GLenum, GLint, const GLvoid* *, GLint);
	void glEdgeFlagPointerListIBM(GLint, const GLboolean* *, GLint);
	void glFogCoordPointerListIBM(GLenum, GLint, const GLvoid* *, GLint);
	void glIndexPointerListIBM(GLenum, GLint, const GLvoid* *, GLint);
	void glNormalPointerListIBM(GLenum, GLint, const GLvoid* *, GLint);
	void glTexCoordPointerListIBM(GLint, GLenum, GLint, const GLvoid* *, GLint);
	void glVertexPointerListIBM(GLint, GLenum, GLint, const GLvoid* *, GLint);
	void glTbufferMask3DFX(GLuint);
	void glSampleMaskEXT(GLclampf, GLboolean);
	void glSamplePatternEXT(GLenum);
	void glTextureColorMaskSGIS(GLboolean, GLboolean, GLboolean, GLboolean);
	void glIglooInterfaceSGIX(GLenum, const GLvoid *);
	void glDeleteFencesNV(GLsizei, const GLuint *);
	void glGenFencesNV(GLsizei, GLuint *);
	GLboolean glIsFenceNV(GLuint);
	GLboolean glTestFenceNV(GLuint);
	void glGetFenceivNV(GLuint, GLenum, GLint *);
	void glFinishFenceNV(GLuint);
	void glSetFenceNV(GLuint, GLenum);
	void glMapControlPointsNV(GLenum, GLuint, GLenum, GLsizei, GLsizei, GLint, GLint, GLboolean, const GLvoid *);
	void glMapParameterivNV(GLenum, GLenum, const GLint *);
	void glMapParameterfvNV(GLenum, GLenum, const GLfloat *);
	void glGetMapControlPointsNV(GLenum, GLuint, GLenum, GLsizei, GLsizei, GLboolean, GLvoid *);
	void glGetMapParameterivNV(GLenum, GLenum, GLint *);
	void glGetMapParameterfvNV(GLenum, GLenum, GLfloat *);
	void glGetMapAttribParameterivNV(GLenum, GLuint, GLenum, GLint *);
	void glGetMapAttribParameterfvNV(GLenum, GLuint, GLenum, GLfloat *);
	void glEvalMapsNV(GLenum, GLenum);
	void glCombinerStageParameterfvNV(GLenum, GLenum, const GLfloat *);
	void glGetCombinerStageParameterfvNV(GLenum, GLenum, GLfloat *);
	GLboolean glAreProgramsResidentNV(GLsizei, const GLuint *, GLboolean *);
	void glBindProgramNV(GLenum, GLuint);
	void glDeleteProgramsNV(GLsizei, const GLuint *);
	void glExecuteProgramNV(GLenum, GLuint, const GLfloat *);
	void glGenProgramsNV(GLsizei, GLuint *);
	void glGetProgramParameterdvNV(GLenum, GLuint, GLenum, GLdouble *);
	void glGetProgramParameterfvNV(GLenum, GLuint, GLenum, GLfloat *);
	void glGetProgramivNV(GLuint, GLenum, GLint *);
	void glGetProgramStringNV(GLuint, GLenum, GLubyte *);
	void glGetTrackMatrixivNV(GLenum, GLuint, GLenum, GLint *);
	void glGetVertexAttribdvNV(GLuint, GLenum, GLdouble *);
	void glGetVertexAttribfvNV(GLuint, GLenum, GLfloat *);
	void glGetVertexAttribivNV(GLuint, GLenum, GLint *);
	void glGetVertexAttribPointervNV(GLuint, GLenum, GLvoid* *);
	GLboolean glIsProgramNV(GLuint);
	void glLoadProgramNV(GLenum, GLuint, GLsizei, const GLubyte *);
	void glProgramParameter4dNV(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
	void glProgramParameter4dvNV(GLenum, GLuint, const GLdouble *);
	void glProgramParameter4fNV(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
	void glProgramParameter4fvNV(GLenum, GLuint, const GLfloat *);
	void glProgramParameters4dvNV(GLenum, GLuint, GLuint, const GLdouble *);
	void glProgramParameters4fvNV(GLenum, GLuint, GLuint, const GLfloat *);
	void glRequestResidentProgramsNV(GLsizei, const GLuint *);
	void glTrackMatrixNV(GLenum, GLuint, GLenum, GLenum);
	void glVertexAttribPointerNV(GLuint, GLint, GLenum, GLsizei, const GLvoid *);
	void glVertexAttrib1dNV(GLuint, GLdouble);
	void glVertexAttrib1dvNV(GLuint, const GLdouble *);
	void glVertexAttrib1fNV(GLuint, GLfloat);
	void glVertexAttrib1fvNV(GLuint, const GLfloat *);
	void glVertexAttrib1sNV(GLuint, GLshort);
	void glVertexAttrib1svNV(GLuint, const GLshort *);
	void glVertexAttrib2dNV(GLuint, GLdouble, GLdouble);
	void glVertexAttrib2dvNV(GLuint, const GLdouble *);
	void glVertexAttrib2fNV(GLuint, GLfloat, GLfloat);
	void glVertexAttrib2fvNV(GLuint, const GLfloat *);
	void glVertexAttrib2sNV(GLuint, GLshort, GLshort);
	void glVertexAttrib2svNV(GLuint, const GLshort *);
	void glVertexAttrib3dNV(GLuint, GLdouble, GLdouble, GLdouble);
	void glVertexAttrib3dvNV(GLuint, const GLdouble *);
	void glVertexAttrib3fNV(GLuint, GLfloat, GLfloat, GLfloat);
	void glVertexAttrib3fvNV(GLuint, const GLfloat *);
	void glVertexAttrib3sNV(GLuint, GLshort, GLshort, GLshort);
	void glVertexAttrib3svNV(GLuint, const GLshort *);
	void glVertexAttrib4dNV(GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
	void glVertexAttrib4dvNV(GLuint, const GLdouble *);
	void glVertexAttrib4fNV(GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
	void glVertexAttrib4fvNV(GLuint, const GLfloat *);
	void glVertexAttrib4sNV(GLuint, GLshort, GLshort, GLshort, GLshort);
	void glVertexAttrib4svNV(GLuint, const GLshort *);
	void glVertexAttrib4ubNV(GLuint, GLubyte, GLubyte, GLubyte, GLubyte);
	void glVertexAttrib4ubvNV(GLuint, const GLubyte *);
	void glVertexAttribs1dvNV(GLuint, GLsizei, const GLdouble *);
	void glVertexAttribs1fvNV(GLuint, GLsizei, const GLfloat *);
	void glVertexAttribs1svNV(GLuint, GLsizei, const GLshort *);
	void glVertexAttribs2dvNV(GLuint, GLsizei, const GLdouble *);
	void glVertexAttribs2fvNV(GLuint, GLsizei, const GLfloat *);
	void glVertexAttribs2svNV(GLuint, GLsizei, const GLshort *);
	void glVertexAttribs3dvNV(GLuint, GLsizei, const GLdouble *);
	void glVertexAttribs3fvNV(GLuint, GLsizei, const GLfloat *);
	void glVertexAttribs3svNV(GLuint, GLsizei, const GLshort *);
	void glVertexAttribs4dvNV(GLuint, GLsizei, const GLdouble *);
	void glVertexAttribs4fvNV(GLuint, GLsizei, const GLfloat *);
	void glVertexAttribs4svNV(GLuint, GLsizei, const GLshort *);
	void glVertexAttribs4ubvNV(GLuint, GLsizei, const GLubyte *);
	void glTexBumpParameterivATI(GLenum, const GLint *);
	void glTexBumpParameterfvATI(GLenum, const GLfloat *);
	void glGetTexBumpParameterivATI(GLenum, GLint *);
	void glGetTexBumpParameterfvATI(GLenum, GLfloat *);
	GLuint glGenFragmentShadersATI(GLuint);
	void glBindFragmentShaderATI(GLuint);
	void glDeleteFragmentShaderATI(GLuint);
	void glBeginFragmentShaderATI(void);
	void glEndFragmentShaderATI(void);
	void glPassTexCoordATI(GLuint, GLuint, GLenum);
	void glSampleMapATI(GLuint, GLuint, GLenum);
	void glColorFragmentOp1ATI(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
	void glColorFragmentOp2ATI(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
	void glColorFragmentOp3ATI(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
	void glAlphaFragmentOp1ATI(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint);
	void glAlphaFragmentOp2ATI(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
	void glAlphaFragmentOp3ATI(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
	void glSetFragmentShaderConstantATI(GLuint, const GLfloat *);
	void glPNTrianglesiATI(GLenum, GLint);
	void glPNTrianglesfATI(GLenum, GLfloat);
	GLuint glNewObjectBufferATI(GLsizei, const GLvoid *, GLenum);
	GLboolean glIsObjectBufferATI(GLuint);
	void glUpdateObjectBufferATI(GLuint, GLuint, GLsizei, const GLvoid *, GLenum);
	void glGetObjectBufferfvATI(GLuint, GLenum, GLfloat *);
	void glGetObjectBufferivATI(GLuint, GLenum, GLint *);
	void glFreeObjectBufferATI(GLuint);
	void glArrayObjectATI(GLenum, GLint, GLenum, GLsizei, GLuint, GLuint);
	void glGetArrayObjectfvATI(GLenum, GLenum, GLfloat *);
	void glGetArrayObjectivATI(GLenum, GLenum, GLint *);
	void glVariantArrayObjectATI(GLuint, GLenum, GLsizei, GLuint, GLuint);
	void glGetVariantArrayObjectfvATI(GLuint, GLenum, GLfloat *);
	void glGetVariantArrayObjectivATI(GLuint, GLenum, GLint *);
	void glBeginVertexShaderEXT(void);
	void glEndVertexShaderEXT(void);
	void glBindVertexShaderEXT(GLuint);
	GLuint glGenVertexShadersEXT(GLuint);
	void glDeleteVertexShaderEXT(GLuint);
	void glShaderOp1EXT(GLenum, GLuint, GLuint);
	void glShaderOp2EXT(GLenum, GLuint, GLuint, GLuint);
	void glShaderOp3EXT(GLenum, GLuint, GLuint, GLuint, GLuint);
	void glSwizzleEXT(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum);
	void glWriteMaskEXT(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum);
	void glInsertComponentEXT(GLuint, GLuint, GLuint);
	void glExtractComponentEXT(GLuint, GLuint, GLuint);
	GLuint glGenSymbolsEXT(GLenum, GLenum, GLenum, GLuint);
	void glSetInvariantEXT(GLuint, GLenum, const GLvoid *);
	void glSetLocalConstantEXT(GLuint, GLenum, const GLvoid *);
	void glVariantbvEXT(GLuint, const GLbyte *);
	void glVariantsvEXT(GLuint, const GLshort *);
	void glVariantivEXT(GLuint, const GLint *);
	void glVariantfvEXT(GLuint, const GLfloat *);
	void glVariantdvEXT(GLuint, const GLdouble *);
	void glVariantubvEXT(GLuint, const GLubyte *);
	void glVariantusvEXT(GLuint, const GLushort *);
	void glVariantuivEXT(GLuint, const GLuint *);
	void glVariantPointerEXT(GLuint, GLenum, GLuint, const GLvoid *);
	void glEnableVariantClientStateEXT(GLuint);
	void glDisableVariantClientStateEXT(GLuint);
	GLuint glBindLightParameterEXT(GLenum, GLenum);
	GLuint glBindMaterialParameterEXT(GLenum, GLenum);
	GLuint glBindTexGenParameterEXT(GLenum, GLenum, GLenum);
	GLuint glBindTextureUnitParameterEXT(GLenum, GLenum);
	GLuint glBindParameterEXT(GLenum);
	GLboolean glIsVariantEnabledEXT(GLuint, GLenum);
	void glGetVariantBooleanvEXT(GLuint, GLenum, GLboolean *);
	void glGetVariantIntegervEXT(GLuint, GLenum, GLint *);
	void glGetVariantFloatvEXT(GLuint, GLenum, GLfloat *);
	void glGetVariantPointervEXT(GLuint, GLenum, GLvoid* *);
	void glGetInvariantBooleanvEXT(GLuint, GLenum, GLboolean *);
	void glGetInvariantIntegervEXT(GLuint, GLenum, GLint *);
	void glGetInvariantFloatvEXT(GLuint, GLenum, GLfloat *);
	void glGetLocalConstantBooleanvEXT(GLuint, GLenum, GLboolean *);
	void glGetLocalConstantIntegervEXT(GLuint, GLenum, GLint *);
	void glGetLocalConstantFloatvEXT(GLuint, GLenum, GLfloat *);
	void glVertexStream1sATI(GLenum, GLshort);
	void glVertexStream1svATI(GLenum, const GLshort *);
	void glVertexStream1iATI(GLenum, GLint);
	void glVertexStream1ivATI(GLenum, const GLint *);
	void glVertexStream1fATI(GLenum, GLfloat);
	void glVertexStream1fvATI(GLenum, const GLfloat *);
	void glVertexStream1dATI(GLenum, GLdouble);
	void glVertexStream1dvATI(GLenum, const GLdouble *);
	void glVertexStream2sATI(GLenum, GLshort, GLshort);
	void glVertexStream2svATI(GLenum, const GLshort *);
	void glVertexStream2iATI(GLenum, GLint, GLint);
	void glVertexStream2ivATI(GLenum, const GLint *);
	void glVertexStream2fATI(GLenum, GLfloat, GLfloat);
	void glVertexStream2fvATI(GLenum, const GLfloat *);
	void glVertexStream2dATI(GLenum, GLdouble, GLdouble);
	void glVertexStream2dvATI(GLenum, const GLdouble *);
	void glVertexStream3sATI(GLenum, GLshort, GLshort, GLshort);
	void glVertexStream3svATI(GLenum, const GLshort *);
	void glVertexStream3iATI(GLenum, GLint, GLint, GLint);
	void glVertexStream3ivATI(GLenum, const GLint *);
	void glVertexStream3fATI(GLenum, GLfloat, GLfloat, GLfloat);
	void glVertexStream3fvATI(GLenum, const GLfloat *);
	void glVertexStream3dATI(GLenum, GLdouble, GLdouble, GLdouble);
	void glVertexStream3dvATI(GLenum, const GLdouble *);
	void glVertexStream4sATI(GLenum, GLshort, GLshort, GLshort, GLshort);
	void glVertexStream4svATI(GLenum, const GLshort *);
	void glVertexStream4iATI(GLenum, GLint, GLint, GLint, GLint);
	void glVertexStream4ivATI(GLenum, const GLint *);
	void glVertexStream4fATI(GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
	void glVertexStream4fvATI(GLenum, const GLfloat *);
	void glVertexStream4dATI(GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
	void glVertexStream4dvATI(GLenum, const GLdouble *);
	void glNormalStream3bATI(GLenum, GLbyte, GLbyte, GLbyte);
	void glNormalStream3bvATI(GLenum, const GLbyte *);
	void glNormalStream3sATI(GLenum, GLshort, GLshort, GLshort);
	void glNormalStream3svATI(GLenum, const GLshort *);
	void glNormalStream3iATI(GLenum, GLint, GLint, GLint);
	void glNormalStream3ivATI(GLenum, const GLint *);
	void glNormalStream3fATI(GLenum, GLfloat, GLfloat, GLfloat);
	void glNormalStream3fvATI(GLenum, const GLfloat *);
	void glNormalStream3dATI(GLenum, GLdouble, GLdouble, GLdouble);
	void glNormalStream3dvATI(GLenum, const GLdouble *);
	void glClientActiveVertexStreamATI(GLenum);
	void glVertexBlendEnviATI(GLenum, GLint);
	void glVertexBlendEnvfATI(GLenum, GLfloat);
	void glElementPointerATI(GLenum, const GLvoid *);
	void glDrawElementArrayATI(GLenum, GLsizei);
	void glDrawRangeElementArrayATI(GLenum, GLuint, GLuint, GLsizei);
	void glDrawMeshArraysSUN(GLenum, GLint, GLsizei, GLsizei);
	void glGenOcclusionQueriesNV(GLsizei, GLuint *);
	void glDeleteOcclusionQueriesNV(GLsizei, const GLuint *);
	GLboolean glIsOcclusionQueryNV(GLuint);
	void glBeginOcclusionQueryNV(GLuint);
	void glEndOcclusionQueryNV(void);
	void glGetOcclusionQueryivNV(GLuint, GLenum, GLint *);
	void glGetOcclusionQueryuivNV(GLuint, GLenum, GLuint *);
	void glPointParameteriNV(GLenum, GLint);
	void glPointParameterivNV(GLenum, const GLint *);
	void glActiveStencilFaceEXT(GLenum);
	void glElementPointerAPPLE(GLenum, const GLvoid *);
	void glDrawElementArrayAPPLE(GLenum, GLint, GLsizei);
	void glDrawRangeElementArrayAPPLE(GLenum, GLuint, GLuint, GLint, GLsizei);
	void glMultiDrawElementArrayAPPLE(GLenum, const GLint *, const GLsizei *, GLsizei);
	void glMultiDrawRangeElementArrayAPPLE(GLenum, GLuint, GLuint, const GLint *, const GLsizei *, GLsizei);
	void glGenFencesAPPLE(GLsizei, GLuint *);
	void glDeleteFencesAPPLE(GLsizei, const GLuint *);
	void glSetFenceAPPLE(GLuint);
	GLboolean glIsFenceAPPLE(GLuint);
	GLboolean glTestFenceAPPLE(GLuint);
	void glFinishFenceAPPLE(GLuint);
	GLboolean glTestObjectAPPLE(GLenum, GLuint);
	void glFinishObjectAPPLE(GLenum, GLint);
	void glBindVertexArrayAPPLE(GLuint);
	void glDeleteVertexArraysAPPLE(GLsizei, const GLuint *);
	void glGenVertexArraysAPPLE(GLsizei, GLuint *);
	GLboolean glIsVertexArrayAPPLE(GLuint);
	void glVertexArrayRangeAPPLE(GLsizei, GLvoid *);
	void glFlushVertexArrayRangeAPPLE(GLsizei, GLvoid *);
	void glVertexArrayParameteriAPPLE(GLenum, GLint);
	void glDrawBuffersATI(GLsizei, const GLenum *);
	void glProgramNamedParameter4fNV(GLuint, GLsizei, const GLubyte *, GLfloat, GLfloat, GLfloat, GLfloat);
	void glProgramNamedParameter4dNV(GLuint, GLsizei, const GLubyte *, GLdouble, GLdouble, GLdouble, GLdouble);
	void glProgramNamedParameter4fvNV(GLuint, GLsizei, const GLubyte *, const GLfloat *);
	void glProgramNamedParameter4dvNV(GLuint, GLsizei, const GLubyte *, const GLdouble *);
	void glGetProgramNamedParameterfvNV(GLuint, GLsizei, const GLubyte *, GLfloat *);
	void glGetProgramNamedParameterdvNV(GLuint, GLsizei, const GLubyte *, GLdouble *);
	void glVertex2hNV(GLhalfNV, GLhalfNV);
	void glVertex2hvNV(const GLhalfNV *);
	void glVertex3hNV(GLhalfNV, GLhalfNV, GLhalfNV);
	void glVertex3hvNV(const GLhalfNV *);
	void glVertex4hNV(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV);
	void glVertex4hvNV(const GLhalfNV *);
	void glNormal3hNV(GLhalfNV, GLhalfNV, GLhalfNV);
	void glNormal3hvNV(const GLhalfNV *);
	void glColor3hNV(GLhalfNV, GLhalfNV, GLhalfNV);
	void glColor3hvNV(const GLhalfNV *);
	void glColor4hNV(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV);
	void glColor4hvNV(const GLhalfNV *);
	void glTexCoord1hNV(GLhalfNV);
	void glTexCoord1hvNV(const GLhalfNV *);
	void glTexCoord2hNV(GLhalfNV, GLhalfNV);
	void glTexCoord2hvNV(const GLhalfNV *);
	void glTexCoord3hNV(GLhalfNV, GLhalfNV, GLhalfNV);
	void glTexCoord3hvNV(const GLhalfNV *);
	void glTexCoord4hNV(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV);
	void glTexCoord4hvNV(const GLhalfNV *);
	void glMultiTexCoord1hNV(GLenum, GLhalfNV);
	void glMultiTexCoord1hvNV(GLenum, const GLhalfNV *);
	void glMultiTexCoord2hNV(GLenum, GLhalfNV, GLhalfNV);
	void glMultiTexCoord2hvNV(GLenum, const GLhalfNV *);
	void glMultiTexCoord3hNV(GLenum, GLhalfNV, GLhalfNV, GLhalfNV);
	void glMultiTexCoord3hvNV(GLenum, const GLhalfNV *);
	void glMultiTexCoord4hNV(GLenum, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV);
	void glMultiTexCoord4hvNV(GLenum, const GLhalfNV *);
	void glFogCoordhNV(GLhalfNV);
	void glFogCoordhvNV(const GLhalfNV *);
	void glSecondaryColor3hNV(GLhalfNV, GLhalfNV, GLhalfNV);
	void glSecondaryColor3hvNV(const GLhalfNV *);
	void glVertexWeighthNV(GLhalfNV);
	void glVertexWeighthvNV(const GLhalfNV *);
	void glVertexAttrib1hNV(GLuint, GLhalfNV);
	void glVertexAttrib1hvNV(GLuint, const GLhalfNV *);
	void glVertexAttrib2hNV(GLuint, GLhalfNV, GLhalfNV);
	void glVertexAttrib2hvNV(GLuint, const GLhalfNV *);
	void glVertexAttrib3hNV(GLuint, GLhalfNV, GLhalfNV, GLhalfNV);
	void glVertexAttrib3hvNV(GLuint, const GLhalfNV *);
	void glVertexAttrib4hNV(GLuint, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV);
	void glVertexAttrib4hvNV(GLuint, const GLhalfNV *);
	void glVertexAttribs1hvNV(GLuint, GLsizei, const GLhalfNV *);
	void glVertexAttribs2hvNV(GLuint, GLsizei, const GLhalfNV *);
	void glVertexAttribs3hvNV(GLuint, GLsizei, const GLhalfNV *);
	void glVertexAttribs4hvNV(GLuint, GLsizei, const GLhalfNV *);
	void glPixelDataRangeNV(GLenum, GLsizei, GLvoid *);
	void glFlushPixelDataRangeNV(GLenum);
	void glPrimitiveRestartNV(void);
	void glPrimitiveRestartIndexNV(GLuint);
	GLvoid* glMapObjectBufferATI(GLuint);
	void glUnmapObjectBufferATI(GLuint);
	void glStencilOpSeparateATI(GLenum, GLenum, GLenum, GLenum);
	void glStencilFuncSeparateATI(GLenum, GLenum, GLint, GLuint);
	void glVertexAttribArrayObjectATI(GLuint, GLint, GLenum, GLboolean, GLsizei, GLuint, GLuint);
	void glGetVertexAttribArrayObjectfvATI(GLuint, GLenum, GLfloat *);
	void glGetVertexAttribArrayObjectivATI(GLuint, GLenum, GLint *);
	void glDepthBoundsEXT(GLclampd, GLclampd);
	void glBlendEquationSeparateEXT(GLenum, GLenum);
	GLboolean glIsRenderbufferEXT(GLuint);
	void glBindRenderbufferEXT(GLenum, GLuint);
	void glDeleteRenderbuffersEXT(GLsizei, const GLuint *);
	void glGenRenderbuffersEXT(GLsizei, GLuint *);
	void glRenderbufferStorageEXT(GLenum, GLenum, GLsizei, GLsizei);
	void glGetRenderbufferParameterivEXT(GLenum, GLenum, GLint *);
	GLboolean glIsFramebufferEXT(GLuint);
	void glBindFramebufferEXT(GLenum, GLuint);
	void glDeleteFramebuffersEXT(GLsizei, const GLuint *);
	void glGenFramebuffersEXT(GLsizei, GLuint *);
	GLenum glCheckFramebufferStatusEXT(GLenum);
	void glFramebufferTexture1DEXT(GLenum, GLenum, GLenum, GLuint, GLint);
	void glFramebufferTexture2DEXT(GLenum, GLenum, GLenum, GLuint, GLint);
	void glFramebufferTexture3DEXT(GLenum, GLenum, GLenum, GLuint, GLint, GLint);
	void glFramebufferRenderbufferEXT(GLenum, GLenum, GLenum, GLuint);
	void glGetFramebufferAttachmentParameterivEXT(GLenum, GLenum, GLenum, GLint *);
	void glGenerateMipmapEXT(GLenum);
	void glStringMarkerGREMEDY(GLsizei, const GLvoid *);
	void glStencilClearTagEXT(GLsizei, GLuint);
	void glBlitFramebufferEXT(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum);
	void glRenderbufferStorageMultisampleEXT(GLenum, GLsizei, GLenum, GLsizei, GLsizei);
	void glGetQueryObjecti64vEXT(GLuint, GLenum, GLint64EXT *);
	void glGetQueryObjectui64vEXT(GLuint, GLenum, GLuint64EXT *);
	void glProgramEnvParameters4fvEXT(GLenum, GLuint, GLsizei, const GLfloat *);
	void glProgramLocalParameters4fvEXT(GLenum, GLuint, GLsizei, const GLfloat *);
	void glBufferParameteriAPPLE(GLenum, GLenum, GLint);
	void glFlushMappedBufferRangeAPPLE(GLenum, GLintptr, GLsizeiptr);
	void glProgramLocalParameterI4iNV(GLenum, GLuint, GLint, GLint, GLint, GLint);
	void glProgramLocalParameterI4ivNV(GLenum, GLuint, const GLint *);
	void glProgramLocalParametersI4ivNV(GLenum, GLuint, GLsizei, const GLint *);
	void glProgramLocalParameterI4uiNV(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint);
	void glProgramLocalParameterI4uivNV(GLenum, GLuint, const GLuint *);
	void glProgramLocalParametersI4uivNV(GLenum, GLuint, GLsizei, const GLuint *);
	void glProgramEnvParameterI4iNV(GLenum, GLuint, GLint, GLint, GLint, GLint);
	void glProgramEnvParameterI4ivNV(GLenum, GLuint, const GLint *);
	void glProgramEnvParametersI4ivNV(GLenum, GLuint, GLsizei, const GLint *);
	void glProgramEnvParameterI4uiNV(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint);
	void glProgramEnvParameterI4uivNV(GLenum, GLuint, const GLuint *);
	void glProgramEnvParametersI4uivNV(GLenum, GLuint, GLsizei, const GLuint *);
	void glGetProgramLocalParameterIivNV(GLenum, GLuint, GLint *);
	void glGetProgramLocalParameterIuivNV(GLenum, GLuint, GLuint *);
	void glGetProgramEnvParameterIivNV(GLenum, GLuint, GLint *);
	void glGetProgramEnvParameterIuivNV(GLenum, GLuint, GLuint *);
	void glProgramVertexLimitNV(GLenum, GLint);
	void glFramebufferTextureEXT(GLenum, GLenum, GLuint, GLint);
	void glFramebufferTextureLayerEXT(GLenum, GLenum, GLuint, GLint, GLint);
	void glFramebufferTextureFaceEXT(GLenum, GLenum, GLuint, GLint, GLenum);
	void glProgramParameteriEXT(GLuint, GLenum, GLint);
	void glVertexAttribI1iEXT(GLuint, GLint);
	void glVertexAttribI2iEXT(GLuint, GLint, GLint);
	void glVertexAttribI3iEXT(GLuint, GLint, GLint, GLint);
	void glVertexAttribI4iEXT(GLuint, GLint, GLint, GLint, GLint);
	void glVertexAttribI1uiEXT(GLuint, GLuint);
	void glVertexAttribI2uiEXT(GLuint, GLuint, GLuint);
	void glVertexAttribI3uiEXT(GLuint, GLuint, GLuint, GLuint);
	void glVertexAttribI4uiEXT(GLuint, GLuint, GLuint, GLuint, GLuint);
	void glVertexAttribI1ivEXT(GLuint, const GLint *);
	void glVertexAttribI2ivEXT(GLuint, const GLint *);
	void glVertexAttribI3ivEXT(GLuint, const GLint *);
	void glVertexAttribI4ivEXT(GLuint, const GLint *);
	void glVertexAttribI1uivEXT(GLuint, const GLuint *);
	void glVertexAttribI2uivEXT(GLuint, const GLuint *);
	void glVertexAttribI3uivEXT(GLuint, const GLuint *);
	void glVertexAttribI4uivEXT(GLuint, const GLuint *);
	void glVertexAttribI4bvEXT(GLuint, const GLbyte *);
	void glVertexAttribI4svEXT(GLuint, const GLshort *);
	void glVertexAttribI4ubvEXT(GLuint, const GLubyte *);
	void glVertexAttribI4usvEXT(GLuint, const GLushort *);
	void glVertexAttribIPointerEXT(GLuint, GLint, GLenum, GLsizei, const GLvoid *);
	void glGetVertexAttribIivEXT(GLuint, GLenum, GLint *);
	void glGetVertexAttribIuivEXT(GLuint, GLenum, GLuint *);
	void glGetUniformuivEXT(GLuint, GLint, GLuint *);
	void glBindFragDataLocationEXT(GLuint, GLuint, const GLchar *);
	GLint glGetFragDataLocationEXT(GLuint, const GLchar *);
	void glUniform1uiEXT(GLint, GLuint);
	void glUniform2uiEXT(GLint, GLuint, GLuint);
	void glUniform3uiEXT(GLint, GLuint, GLuint, GLuint);
	void glUniform4uiEXT(GLint, GLuint, GLuint, GLuint, GLuint);
	void glUniform1uivEXT(GLint, GLsizei, const GLuint *);
	void glUniform2uivEXT(GLint, GLsizei, const GLuint *);
	void glUniform3uivEXT(GLint, GLsizei, const GLuint *);
	void glUniform4uivEXT(GLint, GLsizei, const GLuint *);
	void glDrawArraysInstancedEXT(GLenum, GLint, GLsizei, GLsizei);
	void glDrawElementsInstancedEXT(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei);
	void glTexBufferEXT(GLenum, GLenum, GLuint);
	void glDepthRangedNV(GLdouble, GLdouble);
	void glClearDepthdNV(GLdouble);
	void glDepthBoundsdNV(GLdouble, GLdouble);
	void glRenderbufferStorageMultisampleCoverageNV(GLenum, GLsizei, GLsizei, GLenum, GLsizei, GLsizei);
	void glProgramBufferParametersfvNV(GLenum, GLuint, GLuint, GLsizei, const GLfloat *);
	void glProgramBufferParametersIivNV(GLenum, GLuint, GLuint, GLsizei, const GLint *);
	void glProgramBufferParametersIuivNV(GLenum, GLuint, GLuint, GLsizei, const GLuint *);
	void glColorMaskIndexedEXT(GLuint, GLboolean, GLboolean, GLboolean, GLboolean);
	void glGetBooleanIndexedvEXT(GLenum, GLuint, GLboolean *);
	void glGetIntegerIndexedvEXT(GLenum, GLuint, GLint *);
	void glEnableIndexedEXT(GLenum, GLuint);
	void glDisableIndexedEXT(GLenum, GLuint);
	GLboolean glIsEnabledIndexedEXT(GLenum, GLuint);
	void glBeginTransformFeedbackNV(GLenum);
	void glEndTransformFeedbackNV(void);
	void glTransformFeedbackAttribsNV(GLuint, const GLint *, GLenum);
	void glBindBufferRangeNV(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr);
	void glBindBufferOffsetNV(GLenum, GLuint, GLuint, GLintptr);
	void glBindBufferBaseNV(GLenum, GLuint, GLuint);
	void glTransformFeedbackVaryingsNV(GLuint, GLsizei, const GLchar* *, GLenum);
	void glActiveVaryingNV(GLuint, const GLchar *);
	GLint glGetVaryingLocationNV(GLuint, const GLchar *);
	void glGetActiveVaryingNV(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *);
	void glGetTransformFeedbackVaryingNV(GLuint, GLuint, GLint *);
	void glUniformBufferEXT(GLuint, GLint, GLuint);
	GLint glGetUniformBufferSizeEXT(GLuint, GLint);
	GLintptr glGetUniformOffsetEXT(GLuint, GLint);
	void glTexParameterIivEXT(GLenum, GLenum, const GLint *);
	void glTexParameterIuivEXT(GLenum, GLenum, const GLuint *);
	void glGetTexParameterIivEXT(GLenum, GLenum, GLint *);
	void glGetTexParameterIuivEXT(GLenum, GLenum, GLuint *);
	void glClearColorIiEXT(GLint, GLint, GLint, GLint);
	void glClearColorIuiEXT(GLuint, GLuint, GLuint, GLuint);
	void glFrameTerminatorGREMEDY(void);
	void glBeginConditionalRenderNV(GLuint, GLenum);
	void glEndConditionalRenderNV(void);
	void glPresentFrameKeyedNV(GLuint, GLuint64EXT, GLuint, GLuint, GLenum, GLenum, GLuint, GLuint, GLenum, GLuint, GLuint);
	void glPresentFrameDualFillNV(GLuint, GLuint64EXT, GLuint, GLuint, GLenum, GLenum, GLuint, GLenum, GLuint, GLenum, GLuint, GLenum, GLuint);
	void glGetVideoivNV(GLuint, GLenum, GLint *);
	void glGetVideouivNV(GLuint, GLenum, GLuint *);
	void glGetVideoi64vNV(GLuint, GLenum, GLint64EXT *);
	void glGetVideoui64vNV(GLuint, GLenum, GLuint64EXT *);
	void glBeginTransformFeedbackEXT(GLenum);
	void glEndTransformFeedbackEXT(void);
	void glBindBufferRangeEXT(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr);
	void glBindBufferOffsetEXT(GLenum, GLuint, GLuint, GLintptr);
	void glBindBufferBaseEXT(GLenum, GLuint, GLuint);
	void glTransformFeedbackVaryingsEXT(GLuint, GLsizei, const GLchar* *, GLenum);
	void glGetTransformFeedbackVaryingEXT(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *);
	void glClientAttribDefaultEXT(GLbitfield);
	void glPushClientAttribDefaultEXT(GLbitfield);
	void glMatrixLoadfEXT(GLenum, const GLfloat *);
	void glMatrixLoaddEXT(GLenum, const GLdouble *);
	void glMatrixMultfEXT(GLenum, const GLfloat *);
	void glMatrixMultdEXT(GLenum, const GLdouble *);
	void glMatrixLoadIdentityEXT(GLenum);
	void glMatrixRotatefEXT(GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
	void glMatrixRotatedEXT(GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
	void glMatrixScalefEXT(GLenum, GLfloat, GLfloat, GLfloat);
	void glMatrixScaledEXT(GLenum, GLdouble, GLdouble, GLdouble);
	void glMatrixTranslatefEXT(GLenum, GLfloat, GLfloat, GLfloat);
	void glMatrixTranslatedEXT(GLenum, GLdouble, GLdouble, GLdouble);
	void glMatrixFrustumEXT(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
	void glMatrixOrthoEXT(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
	void glMatrixPopEXT(GLenum);
	void glMatrixPushEXT(GLenum);
	void glMatrixLoadTransposefEXT(GLenum, const GLfloat *);
	void glMatrixLoadTransposedEXT(GLenum, const GLdouble *);
	void glMatrixMultTransposefEXT(GLenum, const GLfloat *);
	void glMatrixMultTransposedEXT(GLenum, const GLdouble *);
	void glTextureParameterfEXT(GLuint, GLenum, GLenum, GLfloat);
	void glTextureParameterfvEXT(GLuint, GLenum, GLenum, const GLfloat *);
	void glTextureParameteriEXT(GLuint, GLenum, GLenum, GLint);
	void glTextureParameterivEXT(GLuint, GLenum, GLenum, const GLint *);
	void glTextureImage1DEXT(GLuint, GLenum, GLint, GLenum, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
	void glTextureImage2DEXT(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
	void glTextureSubImage1DEXT(GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *);
	void glTextureSubImage2DEXT(GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
	void glCopyTextureImage1DEXT(GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
	void glCopyTextureImage2DEXT(GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
	void glCopyTextureSubImage1DEXT(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei);
	void glCopyTextureSubImage2DEXT(GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
	void glGetTextureImageEXT(GLuint, GLenum, GLint, GLenum, GLenum, GLvoid *);
	void glGetTextureParameterfvEXT(GLuint, GLenum, GLenum, GLfloat *);
	void glGetTextureParameterivEXT(GLuint, GLenum, GLenum, GLint *);
	void glGetTextureLevelParameterfvEXT(GLuint, GLenum, GLint, GLenum, GLfloat *);
	void glGetTextureLevelParameterivEXT(GLuint, GLenum, GLint, GLenum, GLint *);
	void glTextureImage3DEXT(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
	void glTextureSubImage3DEXT(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
	void glCopyTextureSubImage3DEXT(GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
	void glMultiTexParameterfEXT(GLenum, GLenum, GLenum, GLfloat);
	void glMultiTexParameterfvEXT(GLenum, GLenum, GLenum, const GLfloat *);
	void glMultiTexParameteriEXT(GLenum, GLenum, GLenum, GLint);
	void glMultiTexParameterivEXT(GLenum, GLenum, GLenum, const GLint *);
	void glMultiTexImage1DEXT(GLenum, GLenum, GLint, GLenum, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
	void glMultiTexImage2DEXT(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
	void glMultiTexSubImage1DEXT(GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *);
	void glMultiTexSubImage2DEXT(GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
	void glCopyMultiTexImage1DEXT(GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
	void glCopyMultiTexImage2DEXT(GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
	void glCopyMultiTexSubImage1DEXT(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei);
	void glCopyMultiTexSubImage2DEXT(GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
	void glGetMultiTexImageEXT(GLenum, GLenum, GLint, GLenum, GLenum, GLvoid *);
	void glGetMultiTexParameterfvEXT(GLenum, GLenum, GLenum, GLfloat *);
	void glGetMultiTexParameterivEXT(GLenum, GLenum, GLenum, GLint *);
	void glGetMultiTexLevelParameterfvEXT(GLenum, GLenum, GLint, GLenum, GLfloat *);
	void glGetMultiTexLevelParameterivEXT(GLenum, GLenum, GLint, GLenum, GLint *);
	void glMultiTexImage3DEXT(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
	void glMultiTexSubImage3DEXT(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
	void glCopyMultiTexSubImage3DEXT(GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
	void glBindMultiTextureEXT(GLenum, GLenum, GLuint);
	void glEnableClientStateIndexedEXT(GLenum, GLuint);
	void glDisableClientStateIndexedEXT(GLenum, GLuint);
	void glMultiTexCoordPointerEXT(GLenum, GLint, GLenum, GLsizei, const GLvoid *);
	void glMultiTexEnvfEXT(GLenum, GLenum, GLenum, GLfloat);
	void glMultiTexEnvfvEXT(GLenum, GLenum, GLenum, const GLfloat *);
	void glMultiTexEnviEXT(GLenum, GLenum, GLenum, GLint);
	void glMultiTexEnvivEXT(GLenum, GLenum, GLenum, const GLint *);
	void glMultiTexGendEXT(GLenum, GLenum, GLenum, GLdouble);
	void glMultiTexGendvEXT(GLenum, GLenum, GLenum, const GLdouble *);
	void glMultiTexGenfEXT(GLenum, GLenum, GLenum, GLfloat);
	void glMultiTexGenfvEXT(GLenum, GLenum, GLenum, const GLfloat *);
	void glMultiTexGeniEXT(GLenum, GLenum, GLenum, GLint);
	void glMultiTexGenivEXT(GLenum, GLenum, GLenum, const GLint *);
	void glGetMultiTexEnvfvEXT(GLenum, GLenum, GLenum, GLfloat *);
	void glGetMultiTexEnvivEXT(GLenum, GLenum, GLenum, GLint *);
	void glGetMultiTexGendvEXT(GLenum, GLenum, GLenum, GLdouble *);
	void glGetMultiTexGenfvEXT(GLenum, GLenum, GLenum, GLfloat *);
	void glGetMultiTexGenivEXT(GLenum, GLenum, GLenum, GLint *);
	void glGetFloatIndexedvEXT(GLenum, GLuint, GLfloat *);
	void glGetDoubleIndexedvEXT(GLenum, GLuint, GLdouble *);
	void glGetPointerIndexedvEXT(GLenum, GLuint, GLvoid* *);
	void glCompressedTextureImage3DEXT(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
	void glCompressedTextureImage2DEXT(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
	void glCompressedTextureImage1DEXT(GLuint, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *);
	void glCompressedTextureSubImage3DEXT(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
	void glCompressedTextureSubImage2DEXT(GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
	void glCompressedTextureSubImage1DEXT(GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *);
	void glGetCompressedTextureImageEXT(GLuint, GLenum, GLint, GLvoid *);
	void glCompressedMultiTexImage3DEXT(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
	void glCompressedMultiTexImage2DEXT(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
	void glCompressedMultiTexImage1DEXT(GLenum, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *);
	void glCompressedMultiTexSubImage3DEXT(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
	void glCompressedMultiTexSubImage2DEXT(GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
	void glCompressedMultiTexSubImage1DEXT(GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *);
	void glGetCompressedMultiTexImageEXT(GLenum, GLenum, GLint, GLvoid *);
	void glNamedProgramStringEXT(GLuint, GLenum, GLenum, GLsizei, const GLvoid *);
	void glNamedProgramLocalParameter4dEXT(GLuint, GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
	void glNamedProgramLocalParameter4dvEXT(GLuint, GLenum, GLuint, const GLdouble *);
	void glNamedProgramLocalParameter4fEXT(GLuint, GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
	void glNamedProgramLocalParameter4fvEXT(GLuint, GLenum, GLuint, const GLfloat *);
	void glGetNamedProgramLocalParameterdvEXT(GLuint, GLenum, GLuint, GLdouble *);
	void glGetNamedProgramLocalParameterfvEXT(GLuint, GLenum, GLuint, GLfloat *);
	void glGetNamedProgramivEXT(GLuint, GLenum, GLenum, GLint *);
	void glGetNamedProgramStringEXT(GLuint, GLenum, GLenum, GLvoid *);
	void glNamedProgramLocalParameters4fvEXT(GLuint, GLenum, GLuint, GLsizei, const GLfloat *);
	void glNamedProgramLocalParameterI4iEXT(GLuint, GLenum, GLuint, GLint, GLint, GLint, GLint);
	void glNamedProgramLocalParameterI4ivEXT(GLuint, GLenum, GLuint, const GLint *);
	void glNamedProgramLocalParametersI4ivEXT(GLuint, GLenum, GLuint, GLsizei, const GLint *);
	void glNamedProgramLocalParameterI4uiEXT(GLuint, GLenum, GLuint, GLuint, GLuint, GLuint, GLuint);
	void glNamedProgramLocalParameterI4uivEXT(GLuint, GLenum, GLuint, const GLuint *);
	void glNamedProgramLocalParametersI4uivEXT(GLuint, GLenum, GLuint, GLsizei, const GLuint *);
	void glGetNamedProgramLocalParameterIivEXT(GLuint, GLenum, GLuint, GLint *);
	void glGetNamedProgramLocalParameterIuivEXT(GLuint, GLenum, GLuint, GLuint *);
	void glTextureParameterIivEXT(GLuint, GLenum, GLenum, const GLint *);
	void glTextureParameterIuivEXT(GLuint, GLenum, GLenum, const GLuint *);
	void glGetTextureParameterIivEXT(GLuint, GLenum, GLenum, GLint *);
	void glGetTextureParameterIuivEXT(GLuint, GLenum, GLenum, GLuint *);
	void glMultiTexParameterIivEXT(GLenum, GLenum, GLenum, const GLint *);
	void glMultiTexParameterIuivEXT(GLenum, GLenum, GLenum, const GLuint *);
	void glGetMultiTexParameterIivEXT(GLenum, GLenum, GLenum, GLint *);
	void glGetMultiTexParameterIuivEXT(GLenum, GLenum, GLenum, GLuint *);
	void glProgramUniform1fEXT(GLuint, GLint, GLfloat);
	void glProgramUniform2fEXT(GLuint, GLint, GLfloat, GLfloat);
	void glProgramUniform3fEXT(GLuint, GLint, GLfloat, GLfloat, GLfloat);
	void glProgramUniform4fEXT(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat);
	void glProgramUniform1iEXT(GLuint, GLint, GLint);
	void glProgramUniform2iEXT(GLuint, GLint, GLint, GLint);
	void glProgramUniform3iEXT(GLuint, GLint, GLint, GLint, GLint);
	void glProgramUniform4iEXT(GLuint, GLint, GLint, GLint, GLint, GLint);
	void glProgramUniform1fvEXT(GLuint, GLint, GLsizei, const GLfloat *);
	void glProgramUniform2fvEXT(GLuint, GLint, GLsizei, const GLfloat *);
	void glProgramUniform3fvEXT(GLuint, GLint, GLsizei, const GLfloat *);
	void glProgramUniform4fvEXT(GLuint, GLint, GLsizei, const GLfloat *);
	void glProgramUniform1ivEXT(GLuint, GLint, GLsizei, const GLint *);
	void glProgramUniform2ivEXT(GLuint, GLint, GLsizei, const GLint *);
	void glProgramUniform3ivEXT(GLuint, GLint, GLsizei, const GLint *);
	void glProgramUniform4ivEXT(GLuint, GLint, GLsizei, const GLint *);
	void glProgramUniformMatrix2fvEXT(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
	void glProgramUniformMatrix3fvEXT(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
	void glProgramUniformMatrix4fvEXT(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
	void glProgramUniformMatrix2x3fvEXT(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
	void glProgramUniformMatrix3x2fvEXT(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
	void glProgramUniformMatrix2x4fvEXT(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
	void glProgramUniformMatrix4x2fvEXT(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
	void glProgramUniformMatrix3x4fvEXT(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
	void glProgramUniformMatrix4x3fvEXT(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
	void glProgramUniform1uiEXT(GLuint, GLint, GLuint);
	void glProgramUniform2uiEXT(GLuint, GLint, GLuint, GLuint);
	void glProgramUniform3uiEXT(GLuint, GLint, GLuint, GLuint, GLuint);
	void glProgramUniform4uiEXT(GLuint, GLint, GLuint, GLuint, GLuint, GLuint);
	void glProgramUniform1uivEXT(GLuint, GLint, GLsizei, const GLuint *);
	void glProgramUniform2uivEXT(GLuint, GLint, GLsizei, const GLuint *);
	void glProgramUniform3uivEXT(GLuint, GLint, GLsizei, const GLuint *);
	void glProgramUniform4uivEXT(GLuint, GLint, GLsizei, const GLuint *);
	void glNamedBufferDataEXT(GLuint, GLsizeiptr, const GLvoid *, GLenum);
	void glNamedBufferSubDataEXT(GLuint, GLintptr, GLsizeiptr, const GLvoid *);
	GLvoid* glMapNamedBufferEXT(GLuint, GLenum);
	GLboolean glUnmapNamedBufferEXT(GLuint);
	void glGetNamedBufferParameterivEXT(GLuint, GLenum, GLint *);
	void glGetNamedBufferPointervEXT(GLuint, GLenum, GLvoid* *);
	void glGetNamedBufferSubDataEXT(GLuint, GLintptr, GLsizeiptr, GLvoid *);
	void glTextureBufferEXT(GLuint, GLenum, GLenum, GLuint);
	void glMultiTexBufferEXT(GLenum, GLenum, GLenum, GLuint);
	void glNamedRenderbufferStorageEXT(GLuint, GLenum, GLsizei, GLsizei);
	void glGetNamedRenderbufferParameterivEXT(GLuint, GLenum, GLint *);
	GLenum glCheckNamedFramebufferStatusEXT(GLuint, GLenum);
	void glNamedFramebufferTexture1DEXT(GLuint, GLenum, GLenum, GLuint, GLint);
	void glNamedFramebufferTexture2DEXT(GLuint, GLenum, GLenum, GLuint, GLint);
	void glNamedFramebufferTexture3DEXT(GLuint, GLenum, GLenum, GLuint, GLint, GLint);
	void glNamedFramebufferRenderbufferEXT(GLuint, GLenum, GLenum, GLuint);
	void glGetNamedFramebufferAttachmentParameterivEXT(GLuint, GLenum, GLenum, GLint *);
	void glGenerateTextureMipmapEXT(GLuint, GLenum);
	void glGenerateMultiTexMipmapEXT(GLenum, GLenum);
	void glFramebufferDrawBufferEXT(GLuint, GLenum);
	void glFramebufferDrawBuffersEXT(GLuint, GLsizei, const GLenum *);
	void glFramebufferReadBufferEXT(GLuint, GLenum);
	void glGetFramebufferParameterivEXT(GLuint, GLenum, GLint *);
	void glNamedRenderbufferStorageMultisampleEXT(GLuint, GLsizei, GLenum, GLsizei, GLsizei);
	void glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint, GLsizei, GLsizei, GLenum, GLsizei, GLsizei);
	void glNamedFramebufferTextureEXT(GLuint, GLenum, GLuint, GLint);
	void glNamedFramebufferTextureLayerEXT(GLuint, GLenum, GLuint, GLint, GLint);
	void glNamedFramebufferTextureFaceEXT(GLuint, GLenum, GLuint, GLint, GLenum);
	void glTextureRenderbufferEXT(GLuint, GLenum, GLuint);
	void glMultiTexRenderbufferEXT(GLenum, GLenum, GLuint);
	void glGetMultisamplefvNV(GLenum, GLuint, GLfloat *);
	void glSampleMaskIndexedNV(GLuint, GLbitfield);
	void glTexRenderbufferNV(GLenum, GLuint);
	void glBindTransformFeedbackNV(GLenum, GLuint);
	void glDeleteTransformFeedbacksNV(GLsizei, const GLuint *);
	void glGenTransformFeedbacksNV(GLsizei, GLuint *);
	GLboolean glIsTransformFeedbackNV(GLuint);
	void glPauseTransformFeedbackNV(void);
	void glResumeTransformFeedbackNV(void);
	void glDrawTransformFeedbackNV(GLenum, GLuint);
	void glGetPerfMonitorGroupsAMD(GLint *, GLsizei, GLuint *);
	void glGetPerfMonitorCountersAMD(GLuint, GLint *, GLint *, GLsizei, GLuint *);
	void glGetPerfMonitorGroupStringAMD(GLuint, GLsizei, GLsizei *, GLchar *);
	void glGetPerfMonitorCounterStringAMD(GLuint, GLuint, GLsizei, GLsizei *, GLchar *);
	void glGetPerfMonitorCounterInfoAMD(GLuint, GLuint, GLenum, void *);
	void glGenPerfMonitorsAMD(GLsizei, GLuint *);
	void glDeletePerfMonitorsAMD(GLsizei, GLuint *);
	void glSelectPerfMonitorCountersAMD(GLuint, GLboolean, GLuint, GLint, GLuint *);
	void glBeginPerfMonitorAMD(GLuint);
	void glEndPerfMonitorAMD(GLuint);
	void glGetPerfMonitorCounterDataAMD(GLuint, GLenum, GLsizei, GLuint *, GLint *);
	void glTessellationFactorAMD(GLfloat);
	void glTessellationModeAMD(GLenum);
	void glProvokingVertexEXT(GLenum);
	void glBlendFuncIndexedAMD(GLuint, GLenum, GLenum);
	void glBlendFuncSeparateIndexedAMD(GLuint, GLenum, GLenum, GLenum, GLenum);
	void glBlendEquationIndexedAMD(GLuint, GLenum);
	void glBlendEquationSeparateIndexedAMD(GLuint, GLenum, GLenum);
	void glTextureRangeAPPLE(GLenum, GLsizei, const GLvoid *);
	void glGetTexParameterPointervAPPLE(GLenum, GLenum, GLvoid* *);
	void glEnableVertexAttribAPPLE(GLuint, GLenum);
	void glDisableVertexAttribAPPLE(GLuint, GLenum);
	GLboolean glIsVertexAttribEnabledAPPLE(GLuint, GLenum);
	void glMapVertexAttrib1dAPPLE(GLuint, GLuint, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
	void glMapVertexAttrib1fAPPLE(GLuint, GLuint, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
	void glMapVertexAttrib2dAPPLE(GLuint, GLuint, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
	void glMapVertexAttrib2fAPPLE(GLuint, GLuint, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
	GLenum glObjectPurgeableAPPLE(GLenum, GLuint, GLenum);
	GLenum glObjectUnpurgeableAPPLE(GLenum, GLuint, GLenum);
	void glGetObjectParameterivAPPLE(GLenum, GLuint, GLenum, GLint *);
	HANDLE wglCreateBufferRegionARB(HDC, int, UINT);
	VOID wglDeleteBufferRegionARB(HANDLE);
	BOOL wglSaveBufferRegionARB(HANDLE, int, int, int, int);
	BOOL wglRestoreBufferRegionARB(HANDLE, int, int, int, int, int, int);
	const char * wglGetExtensionsStringARB(HDC);
	BOOL wglGetPixelFormatAttribivARB(HDC, int, int, UINT, const int *, int *);
	BOOL wglGetPixelFormatAttribfvARB(HDC, int, int, UINT, const int *, FLOAT *);
	BOOL wglChoosePixelFormatARB(HDC, const int *, const FLOAT *, UINT, int *, UINT *);
	BOOL wglMakeContextCurrentARB(HDC, HDC, HGLRC);
	HDC wglGetCurrentReadDCARB(void);
	HPBUFFERARB wglCreatePbufferARB(HDC, int, int, int, const int *);
	HDC wglGetPbufferDCARB(HPBUFFERARB);
	int wglReleasePbufferDCARB(HPBUFFERARB, HDC);
	BOOL wglDestroyPbufferARB(HPBUFFERARB);
	BOOL wglQueryPbufferARB(HPBUFFERARB, int, int *);
	BOOL wglBindTexImageARB(HPBUFFERARB, int);
	BOOL wglReleaseTexImageARB(HPBUFFERARB, int);
	BOOL wglSetPbufferAttribARB(HPBUFFERARB, const int *);
	HGLRC wglCreateContextAttribsARB(HDC, HGLRC, const int *);
	GLboolean wglCreateDisplayColorTableEXT(GLushort);
	GLboolean wglLoadDisplayColorTableEXT(const GLushort *, GLuint);
	GLboolean wglBindDisplayColorTableEXT(GLushort);
	VOID wglDestroyDisplayColorTableEXT(GLushort);
	const char * wglGetExtensionsStringEXT(void);
	BOOL wglMakeContextCurrentEXT(HDC, HDC, HGLRC);
	HDC wglGetCurrentReadDCEXT(void);
	HPBUFFEREXT wglCreatePbufferEXT(HDC, int, int, int, const int *);
	HDC wglGetPbufferDCEXT(HPBUFFEREXT);
	int wglReleasePbufferDCEXT(HPBUFFEREXT, HDC);
	BOOL wglDestroyPbufferEXT(HPBUFFEREXT);
	BOOL wglQueryPbufferEXT(HPBUFFEREXT, int, int *);
	BOOL wglGetPixelFormatAttribivEXT(HDC, int, int, UINT, int *, int *);
	BOOL wglGetPixelFormatAttribfvEXT(HDC, int, int, UINT, int *, FLOAT *);
	BOOL wglChoosePixelFormatEXT(HDC, const int *, const FLOAT *, UINT, int *, UINT *);
	BOOL wglSwapIntervalEXT(int);
	int wglGetSwapIntervalEXT(void);
	void* wglAllocateMemoryNV(GLsizei, GLfloat, GLfloat, GLfloat);
	void wglFreeMemoryNV(void *);
	BOOL wglGetSyncValuesOML(HDC, INT64 *, INT64 *, INT64 *);
	BOOL wglGetMscRateOML(HDC, INT32 *, INT32 *);
	INT64 wglSwapBuffersMscOML(HDC, INT64, INT64, INT64);
	INT64 wglSwapLayerBuffersMscOML(HDC, int, INT64, INT64, INT64);
	BOOL wglWaitForMscOML(HDC, INT64, INT64, INT64, INT64 *, INT64 *, INT64 *);
	BOOL wglWaitForSbcOML(HDC, INT64, INT64 *, INT64 *, INT64 *);
	BOOL wglGetDigitalVideoParametersI3D(HDC, int, int *);
	BOOL wglSetDigitalVideoParametersI3D(HDC, int, const int *);
	BOOL wglGetGammaTableParametersI3D(HDC, int, int *);
	BOOL wglSetGammaTableParametersI3D(HDC, int, const int *);
	BOOL wglGetGammaTableI3D(HDC, int, USHORT *, USHORT *, USHORT *);
	BOOL wglSetGammaTableI3D(HDC, int, const USHORT *, const USHORT *, const USHORT *);
	BOOL wglEnableGenlockI3D(HDC);
	BOOL wglDisableGenlockI3D(HDC);
	BOOL wglIsEnabledGenlockI3D(HDC, BOOL *);
	BOOL wglGenlockSourceI3D(HDC, UINT);
	BOOL wglGetGenlockSourceI3D(HDC, UINT *);
	BOOL wglGenlockSourceEdgeI3D(HDC, UINT);
	BOOL wglGetGenlockSourceEdgeI3D(HDC, UINT *);
	BOOL wglGenlockSampleRateI3D(HDC, UINT);
	BOOL wglGetGenlockSampleRateI3D(HDC, UINT *);
	BOOL wglGenlockSourceDelayI3D(HDC, UINT);
	BOOL wglGetGenlockSourceDelayI3D(HDC, UINT *);
	BOOL wglQueryGenlockMaxSourceDelayI3D(HDC, UINT *, UINT *);
	LPVOID wglCreateImageBufferI3D(HDC, DWORD, UINT);
	BOOL wglDestroyImageBufferI3D(HDC, LPVOID);
	BOOL wglAssociateImageBufferEventsI3D(HDC, const HANDLE *, const LPVOID *, const DWORD *, UINT);
	BOOL wglReleaseImageBufferEventsI3D(HDC, const LPVOID *, UINT);
	BOOL wglEnableFrameLockI3D(void);
	BOOL wglDisableFrameLockI3D(void);
	BOOL wglIsEnabledFrameLockI3D(BOOL *);
	BOOL wglQueryFrameLockMasterI3D(BOOL *);
	BOOL wglGetFrameUsageI3D(float *);
	BOOL wglBeginFrameTrackingI3D(void);
	BOOL wglEndFrameTrackingI3D(void);
	BOOL wglQueryFrameTrackingI3D(DWORD *, DWORD *, float *);
	BOOL wglSetStereoEmitterState3DL(HDC, UINT);
	int wglEnumerateVideoDevicesNV(HDC, HVIDEOOUTPUTDEVICENV *);
	BOOL wglBindVideoDeviceNV(HDC, unsigned int, HVIDEOOUTPUTDEVICENV, const int *);
	BOOL wglQueryCurrentContextNV(int, int *);
	BOOL wglGetVideoDeviceNV(HDC, int, HPVIDEODEV *);
	BOOL wglReleaseVideoDeviceNV(HPVIDEODEV);
	BOOL wglBindVideoImageNV(HPVIDEODEV, HPBUFFERARB, int);
	BOOL wglReleaseVideoImageNV(HPBUFFERARB, int);
	BOOL wglSendPbufferToVideoNV(HPBUFFERARB, int, unsigned long *, BOOL);
	BOOL wglGetVideoInfoNV(HPVIDEODEV, unsigned long *, unsigned long *);
	BOOL wglJoinSwapGroupNV(HDC, GLuint);
	BOOL wglBindSwapBarrierNV(GLuint, GLuint);
	BOOL wglQuerySwapGroupNV(HDC, GLuint *, GLuint *);
	BOOL wglQueryMaxSwapGroupsNV(HDC, GLuint *, GLuint *);
	BOOL wglQueryFrameCountNV(HDC, GLuint *);
	BOOL wglResetFrameCountNV(HDC);
	BOOL wglEnumGpusNV(UINT, HGPUNV *);
	BOOL wglEnumGpuDevicesNV(HGPUNV, UINT, PGPU_DEVICE);
	HDC wglCreateAffinityDCNV(const HGPUNV *);
	BOOL wglEnumGpusFromAffinityDCNV(HDC, UINT, HGPUNV *);
	BOOL wglDeleteDCNV(HDC);
	UINT wglGetGPUIDsAMD(UINT, UINT *);
	INT wglGetGPUInfoAMD(UINT, int, GLenum, UINT, void *);
	UINT wglGetContextGPUIDAMD(HGLRC);
	HGLRC wglCreateAssociatedContextAMD(UINT);
	HGLRC wglCreateAssociatedContextAttribsAMD(UINT, HGLRC, const int *);
	BOOL wglDeleteAssociatedContextAMD(HGLRC);
	BOOL wglMakeAssociatedContextCurrentAMD(HGLRC);
	HGLRC wglGetCurrentAssociatedContextAMD(void);
	VOID wglBlitContextFramebufferAMD(HGLRC, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum);
private:
	// Private member variables
	glexfp *m_pglex;
};

//----------------------------------------------------------------------------

inline glex::glex() {
	m_pglex = new glexfp;
	assert(m_pglex!=NULL);
}

inline glex::~glex() {
	delete m_pglex;
}

inline bool glex::Load() {
	return m_pglex->Load();
}

inline long glex::Count() const {
	return m_pglex->Count();
}

inline long glex::Known() const {
	return m_pglex->Known();
}

inline bool glex::Supports(const char *sExt) const {
	return m_pglex->Supports(sExt);
}

inline void glex::glBlendColor(GLclampf a, GLclampf b, GLclampf c, GLclampf d) {
	m_pglex->glBlendColor(a,b,c,d);
}

inline void glex::glBlendEquation(GLenum a) {
	m_pglex->glBlendEquation(a);
}

inline void glex::glDrawRangeElements(GLenum a, GLuint b, GLuint c, GLsizei d, GLenum e, const GLvoid *f) {
	m_pglex->glDrawRangeElements(a,b,c,d,e,f);
}

inline void glex::glTexImage3D(GLenum a, GLint b, GLint c, GLsizei d, GLsizei e, GLsizei f, GLint g, GLenum h, GLenum i, const GLvoid *j) {
	m_pglex->glTexImage3D(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glTexSubImage3D(GLenum a, GLint b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLsizei h, GLenum i, GLenum j, const GLvoid *k) {
	m_pglex->glTexSubImage3D(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glCopyTexSubImage3D(GLenum a, GLint b, GLint c, GLint d, GLint e, GLint f, GLint g, GLsizei h, GLsizei i) {
	m_pglex->glCopyTexSubImage3D(a,b,c,d,e,f,g,h,i);
}

inline void glex::glColorTable(GLenum a, GLenum b, GLsizei c, GLenum d, GLenum e, const GLvoid *f) {
	m_pglex->glColorTable(a,b,c,d,e,f);
}

inline void glex::glColorTableParameterfv(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glColorTableParameterfv(a,b,c);
}

inline void glex::glColorTableParameteriv(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glColorTableParameteriv(a,b,c);
}

inline void glex::glCopyColorTable(GLenum a, GLenum b, GLint c, GLint d, GLsizei e) {
	m_pglex->glCopyColorTable(a,b,c,d,e);
}

inline void glex::glGetColorTable(GLenum a, GLenum b, GLenum c, GLvoid *d) {
	m_pglex->glGetColorTable(a,b,c,d);
}

inline void glex::glGetColorTableParameterfv(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetColorTableParameterfv(a,b,c);
}

inline void glex::glGetColorTableParameteriv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetColorTableParameteriv(a,b,c);
}

inline void glex::glColorSubTable(GLenum a, GLsizei b, GLsizei c, GLenum d, GLenum e, const GLvoid *f) {
	m_pglex->glColorSubTable(a,b,c,d,e,f);
}

inline void glex::glCopyColorSubTable(GLenum a, GLsizei b, GLint c, GLint d, GLsizei e) {
	m_pglex->glCopyColorSubTable(a,b,c,d,e);
}

inline void glex::glConvolutionFilter1D(GLenum a, GLenum b, GLsizei c, GLenum d, GLenum e, const GLvoid *f) {
	m_pglex->glConvolutionFilter1D(a,b,c,d,e,f);
}

inline void glex::glConvolutionFilter2D(GLenum a, GLenum b, GLsizei c, GLsizei d, GLenum e, GLenum f, const GLvoid *g) {
	m_pglex->glConvolutionFilter2D(a,b,c,d,e,f,g);
}

inline void glex::glConvolutionParameterf(GLenum a, GLenum b, GLfloat c) {
	m_pglex->glConvolutionParameterf(a,b,c);
}

inline void glex::glConvolutionParameterfv(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glConvolutionParameterfv(a,b,c);
}

inline void glex::glConvolutionParameteri(GLenum a, GLenum b, GLint c) {
	m_pglex->glConvolutionParameteri(a,b,c);
}

inline void glex::glConvolutionParameteriv(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glConvolutionParameteriv(a,b,c);
}

inline void glex::glCopyConvolutionFilter1D(GLenum a, GLenum b, GLint c, GLint d, GLsizei e) {
	m_pglex->glCopyConvolutionFilter1D(a,b,c,d,e);
}

inline void glex::glCopyConvolutionFilter2D(GLenum a, GLenum b, GLint c, GLint d, GLsizei e, GLsizei f) {
	m_pglex->glCopyConvolutionFilter2D(a,b,c,d,e,f);
}

inline void glex::glGetConvolutionFilter(GLenum a, GLenum b, GLenum c, GLvoid *d) {
	m_pglex->glGetConvolutionFilter(a,b,c,d);
}

inline void glex::glGetConvolutionParameterfv(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetConvolutionParameterfv(a,b,c);
}

inline void glex::glGetConvolutionParameteriv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetConvolutionParameteriv(a,b,c);
}

inline void glex::glGetSeparableFilter(GLenum a, GLenum b, GLenum c, GLvoid *d, GLvoid *e, GLvoid *f) {
	m_pglex->glGetSeparableFilter(a,b,c,d,e,f);
}

inline void glex::glSeparableFilter2D(GLenum a, GLenum b, GLsizei c, GLsizei d, GLenum e, GLenum f, const GLvoid *g, const GLvoid *h) {
	m_pglex->glSeparableFilter2D(a,b,c,d,e,f,g,h);
}

inline void glex::glGetHistogram(GLenum a, GLboolean b, GLenum c, GLenum d, GLvoid *e) {
	m_pglex->glGetHistogram(a,b,c,d,e);
}

inline void glex::glGetHistogramParameterfv(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetHistogramParameterfv(a,b,c);
}

inline void glex::glGetHistogramParameteriv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetHistogramParameteriv(a,b,c);
}

inline void glex::glGetMinmax(GLenum a, GLboolean b, GLenum c, GLenum d, GLvoid *e) {
	m_pglex->glGetMinmax(a,b,c,d,e);
}

inline void glex::glGetMinmaxParameterfv(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetMinmaxParameterfv(a,b,c);
}

inline void glex::glGetMinmaxParameteriv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetMinmaxParameteriv(a,b,c);
}

inline void glex::glHistogram(GLenum a, GLsizei b, GLenum c, GLboolean d) {
	m_pglex->glHistogram(a,b,c,d);
}

inline void glex::glMinmax(GLenum a, GLenum b, GLboolean c) {
	m_pglex->glMinmax(a,b,c);
}

inline void glex::glResetHistogram(GLenum a) {
	m_pglex->glResetHistogram(a);
}

inline void glex::glResetMinmax(GLenum a) {
	m_pglex->glResetMinmax(a);
}

inline void glex::glActiveTexture(GLenum a) {
	m_pglex->glActiveTexture(a);
}

inline void glex::glSampleCoverage(GLclampf a, GLboolean b) {
	m_pglex->glSampleCoverage(a,b);
}

inline void glex::glCompressedTexImage3D(GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLsizei f, GLint g, GLsizei h, const GLvoid *i) {
	m_pglex->glCompressedTexImage3D(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCompressedTexImage2D(GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLint f, GLsizei g, const GLvoid *h) {
	m_pglex->glCompressedTexImage2D(a,b,c,d,e,f,g,h);
}

inline void glex::glCompressedTexImage1D(GLenum a, GLint b, GLenum c, GLsizei d, GLint e, GLsizei f, const GLvoid *g) {
	m_pglex->glCompressedTexImage1D(a,b,c,d,e,f,g);
}

inline void glex::glCompressedTexSubImage3D(GLenum a, GLint b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLsizei h, GLenum i, GLsizei j, const GLvoid *k) {
	m_pglex->glCompressedTexSubImage3D(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glCompressedTexSubImage2D(GLenum a, GLint b, GLint c, GLint d, GLsizei e, GLsizei f, GLenum g, GLsizei h, const GLvoid *i) {
	m_pglex->glCompressedTexSubImage2D(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCompressedTexSubImage1D(GLenum a, GLint b, GLint c, GLsizei d, GLenum e, GLsizei f, const GLvoid *g) {
	m_pglex->glCompressedTexSubImage1D(a,b,c,d,e,f,g);
}

inline void glex::glGetCompressedTexImage(GLenum a, GLint b, GLvoid *c) {
	m_pglex->glGetCompressedTexImage(a,b,c);
}

inline void glex::glClientActiveTexture(GLenum a) {
	m_pglex->glClientActiveTexture(a);
}

inline void glex::glMultiTexCoord1d(GLenum a, GLdouble b) {
	m_pglex->glMultiTexCoord1d(a,b);
}

inline void glex::glMultiTexCoord1dv(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord1dv(a,b);
}

inline void glex::glMultiTexCoord1f(GLenum a, GLfloat b) {
	m_pglex->glMultiTexCoord1f(a,b);
}

inline void glex::glMultiTexCoord1fv(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord1fv(a,b);
}

inline void glex::glMultiTexCoord1i(GLenum a, GLint b) {
	m_pglex->glMultiTexCoord1i(a,b);
}

inline void glex::glMultiTexCoord1iv(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord1iv(a,b);
}

inline void glex::glMultiTexCoord1s(GLenum a, GLshort b) {
	m_pglex->glMultiTexCoord1s(a,b);
}

inline void glex::glMultiTexCoord1sv(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord1sv(a,b);
}

inline void glex::glMultiTexCoord2d(GLenum a, GLdouble b, GLdouble c) {
	m_pglex->glMultiTexCoord2d(a,b,c);
}

inline void glex::glMultiTexCoord2dv(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord2dv(a,b);
}

inline void glex::glMultiTexCoord2f(GLenum a, GLfloat b, GLfloat c) {
	m_pglex->glMultiTexCoord2f(a,b,c);
}

inline void glex::glMultiTexCoord2fv(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord2fv(a,b);
}

inline void glex::glMultiTexCoord2i(GLenum a, GLint b, GLint c) {
	m_pglex->glMultiTexCoord2i(a,b,c);
}

inline void glex::glMultiTexCoord2iv(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord2iv(a,b);
}

inline void glex::glMultiTexCoord2s(GLenum a, GLshort b, GLshort c) {
	m_pglex->glMultiTexCoord2s(a,b,c);
}

inline void glex::glMultiTexCoord2sv(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord2sv(a,b);
}

inline void glex::glMultiTexCoord3d(GLenum a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glMultiTexCoord3d(a,b,c,d);
}

inline void glex::glMultiTexCoord3dv(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord3dv(a,b);
}

inline void glex::glMultiTexCoord3f(GLenum a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glMultiTexCoord3f(a,b,c,d);
}

inline void glex::glMultiTexCoord3fv(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord3fv(a,b);
}

inline void glex::glMultiTexCoord3i(GLenum a, GLint b, GLint c, GLint d) {
	m_pglex->glMultiTexCoord3i(a,b,c,d);
}

inline void glex::glMultiTexCoord3iv(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord3iv(a,b);
}

inline void glex::glMultiTexCoord3s(GLenum a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glMultiTexCoord3s(a,b,c,d);
}

inline void glex::glMultiTexCoord3sv(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord3sv(a,b);
}

inline void glex::glMultiTexCoord4d(GLenum a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glMultiTexCoord4d(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4dv(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord4dv(a,b);
}

inline void glex::glMultiTexCoord4f(GLenum a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glMultiTexCoord4f(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4fv(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord4fv(a,b);
}

inline void glex::glMultiTexCoord4i(GLenum a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glMultiTexCoord4i(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4iv(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord4iv(a,b);
}

inline void glex::glMultiTexCoord4s(GLenum a, GLshort b, GLshort c, GLshort d, GLshort e) {
	m_pglex->glMultiTexCoord4s(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4sv(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord4sv(a,b);
}

inline void glex::glLoadTransposeMatrixf(const GLfloat *a) {
	m_pglex->glLoadTransposeMatrixf(a);
}

inline void glex::glLoadTransposeMatrixd(const GLdouble *a) {
	m_pglex->glLoadTransposeMatrixd(a);
}

inline void glex::glMultTransposeMatrixf(const GLfloat *a) {
	m_pglex->glMultTransposeMatrixf(a);
}

inline void glex::glMultTransposeMatrixd(const GLdouble *a) {
	m_pglex->glMultTransposeMatrixd(a);
}

inline void glex::glBlendFuncSeparate(GLenum a, GLenum b, GLenum c, GLenum d) {
	m_pglex->glBlendFuncSeparate(a,b,c,d);
}

inline void glex::glMultiDrawArrays(GLenum a, GLint *b, GLsizei *c, GLsizei d) {
	m_pglex->glMultiDrawArrays(a,b,c,d);
}

inline void glex::glMultiDrawElements(GLenum a, const GLsizei *b, GLenum c, const GLvoid* *d, GLsizei e) {
	m_pglex->glMultiDrawElements(a,b,c,d,e);
}

inline void glex::glPointParameterf(GLenum a, GLfloat b) {
	m_pglex->glPointParameterf(a,b);
}

inline void glex::glPointParameterfv(GLenum a, const GLfloat *b) {
	m_pglex->glPointParameterfv(a,b);
}

inline void glex::glPointParameteri(GLenum a, GLint b) {
	m_pglex->glPointParameteri(a,b);
}

inline void glex::glPointParameteriv(GLenum a, const GLint *b) {
	m_pglex->glPointParameteriv(a,b);
}

inline void glex::glFogCoordf(GLfloat a) {
	m_pglex->glFogCoordf(a);
}

inline void glex::glFogCoordfv(const GLfloat *a) {
	m_pglex->glFogCoordfv(a);
}

inline void glex::glFogCoordd(GLdouble a) {
	m_pglex->glFogCoordd(a);
}

inline void glex::glFogCoorddv(const GLdouble *a) {
	m_pglex->glFogCoorddv(a);
}

inline void glex::glFogCoordPointer(GLenum a, GLsizei b, const GLvoid *c) {
	m_pglex->glFogCoordPointer(a,b,c);
}

inline void glex::glSecondaryColor3b(GLbyte a, GLbyte b, GLbyte c) {
	m_pglex->glSecondaryColor3b(a,b,c);
}

inline void glex::glSecondaryColor3bv(const GLbyte *a) {
	m_pglex->glSecondaryColor3bv(a);
}

inline void glex::glSecondaryColor3d(GLdouble a, GLdouble b, GLdouble c) {
	m_pglex->glSecondaryColor3d(a,b,c);
}

inline void glex::glSecondaryColor3dv(const GLdouble *a) {
	m_pglex->glSecondaryColor3dv(a);
}

inline void glex::glSecondaryColor3f(GLfloat a, GLfloat b, GLfloat c) {
	m_pglex->glSecondaryColor3f(a,b,c);
}

inline void glex::glSecondaryColor3fv(const GLfloat *a) {
	m_pglex->glSecondaryColor3fv(a);
}

inline void glex::glSecondaryColor3i(GLint a, GLint b, GLint c) {
	m_pglex->glSecondaryColor3i(a,b,c);
}

inline void glex::glSecondaryColor3iv(const GLint *a) {
	m_pglex->glSecondaryColor3iv(a);
}

inline void glex::glSecondaryColor3s(GLshort a, GLshort b, GLshort c) {
	m_pglex->glSecondaryColor3s(a,b,c);
}

inline void glex::glSecondaryColor3sv(const GLshort *a) {
	m_pglex->glSecondaryColor3sv(a);
}

inline void glex::glSecondaryColor3ub(GLubyte a, GLubyte b, GLubyte c) {
	m_pglex->glSecondaryColor3ub(a,b,c);
}

inline void glex::glSecondaryColor3ubv(const GLubyte *a) {
	m_pglex->glSecondaryColor3ubv(a);
}

inline void glex::glSecondaryColor3ui(GLuint a, GLuint b, GLuint c) {
	m_pglex->glSecondaryColor3ui(a,b,c);
}

inline void glex::glSecondaryColor3uiv(const GLuint *a) {
	m_pglex->glSecondaryColor3uiv(a);
}

inline void glex::glSecondaryColor3us(GLushort a, GLushort b, GLushort c) {
	m_pglex->glSecondaryColor3us(a,b,c);
}

inline void glex::glSecondaryColor3usv(const GLushort *a) {
	m_pglex->glSecondaryColor3usv(a);
}

inline void glex::glSecondaryColorPointer(GLint a, GLenum b, GLsizei c, const GLvoid *d) {
	m_pglex->glSecondaryColorPointer(a,b,c,d);
}

inline void glex::glWindowPos2d(GLdouble a, GLdouble b) {
	m_pglex->glWindowPos2d(a,b);
}

inline void glex::glWindowPos2dv(const GLdouble *a) {
	m_pglex->glWindowPos2dv(a);
}

inline void glex::glWindowPos2f(GLfloat a, GLfloat b) {
	m_pglex->glWindowPos2f(a,b);
}

inline void glex::glWindowPos2fv(const GLfloat *a) {
	m_pglex->glWindowPos2fv(a);
}

inline void glex::glWindowPos2i(GLint a, GLint b) {
	m_pglex->glWindowPos2i(a,b);
}

inline void glex::glWindowPos2iv(const GLint *a) {
	m_pglex->glWindowPos2iv(a);
}

inline void glex::glWindowPos2s(GLshort a, GLshort b) {
	m_pglex->glWindowPos2s(a,b);
}

inline void glex::glWindowPos2sv(const GLshort *a) {
	m_pglex->glWindowPos2sv(a);
}

inline void glex::glWindowPos3d(GLdouble a, GLdouble b, GLdouble c) {
	m_pglex->glWindowPos3d(a,b,c);
}

inline void glex::glWindowPos3dv(const GLdouble *a) {
	m_pglex->glWindowPos3dv(a);
}

inline void glex::glWindowPos3f(GLfloat a, GLfloat b, GLfloat c) {
	m_pglex->glWindowPos3f(a,b,c);
}

inline void glex::glWindowPos3fv(const GLfloat *a) {
	m_pglex->glWindowPos3fv(a);
}

inline void glex::glWindowPos3i(GLint a, GLint b, GLint c) {
	m_pglex->glWindowPos3i(a,b,c);
}

inline void glex::glWindowPos3iv(const GLint *a) {
	m_pglex->glWindowPos3iv(a);
}

inline void glex::glWindowPos3s(GLshort a, GLshort b, GLshort c) {
	m_pglex->glWindowPos3s(a,b,c);
}

inline void glex::glWindowPos3sv(const GLshort *a) {
	m_pglex->glWindowPos3sv(a);
}

inline void glex::glGenQueries(GLsizei a, GLuint *b) {
	m_pglex->glGenQueries(a,b);
}

inline void glex::glDeleteQueries(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteQueries(a,b);
}

inline GLboolean glex::glIsQuery(GLuint a) {
	return m_pglex->glIsQuery(a);
}

inline void glex::glBeginQuery(GLenum a, GLuint b) {
	m_pglex->glBeginQuery(a,b);
}

inline void glex::glEndQuery(GLenum a) {
	m_pglex->glEndQuery(a);
}

inline void glex::glGetQueryiv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetQueryiv(a,b,c);
}

inline void glex::glGetQueryObjectiv(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetQueryObjectiv(a,b,c);
}

inline void glex::glGetQueryObjectuiv(GLuint a, GLenum b, GLuint *c) {
	m_pglex->glGetQueryObjectuiv(a,b,c);
}

inline void glex::glBindBuffer(GLenum a, GLuint b) {
	m_pglex->glBindBuffer(a,b);
}

inline void glex::glDeleteBuffers(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteBuffers(a,b);
}

inline void glex::glGenBuffers(GLsizei a, GLuint *b) {
	m_pglex->glGenBuffers(a,b);
}

inline GLboolean glex::glIsBuffer(GLuint a) {
	return m_pglex->glIsBuffer(a);
}

inline void glex::glBufferData(GLenum a, GLsizeiptr b, const GLvoid *c, GLenum d) {
	m_pglex->glBufferData(a,b,c,d);
}

inline void glex::glBufferSubData(GLenum a, GLintptr b, GLsizeiptr c, const GLvoid *d) {
	m_pglex->glBufferSubData(a,b,c,d);
}

inline void glex::glGetBufferSubData(GLenum a, GLintptr b, GLsizeiptr c, GLvoid *d) {
	m_pglex->glGetBufferSubData(a,b,c,d);
}

inline GLvoid* glex::glMapBuffer(GLenum a, GLenum b) {
	return m_pglex->glMapBuffer(a,b);
}

inline GLboolean glex::glUnmapBuffer(GLenum a) {
	return m_pglex->glUnmapBuffer(a);
}

inline void glex::glGetBufferParameteriv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetBufferParameteriv(a,b,c);
}

inline void glex::glGetBufferPointerv(GLenum a, GLenum b, GLvoid* *c) {
	m_pglex->glGetBufferPointerv(a,b,c);
}

inline void glex::glBlendEquationSeparate(GLenum a, GLenum b) {
	m_pglex->glBlendEquationSeparate(a,b);
}

inline void glex::glDrawBuffers(GLsizei a, const GLenum *b) {
	m_pglex->glDrawBuffers(a,b);
}

inline void glex::glStencilOpSeparate(GLenum a, GLenum b, GLenum c, GLenum d) {
	m_pglex->glStencilOpSeparate(a,b,c,d);
}

inline void glex::glStencilFuncSeparate(GLenum a, GLenum b, GLint c, GLuint d) {
	m_pglex->glStencilFuncSeparate(a,b,c,d);
}

inline void glex::glStencilMaskSeparate(GLenum a, GLuint b) {
	m_pglex->glStencilMaskSeparate(a,b);
}

inline void glex::glAttachShader(GLuint a, GLuint b) {
	m_pglex->glAttachShader(a,b);
}

inline void glex::glBindAttribLocation(GLuint a, GLuint b, const GLchar *c) {
	m_pglex->glBindAttribLocation(a,b,c);
}

inline void glex::glCompileShader(GLuint a) {
	m_pglex->glCompileShader(a);
}

inline GLuint glex::glCreateProgram(void) {
	return m_pglex->glCreateProgram();
}

inline GLuint glex::glCreateShader(GLenum a) {
	return m_pglex->glCreateShader(a);
}

inline void glex::glDeleteProgram(GLuint a) {
	m_pglex->glDeleteProgram(a);
}

inline void glex::glDeleteShader(GLuint a) {
	m_pglex->glDeleteShader(a);
}

inline void glex::glDetachShader(GLuint a, GLuint b) {
	m_pglex->glDetachShader(a,b);
}

inline void glex::glDisableVertexAttribArray(GLuint a) {
	m_pglex->glDisableVertexAttribArray(a);
}

inline void glex::glEnableVertexAttribArray(GLuint a) {
	m_pglex->glEnableVertexAttribArray(a);
}

inline void glex::glGetActiveAttrib(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLint *e, GLenum *f, GLchar *g) {
	m_pglex->glGetActiveAttrib(a,b,c,d,e,f,g);
}

inline void glex::glGetActiveUniform(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLint *e, GLenum *f, GLchar *g) {
	m_pglex->glGetActiveUniform(a,b,c,d,e,f,g);
}

inline void glex::glGetAttachedShaders(GLuint a, GLsizei b, GLsizei *c, GLuint *d) {
	m_pglex->glGetAttachedShaders(a,b,c,d);
}

inline GLint glex::glGetAttribLocation(GLuint a, const GLchar *b) {
	return m_pglex->glGetAttribLocation(a,b);
}

inline void glex::glGetProgramiv(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetProgramiv(a,b,c);
}

inline void glex::glGetProgramInfoLog(GLuint a, GLsizei b, GLsizei *c, GLchar *d) {
	m_pglex->glGetProgramInfoLog(a,b,c,d);
}

inline void glex::glGetShaderiv(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetShaderiv(a,b,c);
}

inline void glex::glGetShaderInfoLog(GLuint a, GLsizei b, GLsizei *c, GLchar *d) {
	m_pglex->glGetShaderInfoLog(a,b,c,d);
}

inline void glex::glGetShaderSource(GLuint a, GLsizei b, GLsizei *c, GLchar *d) {
	m_pglex->glGetShaderSource(a,b,c,d);
}

inline GLint glex::glGetUniformLocation(GLuint a, const GLchar *b) {
	return m_pglex->glGetUniformLocation(a,b);
}

inline void glex::glGetUniformfv(GLuint a, GLint b, GLfloat *c) {
	m_pglex->glGetUniformfv(a,b,c);
}

inline void glex::glGetUniformiv(GLuint a, GLint b, GLint *c) {
	m_pglex->glGetUniformiv(a,b,c);
}

inline void glex::glGetVertexAttribdv(GLuint a, GLenum b, GLdouble *c) {
	m_pglex->glGetVertexAttribdv(a,b,c);
}

inline void glex::glGetVertexAttribfv(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetVertexAttribfv(a,b,c);
}

inline void glex::glGetVertexAttribiv(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVertexAttribiv(a,b,c);
}

inline void glex::glGetVertexAttribPointerv(GLuint a, GLenum b, GLvoid* *c) {
	m_pglex->glGetVertexAttribPointerv(a,b,c);
}

inline GLboolean glex::glIsProgram(GLuint a) {
	return m_pglex->glIsProgram(a);
}

inline GLboolean glex::glIsShader(GLuint a) {
	return m_pglex->glIsShader(a);
}

inline void glex::glLinkProgram(GLuint a) {
	m_pglex->glLinkProgram(a);
}

inline void glex::glShaderSource(GLuint a, GLsizei b, const GLchar* *c, const GLint *d) {
	m_pglex->glShaderSource(a,b,c,d);
}

inline void glex::glUseProgram(GLuint a) {
	m_pglex->glUseProgram(a);
}

inline void glex::glUniform1f(GLint a, GLfloat b) {
	m_pglex->glUniform1f(a,b);
}

inline void glex::glUniform2f(GLint a, GLfloat b, GLfloat c) {
	m_pglex->glUniform2f(a,b,c);
}

inline void glex::glUniform3f(GLint a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glUniform3f(a,b,c,d);
}

inline void glex::glUniform4f(GLint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glUniform4f(a,b,c,d,e);
}

inline void glex::glUniform1i(GLint a, GLint b) {
	m_pglex->glUniform1i(a,b);
}

inline void glex::glUniform2i(GLint a, GLint b, GLint c) {
	m_pglex->glUniform2i(a,b,c);
}

inline void glex::glUniform3i(GLint a, GLint b, GLint c, GLint d) {
	m_pglex->glUniform3i(a,b,c,d);
}

inline void glex::glUniform4i(GLint a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glUniform4i(a,b,c,d,e);
}

inline void glex::glUniform1fv(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform1fv(a,b,c);
}

inline void glex::glUniform2fv(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform2fv(a,b,c);
}

inline void glex::glUniform3fv(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform3fv(a,b,c);
}

inline void glex::glUniform4fv(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform4fv(a,b,c);
}

inline void glex::glUniform1iv(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform1iv(a,b,c);
}

inline void glex::glUniform2iv(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform2iv(a,b,c);
}

inline void glex::glUniform3iv(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform3iv(a,b,c);
}

inline void glex::glUniform4iv(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform4iv(a,b,c);
}

inline void glex::glUniformMatrix2fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix2fv(a,b,c,d);
}

inline void glex::glUniformMatrix3fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix3fv(a,b,c,d);
}

inline void glex::glUniformMatrix4fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix4fv(a,b,c,d);
}

inline void glex::glValidateProgram(GLuint a) {
	m_pglex->glValidateProgram(a);
}

inline void glex::glVertexAttrib1d(GLuint a, GLdouble b) {
	m_pglex->glVertexAttrib1d(a,b);
}

inline void glex::glVertexAttrib1dv(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib1dv(a,b);
}

inline void glex::glVertexAttrib1f(GLuint a, GLfloat b) {
	m_pglex->glVertexAttrib1f(a,b);
}

inline void glex::glVertexAttrib1fv(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib1fv(a,b);
}

inline void glex::glVertexAttrib1s(GLuint a, GLshort b) {
	m_pglex->glVertexAttrib1s(a,b);
}

inline void glex::glVertexAttrib1sv(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib1sv(a,b);
}

inline void glex::glVertexAttrib2d(GLuint a, GLdouble b, GLdouble c) {
	m_pglex->glVertexAttrib2d(a,b,c);
}

inline void glex::glVertexAttrib2dv(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib2dv(a,b);
}

inline void glex::glVertexAttrib2f(GLuint a, GLfloat b, GLfloat c) {
	m_pglex->glVertexAttrib2f(a,b,c);
}

inline void glex::glVertexAttrib2fv(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib2fv(a,b);
}

inline void glex::glVertexAttrib2s(GLuint a, GLshort b, GLshort c) {
	m_pglex->glVertexAttrib2s(a,b,c);
}

inline void glex::glVertexAttrib2sv(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib2sv(a,b);
}

inline void glex::glVertexAttrib3d(GLuint a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glVertexAttrib3d(a,b,c,d);
}

inline void glex::glVertexAttrib3dv(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib3dv(a,b);
}

inline void glex::glVertexAttrib3f(GLuint a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glVertexAttrib3f(a,b,c,d);
}

inline void glex::glVertexAttrib3fv(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib3fv(a,b);
}

inline void glex::glVertexAttrib3s(GLuint a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glVertexAttrib3s(a,b,c,d);
}

inline void glex::glVertexAttrib3sv(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib3sv(a,b);
}

inline void glex::glVertexAttrib4Nbv(GLuint a, const GLbyte *b) {
	m_pglex->glVertexAttrib4Nbv(a,b);
}

inline void glex::glVertexAttrib4Niv(GLuint a, const GLint *b) {
	m_pglex->glVertexAttrib4Niv(a,b);
}

inline void glex::glVertexAttrib4Nsv(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib4Nsv(a,b);
}

inline void glex::glVertexAttrib4Nub(GLuint a, GLubyte b, GLubyte c, GLubyte d, GLubyte e) {
	m_pglex->glVertexAttrib4Nub(a,b,c,d,e);
}

inline void glex::glVertexAttrib4Nubv(GLuint a, const GLubyte *b) {
	m_pglex->glVertexAttrib4Nubv(a,b);
}

inline void glex::glVertexAttrib4Nuiv(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttrib4Nuiv(a,b);
}

inline void glex::glVertexAttrib4Nusv(GLuint a, const GLushort *b) {
	m_pglex->glVertexAttrib4Nusv(a,b);
}

inline void glex::glVertexAttrib4bv(GLuint a, const GLbyte *b) {
	m_pglex->glVertexAttrib4bv(a,b);
}

inline void glex::glVertexAttrib4d(GLuint a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glVertexAttrib4d(a,b,c,d,e);
}

inline void glex::glVertexAttrib4dv(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib4dv(a,b);
}

inline void glex::glVertexAttrib4f(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glVertexAttrib4f(a,b,c,d,e);
}

inline void glex::glVertexAttrib4fv(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib4fv(a,b);
}

inline void glex::glVertexAttrib4iv(GLuint a, const GLint *b) {
	m_pglex->glVertexAttrib4iv(a,b);
}

inline void glex::glVertexAttrib4s(GLuint a, GLshort b, GLshort c, GLshort d, GLshort e) {
	m_pglex->glVertexAttrib4s(a,b,c,d,e);
}

inline void glex::glVertexAttrib4sv(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib4sv(a,b);
}

inline void glex::glVertexAttrib4ubv(GLuint a, const GLubyte *b) {
	m_pglex->glVertexAttrib4ubv(a,b);
}

inline void glex::glVertexAttrib4uiv(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttrib4uiv(a,b);
}

inline void glex::glVertexAttrib4usv(GLuint a, const GLushort *b) {
	m_pglex->glVertexAttrib4usv(a,b);
}

inline void glex::glVertexAttribPointer(GLuint a, GLint b, GLenum c, GLboolean d, GLsizei e, const GLvoid *f) {
	m_pglex->glVertexAttribPointer(a,b,c,d,e,f);
}

inline void glex::glUniformMatrix2x3fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix2x3fv(a,b,c,d);
}

inline void glex::glUniformMatrix3x2fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix3x2fv(a,b,c,d);
}

inline void glex::glUniformMatrix2x4fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix2x4fv(a,b,c,d);
}

inline void glex::glUniformMatrix4x2fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix4x2fv(a,b,c,d);
}

inline void glex::glUniformMatrix3x4fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix3x4fv(a,b,c,d);
}

inline void glex::glUniformMatrix4x3fv(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix4x3fv(a,b,c,d);
}

inline void glex::glColorMaski(GLuint a, GLboolean b, GLboolean c, GLboolean d, GLboolean e) {
	m_pglex->glColorMaski(a,b,c,d,e);
}

inline void glex::glGetBooleani_v(GLenum a, GLuint b, GLboolean *c) {
	m_pglex->glGetBooleani_v(a,b,c);
}

inline void glex::glGetIntegeri_v(GLenum a, GLuint b, GLint *c) {
	m_pglex->glGetIntegeri_v(a,b,c);
}

inline void glex::glEnablei(GLenum a, GLuint b) {
	m_pglex->glEnablei(a,b);
}

inline void glex::glDisablei(GLenum a, GLuint b) {
	m_pglex->glDisablei(a,b);
}

inline GLboolean glex::glIsEnabledi(GLenum a, GLuint b) {
	return m_pglex->glIsEnabledi(a,b);
}

inline void glex::glBeginTransformFeedback(GLenum a) {
	m_pglex->glBeginTransformFeedback(a);
}

inline void glex::glEndTransformFeedback(void) {
	m_pglex->glEndTransformFeedback();
}

inline void glex::glBindBufferRange(GLenum a, GLuint b, GLuint c, GLintptr d, GLsizeiptr e) {
	m_pglex->glBindBufferRange(a,b,c,d,e);
}

inline void glex::glBindBufferBase(GLenum a, GLuint b, GLuint c) {
	m_pglex->glBindBufferBase(a,b,c);
}

inline void glex::glTransformFeedbackVaryings(GLuint a, GLsizei b, const GLchar* *c, GLenum d) {
	m_pglex->glTransformFeedbackVaryings(a,b,c,d);
}

inline void glex::glGetTransformFeedbackVarying(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLsizei *e, GLenum *f, GLchar *g) {
	m_pglex->glGetTransformFeedbackVarying(a,b,c,d,e,f,g);
}

inline void glex::glClampColor(GLenum a, GLenum b) {
	m_pglex->glClampColor(a,b);
}

inline void glex::glBeginConditionalRender(GLuint a, GLenum b) {
	m_pglex->glBeginConditionalRender(a,b);
}

inline void glex::glEndConditionalRender(void) {
	m_pglex->glEndConditionalRender();
}

inline void glex::glVertexAttribIPointer(GLuint a, GLint b, GLenum c, GLsizei d, const GLvoid *e) {
	m_pglex->glVertexAttribIPointer(a,b,c,d,e);
}

inline void glex::glGetVertexAttribIiv(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVertexAttribIiv(a,b,c);
}

inline void glex::glGetVertexAttribIuiv(GLuint a, GLenum b, GLuint *c) {
	m_pglex->glGetVertexAttribIuiv(a,b,c);
}

inline void glex::glVertexAttribI1i(GLuint a, GLint b) {
	m_pglex->glVertexAttribI1i(a,b);
}

inline void glex::glVertexAttribI2i(GLuint a, GLint b, GLint c) {
	m_pglex->glVertexAttribI2i(a,b,c);
}

inline void glex::glVertexAttribI3i(GLuint a, GLint b, GLint c, GLint d) {
	m_pglex->glVertexAttribI3i(a,b,c,d);
}

inline void glex::glVertexAttribI4i(GLuint a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glVertexAttribI4i(a,b,c,d,e);
}

inline void glex::glVertexAttribI1ui(GLuint a, GLuint b) {
	m_pglex->glVertexAttribI1ui(a,b);
}

inline void glex::glVertexAttribI2ui(GLuint a, GLuint b, GLuint c) {
	m_pglex->glVertexAttribI2ui(a,b,c);
}

inline void glex::glVertexAttribI3ui(GLuint a, GLuint b, GLuint c, GLuint d) {
	m_pglex->glVertexAttribI3ui(a,b,c,d);
}

inline void glex::glVertexAttribI4ui(GLuint a, GLuint b, GLuint c, GLuint d, GLuint e) {
	m_pglex->glVertexAttribI4ui(a,b,c,d,e);
}

inline void glex::glVertexAttribI1iv(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI1iv(a,b);
}

inline void glex::glVertexAttribI2iv(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI2iv(a,b);
}

inline void glex::glVertexAttribI3iv(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI3iv(a,b);
}

inline void glex::glVertexAttribI4iv(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI4iv(a,b);
}

inline void glex::glVertexAttribI1uiv(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI1uiv(a,b);
}

inline void glex::glVertexAttribI2uiv(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI2uiv(a,b);
}

inline void glex::glVertexAttribI3uiv(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI3uiv(a,b);
}

inline void glex::glVertexAttribI4uiv(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI4uiv(a,b);
}

inline void glex::glVertexAttribI4bv(GLuint a, const GLbyte *b) {
	m_pglex->glVertexAttribI4bv(a,b);
}

inline void glex::glVertexAttribI4sv(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttribI4sv(a,b);
}

inline void glex::glVertexAttribI4ubv(GLuint a, const GLubyte *b) {
	m_pglex->glVertexAttribI4ubv(a,b);
}

inline void glex::glVertexAttribI4usv(GLuint a, const GLushort *b) {
	m_pglex->glVertexAttribI4usv(a,b);
}

inline void glex::glGetUniformuiv(GLuint a, GLint b, GLuint *c) {
	m_pglex->glGetUniformuiv(a,b,c);
}

inline void glex::glBindFragDataLocation(GLuint a, GLuint b, const GLchar *c) {
	m_pglex->glBindFragDataLocation(a,b,c);
}

inline GLint glex::glGetFragDataLocation(GLuint a, const GLchar *b) {
	return m_pglex->glGetFragDataLocation(a,b);
}

inline void glex::glUniform1ui(GLint a, GLuint b) {
	m_pglex->glUniform1ui(a,b);
}

inline void glex::glUniform2ui(GLint a, GLuint b, GLuint c) {
	m_pglex->glUniform2ui(a,b,c);
}

inline void glex::glUniform3ui(GLint a, GLuint b, GLuint c, GLuint d) {
	m_pglex->glUniform3ui(a,b,c,d);
}

inline void glex::glUniform4ui(GLint a, GLuint b, GLuint c, GLuint d, GLuint e) {
	m_pglex->glUniform4ui(a,b,c,d,e);
}

inline void glex::glUniform1uiv(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform1uiv(a,b,c);
}

inline void glex::glUniform2uiv(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform2uiv(a,b,c);
}

inline void glex::glUniform3uiv(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform3uiv(a,b,c);
}

inline void glex::glUniform4uiv(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform4uiv(a,b,c);
}

inline void glex::glTexParameterIiv(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glTexParameterIiv(a,b,c);
}

inline void glex::glTexParameterIuiv(GLenum a, GLenum b, const GLuint *c) {
	m_pglex->glTexParameterIuiv(a,b,c);
}

inline void glex::glGetTexParameterIiv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetTexParameterIiv(a,b,c);
}

inline void glex::glGetTexParameterIuiv(GLenum a, GLenum b, GLuint *c) {
	m_pglex->glGetTexParameterIuiv(a,b,c);
}

inline void glex::glClearBufferiv(GLenum a, GLint b, const GLint *c) {
	m_pglex->glClearBufferiv(a,b,c);
}

inline void glex::glClearBufferuiv(GLenum a, GLint b, const GLuint *c) {
	m_pglex->glClearBufferuiv(a,b,c);
}

inline void glex::glClearBufferfv(GLenum a, GLint b, const GLfloat *c) {
	m_pglex->glClearBufferfv(a,b,c);
}

inline void glex::glClearBufferfi(GLenum a, GLint b, GLfloat c, GLint d) {
	m_pglex->glClearBufferfi(a,b,c,d);
}

inline const GLubyte * glex::glGetStringi(GLenum a, GLuint b) {
	return m_pglex->glGetStringi(a,b);
}

inline void glex::glDrawArraysInstanced(GLenum a, GLint b, GLsizei c, GLsizei d) {
	m_pglex->glDrawArraysInstanced(a,b,c,d);
}

inline void glex::glDrawElementsInstanced(GLenum a, GLsizei b, GLenum c, const GLvoid *d, GLsizei e) {
	m_pglex->glDrawElementsInstanced(a,b,c,d,e);
}

inline void glex::glTexBuffer(GLenum a, GLenum b, GLuint c) {
	m_pglex->glTexBuffer(a,b,c);
}

inline void glex::glPrimitiveRestartIndex(GLuint a) {
	m_pglex->glPrimitiveRestartIndex(a);
}

inline void glex::glGetInteger64i_v(GLenum a, GLuint b, GLint64 *c) {
	m_pglex->glGetInteger64i_v(a,b,c);
}

inline void glex::glGetBufferParameteri64v(GLenum a, GLenum b, GLint64 *c) {
	m_pglex->glGetBufferParameteri64v(a,b,c);
}

inline void glex::glProgramParameteri(GLuint a, GLenum b, GLint c) {
	m_pglex->glProgramParameteri(a,b,c);
}

inline void glex::glFramebufferTexture(GLenum a, GLenum b, GLuint c, GLint d) {
	m_pglex->glFramebufferTexture(a,b,c,d);
}

inline void glex::glFramebufferTextureFace(GLenum a, GLenum b, GLuint c, GLint d, GLenum e) {
	m_pglex->glFramebufferTextureFace(a,b,c,d,e);
}

inline void glex::glActiveTextureARB(GLenum a) {
	m_pglex->glActiveTextureARB(a);
}

inline void glex::glClientActiveTextureARB(GLenum a) {
	m_pglex->glClientActiveTextureARB(a);
}

inline void glex::glMultiTexCoord1dARB(GLenum a, GLdouble b) {
	m_pglex->glMultiTexCoord1dARB(a,b);
}

inline void glex::glMultiTexCoord1dvARB(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord1dvARB(a,b);
}

inline void glex::glMultiTexCoord1fARB(GLenum a, GLfloat b) {
	m_pglex->glMultiTexCoord1fARB(a,b);
}

inline void glex::glMultiTexCoord1fvARB(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord1fvARB(a,b);
}

inline void glex::glMultiTexCoord1iARB(GLenum a, GLint b) {
	m_pglex->glMultiTexCoord1iARB(a,b);
}

inline void glex::glMultiTexCoord1ivARB(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord1ivARB(a,b);
}

inline void glex::glMultiTexCoord1sARB(GLenum a, GLshort b) {
	m_pglex->glMultiTexCoord1sARB(a,b);
}

inline void glex::glMultiTexCoord1svARB(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord1svARB(a,b);
}

inline void glex::glMultiTexCoord2dARB(GLenum a, GLdouble b, GLdouble c) {
	m_pglex->glMultiTexCoord2dARB(a,b,c);
}

inline void glex::glMultiTexCoord2dvARB(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord2dvARB(a,b);
}

inline void glex::glMultiTexCoord2fARB(GLenum a, GLfloat b, GLfloat c) {
	m_pglex->glMultiTexCoord2fARB(a,b,c);
}

inline void glex::glMultiTexCoord2fvARB(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord2fvARB(a,b);
}

inline void glex::glMultiTexCoord2iARB(GLenum a, GLint b, GLint c) {
	m_pglex->glMultiTexCoord2iARB(a,b,c);
}

inline void glex::glMultiTexCoord2ivARB(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord2ivARB(a,b);
}

inline void glex::glMultiTexCoord2sARB(GLenum a, GLshort b, GLshort c) {
	m_pglex->glMultiTexCoord2sARB(a,b,c);
}

inline void glex::glMultiTexCoord2svARB(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord2svARB(a,b);
}

inline void glex::glMultiTexCoord3dARB(GLenum a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glMultiTexCoord3dARB(a,b,c,d);
}

inline void glex::glMultiTexCoord3dvARB(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord3dvARB(a,b);
}

inline void glex::glMultiTexCoord3fARB(GLenum a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glMultiTexCoord3fARB(a,b,c,d);
}

inline void glex::glMultiTexCoord3fvARB(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord3fvARB(a,b);
}

inline void glex::glMultiTexCoord3iARB(GLenum a, GLint b, GLint c, GLint d) {
	m_pglex->glMultiTexCoord3iARB(a,b,c,d);
}

inline void glex::glMultiTexCoord3ivARB(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord3ivARB(a,b);
}

inline void glex::glMultiTexCoord3sARB(GLenum a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glMultiTexCoord3sARB(a,b,c,d);
}

inline void glex::glMultiTexCoord3svARB(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord3svARB(a,b);
}

inline void glex::glMultiTexCoord4dARB(GLenum a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glMultiTexCoord4dARB(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4dvARB(GLenum a, const GLdouble *b) {
	m_pglex->glMultiTexCoord4dvARB(a,b);
}

inline void glex::glMultiTexCoord4fARB(GLenum a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glMultiTexCoord4fARB(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4fvARB(GLenum a, const GLfloat *b) {
	m_pglex->glMultiTexCoord4fvARB(a,b);
}

inline void glex::glMultiTexCoord4iARB(GLenum a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glMultiTexCoord4iARB(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4ivARB(GLenum a, const GLint *b) {
	m_pglex->glMultiTexCoord4ivARB(a,b);
}

inline void glex::glMultiTexCoord4sARB(GLenum a, GLshort b, GLshort c, GLshort d, GLshort e) {
	m_pglex->glMultiTexCoord4sARB(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4svARB(GLenum a, const GLshort *b) {
	m_pglex->glMultiTexCoord4svARB(a,b);
}

inline void glex::glLoadTransposeMatrixfARB(const GLfloat *a) {
	m_pglex->glLoadTransposeMatrixfARB(a);
}

inline void glex::glLoadTransposeMatrixdARB(const GLdouble *a) {
	m_pglex->glLoadTransposeMatrixdARB(a);
}

inline void glex::glMultTransposeMatrixfARB(const GLfloat *a) {
	m_pglex->glMultTransposeMatrixfARB(a);
}

inline void glex::glMultTransposeMatrixdARB(const GLdouble *a) {
	m_pglex->glMultTransposeMatrixdARB(a);
}

inline void glex::glSampleCoverageARB(GLclampf a, GLboolean b) {
	m_pglex->glSampleCoverageARB(a,b);
}

inline void glex::glCompressedTexImage3DARB(GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLsizei f, GLint g, GLsizei h, const GLvoid *i) {
	m_pglex->glCompressedTexImage3DARB(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCompressedTexImage2DARB(GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLint f, GLsizei g, const GLvoid *h) {
	m_pglex->glCompressedTexImage2DARB(a,b,c,d,e,f,g,h);
}

inline void glex::glCompressedTexImage1DARB(GLenum a, GLint b, GLenum c, GLsizei d, GLint e, GLsizei f, const GLvoid *g) {
	m_pglex->glCompressedTexImage1DARB(a,b,c,d,e,f,g);
}

inline void glex::glCompressedTexSubImage3DARB(GLenum a, GLint b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLsizei h, GLenum i, GLsizei j, const GLvoid *k) {
	m_pglex->glCompressedTexSubImage3DARB(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glCompressedTexSubImage2DARB(GLenum a, GLint b, GLint c, GLint d, GLsizei e, GLsizei f, GLenum g, GLsizei h, const GLvoid *i) {
	m_pglex->glCompressedTexSubImage2DARB(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCompressedTexSubImage1DARB(GLenum a, GLint b, GLint c, GLsizei d, GLenum e, GLsizei f, const GLvoid *g) {
	m_pglex->glCompressedTexSubImage1DARB(a,b,c,d,e,f,g);
}

inline void glex::glGetCompressedTexImageARB(GLenum a, GLint b, GLvoid *c) {
	m_pglex->glGetCompressedTexImageARB(a,b,c);
}

inline void glex::glPointParameterfARB(GLenum a, GLfloat b) {
	m_pglex->glPointParameterfARB(a,b);
}

inline void glex::glPointParameterfvARB(GLenum a, const GLfloat *b) {
	m_pglex->glPointParameterfvARB(a,b);
}

inline void glex::glWeightbvARB(GLint a, const GLbyte *b) {
	m_pglex->glWeightbvARB(a,b);
}

inline void glex::glWeightsvARB(GLint a, const GLshort *b) {
	m_pglex->glWeightsvARB(a,b);
}

inline void glex::glWeightivARB(GLint a, const GLint *b) {
	m_pglex->glWeightivARB(a,b);
}

inline void glex::glWeightfvARB(GLint a, const GLfloat *b) {
	m_pglex->glWeightfvARB(a,b);
}

inline void glex::glWeightdvARB(GLint a, const GLdouble *b) {
	m_pglex->glWeightdvARB(a,b);
}

inline void glex::glWeightubvARB(GLint a, const GLubyte *b) {
	m_pglex->glWeightubvARB(a,b);
}

inline void glex::glWeightusvARB(GLint a, const GLushort *b) {
	m_pglex->glWeightusvARB(a,b);
}

inline void glex::glWeightuivARB(GLint a, const GLuint *b) {
	m_pglex->glWeightuivARB(a,b);
}

inline void glex::glWeightPointerARB(GLint a, GLenum b, GLsizei c, const GLvoid *d) {
	m_pglex->glWeightPointerARB(a,b,c,d);
}

inline void glex::glVertexBlendARB(GLint a) {
	m_pglex->glVertexBlendARB(a);
}

inline void glex::glCurrentPaletteMatrixARB(GLint a) {
	m_pglex->glCurrentPaletteMatrixARB(a);
}

inline void glex::glMatrixIndexubvARB(GLint a, const GLubyte *b) {
	m_pglex->glMatrixIndexubvARB(a,b);
}

inline void glex::glMatrixIndexusvARB(GLint a, const GLushort *b) {
	m_pglex->glMatrixIndexusvARB(a,b);
}

inline void glex::glMatrixIndexuivARB(GLint a, const GLuint *b) {
	m_pglex->glMatrixIndexuivARB(a,b);
}

inline void glex::glMatrixIndexPointerARB(GLint a, GLenum b, GLsizei c, const GLvoid *d) {
	m_pglex->glMatrixIndexPointerARB(a,b,c,d);
}

inline void glex::glWindowPos2dARB(GLdouble a, GLdouble b) {
	m_pglex->glWindowPos2dARB(a,b);
}

inline void glex::glWindowPos2dvARB(const GLdouble *a) {
	m_pglex->glWindowPos2dvARB(a);
}

inline void glex::glWindowPos2fARB(GLfloat a, GLfloat b) {
	m_pglex->glWindowPos2fARB(a,b);
}

inline void glex::glWindowPos2fvARB(const GLfloat *a) {
	m_pglex->glWindowPos2fvARB(a);
}

inline void glex::glWindowPos2iARB(GLint a, GLint b) {
	m_pglex->glWindowPos2iARB(a,b);
}

inline void glex::glWindowPos2ivARB(const GLint *a) {
	m_pglex->glWindowPos2ivARB(a);
}

inline void glex::glWindowPos2sARB(GLshort a, GLshort b) {
	m_pglex->glWindowPos2sARB(a,b);
}

inline void glex::glWindowPos2svARB(const GLshort *a) {
	m_pglex->glWindowPos2svARB(a);
}

inline void glex::glWindowPos3dARB(GLdouble a, GLdouble b, GLdouble c) {
	m_pglex->glWindowPos3dARB(a,b,c);
}

inline void glex::glWindowPos3dvARB(const GLdouble *a) {
	m_pglex->glWindowPos3dvARB(a);
}

inline void glex::glWindowPos3fARB(GLfloat a, GLfloat b, GLfloat c) {
	m_pglex->glWindowPos3fARB(a,b,c);
}

inline void glex::glWindowPos3fvARB(const GLfloat *a) {
	m_pglex->glWindowPos3fvARB(a);
}

inline void glex::glWindowPos3iARB(GLint a, GLint b, GLint c) {
	m_pglex->glWindowPos3iARB(a,b,c);
}

inline void glex::glWindowPos3ivARB(const GLint *a) {
	m_pglex->glWindowPos3ivARB(a);
}

inline void glex::glWindowPos3sARB(GLshort a, GLshort b, GLshort c) {
	m_pglex->glWindowPos3sARB(a,b,c);
}

inline void glex::glWindowPos3svARB(const GLshort *a) {
	m_pglex->glWindowPos3svARB(a);
}

inline void glex::glVertexAttrib1dARB(GLuint a, GLdouble b) {
	m_pglex->glVertexAttrib1dARB(a,b);
}

inline void glex::glVertexAttrib1dvARB(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib1dvARB(a,b);
}

inline void glex::glVertexAttrib1fARB(GLuint a, GLfloat b) {
	m_pglex->glVertexAttrib1fARB(a,b);
}

inline void glex::glVertexAttrib1fvARB(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib1fvARB(a,b);
}

inline void glex::glVertexAttrib1sARB(GLuint a, GLshort b) {
	m_pglex->glVertexAttrib1sARB(a,b);
}

inline void glex::glVertexAttrib1svARB(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib1svARB(a,b);
}

inline void glex::glVertexAttrib2dARB(GLuint a, GLdouble b, GLdouble c) {
	m_pglex->glVertexAttrib2dARB(a,b,c);
}

inline void glex::glVertexAttrib2dvARB(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib2dvARB(a,b);
}

inline void glex::glVertexAttrib2fARB(GLuint a, GLfloat b, GLfloat c) {
	m_pglex->glVertexAttrib2fARB(a,b,c);
}

inline void glex::glVertexAttrib2fvARB(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib2fvARB(a,b);
}

inline void glex::glVertexAttrib2sARB(GLuint a, GLshort b, GLshort c) {
	m_pglex->glVertexAttrib2sARB(a,b,c);
}

inline void glex::glVertexAttrib2svARB(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib2svARB(a,b);
}

inline void glex::glVertexAttrib3dARB(GLuint a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glVertexAttrib3dARB(a,b,c,d);
}

inline void glex::glVertexAttrib3dvARB(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib3dvARB(a,b);
}

inline void glex::glVertexAttrib3fARB(GLuint a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glVertexAttrib3fARB(a,b,c,d);
}

inline void glex::glVertexAttrib3fvARB(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib3fvARB(a,b);
}

inline void glex::glVertexAttrib3sARB(GLuint a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glVertexAttrib3sARB(a,b,c,d);
}

inline void glex::glVertexAttrib3svARB(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib3svARB(a,b);
}

inline void glex::glVertexAttrib4NbvARB(GLuint a, const GLbyte *b) {
	m_pglex->glVertexAttrib4NbvARB(a,b);
}

inline void glex::glVertexAttrib4NivARB(GLuint a, const GLint *b) {
	m_pglex->glVertexAttrib4NivARB(a,b);
}

inline void glex::glVertexAttrib4NsvARB(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib4NsvARB(a,b);
}

inline void glex::glVertexAttrib4NubARB(GLuint a, GLubyte b, GLubyte c, GLubyte d, GLubyte e) {
	m_pglex->glVertexAttrib4NubARB(a,b,c,d,e);
}

inline void glex::glVertexAttrib4NubvARB(GLuint a, const GLubyte *b) {
	m_pglex->glVertexAttrib4NubvARB(a,b);
}

inline void glex::glVertexAttrib4NuivARB(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttrib4NuivARB(a,b);
}

inline void glex::glVertexAttrib4NusvARB(GLuint a, const GLushort *b) {
	m_pglex->glVertexAttrib4NusvARB(a,b);
}

inline void glex::glVertexAttrib4bvARB(GLuint a, const GLbyte *b) {
	m_pglex->glVertexAttrib4bvARB(a,b);
}

inline void glex::glVertexAttrib4dARB(GLuint a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glVertexAttrib4dARB(a,b,c,d,e);
}

inline void glex::glVertexAttrib4dvARB(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib4dvARB(a,b);
}

inline void glex::glVertexAttrib4fARB(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glVertexAttrib4fARB(a,b,c,d,e);
}

inline void glex::glVertexAttrib4fvARB(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib4fvARB(a,b);
}

inline void glex::glVertexAttrib4ivARB(GLuint a, const GLint *b) {
	m_pglex->glVertexAttrib4ivARB(a,b);
}

inline void glex::glVertexAttrib4sARB(GLuint a, GLshort b, GLshort c, GLshort d, GLshort e) {
	m_pglex->glVertexAttrib4sARB(a,b,c,d,e);
}

inline void glex::glVertexAttrib4svARB(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib4svARB(a,b);
}

inline void glex::glVertexAttrib4ubvARB(GLuint a, const GLubyte *b) {
	m_pglex->glVertexAttrib4ubvARB(a,b);
}

inline void glex::glVertexAttrib4uivARB(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttrib4uivARB(a,b);
}

inline void glex::glVertexAttrib4usvARB(GLuint a, const GLushort *b) {
	m_pglex->glVertexAttrib4usvARB(a,b);
}

inline void glex::glVertexAttribPointerARB(GLuint a, GLint b, GLenum c, GLboolean d, GLsizei e, const GLvoid *f) {
	m_pglex->glVertexAttribPointerARB(a,b,c,d,e,f);
}

inline void glex::glEnableVertexAttribArrayARB(GLuint a) {
	m_pglex->glEnableVertexAttribArrayARB(a);
}

inline void glex::glDisableVertexAttribArrayARB(GLuint a) {
	m_pglex->glDisableVertexAttribArrayARB(a);
}

inline void glex::glProgramStringARB(GLenum a, GLenum b, GLsizei c, const GLvoid *d) {
	m_pglex->glProgramStringARB(a,b,c,d);
}

inline void glex::glBindProgramARB(GLenum a, GLuint b) {
	m_pglex->glBindProgramARB(a,b);
}

inline void glex::glDeleteProgramsARB(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteProgramsARB(a,b);
}

inline void glex::glGenProgramsARB(GLsizei a, GLuint *b) {
	m_pglex->glGenProgramsARB(a,b);
}

inline void glex::glProgramEnvParameter4dARB(GLenum a, GLuint b, GLdouble c, GLdouble d, GLdouble e, GLdouble f) {
	m_pglex->glProgramEnvParameter4dARB(a,b,c,d,e,f);
}

inline void glex::glProgramEnvParameter4dvARB(GLenum a, GLuint b, const GLdouble *c) {
	m_pglex->glProgramEnvParameter4dvARB(a,b,c);
}

inline void glex::glProgramEnvParameter4fARB(GLenum a, GLuint b, GLfloat c, GLfloat d, GLfloat e, GLfloat f) {
	m_pglex->glProgramEnvParameter4fARB(a,b,c,d,e,f);
}

inline void glex::glProgramEnvParameter4fvARB(GLenum a, GLuint b, const GLfloat *c) {
	m_pglex->glProgramEnvParameter4fvARB(a,b,c);
}

inline void glex::glProgramLocalParameter4dARB(GLenum a, GLuint b, GLdouble c, GLdouble d, GLdouble e, GLdouble f) {
	m_pglex->glProgramLocalParameter4dARB(a,b,c,d,e,f);
}

inline void glex::glProgramLocalParameter4dvARB(GLenum a, GLuint b, const GLdouble *c) {
	m_pglex->glProgramLocalParameter4dvARB(a,b,c);
}

inline void glex::glProgramLocalParameter4fARB(GLenum a, GLuint b, GLfloat c, GLfloat d, GLfloat e, GLfloat f) {
	m_pglex->glProgramLocalParameter4fARB(a,b,c,d,e,f);
}

inline void glex::glProgramLocalParameter4fvARB(GLenum a, GLuint b, const GLfloat *c) {
	m_pglex->glProgramLocalParameter4fvARB(a,b,c);
}

inline void glex::glGetProgramEnvParameterdvARB(GLenum a, GLuint b, GLdouble *c) {
	m_pglex->glGetProgramEnvParameterdvARB(a,b,c);
}

inline void glex::glGetProgramEnvParameterfvARB(GLenum a, GLuint b, GLfloat *c) {
	m_pglex->glGetProgramEnvParameterfvARB(a,b,c);
}

inline void glex::glGetProgramLocalParameterdvARB(GLenum a, GLuint b, GLdouble *c) {
	m_pglex->glGetProgramLocalParameterdvARB(a,b,c);
}

inline void glex::glGetProgramLocalParameterfvARB(GLenum a, GLuint b, GLfloat *c) {
	m_pglex->glGetProgramLocalParameterfvARB(a,b,c);
}

inline void glex::glGetProgramivARB(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetProgramivARB(a,b,c);
}

inline void glex::glGetProgramStringARB(GLenum a, GLenum b, GLvoid *c) {
	m_pglex->glGetProgramStringARB(a,b,c);
}

inline void glex::glGetVertexAttribdvARB(GLuint a, GLenum b, GLdouble *c) {
	m_pglex->glGetVertexAttribdvARB(a,b,c);
}

inline void glex::glGetVertexAttribfvARB(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetVertexAttribfvARB(a,b,c);
}

inline void glex::glGetVertexAttribivARB(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVertexAttribivARB(a,b,c);
}

inline void glex::glGetVertexAttribPointervARB(GLuint a, GLenum b, GLvoid* *c) {
	m_pglex->glGetVertexAttribPointervARB(a,b,c);
}

inline GLboolean glex::glIsProgramARB(GLuint a) {
	return m_pglex->glIsProgramARB(a);
}

inline void glex::glBindBufferARB(GLenum a, GLuint b) {
	m_pglex->glBindBufferARB(a,b);
}

inline void glex::glDeleteBuffersARB(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteBuffersARB(a,b);
}

inline void glex::glGenBuffersARB(GLsizei a, GLuint *b) {
	m_pglex->glGenBuffersARB(a,b);
}

inline GLboolean glex::glIsBufferARB(GLuint a) {
	return m_pglex->glIsBufferARB(a);
}

inline void glex::glBufferDataARB(GLenum a, GLsizeiptrARB b, const GLvoid *c, GLenum d) {
	m_pglex->glBufferDataARB(a,b,c,d);
}

inline void glex::glBufferSubDataARB(GLenum a, GLintptrARB b, GLsizeiptrARB c, const GLvoid *d) {
	m_pglex->glBufferSubDataARB(a,b,c,d);
}

inline void glex::glGetBufferSubDataARB(GLenum a, GLintptrARB b, GLsizeiptrARB c, GLvoid *d) {
	m_pglex->glGetBufferSubDataARB(a,b,c,d);
}

inline GLvoid* glex::glMapBufferARB(GLenum a, GLenum b) {
	return m_pglex->glMapBufferARB(a,b);
}

inline GLboolean glex::glUnmapBufferARB(GLenum a) {
	return m_pglex->glUnmapBufferARB(a);
}

inline void glex::glGetBufferParameterivARB(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetBufferParameterivARB(a,b,c);
}

inline void glex::glGetBufferPointervARB(GLenum a, GLenum b, GLvoid* *c) {
	m_pglex->glGetBufferPointervARB(a,b,c);
}

inline void glex::glGenQueriesARB(GLsizei a, GLuint *b) {
	m_pglex->glGenQueriesARB(a,b);
}

inline void glex::glDeleteQueriesARB(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteQueriesARB(a,b);
}

inline GLboolean glex::glIsQueryARB(GLuint a) {
	return m_pglex->glIsQueryARB(a);
}

inline void glex::glBeginQueryARB(GLenum a, GLuint b) {
	m_pglex->glBeginQueryARB(a,b);
}

inline void glex::glEndQueryARB(GLenum a) {
	m_pglex->glEndQueryARB(a);
}

inline void glex::glGetQueryivARB(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetQueryivARB(a,b,c);
}

inline void glex::glGetQueryObjectivARB(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetQueryObjectivARB(a,b,c);
}

inline void glex::glGetQueryObjectuivARB(GLuint a, GLenum b, GLuint *c) {
	m_pglex->glGetQueryObjectuivARB(a,b,c);
}

inline void glex::glDeleteObjectARB(GLhandleARB a) {
	m_pglex->glDeleteObjectARB(a);
}

inline GLhandleARB glex::glGetHandleARB(GLenum a) {
	return m_pglex->glGetHandleARB(a);
}

inline void glex::glDetachObjectARB(GLhandleARB a, GLhandleARB b) {
	m_pglex->glDetachObjectARB(a,b);
}

inline GLhandleARB glex::glCreateShaderObjectARB(GLenum a) {
	return m_pglex->glCreateShaderObjectARB(a);
}

inline void glex::glShaderSourceARB(GLhandleARB a, GLsizei b, const GLcharARB* *c, const GLint *d) {
	m_pglex->glShaderSourceARB(a,b,c,d);
}

inline void glex::glCompileShaderARB(GLhandleARB a) {
	m_pglex->glCompileShaderARB(a);
}

inline GLhandleARB glex::glCreateProgramObjectARB(void) {
	return m_pglex->glCreateProgramObjectARB();
}

inline void glex::glAttachObjectARB(GLhandleARB a, GLhandleARB b) {
	m_pglex->glAttachObjectARB(a,b);
}

inline void glex::glLinkProgramARB(GLhandleARB a) {
	m_pglex->glLinkProgramARB(a);
}

inline void glex::glUseProgramObjectARB(GLhandleARB a) {
	m_pglex->glUseProgramObjectARB(a);
}

inline void glex::glValidateProgramARB(GLhandleARB a) {
	m_pglex->glValidateProgramARB(a);
}

inline void glex::glUniform1fARB(GLint a, GLfloat b) {
	m_pglex->glUniform1fARB(a,b);
}

inline void glex::glUniform2fARB(GLint a, GLfloat b, GLfloat c) {
	m_pglex->glUniform2fARB(a,b,c);
}

inline void glex::glUniform3fARB(GLint a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glUniform3fARB(a,b,c,d);
}

inline void glex::glUniform4fARB(GLint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glUniform4fARB(a,b,c,d,e);
}

inline void glex::glUniform1iARB(GLint a, GLint b) {
	m_pglex->glUniform1iARB(a,b);
}

inline void glex::glUniform2iARB(GLint a, GLint b, GLint c) {
	m_pglex->glUniform2iARB(a,b,c);
}

inline void glex::glUniform3iARB(GLint a, GLint b, GLint c, GLint d) {
	m_pglex->glUniform3iARB(a,b,c,d);
}

inline void glex::glUniform4iARB(GLint a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glUniform4iARB(a,b,c,d,e);
}

inline void glex::glUniform1fvARB(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform1fvARB(a,b,c);
}

inline void glex::glUniform2fvARB(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform2fvARB(a,b,c);
}

inline void glex::glUniform3fvARB(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform3fvARB(a,b,c);
}

inline void glex::glUniform4fvARB(GLint a, GLsizei b, const GLfloat *c) {
	m_pglex->glUniform4fvARB(a,b,c);
}

inline void glex::glUniform1ivARB(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform1ivARB(a,b,c);
}

inline void glex::glUniform2ivARB(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform2ivARB(a,b,c);
}

inline void glex::glUniform3ivARB(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform3ivARB(a,b,c);
}

inline void glex::glUniform4ivARB(GLint a, GLsizei b, const GLint *c) {
	m_pglex->glUniform4ivARB(a,b,c);
}

inline void glex::glUniformMatrix2fvARB(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix2fvARB(a,b,c,d);
}

inline void glex::glUniformMatrix3fvARB(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix3fvARB(a,b,c,d);
}

inline void glex::glUniformMatrix4fvARB(GLint a, GLsizei b, GLboolean c, const GLfloat *d) {
	m_pglex->glUniformMatrix4fvARB(a,b,c,d);
}

inline void glex::glGetObjectParameterfvARB(GLhandleARB a, GLenum b, GLfloat *c) {
	m_pglex->glGetObjectParameterfvARB(a,b,c);
}

inline void glex::glGetObjectParameterivARB(GLhandleARB a, GLenum b, GLint *c) {
	m_pglex->glGetObjectParameterivARB(a,b,c);
}

inline void glex::glGetInfoLogARB(GLhandleARB a, GLsizei b, GLsizei *c, GLcharARB *d) {
	m_pglex->glGetInfoLogARB(a,b,c,d);
}

inline void glex::glGetAttachedObjectsARB(GLhandleARB a, GLsizei b, GLsizei *c, GLhandleARB *d) {
	m_pglex->glGetAttachedObjectsARB(a,b,c,d);
}

inline GLint glex::glGetUniformLocationARB(GLhandleARB a, const GLcharARB *b) {
	return m_pglex->glGetUniformLocationARB(a,b);
}

inline void glex::glGetActiveUniformARB(GLhandleARB a, GLuint b, GLsizei c, GLsizei *d, GLint *e, GLenum *f, GLcharARB *g) {
	m_pglex->glGetActiveUniformARB(a,b,c,d,e,f,g);
}

inline void glex::glGetUniformfvARB(GLhandleARB a, GLint b, GLfloat *c) {
	m_pglex->glGetUniformfvARB(a,b,c);
}

inline void glex::glGetUniformivARB(GLhandleARB a, GLint b, GLint *c) {
	m_pglex->glGetUniformivARB(a,b,c);
}

inline void glex::glGetShaderSourceARB(GLhandleARB a, GLsizei b, GLsizei *c, GLcharARB *d) {
	m_pglex->glGetShaderSourceARB(a,b,c,d);
}

inline void glex::glBindAttribLocationARB(GLhandleARB a, GLuint b, const GLcharARB *c) {
	m_pglex->glBindAttribLocationARB(a,b,c);
}

inline void glex::glGetActiveAttribARB(GLhandleARB a, GLuint b, GLsizei c, GLsizei *d, GLint *e, GLenum *f, GLcharARB *g) {
	m_pglex->glGetActiveAttribARB(a,b,c,d,e,f,g);
}

inline GLint glex::glGetAttribLocationARB(GLhandleARB a, const GLcharARB *b) {
	return m_pglex->glGetAttribLocationARB(a,b);
}

inline void glex::glDrawBuffersARB(GLsizei a, const GLenum *b) {
	m_pglex->glDrawBuffersARB(a,b);
}

inline void glex::glClampColorARB(GLenum a, GLenum b) {
	m_pglex->glClampColorARB(a,b);
}

inline void glex::glDrawArraysInstancedARB(GLenum a, GLint b, GLsizei c, GLsizei d) {
	m_pglex->glDrawArraysInstancedARB(a,b,c,d);
}

inline void glex::glDrawElementsInstancedARB(GLenum a, GLsizei b, GLenum c, const GLvoid *d, GLsizei e) {
	m_pglex->glDrawElementsInstancedARB(a,b,c,d,e);
}

inline GLboolean glex::glIsRenderbuffer(GLuint a) {
	return m_pglex->glIsRenderbuffer(a);
}

inline void glex::glBindRenderbuffer(GLenum a, GLuint b) {
	m_pglex->glBindRenderbuffer(a,b);
}

inline void glex::glDeleteRenderbuffers(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteRenderbuffers(a,b);
}

inline void glex::glGenRenderbuffers(GLsizei a, GLuint *b) {
	m_pglex->glGenRenderbuffers(a,b);
}

inline void glex::glRenderbufferStorage(GLenum a, GLenum b, GLsizei c, GLsizei d) {
	m_pglex->glRenderbufferStorage(a,b,c,d);
}

inline void glex::glGetRenderbufferParameteriv(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetRenderbufferParameteriv(a,b,c);
}

inline GLboolean glex::glIsFramebuffer(GLuint a) {
	return m_pglex->glIsFramebuffer(a);
}

inline void glex::glBindFramebuffer(GLenum a, GLuint b) {
	m_pglex->glBindFramebuffer(a,b);
}

inline void glex::glDeleteFramebuffers(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteFramebuffers(a,b);
}

inline void glex::glGenFramebuffers(GLsizei a, GLuint *b) {
	m_pglex->glGenFramebuffers(a,b);
}

inline GLenum glex::glCheckFramebufferStatus(GLenum a) {
	return m_pglex->glCheckFramebufferStatus(a);
}

inline void glex::glFramebufferTexture1D(GLenum a, GLenum b, GLenum c, GLuint d, GLint e) {
	m_pglex->glFramebufferTexture1D(a,b,c,d,e);
}

inline void glex::glFramebufferTexture2D(GLenum a, GLenum b, GLenum c, GLuint d, GLint e) {
	m_pglex->glFramebufferTexture2D(a,b,c,d,e);
}

inline void glex::glFramebufferTexture3D(GLenum a, GLenum b, GLenum c, GLuint d, GLint e, GLint f) {
	m_pglex->glFramebufferTexture3D(a,b,c,d,e,f);
}

inline void glex::glFramebufferRenderbuffer(GLenum a, GLenum b, GLenum c, GLuint d) {
	m_pglex->glFramebufferRenderbuffer(a,b,c,d);
}

inline void glex::glGetFramebufferAttachmentParameteriv(GLenum a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetFramebufferAttachmentParameteriv(a,b,c,d);
}

inline void glex::glGenerateMipmap(GLenum a) {
	m_pglex->glGenerateMipmap(a);
}

inline void glex::glBlitFramebuffer(GLint a, GLint b, GLint c, GLint d, GLint e, GLint f, GLint g, GLint h, GLbitfield i, GLenum j) {
	m_pglex->glBlitFramebuffer(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glRenderbufferStorageMultisample(GLenum a, GLsizei b, GLenum c, GLsizei d, GLsizei e) {
	m_pglex->glRenderbufferStorageMultisample(a,b,c,d,e);
}

inline void glex::glFramebufferTextureLayer(GLenum a, GLenum b, GLuint c, GLint d, GLint e) {
	m_pglex->glFramebufferTextureLayer(a,b,c,d,e);
}

inline void glex::glProgramParameteriARB(GLuint a, GLenum b, GLint c) {
	m_pglex->glProgramParameteriARB(a,b,c);
}

inline void glex::glFramebufferTextureARB(GLenum a, GLenum b, GLuint c, GLint d) {
	m_pglex->glFramebufferTextureARB(a,b,c,d);
}

inline void glex::glFramebufferTextureLayerARB(GLenum a, GLenum b, GLuint c, GLint d, GLint e) {
	m_pglex->glFramebufferTextureLayerARB(a,b,c,d,e);
}

inline void glex::glFramebufferTextureFaceARB(GLenum a, GLenum b, GLuint c, GLint d, GLenum e) {
	m_pglex->glFramebufferTextureFaceARB(a,b,c,d,e);
}

inline void glex::glVertexAttribDivisorARB(GLuint a, GLuint b) {
	m_pglex->glVertexAttribDivisorARB(a,b);
}

inline GLvoid* glex::glMapBufferRange(GLenum a, GLintptr b, GLsizeiptr c, GLbitfield d) {
	return m_pglex->glMapBufferRange(a,b,c,d);
}

inline void glex::glFlushMappedBufferRange(GLenum a, GLintptr b, GLsizeiptr c) {
	m_pglex->glFlushMappedBufferRange(a,b,c);
}

inline void glex::glTexBufferARB(GLenum a, GLenum b, GLuint c) {
	m_pglex->glTexBufferARB(a,b,c);
}

inline void glex::glBindVertexArray(GLuint a) {
	m_pglex->glBindVertexArray(a);
}

inline void glex::glDeleteVertexArrays(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteVertexArrays(a,b);
}

inline void glex::glGenVertexArrays(GLsizei a, GLuint *b) {
	m_pglex->glGenVertexArrays(a,b);
}

inline GLboolean glex::glIsVertexArray(GLuint a) {
	return m_pglex->glIsVertexArray(a);
}

inline void glex::glGetUniformIndices(GLuint a, GLsizei b, const GLchar* *c, GLuint *d) {
	m_pglex->glGetUniformIndices(a,b,c,d);
}

inline void glex::glGetActiveUniformsiv(GLuint a, GLsizei b, const GLuint *c, GLenum d, GLint *e) {
	m_pglex->glGetActiveUniformsiv(a,b,c,d,e);
}

inline void glex::glGetActiveUniformName(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLchar *e) {
	m_pglex->glGetActiveUniformName(a,b,c,d,e);
}

inline GLuint glex::glGetUniformBlockIndex(GLuint a, const GLchar *b) {
	return m_pglex->glGetUniformBlockIndex(a,b);
}

inline void glex::glGetActiveUniformBlockiv(GLuint a, GLuint b, GLenum c, GLint *d) {
	m_pglex->glGetActiveUniformBlockiv(a,b,c,d);
}

inline void glex::glGetActiveUniformBlockName(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLchar *e) {
	m_pglex->glGetActiveUniformBlockName(a,b,c,d,e);
}

inline void glex::glUniformBlockBinding(GLuint a, GLuint b, GLuint c) {
	m_pglex->glUniformBlockBinding(a,b,c);
}

inline void glex::glCopyBufferSubData(GLenum a, GLenum b, GLintptr c, GLintptr d, GLsizeiptr e) {
	m_pglex->glCopyBufferSubData(a,b,c,d,e);
}

inline void glex::glDrawElementsBaseVertex(GLenum a, GLsizei b, GLenum c, const GLvoid *d, GLint e) {
	m_pglex->glDrawElementsBaseVertex(a,b,c,d,e);
}

inline void glex::glDrawRangeElementsBaseVertex(GLenum a, GLuint b, GLuint c, GLsizei d, GLenum e, const GLvoid *f, GLint g) {
	m_pglex->glDrawRangeElementsBaseVertex(a,b,c,d,e,f,g);
}

inline void glex::glDrawElementsInstancedBaseVertex(GLenum a, GLsizei b, GLenum c, const GLvoid *d, GLsizei e, GLint f) {
	m_pglex->glDrawElementsInstancedBaseVertex(a,b,c,d,e,f);
}

inline void glex::glMultiDrawElementsBaseVertex(GLenum a, const GLsizei *b, GLenum c, const GLvoid* *d, GLsizei e, const GLint *f) {
	m_pglex->glMultiDrawElementsBaseVertex(a,b,c,d,e,f);
}

inline void glex::glProvokingVertex(GLenum a) {
	m_pglex->glProvokingVertex(a);
}

inline GLsync glex::glFenceSync(GLenum a, GLbitfield b) {
	return m_pglex->glFenceSync(a,b);
}

inline GLboolean glex::glIsSync(GLsync a) {
	return m_pglex->glIsSync(a);
}

inline void glex::glDeleteSync(GLsync a) {
	m_pglex->glDeleteSync(a);
}

inline GLenum glex::glClientWaitSync(GLsync a, GLbitfield b, GLuint64 c) {
	return m_pglex->glClientWaitSync(a,b,c);
}

inline void glex::glWaitSync(GLsync a, GLbitfield b, GLuint64 c) {
	m_pglex->glWaitSync(a,b,c);
}

inline void glex::glGetInteger64v(GLenum a, GLint64 *b) {
	m_pglex->glGetInteger64v(a,b);
}

inline void glex::glGetSynciv(GLsync a, GLenum b, GLsizei c, GLsizei *d, GLint *e) {
	m_pglex->glGetSynciv(a,b,c,d,e);
}

inline void glex::glTexImage2DMultisample(GLenum a, GLsizei b, GLint c, GLsizei d, GLsizei e, GLboolean f) {
	m_pglex->glTexImage2DMultisample(a,b,c,d,e,f);
}

inline void glex::glTexImage3DMultisample(GLenum a, GLsizei b, GLint c, GLsizei d, GLsizei e, GLsizei f, GLboolean g) {
	m_pglex->glTexImage3DMultisample(a,b,c,d,e,f,g);
}

inline void glex::glGetMultisamplefv(GLenum a, GLuint b, GLfloat *c) {
	m_pglex->glGetMultisamplefv(a,b,c);
}

inline void glex::glSampleMaski(GLuint a, GLbitfield b) {
	m_pglex->glSampleMaski(a,b);
}

inline void glex::glBlendEquationi(GLuint a, GLenum b) {
	m_pglex->glBlendEquationi(a,b);
}

inline void glex::glBlendEquationSeparatei(GLuint a, GLenum b, GLenum c) {
	m_pglex->glBlendEquationSeparatei(a,b,c);
}

inline void glex::glBlendFunci(GLuint a, GLenum b, GLenum c) {
	m_pglex->glBlendFunci(a,b,c);
}

inline void glex::glBlendFuncSeparatei(GLuint a, GLenum b, GLenum c, GLenum d, GLenum e) {
	m_pglex->glBlendFuncSeparatei(a,b,c,d,e);
}

inline void glex::glMinSampleShading(GLclampf a) {
	m_pglex->glMinSampleShading(a);
}

inline void glex::glBlendColorEXT(GLclampf a, GLclampf b, GLclampf c, GLclampf d) {
	m_pglex->glBlendColorEXT(a,b,c,d);
}

inline void glex::glPolygonOffsetEXT(GLfloat a, GLfloat b) {
	m_pglex->glPolygonOffsetEXT(a,b);
}

inline void glex::glTexImage3DEXT(GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLsizei f, GLint g, GLenum h, GLenum i, const GLvoid *j) {
	m_pglex->glTexImage3DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glTexSubImage3DEXT(GLenum a, GLint b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLsizei h, GLenum i, GLenum j, const GLvoid *k) {
	m_pglex->glTexSubImage3DEXT(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glGetTexFilterFuncSGIS(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetTexFilterFuncSGIS(a,b,c);
}

inline void glex::glTexFilterFuncSGIS(GLenum a, GLenum b, GLsizei c, const GLfloat *d) {
	m_pglex->glTexFilterFuncSGIS(a,b,c,d);
}

inline void glex::glTexSubImage1DEXT(GLenum a, GLint b, GLint c, GLsizei d, GLenum e, GLenum f, const GLvoid *g) {
	m_pglex->glTexSubImage1DEXT(a,b,c,d,e,f,g);
}

inline void glex::glTexSubImage2DEXT(GLenum a, GLint b, GLint c, GLint d, GLsizei e, GLsizei f, GLenum g, GLenum h, const GLvoid *i) {
	m_pglex->glTexSubImage2DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCopyTexImage1DEXT(GLenum a, GLint b, GLenum c, GLint d, GLint e, GLsizei f, GLint g) {
	m_pglex->glCopyTexImage1DEXT(a,b,c,d,e,f,g);
}

inline void glex::glCopyTexImage2DEXT(GLenum a, GLint b, GLenum c, GLint d, GLint e, GLsizei f, GLsizei g, GLint h) {
	m_pglex->glCopyTexImage2DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glCopyTexSubImage1DEXT(GLenum a, GLint b, GLint c, GLint d, GLint e, GLsizei f) {
	m_pglex->glCopyTexSubImage1DEXT(a,b,c,d,e,f);
}

inline void glex::glCopyTexSubImage2DEXT(GLenum a, GLint b, GLint c, GLint d, GLint e, GLint f, GLsizei g, GLsizei h) {
	m_pglex->glCopyTexSubImage2DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glCopyTexSubImage3DEXT(GLenum a, GLint b, GLint c, GLint d, GLint e, GLint f, GLint g, GLsizei h, GLsizei i) {
	m_pglex->glCopyTexSubImage3DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glGetHistogramEXT(GLenum a, GLboolean b, GLenum c, GLenum d, GLvoid *e) {
	m_pglex->glGetHistogramEXT(a,b,c,d,e);
}

inline void glex::glGetHistogramParameterfvEXT(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetHistogramParameterfvEXT(a,b,c);
}

inline void glex::glGetHistogramParameterivEXT(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetHistogramParameterivEXT(a,b,c);
}

inline void glex::glGetMinmaxEXT(GLenum a, GLboolean b, GLenum c, GLenum d, GLvoid *e) {
	m_pglex->glGetMinmaxEXT(a,b,c,d,e);
}

inline void glex::glGetMinmaxParameterfvEXT(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetMinmaxParameterfvEXT(a,b,c);
}

inline void glex::glGetMinmaxParameterivEXT(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetMinmaxParameterivEXT(a,b,c);
}

inline void glex::glHistogramEXT(GLenum a, GLsizei b, GLenum c, GLboolean d) {
	m_pglex->glHistogramEXT(a,b,c,d);
}

inline void glex::glMinmaxEXT(GLenum a, GLenum b, GLboolean c) {
	m_pglex->glMinmaxEXT(a,b,c);
}

inline void glex::glResetHistogramEXT(GLenum a) {
	m_pglex->glResetHistogramEXT(a);
}

inline void glex::glResetMinmaxEXT(GLenum a) {
	m_pglex->glResetMinmaxEXT(a);
}

inline void glex::glConvolutionFilter1DEXT(GLenum a, GLenum b, GLsizei c, GLenum d, GLenum e, const GLvoid *f) {
	m_pglex->glConvolutionFilter1DEXT(a,b,c,d,e,f);
}

inline void glex::glConvolutionFilter2DEXT(GLenum a, GLenum b, GLsizei c, GLsizei d, GLenum e, GLenum f, const GLvoid *g) {
	m_pglex->glConvolutionFilter2DEXT(a,b,c,d,e,f,g);
}

inline void glex::glConvolutionParameterfEXT(GLenum a, GLenum b, GLfloat c) {
	m_pglex->glConvolutionParameterfEXT(a,b,c);
}

inline void glex::glConvolutionParameterfvEXT(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glConvolutionParameterfvEXT(a,b,c);
}

inline void glex::glConvolutionParameteriEXT(GLenum a, GLenum b, GLint c) {
	m_pglex->glConvolutionParameteriEXT(a,b,c);
}

inline void glex::glConvolutionParameterivEXT(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glConvolutionParameterivEXT(a,b,c);
}

inline void glex::glCopyConvolutionFilter1DEXT(GLenum a, GLenum b, GLint c, GLint d, GLsizei e) {
	m_pglex->glCopyConvolutionFilter1DEXT(a,b,c,d,e);
}

inline void glex::glCopyConvolutionFilter2DEXT(GLenum a, GLenum b, GLint c, GLint d, GLsizei e, GLsizei f) {
	m_pglex->glCopyConvolutionFilter2DEXT(a,b,c,d,e,f);
}

inline void glex::glGetConvolutionFilterEXT(GLenum a, GLenum b, GLenum c, GLvoid *d) {
	m_pglex->glGetConvolutionFilterEXT(a,b,c,d);
}

inline void glex::glGetConvolutionParameterfvEXT(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetConvolutionParameterfvEXT(a,b,c);
}

inline void glex::glGetConvolutionParameterivEXT(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetConvolutionParameterivEXT(a,b,c);
}

inline void glex::glGetSeparableFilterEXT(GLenum a, GLenum b, GLenum c, GLvoid *d, GLvoid *e, GLvoid *f) {
	m_pglex->glGetSeparableFilterEXT(a,b,c,d,e,f);
}

inline void glex::glSeparableFilter2DEXT(GLenum a, GLenum b, GLsizei c, GLsizei d, GLenum e, GLenum f, const GLvoid *g, const GLvoid *h) {
	m_pglex->glSeparableFilter2DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glColorTableSGI(GLenum a, GLenum b, GLsizei c, GLenum d, GLenum e, const GLvoid *f) {
	m_pglex->glColorTableSGI(a,b,c,d,e,f);
}

inline void glex::glColorTableParameterfvSGI(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glColorTableParameterfvSGI(a,b,c);
}

inline void glex::glColorTableParameterivSGI(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glColorTableParameterivSGI(a,b,c);
}

inline void glex::glCopyColorTableSGI(GLenum a, GLenum b, GLint c, GLint d, GLsizei e) {
	m_pglex->glCopyColorTableSGI(a,b,c,d,e);
}

inline void glex::glGetColorTableSGI(GLenum a, GLenum b, GLenum c, GLvoid *d) {
	m_pglex->glGetColorTableSGI(a,b,c,d);
}

inline void glex::glGetColorTableParameterfvSGI(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetColorTableParameterfvSGI(a,b,c);
}

inline void glex::glGetColorTableParameterivSGI(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetColorTableParameterivSGI(a,b,c);
}

inline void glex::glPixelTexGenSGIX(GLenum a) {
	m_pglex->glPixelTexGenSGIX(a);
}

inline void glex::glPixelTexGenParameteriSGIS(GLenum a, GLint b) {
	m_pglex->glPixelTexGenParameteriSGIS(a,b);
}

inline void glex::glPixelTexGenParameterivSGIS(GLenum a, const GLint *b) {
	m_pglex->glPixelTexGenParameterivSGIS(a,b);
}

inline void glex::glPixelTexGenParameterfSGIS(GLenum a, GLfloat b) {
	m_pglex->glPixelTexGenParameterfSGIS(a,b);
}

inline void glex::glPixelTexGenParameterfvSGIS(GLenum a, const GLfloat *b) {
	m_pglex->glPixelTexGenParameterfvSGIS(a,b);
}

inline void glex::glGetPixelTexGenParameterivSGIS(GLenum a, GLint *b) {
	m_pglex->glGetPixelTexGenParameterivSGIS(a,b);
}

inline void glex::glGetPixelTexGenParameterfvSGIS(GLenum a, GLfloat *b) {
	m_pglex->glGetPixelTexGenParameterfvSGIS(a,b);
}

inline void glex::glTexImage4DSGIS(GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLsizei f, GLsizei g, GLint h, GLenum i, GLenum j, const GLvoid *k) {
	m_pglex->glTexImage4DSGIS(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glTexSubImage4DSGIS(GLenum a, GLint b, GLint c, GLint d, GLint e, GLint f, GLsizei g, GLsizei h, GLsizei i, GLsizei j, GLenum k, GLenum l, const GLvoid *m) {
	m_pglex->glTexSubImage4DSGIS(a,b,c,d,e,f,g,h,i,j,k,l,m);
}

inline GLboolean glex::glAreTexturesResidentEXT(GLsizei a, const GLuint *b, GLboolean *c) {
	return m_pglex->glAreTexturesResidentEXT(a,b,c);
}

inline void glex::glBindTextureEXT(GLenum a, GLuint b) {
	m_pglex->glBindTextureEXT(a,b);
}

inline void glex::glDeleteTexturesEXT(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteTexturesEXT(a,b);
}

inline void glex::glGenTexturesEXT(GLsizei a, GLuint *b) {
	m_pglex->glGenTexturesEXT(a,b);
}

inline GLboolean glex::glIsTextureEXT(GLuint a) {
	return m_pglex->glIsTextureEXT(a);
}

inline void glex::glPrioritizeTexturesEXT(GLsizei a, const GLuint *b, const GLclampf *c) {
	m_pglex->glPrioritizeTexturesEXT(a,b,c);
}

inline void glex::glDetailTexFuncSGIS(GLenum a, GLsizei b, const GLfloat *c) {
	m_pglex->glDetailTexFuncSGIS(a,b,c);
}

inline void glex::glGetDetailTexFuncSGIS(GLenum a, GLfloat *b) {
	m_pglex->glGetDetailTexFuncSGIS(a,b);
}

inline void glex::glSharpenTexFuncSGIS(GLenum a, GLsizei b, const GLfloat *c) {
	m_pglex->glSharpenTexFuncSGIS(a,b,c);
}

inline void glex::glGetSharpenTexFuncSGIS(GLenum a, GLfloat *b) {
	m_pglex->glGetSharpenTexFuncSGIS(a,b);
}

inline void glex::glSampleMaskSGIS(GLclampf a, GLboolean b) {
	m_pglex->glSampleMaskSGIS(a,b);
}

inline void glex::glSamplePatternSGIS(GLenum a) {
	m_pglex->glSamplePatternSGIS(a);
}

inline void glex::glArrayElementEXT(GLint a) {
	m_pglex->glArrayElementEXT(a);
}

inline void glex::glColorPointerEXT(GLint a, GLenum b, GLsizei c, GLsizei d, const GLvoid *e) {
	m_pglex->glColorPointerEXT(a,b,c,d,e);
}

inline void glex::glDrawArraysEXT(GLenum a, GLint b, GLsizei c) {
	m_pglex->glDrawArraysEXT(a,b,c);
}

inline void glex::glEdgeFlagPointerEXT(GLsizei a, GLsizei b, const GLboolean *c) {
	m_pglex->glEdgeFlagPointerEXT(a,b,c);
}

inline void glex::glGetPointervEXT(GLenum a, GLvoid* *b) {
	m_pglex->glGetPointervEXT(a,b);
}

inline void glex::glIndexPointerEXT(GLenum a, GLsizei b, GLsizei c, const GLvoid *d) {
	m_pglex->glIndexPointerEXT(a,b,c,d);
}

inline void glex::glNormalPointerEXT(GLenum a, GLsizei b, GLsizei c, const GLvoid *d) {
	m_pglex->glNormalPointerEXT(a,b,c,d);
}

inline void glex::glTexCoordPointerEXT(GLint a, GLenum b, GLsizei c, GLsizei d, const GLvoid *e) {
	m_pglex->glTexCoordPointerEXT(a,b,c,d,e);
}

inline void glex::glVertexPointerEXT(GLint a, GLenum b, GLsizei c, GLsizei d, const GLvoid *e) {
	m_pglex->glVertexPointerEXT(a,b,c,d,e);
}

inline void glex::glBlendEquationEXT(GLenum a) {
	m_pglex->glBlendEquationEXT(a);
}

inline void glex::glSpriteParameterfSGIX(GLenum a, GLfloat b) {
	m_pglex->glSpriteParameterfSGIX(a,b);
}

inline void glex::glSpriteParameterfvSGIX(GLenum a, const GLfloat *b) {
	m_pglex->glSpriteParameterfvSGIX(a,b);
}

inline void glex::glSpriteParameteriSGIX(GLenum a, GLint b) {
	m_pglex->glSpriteParameteriSGIX(a,b);
}

inline void glex::glSpriteParameterivSGIX(GLenum a, const GLint *b) {
	m_pglex->glSpriteParameterivSGIX(a,b);
}

inline void glex::glPointParameterfEXT(GLenum a, GLfloat b) {
	m_pglex->glPointParameterfEXT(a,b);
}

inline void glex::glPointParameterfvEXT(GLenum a, const GLfloat *b) {
	m_pglex->glPointParameterfvEXT(a,b);
}

inline void glex::glPointParameterfSGIS(GLenum a, GLfloat b) {
	m_pglex->glPointParameterfSGIS(a,b);
}

inline void glex::glPointParameterfvSGIS(GLenum a, const GLfloat *b) {
	m_pglex->glPointParameterfvSGIS(a,b);
}

inline GLint glex::glGetInstrumentsSGIX(void) {
	return m_pglex->glGetInstrumentsSGIX();
}

inline void glex::glInstrumentsBufferSGIX(GLsizei a, GLint *b) {
	m_pglex->glInstrumentsBufferSGIX(a,b);
}

inline GLint glex::glPollInstrumentsSGIX(GLint *a) {
	return m_pglex->glPollInstrumentsSGIX(a);
}

inline void glex::glReadInstrumentsSGIX(GLint a) {
	m_pglex->glReadInstrumentsSGIX(a);
}

inline void glex::glStartInstrumentsSGIX(void) {
	m_pglex->glStartInstrumentsSGIX();
}

inline void glex::glStopInstrumentsSGIX(GLint a) {
	m_pglex->glStopInstrumentsSGIX(a);
}

inline void glex::glFrameZoomSGIX(GLint a) {
	m_pglex->glFrameZoomSGIX(a);
}

inline void glex::glTagSampleBufferSGIX(void) {
	m_pglex->glTagSampleBufferSGIX();
}

inline void glex::glDeformationMap3dSGIX(GLenum a, GLdouble b, GLdouble c, GLint d, GLint e, GLdouble f, GLdouble g, GLint h, GLint i, GLdouble j, GLdouble k, GLint l, GLint m, const GLdouble *n) {
	m_pglex->glDeformationMap3dSGIX(a,b,c,d,e,f,g,h,i,j,k,l,m,n);
}

inline void glex::glDeformationMap3fSGIX(GLenum a, GLfloat b, GLfloat c, GLint d, GLint e, GLfloat f, GLfloat g, GLint h, GLint i, GLfloat j, GLfloat k, GLint l, GLint m, const GLfloat *n) {
	m_pglex->glDeformationMap3fSGIX(a,b,c,d,e,f,g,h,i,j,k,l,m,n);
}

inline void glex::glDeformSGIX(GLbitfield a) {
	m_pglex->glDeformSGIX(a);
}

inline void glex::glLoadIdentityDeformationMapSGIX(GLbitfield a) {
	m_pglex->glLoadIdentityDeformationMapSGIX(a);
}

inline void glex::glReferencePlaneSGIX(const GLdouble *a) {
	m_pglex->glReferencePlaneSGIX(a);
}

inline void glex::glFlushRasterSGIX(void) {
	m_pglex->glFlushRasterSGIX();
}

inline void glex::glFogFuncSGIS(GLsizei a, const GLfloat *b) {
	m_pglex->glFogFuncSGIS(a,b);
}

inline void glex::glGetFogFuncSGIS(GLfloat *a) {
	m_pglex->glGetFogFuncSGIS(a);
}

inline void glex::glImageTransformParameteriHP(GLenum a, GLenum b, GLint c) {
	m_pglex->glImageTransformParameteriHP(a,b,c);
}

inline void glex::glImageTransformParameterfHP(GLenum a, GLenum b, GLfloat c) {
	m_pglex->glImageTransformParameterfHP(a,b,c);
}

inline void glex::glImageTransformParameterivHP(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glImageTransformParameterivHP(a,b,c);
}

inline void glex::glImageTransformParameterfvHP(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glImageTransformParameterfvHP(a,b,c);
}

inline void glex::glGetImageTransformParameterivHP(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetImageTransformParameterivHP(a,b,c);
}

inline void glex::glGetImageTransformParameterfvHP(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetImageTransformParameterfvHP(a,b,c);
}

inline void glex::glColorSubTableEXT(GLenum a, GLsizei b, GLsizei c, GLenum d, GLenum e, const GLvoid *f) {
	m_pglex->glColorSubTableEXT(a,b,c,d,e,f);
}

inline void glex::glCopyColorSubTableEXT(GLenum a, GLsizei b, GLint c, GLint d, GLsizei e) {
	m_pglex->glCopyColorSubTableEXT(a,b,c,d,e);
}

inline void glex::glHintPGI(GLenum a, GLint b) {
	m_pglex->glHintPGI(a,b);
}

inline void glex::glColorTableEXT(GLenum a, GLenum b, GLsizei c, GLenum d, GLenum e, const GLvoid *f) {
	m_pglex->glColorTableEXT(a,b,c,d,e,f);
}

inline void glex::glGetColorTableEXT(GLenum a, GLenum b, GLenum c, GLvoid *d) {
	m_pglex->glGetColorTableEXT(a,b,c,d);
}

inline void glex::glGetColorTableParameterivEXT(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetColorTableParameterivEXT(a,b,c);
}

inline void glex::glGetColorTableParameterfvEXT(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetColorTableParameterfvEXT(a,b,c);
}

inline void glex::glGetListParameterfvSGIX(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetListParameterfvSGIX(a,b,c);
}

inline void glex::glGetListParameterivSGIX(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetListParameterivSGIX(a,b,c);
}

inline void glex::glListParameterfSGIX(GLuint a, GLenum b, GLfloat c) {
	m_pglex->glListParameterfSGIX(a,b,c);
}

inline void glex::glListParameterfvSGIX(GLuint a, GLenum b, const GLfloat *c) {
	m_pglex->glListParameterfvSGIX(a,b,c);
}

inline void glex::glListParameteriSGIX(GLuint a, GLenum b, GLint c) {
	m_pglex->glListParameteriSGIX(a,b,c);
}

inline void glex::glListParameterivSGIX(GLuint a, GLenum b, const GLint *c) {
	m_pglex->glListParameterivSGIX(a,b,c);
}

inline void glex::glIndexMaterialEXT(GLenum a, GLenum b) {
	m_pglex->glIndexMaterialEXT(a,b);
}

inline void glex::glIndexFuncEXT(GLenum a, GLclampf b) {
	m_pglex->glIndexFuncEXT(a,b);
}

inline void glex::glLockArraysEXT(GLint a, GLsizei b) {
	m_pglex->glLockArraysEXT(a,b);
}

inline void glex::glUnlockArraysEXT(void) {
	m_pglex->glUnlockArraysEXT();
}

inline void glex::glCullParameterdvEXT(GLenum a, GLdouble *b) {
	m_pglex->glCullParameterdvEXT(a,b);
}

inline void glex::glCullParameterfvEXT(GLenum a, GLfloat *b) {
	m_pglex->glCullParameterfvEXT(a,b);
}

inline void glex::glFragmentColorMaterialSGIX(GLenum a, GLenum b) {
	m_pglex->glFragmentColorMaterialSGIX(a,b);
}

inline void glex::glFragmentLightfSGIX(GLenum a, GLenum b, GLfloat c) {
	m_pglex->glFragmentLightfSGIX(a,b,c);
}

inline void glex::glFragmentLightfvSGIX(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glFragmentLightfvSGIX(a,b,c);
}

inline void glex::glFragmentLightiSGIX(GLenum a, GLenum b, GLint c) {
	m_pglex->glFragmentLightiSGIX(a,b,c);
}

inline void glex::glFragmentLightivSGIX(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glFragmentLightivSGIX(a,b,c);
}

inline void glex::glFragmentLightModelfSGIX(GLenum a, GLfloat b) {
	m_pglex->glFragmentLightModelfSGIX(a,b);
}

inline void glex::glFragmentLightModelfvSGIX(GLenum a, const GLfloat *b) {
	m_pglex->glFragmentLightModelfvSGIX(a,b);
}

inline void glex::glFragmentLightModeliSGIX(GLenum a, GLint b) {
	m_pglex->glFragmentLightModeliSGIX(a,b);
}

inline void glex::glFragmentLightModelivSGIX(GLenum a, const GLint *b) {
	m_pglex->glFragmentLightModelivSGIX(a,b);
}

inline void glex::glFragmentMaterialfSGIX(GLenum a, GLenum b, GLfloat c) {
	m_pglex->glFragmentMaterialfSGIX(a,b,c);
}

inline void glex::glFragmentMaterialfvSGIX(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glFragmentMaterialfvSGIX(a,b,c);
}

inline void glex::glFragmentMaterialiSGIX(GLenum a, GLenum b, GLint c) {
	m_pglex->glFragmentMaterialiSGIX(a,b,c);
}

inline void glex::glFragmentMaterialivSGIX(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glFragmentMaterialivSGIX(a,b,c);
}

inline void glex::glGetFragmentLightfvSGIX(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetFragmentLightfvSGIX(a,b,c);
}

inline void glex::glGetFragmentLightivSGIX(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetFragmentLightivSGIX(a,b,c);
}

inline void glex::glGetFragmentMaterialfvSGIX(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetFragmentMaterialfvSGIX(a,b,c);
}

inline void glex::glGetFragmentMaterialivSGIX(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetFragmentMaterialivSGIX(a,b,c);
}

inline void glex::glLightEnviSGIX(GLenum a, GLint b) {
	m_pglex->glLightEnviSGIX(a,b);
}

inline void glex::glDrawRangeElementsEXT(GLenum a, GLuint b, GLuint c, GLsizei d, GLenum e, const GLvoid *f) {
	m_pglex->glDrawRangeElementsEXT(a,b,c,d,e,f);
}

inline void glex::glApplyTextureEXT(GLenum a) {
	m_pglex->glApplyTextureEXT(a);
}

inline void glex::glTextureLightEXT(GLenum a) {
	m_pglex->glTextureLightEXT(a);
}

inline void glex::glTextureMaterialEXT(GLenum a, GLenum b) {
	m_pglex->glTextureMaterialEXT(a,b);
}

inline void glex::glAsyncMarkerSGIX(GLuint a) {
	m_pglex->glAsyncMarkerSGIX(a);
}

inline GLint glex::glFinishAsyncSGIX(GLuint *a) {
	return m_pglex->glFinishAsyncSGIX(a);
}

inline GLint glex::glPollAsyncSGIX(GLuint *a) {
	return m_pglex->glPollAsyncSGIX(a);
}

inline GLuint glex::glGenAsyncMarkersSGIX(GLsizei a) {
	return m_pglex->glGenAsyncMarkersSGIX(a);
}

inline void glex::glDeleteAsyncMarkersSGIX(GLuint a, GLsizei b) {
	m_pglex->glDeleteAsyncMarkersSGIX(a,b);
}

inline GLboolean glex::glIsAsyncMarkerSGIX(GLuint a) {
	return m_pglex->glIsAsyncMarkerSGIX(a);
}

inline void glex::glVertexPointervINTEL(GLint a, GLenum b, const GLvoid* *c) {
	m_pglex->glVertexPointervINTEL(a,b,c);
}

inline void glex::glNormalPointervINTEL(GLenum a, const GLvoid* *b) {
	m_pglex->glNormalPointervINTEL(a,b);
}

inline void glex::glColorPointervINTEL(GLint a, GLenum b, const GLvoid* *c) {
	m_pglex->glColorPointervINTEL(a,b,c);
}

inline void glex::glTexCoordPointervINTEL(GLint a, GLenum b, const GLvoid* *c) {
	m_pglex->glTexCoordPointervINTEL(a,b,c);
}

inline void glex::glPixelTransformParameteriEXT(GLenum a, GLenum b, GLint c) {
	m_pglex->glPixelTransformParameteriEXT(a,b,c);
}

inline void glex::glPixelTransformParameterfEXT(GLenum a, GLenum b, GLfloat c) {
	m_pglex->glPixelTransformParameterfEXT(a,b,c);
}

inline void glex::glPixelTransformParameterivEXT(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glPixelTransformParameterivEXT(a,b,c);
}

inline void glex::glPixelTransformParameterfvEXT(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glPixelTransformParameterfvEXT(a,b,c);
}

inline void glex::glSecondaryColor3bEXT(GLbyte a, GLbyte b, GLbyte c) {
	m_pglex->glSecondaryColor3bEXT(a,b,c);
}

inline void glex::glSecondaryColor3bvEXT(const GLbyte *a) {
	m_pglex->glSecondaryColor3bvEXT(a);
}

inline void glex::glSecondaryColor3dEXT(GLdouble a, GLdouble b, GLdouble c) {
	m_pglex->glSecondaryColor3dEXT(a,b,c);
}

inline void glex::glSecondaryColor3dvEXT(const GLdouble *a) {
	m_pglex->glSecondaryColor3dvEXT(a);
}

inline void glex::glSecondaryColor3fEXT(GLfloat a, GLfloat b, GLfloat c) {
	m_pglex->glSecondaryColor3fEXT(a,b,c);
}

inline void glex::glSecondaryColor3fvEXT(const GLfloat *a) {
	m_pglex->glSecondaryColor3fvEXT(a);
}

inline void glex::glSecondaryColor3iEXT(GLint a, GLint b, GLint c) {
	m_pglex->glSecondaryColor3iEXT(a,b,c);
}

inline void glex::glSecondaryColor3ivEXT(const GLint *a) {
	m_pglex->glSecondaryColor3ivEXT(a);
}

inline void glex::glSecondaryColor3sEXT(GLshort a, GLshort b, GLshort c) {
	m_pglex->glSecondaryColor3sEXT(a,b,c);
}

inline void glex::glSecondaryColor3svEXT(const GLshort *a) {
	m_pglex->glSecondaryColor3svEXT(a);
}

inline void glex::glSecondaryColor3ubEXT(GLubyte a, GLubyte b, GLubyte c) {
	m_pglex->glSecondaryColor3ubEXT(a,b,c);
}

inline void glex::glSecondaryColor3ubvEXT(const GLubyte *a) {
	m_pglex->glSecondaryColor3ubvEXT(a);
}

inline void glex::glSecondaryColor3uiEXT(GLuint a, GLuint b, GLuint c) {
	m_pglex->glSecondaryColor3uiEXT(a,b,c);
}

inline void glex::glSecondaryColor3uivEXT(const GLuint *a) {
	m_pglex->glSecondaryColor3uivEXT(a);
}

inline void glex::glSecondaryColor3usEXT(GLushort a, GLushort b, GLushort c) {
	m_pglex->glSecondaryColor3usEXT(a,b,c);
}

inline void glex::glSecondaryColor3usvEXT(const GLushort *a) {
	m_pglex->glSecondaryColor3usvEXT(a);
}

inline void glex::glSecondaryColorPointerEXT(GLint a, GLenum b, GLsizei c, const GLvoid *d) {
	m_pglex->glSecondaryColorPointerEXT(a,b,c,d);
}

inline void glex::glTextureNormalEXT(GLenum a) {
	m_pglex->glTextureNormalEXT(a);
}

inline void glex::glMultiDrawArraysEXT(GLenum a, GLint *b, GLsizei *c, GLsizei d) {
	m_pglex->glMultiDrawArraysEXT(a,b,c,d);
}

inline void glex::glMultiDrawElementsEXT(GLenum a, const GLsizei *b, GLenum c, const GLvoid* *d, GLsizei e) {
	m_pglex->glMultiDrawElementsEXT(a,b,c,d,e);
}

inline void glex::glFogCoordfEXT(GLfloat a) {
	m_pglex->glFogCoordfEXT(a);
}

inline void glex::glFogCoordfvEXT(const GLfloat *a) {
	m_pglex->glFogCoordfvEXT(a);
}

inline void glex::glFogCoorddEXT(GLdouble a) {
	m_pglex->glFogCoorddEXT(a);
}

inline void glex::glFogCoorddvEXT(const GLdouble *a) {
	m_pglex->glFogCoorddvEXT(a);
}

inline void glex::glFogCoordPointerEXT(GLenum a, GLsizei b, const GLvoid *c) {
	m_pglex->glFogCoordPointerEXT(a,b,c);
}

inline void glex::glTangent3bEXT(GLbyte a, GLbyte b, GLbyte c) {
	m_pglex->glTangent3bEXT(a,b,c);
}

inline void glex::glTangent3bvEXT(const GLbyte *a) {
	m_pglex->glTangent3bvEXT(a);
}

inline void glex::glTangent3dEXT(GLdouble a, GLdouble b, GLdouble c) {
	m_pglex->glTangent3dEXT(a,b,c);
}

inline void glex::glTangent3dvEXT(const GLdouble *a) {
	m_pglex->glTangent3dvEXT(a);
}

inline void glex::glTangent3fEXT(GLfloat a, GLfloat b, GLfloat c) {
	m_pglex->glTangent3fEXT(a,b,c);
}

inline void glex::glTangent3fvEXT(const GLfloat *a) {
	m_pglex->glTangent3fvEXT(a);
}

inline void glex::glTangent3iEXT(GLint a, GLint b, GLint c) {
	m_pglex->glTangent3iEXT(a,b,c);
}

inline void glex::glTangent3ivEXT(const GLint *a) {
	m_pglex->glTangent3ivEXT(a);
}

inline void glex::glTangent3sEXT(GLshort a, GLshort b, GLshort c) {
	m_pglex->glTangent3sEXT(a,b,c);
}

inline void glex::glTangent3svEXT(const GLshort *a) {
	m_pglex->glTangent3svEXT(a);
}

inline void glex::glBinormal3bEXT(GLbyte a, GLbyte b, GLbyte c) {
	m_pglex->glBinormal3bEXT(a,b,c);
}

inline void glex::glBinormal3bvEXT(const GLbyte *a) {
	m_pglex->glBinormal3bvEXT(a);
}

inline void glex::glBinormal3dEXT(GLdouble a, GLdouble b, GLdouble c) {
	m_pglex->glBinormal3dEXT(a,b,c);
}

inline void glex::glBinormal3dvEXT(const GLdouble *a) {
	m_pglex->glBinormal3dvEXT(a);
}

inline void glex::glBinormal3fEXT(GLfloat a, GLfloat b, GLfloat c) {
	m_pglex->glBinormal3fEXT(a,b,c);
}

inline void glex::glBinormal3fvEXT(const GLfloat *a) {
	m_pglex->glBinormal3fvEXT(a);
}

inline void glex::glBinormal3iEXT(GLint a, GLint b, GLint c) {
	m_pglex->glBinormal3iEXT(a,b,c);
}

inline void glex::glBinormal3ivEXT(const GLint *a) {
	m_pglex->glBinormal3ivEXT(a);
}

inline void glex::glBinormal3sEXT(GLshort a, GLshort b, GLshort c) {
	m_pglex->glBinormal3sEXT(a,b,c);
}

inline void glex::glBinormal3svEXT(const GLshort *a) {
	m_pglex->glBinormal3svEXT(a);
}

inline void glex::glTangentPointerEXT(GLenum a, GLsizei b, const GLvoid *c) {
	m_pglex->glTangentPointerEXT(a,b,c);
}

inline void glex::glBinormalPointerEXT(GLenum a, GLsizei b, const GLvoid *c) {
	m_pglex->glBinormalPointerEXT(a,b,c);
}

inline void glex::glFinishTextureSUNX(void) {
	m_pglex->glFinishTextureSUNX();
}

inline void glex::glGlobalAlphaFactorbSUN(GLbyte a) {
	m_pglex->glGlobalAlphaFactorbSUN(a);
}

inline void glex::glGlobalAlphaFactorsSUN(GLshort a) {
	m_pglex->glGlobalAlphaFactorsSUN(a);
}

inline void glex::glGlobalAlphaFactoriSUN(GLint a) {
	m_pglex->glGlobalAlphaFactoriSUN(a);
}

inline void glex::glGlobalAlphaFactorfSUN(GLfloat a) {
	m_pglex->glGlobalAlphaFactorfSUN(a);
}

inline void glex::glGlobalAlphaFactordSUN(GLdouble a) {
	m_pglex->glGlobalAlphaFactordSUN(a);
}

inline void glex::glGlobalAlphaFactorubSUN(GLubyte a) {
	m_pglex->glGlobalAlphaFactorubSUN(a);
}

inline void glex::glGlobalAlphaFactorusSUN(GLushort a) {
	m_pglex->glGlobalAlphaFactorusSUN(a);
}

inline void glex::glGlobalAlphaFactoruiSUN(GLuint a) {
	m_pglex->glGlobalAlphaFactoruiSUN(a);
}

inline void glex::glReplacementCodeuiSUN(GLuint a) {
	m_pglex->glReplacementCodeuiSUN(a);
}

inline void glex::glReplacementCodeusSUN(GLushort a) {
	m_pglex->glReplacementCodeusSUN(a);
}

inline void glex::glReplacementCodeubSUN(GLubyte a) {
	m_pglex->glReplacementCodeubSUN(a);
}

inline void glex::glReplacementCodeuivSUN(const GLuint *a) {
	m_pglex->glReplacementCodeuivSUN(a);
}

inline void glex::glReplacementCodeusvSUN(const GLushort *a) {
	m_pglex->glReplacementCodeusvSUN(a);
}

inline void glex::glReplacementCodeubvSUN(const GLubyte *a) {
	m_pglex->glReplacementCodeubvSUN(a);
}

inline void glex::glReplacementCodePointerSUN(GLenum a, GLsizei b, const GLvoid* *c) {
	m_pglex->glReplacementCodePointerSUN(a,b,c);
}

inline void glex::glColor4ubVertex2fSUN(GLubyte a, GLubyte b, GLubyte c, GLubyte d, GLfloat e, GLfloat f) {
	m_pglex->glColor4ubVertex2fSUN(a,b,c,d,e,f);
}

inline void glex::glColor4ubVertex2fvSUN(const GLubyte *a, const GLfloat *b) {
	m_pglex->glColor4ubVertex2fvSUN(a,b);
}

inline void glex::glColor4ubVertex3fSUN(GLubyte a, GLubyte b, GLubyte c, GLubyte d, GLfloat e, GLfloat f, GLfloat g) {
	m_pglex->glColor4ubVertex3fSUN(a,b,c,d,e,f,g);
}

inline void glex::glColor4ubVertex3fvSUN(const GLubyte *a, const GLfloat *b) {
	m_pglex->glColor4ubVertex3fvSUN(a,b);
}

inline void glex::glColor3fVertex3fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f) {
	m_pglex->glColor3fVertex3fSUN(a,b,c,d,e,f);
}

inline void glex::glColor3fVertex3fvSUN(const GLfloat *a, const GLfloat *b) {
	m_pglex->glColor3fVertex3fvSUN(a,b);
}

inline void glex::glNormal3fVertex3fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f) {
	m_pglex->glNormal3fVertex3fSUN(a,b,c,d,e,f);
}

inline void glex::glNormal3fVertex3fvSUN(const GLfloat *a, const GLfloat *b) {
	m_pglex->glNormal3fVertex3fvSUN(a,b);
}

inline void glex::glColor4fNormal3fVertex3fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h, GLfloat i, GLfloat j) {
	m_pglex->glColor4fNormal3fVertex3fSUN(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glColor4fNormal3fVertex3fvSUN(const GLfloat *a, const GLfloat *b, const GLfloat *c) {
	m_pglex->glColor4fNormal3fVertex3fvSUN(a,b,c);
}

inline void glex::glTexCoord2fVertex3fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glTexCoord2fVertex3fSUN(a,b,c,d,e);
}

inline void glex::glTexCoord2fVertex3fvSUN(const GLfloat *a, const GLfloat *b) {
	m_pglex->glTexCoord2fVertex3fvSUN(a,b);
}

inline void glex::glTexCoord4fVertex4fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h) {
	m_pglex->glTexCoord4fVertex4fSUN(a,b,c,d,e,f,g,h);
}

inline void glex::glTexCoord4fVertex4fvSUN(const GLfloat *a, const GLfloat *b) {
	m_pglex->glTexCoord4fVertex4fvSUN(a,b);
}

inline void glex::glTexCoord2fColor4ubVertex3fSUN(GLfloat a, GLfloat b, GLubyte c, GLubyte d, GLubyte e, GLubyte f, GLfloat g, GLfloat h, GLfloat i) {
	m_pglex->glTexCoord2fColor4ubVertex3fSUN(a,b,c,d,e,f,g,h,i);
}

inline void glex::glTexCoord2fColor4ubVertex3fvSUN(const GLfloat *a, const GLubyte *b, const GLfloat *c) {
	m_pglex->glTexCoord2fColor4ubVertex3fvSUN(a,b,c);
}

inline void glex::glTexCoord2fColor3fVertex3fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h) {
	m_pglex->glTexCoord2fColor3fVertex3fSUN(a,b,c,d,e,f,g,h);
}

inline void glex::glTexCoord2fColor3fVertex3fvSUN(const GLfloat *a, const GLfloat *b, const GLfloat *c) {
	m_pglex->glTexCoord2fColor3fVertex3fvSUN(a,b,c);
}

inline void glex::glTexCoord2fNormal3fVertex3fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h) {
	m_pglex->glTexCoord2fNormal3fVertex3fSUN(a,b,c,d,e,f,g,h);
}

inline void glex::glTexCoord2fNormal3fVertex3fvSUN(const GLfloat *a, const GLfloat *b, const GLfloat *c) {
	m_pglex->glTexCoord2fNormal3fVertex3fvSUN(a,b,c);
}

inline void glex::glTexCoord2fColor4fNormal3fVertex3fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h, GLfloat i, GLfloat j, GLfloat k, GLfloat l) {
	m_pglex->glTexCoord2fColor4fNormal3fVertex3fSUN(a,b,c,d,e,f,g,h,i,j,k,l);
}

inline void glex::glTexCoord2fColor4fNormal3fVertex3fvSUN(const GLfloat *a, const GLfloat *b, const GLfloat *c, const GLfloat *d) {
	m_pglex->glTexCoord2fColor4fNormal3fVertex3fvSUN(a,b,c,d);
}

inline void glex::glTexCoord4fColor4fNormal3fVertex4fSUN(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h, GLfloat i, GLfloat j, GLfloat k, GLfloat l, GLfloat m, GLfloat n, GLfloat o) {
	m_pglex->glTexCoord4fColor4fNormal3fVertex4fSUN(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o);
}

inline void glex::glTexCoord4fColor4fNormal3fVertex4fvSUN(const GLfloat *a, const GLfloat *b, const GLfloat *c, const GLfloat *d) {
	m_pglex->glTexCoord4fColor4fNormal3fVertex4fvSUN(a,b,c,d);
}

inline void glex::glReplacementCodeuiVertex3fSUN(GLuint a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glReplacementCodeuiVertex3fSUN(a,b,c,d);
}

inline void glex::glReplacementCodeuiVertex3fvSUN(const GLuint *a, const GLfloat *b) {
	m_pglex->glReplacementCodeuiVertex3fvSUN(a,b);
}

inline void glex::glReplacementCodeuiColor4ubVertex3fSUN(GLuint a, GLubyte b, GLubyte c, GLubyte d, GLubyte e, GLfloat f, GLfloat g, GLfloat h) {
	m_pglex->glReplacementCodeuiColor4ubVertex3fSUN(a,b,c,d,e,f,g,h);
}

inline void glex::glReplacementCodeuiColor4ubVertex3fvSUN(const GLuint *a, const GLubyte *b, const GLfloat *c) {
	m_pglex->glReplacementCodeuiColor4ubVertex3fvSUN(a,b,c);
}

inline void glex::glReplacementCodeuiColor3fVertex3fSUN(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g) {
	m_pglex->glReplacementCodeuiColor3fVertex3fSUN(a,b,c,d,e,f,g);
}

inline void glex::glReplacementCodeuiColor3fVertex3fvSUN(const GLuint *a, const GLfloat *b, const GLfloat *c) {
	m_pglex->glReplacementCodeuiColor3fVertex3fvSUN(a,b,c);
}

inline void glex::glReplacementCodeuiNormal3fVertex3fSUN(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g) {
	m_pglex->glReplacementCodeuiNormal3fVertex3fSUN(a,b,c,d,e,f,g);
}

inline void glex::glReplacementCodeuiNormal3fVertex3fvSUN(const GLuint *a, const GLfloat *b, const GLfloat *c) {
	m_pglex->glReplacementCodeuiNormal3fVertex3fvSUN(a,b,c);
}

inline void glex::glReplacementCodeuiColor4fNormal3fVertex3fSUN(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h, GLfloat i, GLfloat j, GLfloat k) {
	m_pglex->glReplacementCodeuiColor4fNormal3fVertex3fSUN(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glReplacementCodeuiColor4fNormal3fVertex3fvSUN(const GLuint *a, const GLfloat *b, const GLfloat *c, const GLfloat *d) {
	m_pglex->glReplacementCodeuiColor4fNormal3fVertex3fvSUN(a,b,c,d);
}

inline void glex::glReplacementCodeuiTexCoord2fVertex3fSUN(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f) {
	m_pglex->glReplacementCodeuiTexCoord2fVertex3fSUN(a,b,c,d,e,f);
}

inline void glex::glReplacementCodeuiTexCoord2fVertex3fvSUN(const GLuint *a, const GLfloat *b, const GLfloat *c) {
	m_pglex->glReplacementCodeuiTexCoord2fVertex3fvSUN(a,b,c);
}

inline void glex::glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h, GLfloat i) {
	m_pglex->glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(a,b,c,d,e,f,g,h,i);
}

inline void glex::glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(const GLuint *a, const GLfloat *b, const GLfloat *c, const GLfloat *d) {
	m_pglex->glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(a,b,c,d);
}

inline void glex::glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f, GLfloat g, GLfloat h, GLfloat i, GLfloat j, GLfloat k, GLfloat l, GLfloat m) {
	m_pglex->glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(a,b,c,d,e,f,g,h,i,j,k,l,m);
}

inline void glex::glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(const GLuint *a, const GLfloat *b, const GLfloat *c, const GLfloat *d, const GLfloat *e) {
	m_pglex->glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(a,b,c,d,e);
}

inline void glex::glBlendFuncSeparateEXT(GLenum a, GLenum b, GLenum c, GLenum d) {
	m_pglex->glBlendFuncSeparateEXT(a,b,c,d);
}

inline void glex::glBlendFuncSeparateINGR(GLenum a, GLenum b, GLenum c, GLenum d) {
	m_pglex->glBlendFuncSeparateINGR(a,b,c,d);
}

inline void glex::glVertexWeightfEXT(GLfloat a) {
	m_pglex->glVertexWeightfEXT(a);
}

inline void glex::glVertexWeightfvEXT(const GLfloat *a) {
	m_pglex->glVertexWeightfvEXT(a);
}

inline void glex::glVertexWeightPointerEXT(GLsizei a, GLenum b, GLsizei c, const GLvoid *d) {
	m_pglex->glVertexWeightPointerEXT(a,b,c,d);
}

inline void glex::glFlushVertexArrayRangeNV(void) {
	m_pglex->glFlushVertexArrayRangeNV();
}

inline void glex::glVertexArrayRangeNV(GLsizei a, const GLvoid *b) {
	m_pglex->glVertexArrayRangeNV(a,b);
}

inline void glex::glCombinerParameterfvNV(GLenum a, const GLfloat *b) {
	m_pglex->glCombinerParameterfvNV(a,b);
}

inline void glex::glCombinerParameterfNV(GLenum a, GLfloat b) {
	m_pglex->glCombinerParameterfNV(a,b);
}

inline void glex::glCombinerParameterivNV(GLenum a, const GLint *b) {
	m_pglex->glCombinerParameterivNV(a,b);
}

inline void glex::glCombinerParameteriNV(GLenum a, GLint b) {
	m_pglex->glCombinerParameteriNV(a,b);
}

inline void glex::glCombinerInputNV(GLenum a, GLenum b, GLenum c, GLenum d, GLenum e, GLenum f) {
	m_pglex->glCombinerInputNV(a,b,c,d,e,f);
}

inline void glex::glCombinerOutputNV(GLenum a, GLenum b, GLenum c, GLenum d, GLenum e, GLenum f, GLenum g, GLboolean h, GLboolean i, GLboolean j) {
	m_pglex->glCombinerOutputNV(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glFinalCombinerInputNV(GLenum a, GLenum b, GLenum c, GLenum d) {
	m_pglex->glFinalCombinerInputNV(a,b,c,d);
}

inline void glex::glGetCombinerInputParameterfvNV(GLenum a, GLenum b, GLenum c, GLenum d, GLfloat *e) {
	m_pglex->glGetCombinerInputParameterfvNV(a,b,c,d,e);
}

inline void glex::glGetCombinerInputParameterivNV(GLenum a, GLenum b, GLenum c, GLenum d, GLint *e) {
	m_pglex->glGetCombinerInputParameterivNV(a,b,c,d,e);
}

inline void glex::glGetCombinerOutputParameterfvNV(GLenum a, GLenum b, GLenum c, GLfloat *d) {
	m_pglex->glGetCombinerOutputParameterfvNV(a,b,c,d);
}

inline void glex::glGetCombinerOutputParameterivNV(GLenum a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetCombinerOutputParameterivNV(a,b,c,d);
}

inline void glex::glGetFinalCombinerInputParameterfvNV(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetFinalCombinerInputParameterfvNV(a,b,c);
}

inline void glex::glGetFinalCombinerInputParameterivNV(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetFinalCombinerInputParameterivNV(a,b,c);
}

inline void glex::glResizeBuffersMESA(void) {
	m_pglex->glResizeBuffersMESA();
}

inline void glex::glWindowPos2dMESA(GLdouble a, GLdouble b) {
	m_pglex->glWindowPos2dMESA(a,b);
}

inline void glex::glWindowPos2dvMESA(const GLdouble *a) {
	m_pglex->glWindowPos2dvMESA(a);
}

inline void glex::glWindowPos2fMESA(GLfloat a, GLfloat b) {
	m_pglex->glWindowPos2fMESA(a,b);
}

inline void glex::glWindowPos2fvMESA(const GLfloat *a) {
	m_pglex->glWindowPos2fvMESA(a);
}

inline void glex::glWindowPos2iMESA(GLint a, GLint b) {
	m_pglex->glWindowPos2iMESA(a,b);
}

inline void glex::glWindowPos2ivMESA(const GLint *a) {
	m_pglex->glWindowPos2ivMESA(a);
}

inline void glex::glWindowPos2sMESA(GLshort a, GLshort b) {
	m_pglex->glWindowPos2sMESA(a,b);
}

inline void glex::glWindowPos2svMESA(const GLshort *a) {
	m_pglex->glWindowPos2svMESA(a);
}

inline void glex::glWindowPos3dMESA(GLdouble a, GLdouble b, GLdouble c) {
	m_pglex->glWindowPos3dMESA(a,b,c);
}

inline void glex::glWindowPos3dvMESA(const GLdouble *a) {
	m_pglex->glWindowPos3dvMESA(a);
}

inline void glex::glWindowPos3fMESA(GLfloat a, GLfloat b, GLfloat c) {
	m_pglex->glWindowPos3fMESA(a,b,c);
}

inline void glex::glWindowPos3fvMESA(const GLfloat *a) {
	m_pglex->glWindowPos3fvMESA(a);
}

inline void glex::glWindowPos3iMESA(GLint a, GLint b, GLint c) {
	m_pglex->glWindowPos3iMESA(a,b,c);
}

inline void glex::glWindowPos3ivMESA(const GLint *a) {
	m_pglex->glWindowPos3ivMESA(a);
}

inline void glex::glWindowPos3sMESA(GLshort a, GLshort b, GLshort c) {
	m_pglex->glWindowPos3sMESA(a,b,c);
}

inline void glex::glWindowPos3svMESA(const GLshort *a) {
	m_pglex->glWindowPos3svMESA(a);
}

inline void glex::glWindowPos4dMESA(GLdouble a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glWindowPos4dMESA(a,b,c,d);
}

inline void glex::glWindowPos4dvMESA(const GLdouble *a) {
	m_pglex->glWindowPos4dvMESA(a);
}

inline void glex::glWindowPos4fMESA(GLfloat a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glWindowPos4fMESA(a,b,c,d);
}

inline void glex::glWindowPos4fvMESA(const GLfloat *a) {
	m_pglex->glWindowPos4fvMESA(a);
}

inline void glex::glWindowPos4iMESA(GLint a, GLint b, GLint c, GLint d) {
	m_pglex->glWindowPos4iMESA(a,b,c,d);
}

inline void glex::glWindowPos4ivMESA(const GLint *a) {
	m_pglex->glWindowPos4ivMESA(a);
}

inline void glex::glWindowPos4sMESA(GLshort a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glWindowPos4sMESA(a,b,c,d);
}

inline void glex::glWindowPos4svMESA(const GLshort *a) {
	m_pglex->glWindowPos4svMESA(a);
}

inline void glex::glMultiModeDrawArraysIBM(const GLenum *a, const GLint *b, const GLsizei *c, GLsizei d, GLint e) {
	m_pglex->glMultiModeDrawArraysIBM(a,b,c,d,e);
}

inline void glex::glMultiModeDrawElementsIBM(const GLenum *a, const GLsizei *b, GLenum c, const GLvoid* const *d, GLsizei e, GLint f) {
	m_pglex->glMultiModeDrawElementsIBM(a,b,c,d,e,f);
}

inline void glex::glColorPointerListIBM(GLint a, GLenum b, GLint c, const GLvoid* *d, GLint e) {
	m_pglex->glColorPointerListIBM(a,b,c,d,e);
}

inline void glex::glSecondaryColorPointerListIBM(GLint a, GLenum b, GLint c, const GLvoid* *d, GLint e) {
	m_pglex->glSecondaryColorPointerListIBM(a,b,c,d,e);
}

inline void glex::glEdgeFlagPointerListIBM(GLint a, const GLboolean* *b, GLint c) {
	m_pglex->glEdgeFlagPointerListIBM(a,b,c);
}

inline void glex::glFogCoordPointerListIBM(GLenum a, GLint b, const GLvoid* *c, GLint d) {
	m_pglex->glFogCoordPointerListIBM(a,b,c,d);
}

inline void glex::glIndexPointerListIBM(GLenum a, GLint b, const GLvoid* *c, GLint d) {
	m_pglex->glIndexPointerListIBM(a,b,c,d);
}

inline void glex::glNormalPointerListIBM(GLenum a, GLint b, const GLvoid* *c, GLint d) {
	m_pglex->glNormalPointerListIBM(a,b,c,d);
}

inline void glex::glTexCoordPointerListIBM(GLint a, GLenum b, GLint c, const GLvoid* *d, GLint e) {
	m_pglex->glTexCoordPointerListIBM(a,b,c,d,e);
}

inline void glex::glVertexPointerListIBM(GLint a, GLenum b, GLint c, const GLvoid* *d, GLint e) {
	m_pglex->glVertexPointerListIBM(a,b,c,d,e);
}

inline void glex::glTbufferMask3DFX(GLuint a) {
	m_pglex->glTbufferMask3DFX(a);
}

inline void glex::glSampleMaskEXT(GLclampf a, GLboolean b) {
	m_pglex->glSampleMaskEXT(a,b);
}

inline void glex::glSamplePatternEXT(GLenum a) {
	m_pglex->glSamplePatternEXT(a);
}

inline void glex::glTextureColorMaskSGIS(GLboolean a, GLboolean b, GLboolean c, GLboolean d) {
	m_pglex->glTextureColorMaskSGIS(a,b,c,d);
}

inline void glex::glIglooInterfaceSGIX(GLenum a, const GLvoid *b) {
	m_pglex->glIglooInterfaceSGIX(a,b);
}

inline void glex::glDeleteFencesNV(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteFencesNV(a,b);
}

inline void glex::glGenFencesNV(GLsizei a, GLuint *b) {
	m_pglex->glGenFencesNV(a,b);
}

inline GLboolean glex::glIsFenceNV(GLuint a) {
	return m_pglex->glIsFenceNV(a);
}

inline GLboolean glex::glTestFenceNV(GLuint a) {
	return m_pglex->glTestFenceNV(a);
}

inline void glex::glGetFenceivNV(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetFenceivNV(a,b,c);
}

inline void glex::glFinishFenceNV(GLuint a) {
	m_pglex->glFinishFenceNV(a);
}

inline void glex::glSetFenceNV(GLuint a, GLenum b) {
	m_pglex->glSetFenceNV(a,b);
}

inline void glex::glMapControlPointsNV(GLenum a, GLuint b, GLenum c, GLsizei d, GLsizei e, GLint f, GLint g, GLboolean h, const GLvoid *i) {
	m_pglex->glMapControlPointsNV(a,b,c,d,e,f,g,h,i);
}

inline void glex::glMapParameterivNV(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glMapParameterivNV(a,b,c);
}

inline void glex::glMapParameterfvNV(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glMapParameterfvNV(a,b,c);
}

inline void glex::glGetMapControlPointsNV(GLenum a, GLuint b, GLenum c, GLsizei d, GLsizei e, GLboolean f, GLvoid *g) {
	m_pglex->glGetMapControlPointsNV(a,b,c,d,e,f,g);
}

inline void glex::glGetMapParameterivNV(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetMapParameterivNV(a,b,c);
}

inline void glex::glGetMapParameterfvNV(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetMapParameterfvNV(a,b,c);
}

inline void glex::glGetMapAttribParameterivNV(GLenum a, GLuint b, GLenum c, GLint *d) {
	m_pglex->glGetMapAttribParameterivNV(a,b,c,d);
}

inline void glex::glGetMapAttribParameterfvNV(GLenum a, GLuint b, GLenum c, GLfloat *d) {
	m_pglex->glGetMapAttribParameterfvNV(a,b,c,d);
}

inline void glex::glEvalMapsNV(GLenum a, GLenum b) {
	m_pglex->glEvalMapsNV(a,b);
}

inline void glex::glCombinerStageParameterfvNV(GLenum a, GLenum b, const GLfloat *c) {
	m_pglex->glCombinerStageParameterfvNV(a,b,c);
}

inline void glex::glGetCombinerStageParameterfvNV(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetCombinerStageParameterfvNV(a,b,c);
}

inline GLboolean glex::glAreProgramsResidentNV(GLsizei a, const GLuint *b, GLboolean *c) {
	return m_pglex->glAreProgramsResidentNV(a,b,c);
}

inline void glex::glBindProgramNV(GLenum a, GLuint b) {
	m_pglex->glBindProgramNV(a,b);
}

inline void glex::glDeleteProgramsNV(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteProgramsNV(a,b);
}

inline void glex::glExecuteProgramNV(GLenum a, GLuint b, const GLfloat *c) {
	m_pglex->glExecuteProgramNV(a,b,c);
}

inline void glex::glGenProgramsNV(GLsizei a, GLuint *b) {
	m_pglex->glGenProgramsNV(a,b);
}

inline void glex::glGetProgramParameterdvNV(GLenum a, GLuint b, GLenum c, GLdouble *d) {
	m_pglex->glGetProgramParameterdvNV(a,b,c,d);
}

inline void glex::glGetProgramParameterfvNV(GLenum a, GLuint b, GLenum c, GLfloat *d) {
	m_pglex->glGetProgramParameterfvNV(a,b,c,d);
}

inline void glex::glGetProgramivNV(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetProgramivNV(a,b,c);
}

inline void glex::glGetProgramStringNV(GLuint a, GLenum b, GLubyte *c) {
	m_pglex->glGetProgramStringNV(a,b,c);
}

inline void glex::glGetTrackMatrixivNV(GLenum a, GLuint b, GLenum c, GLint *d) {
	m_pglex->glGetTrackMatrixivNV(a,b,c,d);
}

inline void glex::glGetVertexAttribdvNV(GLuint a, GLenum b, GLdouble *c) {
	m_pglex->glGetVertexAttribdvNV(a,b,c);
}

inline void glex::glGetVertexAttribfvNV(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetVertexAttribfvNV(a,b,c);
}

inline void glex::glGetVertexAttribivNV(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVertexAttribivNV(a,b,c);
}

inline void glex::glGetVertexAttribPointervNV(GLuint a, GLenum b, GLvoid* *c) {
	m_pglex->glGetVertexAttribPointervNV(a,b,c);
}

inline GLboolean glex::glIsProgramNV(GLuint a) {
	return m_pglex->glIsProgramNV(a);
}

inline void glex::glLoadProgramNV(GLenum a, GLuint b, GLsizei c, const GLubyte *d) {
	m_pglex->glLoadProgramNV(a,b,c,d);
}

inline void glex::glProgramParameter4dNV(GLenum a, GLuint b, GLdouble c, GLdouble d, GLdouble e, GLdouble f) {
	m_pglex->glProgramParameter4dNV(a,b,c,d,e,f);
}

inline void glex::glProgramParameter4dvNV(GLenum a, GLuint b, const GLdouble *c) {
	m_pglex->glProgramParameter4dvNV(a,b,c);
}

inline void glex::glProgramParameter4fNV(GLenum a, GLuint b, GLfloat c, GLfloat d, GLfloat e, GLfloat f) {
	m_pglex->glProgramParameter4fNV(a,b,c,d,e,f);
}

inline void glex::glProgramParameter4fvNV(GLenum a, GLuint b, const GLfloat *c) {
	m_pglex->glProgramParameter4fvNV(a,b,c);
}

inline void glex::glProgramParameters4dvNV(GLenum a, GLuint b, GLuint c, const GLdouble *d) {
	m_pglex->glProgramParameters4dvNV(a,b,c,d);
}

inline void glex::glProgramParameters4fvNV(GLenum a, GLuint b, GLuint c, const GLfloat *d) {
	m_pglex->glProgramParameters4fvNV(a,b,c,d);
}

inline void glex::glRequestResidentProgramsNV(GLsizei a, const GLuint *b) {
	m_pglex->glRequestResidentProgramsNV(a,b);
}

inline void glex::glTrackMatrixNV(GLenum a, GLuint b, GLenum c, GLenum d) {
	m_pglex->glTrackMatrixNV(a,b,c,d);
}

inline void glex::glVertexAttribPointerNV(GLuint a, GLint b, GLenum c, GLsizei d, const GLvoid *e) {
	m_pglex->glVertexAttribPointerNV(a,b,c,d,e);
}

inline void glex::glVertexAttrib1dNV(GLuint a, GLdouble b) {
	m_pglex->glVertexAttrib1dNV(a,b);
}

inline void glex::glVertexAttrib1dvNV(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib1dvNV(a,b);
}

inline void glex::glVertexAttrib1fNV(GLuint a, GLfloat b) {
	m_pglex->glVertexAttrib1fNV(a,b);
}

inline void glex::glVertexAttrib1fvNV(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib1fvNV(a,b);
}

inline void glex::glVertexAttrib1sNV(GLuint a, GLshort b) {
	m_pglex->glVertexAttrib1sNV(a,b);
}

inline void glex::glVertexAttrib1svNV(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib1svNV(a,b);
}

inline void glex::glVertexAttrib2dNV(GLuint a, GLdouble b, GLdouble c) {
	m_pglex->glVertexAttrib2dNV(a,b,c);
}

inline void glex::glVertexAttrib2dvNV(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib2dvNV(a,b);
}

inline void glex::glVertexAttrib2fNV(GLuint a, GLfloat b, GLfloat c) {
	m_pglex->glVertexAttrib2fNV(a,b,c);
}

inline void glex::glVertexAttrib2fvNV(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib2fvNV(a,b);
}

inline void glex::glVertexAttrib2sNV(GLuint a, GLshort b, GLshort c) {
	m_pglex->glVertexAttrib2sNV(a,b,c);
}

inline void glex::glVertexAttrib2svNV(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib2svNV(a,b);
}

inline void glex::glVertexAttrib3dNV(GLuint a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glVertexAttrib3dNV(a,b,c,d);
}

inline void glex::glVertexAttrib3dvNV(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib3dvNV(a,b);
}

inline void glex::glVertexAttrib3fNV(GLuint a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glVertexAttrib3fNV(a,b,c,d);
}

inline void glex::glVertexAttrib3fvNV(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib3fvNV(a,b);
}

inline void glex::glVertexAttrib3sNV(GLuint a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glVertexAttrib3sNV(a,b,c,d);
}

inline void glex::glVertexAttrib3svNV(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib3svNV(a,b);
}

inline void glex::glVertexAttrib4dNV(GLuint a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glVertexAttrib4dNV(a,b,c,d,e);
}

inline void glex::glVertexAttrib4dvNV(GLuint a, const GLdouble *b) {
	m_pglex->glVertexAttrib4dvNV(a,b);
}

inline void glex::glVertexAttrib4fNV(GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glVertexAttrib4fNV(a,b,c,d,e);
}

inline void glex::glVertexAttrib4fvNV(GLuint a, const GLfloat *b) {
	m_pglex->glVertexAttrib4fvNV(a,b);
}

inline void glex::glVertexAttrib4sNV(GLuint a, GLshort b, GLshort c, GLshort d, GLshort e) {
	m_pglex->glVertexAttrib4sNV(a,b,c,d,e);
}

inline void glex::glVertexAttrib4svNV(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttrib4svNV(a,b);
}

inline void glex::glVertexAttrib4ubNV(GLuint a, GLubyte b, GLubyte c, GLubyte d, GLubyte e) {
	m_pglex->glVertexAttrib4ubNV(a,b,c,d,e);
}

inline void glex::glVertexAttrib4ubvNV(GLuint a, const GLubyte *b) {
	m_pglex->glVertexAttrib4ubvNV(a,b);
}

inline void glex::glVertexAttribs1dvNV(GLuint a, GLsizei b, const GLdouble *c) {
	m_pglex->glVertexAttribs1dvNV(a,b,c);
}

inline void glex::glVertexAttribs1fvNV(GLuint a, GLsizei b, const GLfloat *c) {
	m_pglex->glVertexAttribs1fvNV(a,b,c);
}

inline void glex::glVertexAttribs1svNV(GLuint a, GLsizei b, const GLshort *c) {
	m_pglex->glVertexAttribs1svNV(a,b,c);
}

inline void glex::glVertexAttribs2dvNV(GLuint a, GLsizei b, const GLdouble *c) {
	m_pglex->glVertexAttribs2dvNV(a,b,c);
}

inline void glex::glVertexAttribs2fvNV(GLuint a, GLsizei b, const GLfloat *c) {
	m_pglex->glVertexAttribs2fvNV(a,b,c);
}

inline void glex::glVertexAttribs2svNV(GLuint a, GLsizei b, const GLshort *c) {
	m_pglex->glVertexAttribs2svNV(a,b,c);
}

inline void glex::glVertexAttribs3dvNV(GLuint a, GLsizei b, const GLdouble *c) {
	m_pglex->glVertexAttribs3dvNV(a,b,c);
}

inline void glex::glVertexAttribs3fvNV(GLuint a, GLsizei b, const GLfloat *c) {
	m_pglex->glVertexAttribs3fvNV(a,b,c);
}

inline void glex::glVertexAttribs3svNV(GLuint a, GLsizei b, const GLshort *c) {
	m_pglex->glVertexAttribs3svNV(a,b,c);
}

inline void glex::glVertexAttribs4dvNV(GLuint a, GLsizei b, const GLdouble *c) {
	m_pglex->glVertexAttribs4dvNV(a,b,c);
}

inline void glex::glVertexAttribs4fvNV(GLuint a, GLsizei b, const GLfloat *c) {
	m_pglex->glVertexAttribs4fvNV(a,b,c);
}

inline void glex::glVertexAttribs4svNV(GLuint a, GLsizei b, const GLshort *c) {
	m_pglex->glVertexAttribs4svNV(a,b,c);
}

inline void glex::glVertexAttribs4ubvNV(GLuint a, GLsizei b, const GLubyte *c) {
	m_pglex->glVertexAttribs4ubvNV(a,b,c);
}

inline void glex::glTexBumpParameterivATI(GLenum a, const GLint *b) {
	m_pglex->glTexBumpParameterivATI(a,b);
}

inline void glex::glTexBumpParameterfvATI(GLenum a, const GLfloat *b) {
	m_pglex->glTexBumpParameterfvATI(a,b);
}

inline void glex::glGetTexBumpParameterivATI(GLenum a, GLint *b) {
	m_pglex->glGetTexBumpParameterivATI(a,b);
}

inline void glex::glGetTexBumpParameterfvATI(GLenum a, GLfloat *b) {
	m_pglex->glGetTexBumpParameterfvATI(a,b);
}

inline GLuint glex::glGenFragmentShadersATI(GLuint a) {
	return m_pglex->glGenFragmentShadersATI(a);
}

inline void glex::glBindFragmentShaderATI(GLuint a) {
	m_pglex->glBindFragmentShaderATI(a);
}

inline void glex::glDeleteFragmentShaderATI(GLuint a) {
	m_pglex->glDeleteFragmentShaderATI(a);
}

inline void glex::glBeginFragmentShaderATI(void) {
	m_pglex->glBeginFragmentShaderATI();
}

inline void glex::glEndFragmentShaderATI(void) {
	m_pglex->glEndFragmentShaderATI();
}

inline void glex::glPassTexCoordATI(GLuint a, GLuint b, GLenum c) {
	m_pglex->glPassTexCoordATI(a,b,c);
}

inline void glex::glSampleMapATI(GLuint a, GLuint b, GLenum c) {
	m_pglex->glSampleMapATI(a,b,c);
}

inline void glex::glColorFragmentOp1ATI(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f, GLuint g) {
	m_pglex->glColorFragmentOp1ATI(a,b,c,d,e,f,g);
}

inline void glex::glColorFragmentOp2ATI(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f, GLuint g, GLuint h, GLuint i, GLuint j) {
	m_pglex->glColorFragmentOp2ATI(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glColorFragmentOp3ATI(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f, GLuint g, GLuint h, GLuint i, GLuint j, GLuint k, GLuint l, GLuint m) {
	m_pglex->glColorFragmentOp3ATI(a,b,c,d,e,f,g,h,i,j,k,l,m);
}

inline void glex::glAlphaFragmentOp1ATI(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f) {
	m_pglex->glAlphaFragmentOp1ATI(a,b,c,d,e,f);
}

inline void glex::glAlphaFragmentOp2ATI(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f, GLuint g, GLuint h, GLuint i) {
	m_pglex->glAlphaFragmentOp2ATI(a,b,c,d,e,f,g,h,i);
}

inline void glex::glAlphaFragmentOp3ATI(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f, GLuint g, GLuint h, GLuint i, GLuint j, GLuint k, GLuint l) {
	m_pglex->glAlphaFragmentOp3ATI(a,b,c,d,e,f,g,h,i,j,k,l);
}

inline void glex::glSetFragmentShaderConstantATI(GLuint a, const GLfloat *b) {
	m_pglex->glSetFragmentShaderConstantATI(a,b);
}

inline void glex::glPNTrianglesiATI(GLenum a, GLint b) {
	m_pglex->glPNTrianglesiATI(a,b);
}

inline void glex::glPNTrianglesfATI(GLenum a, GLfloat b) {
	m_pglex->glPNTrianglesfATI(a,b);
}

inline GLuint glex::glNewObjectBufferATI(GLsizei a, const GLvoid *b, GLenum c) {
	return m_pglex->glNewObjectBufferATI(a,b,c);
}

inline GLboolean glex::glIsObjectBufferATI(GLuint a) {
	return m_pglex->glIsObjectBufferATI(a);
}

inline void glex::glUpdateObjectBufferATI(GLuint a, GLuint b, GLsizei c, const GLvoid *d, GLenum e) {
	m_pglex->glUpdateObjectBufferATI(a,b,c,d,e);
}

inline void glex::glGetObjectBufferfvATI(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetObjectBufferfvATI(a,b,c);
}

inline void glex::glGetObjectBufferivATI(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetObjectBufferivATI(a,b,c);
}

inline void glex::glFreeObjectBufferATI(GLuint a) {
	m_pglex->glFreeObjectBufferATI(a);
}

inline void glex::glArrayObjectATI(GLenum a, GLint b, GLenum c, GLsizei d, GLuint e, GLuint f) {
	m_pglex->glArrayObjectATI(a,b,c,d,e,f);
}

inline void glex::glGetArrayObjectfvATI(GLenum a, GLenum b, GLfloat *c) {
	m_pglex->glGetArrayObjectfvATI(a,b,c);
}

inline void glex::glGetArrayObjectivATI(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetArrayObjectivATI(a,b,c);
}

inline void glex::glVariantArrayObjectATI(GLuint a, GLenum b, GLsizei c, GLuint d, GLuint e) {
	m_pglex->glVariantArrayObjectATI(a,b,c,d,e);
}

inline void glex::glGetVariantArrayObjectfvATI(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetVariantArrayObjectfvATI(a,b,c);
}

inline void glex::glGetVariantArrayObjectivATI(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVariantArrayObjectivATI(a,b,c);
}

inline void glex::glBeginVertexShaderEXT(void) {
	m_pglex->glBeginVertexShaderEXT();
}

inline void glex::glEndVertexShaderEXT(void) {
	m_pglex->glEndVertexShaderEXT();
}

inline void glex::glBindVertexShaderEXT(GLuint a) {
	m_pglex->glBindVertexShaderEXT(a);
}

inline GLuint glex::glGenVertexShadersEXT(GLuint a) {
	return m_pglex->glGenVertexShadersEXT(a);
}

inline void glex::glDeleteVertexShaderEXT(GLuint a) {
	m_pglex->glDeleteVertexShaderEXT(a);
}

inline void glex::glShaderOp1EXT(GLenum a, GLuint b, GLuint c) {
	m_pglex->glShaderOp1EXT(a,b,c);
}

inline void glex::glShaderOp2EXT(GLenum a, GLuint b, GLuint c, GLuint d) {
	m_pglex->glShaderOp2EXT(a,b,c,d);
}

inline void glex::glShaderOp3EXT(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e) {
	m_pglex->glShaderOp3EXT(a,b,c,d,e);
}

inline void glex::glSwizzleEXT(GLuint a, GLuint b, GLenum c, GLenum d, GLenum e, GLenum f) {
	m_pglex->glSwizzleEXT(a,b,c,d,e,f);
}

inline void glex::glWriteMaskEXT(GLuint a, GLuint b, GLenum c, GLenum d, GLenum e, GLenum f) {
	m_pglex->glWriteMaskEXT(a,b,c,d,e,f);
}

inline void glex::glInsertComponentEXT(GLuint a, GLuint b, GLuint c) {
	m_pglex->glInsertComponentEXT(a,b,c);
}

inline void glex::glExtractComponentEXT(GLuint a, GLuint b, GLuint c) {
	m_pglex->glExtractComponentEXT(a,b,c);
}

inline GLuint glex::glGenSymbolsEXT(GLenum a, GLenum b, GLenum c, GLuint d) {
	return m_pglex->glGenSymbolsEXT(a,b,c,d);
}

inline void glex::glSetInvariantEXT(GLuint a, GLenum b, const GLvoid *c) {
	m_pglex->glSetInvariantEXT(a,b,c);
}

inline void glex::glSetLocalConstantEXT(GLuint a, GLenum b, const GLvoid *c) {
	m_pglex->glSetLocalConstantEXT(a,b,c);
}

inline void glex::glVariantbvEXT(GLuint a, const GLbyte *b) {
	m_pglex->glVariantbvEXT(a,b);
}

inline void glex::glVariantsvEXT(GLuint a, const GLshort *b) {
	m_pglex->glVariantsvEXT(a,b);
}

inline void glex::glVariantivEXT(GLuint a, const GLint *b) {
	m_pglex->glVariantivEXT(a,b);
}

inline void glex::glVariantfvEXT(GLuint a, const GLfloat *b) {
	m_pglex->glVariantfvEXT(a,b);
}

inline void glex::glVariantdvEXT(GLuint a, const GLdouble *b) {
	m_pglex->glVariantdvEXT(a,b);
}

inline void glex::glVariantubvEXT(GLuint a, const GLubyte *b) {
	m_pglex->glVariantubvEXT(a,b);
}

inline void glex::glVariantusvEXT(GLuint a, const GLushort *b) {
	m_pglex->glVariantusvEXT(a,b);
}

inline void glex::glVariantuivEXT(GLuint a, const GLuint *b) {
	m_pglex->glVariantuivEXT(a,b);
}

inline void glex::glVariantPointerEXT(GLuint a, GLenum b, GLuint c, const GLvoid *d) {
	m_pglex->glVariantPointerEXT(a,b,c,d);
}

inline void glex::glEnableVariantClientStateEXT(GLuint a) {
	m_pglex->glEnableVariantClientStateEXT(a);
}

inline void glex::glDisableVariantClientStateEXT(GLuint a) {
	m_pglex->glDisableVariantClientStateEXT(a);
}

inline GLuint glex::glBindLightParameterEXT(GLenum a, GLenum b) {
	return m_pglex->glBindLightParameterEXT(a,b);
}

inline GLuint glex::glBindMaterialParameterEXT(GLenum a, GLenum b) {
	return m_pglex->glBindMaterialParameterEXT(a,b);
}

inline GLuint glex::glBindTexGenParameterEXT(GLenum a, GLenum b, GLenum c) {
	return m_pglex->glBindTexGenParameterEXT(a,b,c);
}

inline GLuint glex::glBindTextureUnitParameterEXT(GLenum a, GLenum b) {
	return m_pglex->glBindTextureUnitParameterEXT(a,b);
}

inline GLuint glex::glBindParameterEXT(GLenum a) {
	return m_pglex->glBindParameterEXT(a);
}

inline GLboolean glex::glIsVariantEnabledEXT(GLuint a, GLenum b) {
	return m_pglex->glIsVariantEnabledEXT(a,b);
}

inline void glex::glGetVariantBooleanvEXT(GLuint a, GLenum b, GLboolean *c) {
	m_pglex->glGetVariantBooleanvEXT(a,b,c);
}

inline void glex::glGetVariantIntegervEXT(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVariantIntegervEXT(a,b,c);
}

inline void glex::glGetVariantFloatvEXT(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetVariantFloatvEXT(a,b,c);
}

inline void glex::glGetVariantPointervEXT(GLuint a, GLenum b, GLvoid* *c) {
	m_pglex->glGetVariantPointervEXT(a,b,c);
}

inline void glex::glGetInvariantBooleanvEXT(GLuint a, GLenum b, GLboolean *c) {
	m_pglex->glGetInvariantBooleanvEXT(a,b,c);
}

inline void glex::glGetInvariantIntegervEXT(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetInvariantIntegervEXT(a,b,c);
}

inline void glex::glGetInvariantFloatvEXT(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetInvariantFloatvEXT(a,b,c);
}

inline void glex::glGetLocalConstantBooleanvEXT(GLuint a, GLenum b, GLboolean *c) {
	m_pglex->glGetLocalConstantBooleanvEXT(a,b,c);
}

inline void glex::glGetLocalConstantIntegervEXT(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetLocalConstantIntegervEXT(a,b,c);
}

inline void glex::glGetLocalConstantFloatvEXT(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetLocalConstantFloatvEXT(a,b,c);
}

inline void glex::glVertexStream1sATI(GLenum a, GLshort b) {
	m_pglex->glVertexStream1sATI(a,b);
}

inline void glex::glVertexStream1svATI(GLenum a, const GLshort *b) {
	m_pglex->glVertexStream1svATI(a,b);
}

inline void glex::glVertexStream1iATI(GLenum a, GLint b) {
	m_pglex->glVertexStream1iATI(a,b);
}

inline void glex::glVertexStream1ivATI(GLenum a, const GLint *b) {
	m_pglex->glVertexStream1ivATI(a,b);
}

inline void glex::glVertexStream1fATI(GLenum a, GLfloat b) {
	m_pglex->glVertexStream1fATI(a,b);
}

inline void glex::glVertexStream1fvATI(GLenum a, const GLfloat *b) {
	m_pglex->glVertexStream1fvATI(a,b);
}

inline void glex::glVertexStream1dATI(GLenum a, GLdouble b) {
	m_pglex->glVertexStream1dATI(a,b);
}

inline void glex::glVertexStream1dvATI(GLenum a, const GLdouble *b) {
	m_pglex->glVertexStream1dvATI(a,b);
}

inline void glex::glVertexStream2sATI(GLenum a, GLshort b, GLshort c) {
	m_pglex->glVertexStream2sATI(a,b,c);
}

inline void glex::glVertexStream2svATI(GLenum a, const GLshort *b) {
	m_pglex->glVertexStream2svATI(a,b);
}

inline void glex::glVertexStream2iATI(GLenum a, GLint b, GLint c) {
	m_pglex->glVertexStream2iATI(a,b,c);
}

inline void glex::glVertexStream2ivATI(GLenum a, const GLint *b) {
	m_pglex->glVertexStream2ivATI(a,b);
}

inline void glex::glVertexStream2fATI(GLenum a, GLfloat b, GLfloat c) {
	m_pglex->glVertexStream2fATI(a,b,c);
}

inline void glex::glVertexStream2fvATI(GLenum a, const GLfloat *b) {
	m_pglex->glVertexStream2fvATI(a,b);
}

inline void glex::glVertexStream2dATI(GLenum a, GLdouble b, GLdouble c) {
	m_pglex->glVertexStream2dATI(a,b,c);
}

inline void glex::glVertexStream2dvATI(GLenum a, const GLdouble *b) {
	m_pglex->glVertexStream2dvATI(a,b);
}

inline void glex::glVertexStream3sATI(GLenum a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glVertexStream3sATI(a,b,c,d);
}

inline void glex::glVertexStream3svATI(GLenum a, const GLshort *b) {
	m_pglex->glVertexStream3svATI(a,b);
}

inline void glex::glVertexStream3iATI(GLenum a, GLint b, GLint c, GLint d) {
	m_pglex->glVertexStream3iATI(a,b,c,d);
}

inline void glex::glVertexStream3ivATI(GLenum a, const GLint *b) {
	m_pglex->glVertexStream3ivATI(a,b);
}

inline void glex::glVertexStream3fATI(GLenum a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glVertexStream3fATI(a,b,c,d);
}

inline void glex::glVertexStream3fvATI(GLenum a, const GLfloat *b) {
	m_pglex->glVertexStream3fvATI(a,b);
}

inline void glex::glVertexStream3dATI(GLenum a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glVertexStream3dATI(a,b,c,d);
}

inline void glex::glVertexStream3dvATI(GLenum a, const GLdouble *b) {
	m_pglex->glVertexStream3dvATI(a,b);
}

inline void glex::glVertexStream4sATI(GLenum a, GLshort b, GLshort c, GLshort d, GLshort e) {
	m_pglex->glVertexStream4sATI(a,b,c,d,e);
}

inline void glex::glVertexStream4svATI(GLenum a, const GLshort *b) {
	m_pglex->glVertexStream4svATI(a,b);
}

inline void glex::glVertexStream4iATI(GLenum a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glVertexStream4iATI(a,b,c,d,e);
}

inline void glex::glVertexStream4ivATI(GLenum a, const GLint *b) {
	m_pglex->glVertexStream4ivATI(a,b);
}

inline void glex::glVertexStream4fATI(GLenum a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glVertexStream4fATI(a,b,c,d,e);
}

inline void glex::glVertexStream4fvATI(GLenum a, const GLfloat *b) {
	m_pglex->glVertexStream4fvATI(a,b);
}

inline void glex::glVertexStream4dATI(GLenum a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glVertexStream4dATI(a,b,c,d,e);
}

inline void glex::glVertexStream4dvATI(GLenum a, const GLdouble *b) {
	m_pglex->glVertexStream4dvATI(a,b);
}

inline void glex::glNormalStream3bATI(GLenum a, GLbyte b, GLbyte c, GLbyte d) {
	m_pglex->glNormalStream3bATI(a,b,c,d);
}

inline void glex::glNormalStream3bvATI(GLenum a, const GLbyte *b) {
	m_pglex->glNormalStream3bvATI(a,b);
}

inline void glex::glNormalStream3sATI(GLenum a, GLshort b, GLshort c, GLshort d) {
	m_pglex->glNormalStream3sATI(a,b,c,d);
}

inline void glex::glNormalStream3svATI(GLenum a, const GLshort *b) {
	m_pglex->glNormalStream3svATI(a,b);
}

inline void glex::glNormalStream3iATI(GLenum a, GLint b, GLint c, GLint d) {
	m_pglex->glNormalStream3iATI(a,b,c,d);
}

inline void glex::glNormalStream3ivATI(GLenum a, const GLint *b) {
	m_pglex->glNormalStream3ivATI(a,b);
}

inline void glex::glNormalStream3fATI(GLenum a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glNormalStream3fATI(a,b,c,d);
}

inline void glex::glNormalStream3fvATI(GLenum a, const GLfloat *b) {
	m_pglex->glNormalStream3fvATI(a,b);
}

inline void glex::glNormalStream3dATI(GLenum a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glNormalStream3dATI(a,b,c,d);
}

inline void glex::glNormalStream3dvATI(GLenum a, const GLdouble *b) {
	m_pglex->glNormalStream3dvATI(a,b);
}

inline void glex::glClientActiveVertexStreamATI(GLenum a) {
	m_pglex->glClientActiveVertexStreamATI(a);
}

inline void glex::glVertexBlendEnviATI(GLenum a, GLint b) {
	m_pglex->glVertexBlendEnviATI(a,b);
}

inline void glex::glVertexBlendEnvfATI(GLenum a, GLfloat b) {
	m_pglex->glVertexBlendEnvfATI(a,b);
}

inline void glex::glElementPointerATI(GLenum a, const GLvoid *b) {
	m_pglex->glElementPointerATI(a,b);
}

inline void glex::glDrawElementArrayATI(GLenum a, GLsizei b) {
	m_pglex->glDrawElementArrayATI(a,b);
}

inline void glex::glDrawRangeElementArrayATI(GLenum a, GLuint b, GLuint c, GLsizei d) {
	m_pglex->glDrawRangeElementArrayATI(a,b,c,d);
}

inline void glex::glDrawMeshArraysSUN(GLenum a, GLint b, GLsizei c, GLsizei d) {
	m_pglex->glDrawMeshArraysSUN(a,b,c,d);
}

inline void glex::glGenOcclusionQueriesNV(GLsizei a, GLuint *b) {
	m_pglex->glGenOcclusionQueriesNV(a,b);
}

inline void glex::glDeleteOcclusionQueriesNV(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteOcclusionQueriesNV(a,b);
}

inline GLboolean glex::glIsOcclusionQueryNV(GLuint a) {
	return m_pglex->glIsOcclusionQueryNV(a);
}

inline void glex::glBeginOcclusionQueryNV(GLuint a) {
	m_pglex->glBeginOcclusionQueryNV(a);
}

inline void glex::glEndOcclusionQueryNV(void) {
	m_pglex->glEndOcclusionQueryNV();
}

inline void glex::glGetOcclusionQueryivNV(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetOcclusionQueryivNV(a,b,c);
}

inline void glex::glGetOcclusionQueryuivNV(GLuint a, GLenum b, GLuint *c) {
	m_pglex->glGetOcclusionQueryuivNV(a,b,c);
}

inline void glex::glPointParameteriNV(GLenum a, GLint b) {
	m_pglex->glPointParameteriNV(a,b);
}

inline void glex::glPointParameterivNV(GLenum a, const GLint *b) {
	m_pglex->glPointParameterivNV(a,b);
}

inline void glex::glActiveStencilFaceEXT(GLenum a) {
	m_pglex->glActiveStencilFaceEXT(a);
}

inline void glex::glElementPointerAPPLE(GLenum a, const GLvoid *b) {
	m_pglex->glElementPointerAPPLE(a,b);
}

inline void glex::glDrawElementArrayAPPLE(GLenum a, GLint b, GLsizei c) {
	m_pglex->glDrawElementArrayAPPLE(a,b,c);
}

inline void glex::glDrawRangeElementArrayAPPLE(GLenum a, GLuint b, GLuint c, GLint d, GLsizei e) {
	m_pglex->glDrawRangeElementArrayAPPLE(a,b,c,d,e);
}

inline void glex::glMultiDrawElementArrayAPPLE(GLenum a, const GLint *b, const GLsizei *c, GLsizei d) {
	m_pglex->glMultiDrawElementArrayAPPLE(a,b,c,d);
}

inline void glex::glMultiDrawRangeElementArrayAPPLE(GLenum a, GLuint b, GLuint c, const GLint *d, const GLsizei *e, GLsizei f) {
	m_pglex->glMultiDrawRangeElementArrayAPPLE(a,b,c,d,e,f);
}

inline void glex::glGenFencesAPPLE(GLsizei a, GLuint *b) {
	m_pglex->glGenFencesAPPLE(a,b);
}

inline void glex::glDeleteFencesAPPLE(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteFencesAPPLE(a,b);
}

inline void glex::glSetFenceAPPLE(GLuint a) {
	m_pglex->glSetFenceAPPLE(a);
}

inline GLboolean glex::glIsFenceAPPLE(GLuint a) {
	return m_pglex->glIsFenceAPPLE(a);
}

inline GLboolean glex::glTestFenceAPPLE(GLuint a) {
	return m_pglex->glTestFenceAPPLE(a);
}

inline void glex::glFinishFenceAPPLE(GLuint a) {
	m_pglex->glFinishFenceAPPLE(a);
}

inline GLboolean glex::glTestObjectAPPLE(GLenum a, GLuint b) {
	return m_pglex->glTestObjectAPPLE(a,b);
}

inline void glex::glFinishObjectAPPLE(GLenum a, GLint b) {
	m_pglex->glFinishObjectAPPLE(a,b);
}

inline void glex::glBindVertexArrayAPPLE(GLuint a) {
	m_pglex->glBindVertexArrayAPPLE(a);
}

inline void glex::glDeleteVertexArraysAPPLE(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteVertexArraysAPPLE(a,b);
}

inline void glex::glGenVertexArraysAPPLE(GLsizei a, GLuint *b) {
	m_pglex->glGenVertexArraysAPPLE(a,b);
}

inline GLboolean glex::glIsVertexArrayAPPLE(GLuint a) {
	return m_pglex->glIsVertexArrayAPPLE(a);
}

inline void glex::glVertexArrayRangeAPPLE(GLsizei a, GLvoid *b) {
	m_pglex->glVertexArrayRangeAPPLE(a,b);
}

inline void glex::glFlushVertexArrayRangeAPPLE(GLsizei a, GLvoid *b) {
	m_pglex->glFlushVertexArrayRangeAPPLE(a,b);
}

inline void glex::glVertexArrayParameteriAPPLE(GLenum a, GLint b) {
	m_pglex->glVertexArrayParameteriAPPLE(a,b);
}

inline void glex::glDrawBuffersATI(GLsizei a, const GLenum *b) {
	m_pglex->glDrawBuffersATI(a,b);
}

inline void glex::glProgramNamedParameter4fNV(GLuint a, GLsizei b, const GLubyte *c, GLfloat d, GLfloat e, GLfloat f, GLfloat g) {
	m_pglex->glProgramNamedParameter4fNV(a,b,c,d,e,f,g);
}

inline void glex::glProgramNamedParameter4dNV(GLuint a, GLsizei b, const GLubyte *c, GLdouble d, GLdouble e, GLdouble f, GLdouble g) {
	m_pglex->glProgramNamedParameter4dNV(a,b,c,d,e,f,g);
}

inline void glex::glProgramNamedParameter4fvNV(GLuint a, GLsizei b, const GLubyte *c, const GLfloat *d) {
	m_pglex->glProgramNamedParameter4fvNV(a,b,c,d);
}

inline void glex::glProgramNamedParameter4dvNV(GLuint a, GLsizei b, const GLubyte *c, const GLdouble *d) {
	m_pglex->glProgramNamedParameter4dvNV(a,b,c,d);
}

inline void glex::glGetProgramNamedParameterfvNV(GLuint a, GLsizei b, const GLubyte *c, GLfloat *d) {
	m_pglex->glGetProgramNamedParameterfvNV(a,b,c,d);
}

inline void glex::glGetProgramNamedParameterdvNV(GLuint a, GLsizei b, const GLubyte *c, GLdouble *d) {
	m_pglex->glGetProgramNamedParameterdvNV(a,b,c,d);
}

inline void glex::glVertex2hNV(GLhalfNV a, GLhalfNV b) {
	m_pglex->glVertex2hNV(a,b);
}

inline void glex::glVertex2hvNV(const GLhalfNV *a) {
	m_pglex->glVertex2hvNV(a);
}

inline void glex::glVertex3hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c) {
	m_pglex->glVertex3hNV(a,b,c);
}

inline void glex::glVertex3hvNV(const GLhalfNV *a) {
	m_pglex->glVertex3hvNV(a);
}

inline void glex::glVertex4hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c, GLhalfNV d) {
	m_pglex->glVertex4hNV(a,b,c,d);
}

inline void glex::glVertex4hvNV(const GLhalfNV *a) {
	m_pglex->glVertex4hvNV(a);
}

inline void glex::glNormal3hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c) {
	m_pglex->glNormal3hNV(a,b,c);
}

inline void glex::glNormal3hvNV(const GLhalfNV *a) {
	m_pglex->glNormal3hvNV(a);
}

inline void glex::glColor3hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c) {
	m_pglex->glColor3hNV(a,b,c);
}

inline void glex::glColor3hvNV(const GLhalfNV *a) {
	m_pglex->glColor3hvNV(a);
}

inline void glex::glColor4hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c, GLhalfNV d) {
	m_pglex->glColor4hNV(a,b,c,d);
}

inline void glex::glColor4hvNV(const GLhalfNV *a) {
	m_pglex->glColor4hvNV(a);
}

inline void glex::glTexCoord1hNV(GLhalfNV a) {
	m_pglex->glTexCoord1hNV(a);
}

inline void glex::glTexCoord1hvNV(const GLhalfNV *a) {
	m_pglex->glTexCoord1hvNV(a);
}

inline void glex::glTexCoord2hNV(GLhalfNV a, GLhalfNV b) {
	m_pglex->glTexCoord2hNV(a,b);
}

inline void glex::glTexCoord2hvNV(const GLhalfNV *a) {
	m_pglex->glTexCoord2hvNV(a);
}

inline void glex::glTexCoord3hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c) {
	m_pglex->glTexCoord3hNV(a,b,c);
}

inline void glex::glTexCoord3hvNV(const GLhalfNV *a) {
	m_pglex->glTexCoord3hvNV(a);
}

inline void glex::glTexCoord4hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c, GLhalfNV d) {
	m_pglex->glTexCoord4hNV(a,b,c,d);
}

inline void glex::glTexCoord4hvNV(const GLhalfNV *a) {
	m_pglex->glTexCoord4hvNV(a);
}

inline void glex::glMultiTexCoord1hNV(GLenum a, GLhalfNV b) {
	m_pglex->glMultiTexCoord1hNV(a,b);
}

inline void glex::glMultiTexCoord1hvNV(GLenum a, const GLhalfNV *b) {
	m_pglex->glMultiTexCoord1hvNV(a,b);
}

inline void glex::glMultiTexCoord2hNV(GLenum a, GLhalfNV b, GLhalfNV c) {
	m_pglex->glMultiTexCoord2hNV(a,b,c);
}

inline void glex::glMultiTexCoord2hvNV(GLenum a, const GLhalfNV *b) {
	m_pglex->glMultiTexCoord2hvNV(a,b);
}

inline void glex::glMultiTexCoord3hNV(GLenum a, GLhalfNV b, GLhalfNV c, GLhalfNV d) {
	m_pglex->glMultiTexCoord3hNV(a,b,c,d);
}

inline void glex::glMultiTexCoord3hvNV(GLenum a, const GLhalfNV *b) {
	m_pglex->glMultiTexCoord3hvNV(a,b);
}

inline void glex::glMultiTexCoord4hNV(GLenum a, GLhalfNV b, GLhalfNV c, GLhalfNV d, GLhalfNV e) {
	m_pglex->glMultiTexCoord4hNV(a,b,c,d,e);
}

inline void glex::glMultiTexCoord4hvNV(GLenum a, const GLhalfNV *b) {
	m_pglex->glMultiTexCoord4hvNV(a,b);
}

inline void glex::glFogCoordhNV(GLhalfNV a) {
	m_pglex->glFogCoordhNV(a);
}

inline void glex::glFogCoordhvNV(const GLhalfNV *a) {
	m_pglex->glFogCoordhvNV(a);
}

inline void glex::glSecondaryColor3hNV(GLhalfNV a, GLhalfNV b, GLhalfNV c) {
	m_pglex->glSecondaryColor3hNV(a,b,c);
}

inline void glex::glSecondaryColor3hvNV(const GLhalfNV *a) {
	m_pglex->glSecondaryColor3hvNV(a);
}

inline void glex::glVertexWeighthNV(GLhalfNV a) {
	m_pglex->glVertexWeighthNV(a);
}

inline void glex::glVertexWeighthvNV(const GLhalfNV *a) {
	m_pglex->glVertexWeighthvNV(a);
}

inline void glex::glVertexAttrib1hNV(GLuint a, GLhalfNV b) {
	m_pglex->glVertexAttrib1hNV(a,b);
}

inline void glex::glVertexAttrib1hvNV(GLuint a, const GLhalfNV *b) {
	m_pglex->glVertexAttrib1hvNV(a,b);
}

inline void glex::glVertexAttrib2hNV(GLuint a, GLhalfNV b, GLhalfNV c) {
	m_pglex->glVertexAttrib2hNV(a,b,c);
}

inline void glex::glVertexAttrib2hvNV(GLuint a, const GLhalfNV *b) {
	m_pglex->glVertexAttrib2hvNV(a,b);
}

inline void glex::glVertexAttrib3hNV(GLuint a, GLhalfNV b, GLhalfNV c, GLhalfNV d) {
	m_pglex->glVertexAttrib3hNV(a,b,c,d);
}

inline void glex::glVertexAttrib3hvNV(GLuint a, const GLhalfNV *b) {
	m_pglex->glVertexAttrib3hvNV(a,b);
}

inline void glex::glVertexAttrib4hNV(GLuint a, GLhalfNV b, GLhalfNV c, GLhalfNV d, GLhalfNV e) {
	m_pglex->glVertexAttrib4hNV(a,b,c,d,e);
}

inline void glex::glVertexAttrib4hvNV(GLuint a, const GLhalfNV *b) {
	m_pglex->glVertexAttrib4hvNV(a,b);
}

inline void glex::glVertexAttribs1hvNV(GLuint a, GLsizei b, const GLhalfNV *c) {
	m_pglex->glVertexAttribs1hvNV(a,b,c);
}

inline void glex::glVertexAttribs2hvNV(GLuint a, GLsizei b, const GLhalfNV *c) {
	m_pglex->glVertexAttribs2hvNV(a,b,c);
}

inline void glex::glVertexAttribs3hvNV(GLuint a, GLsizei b, const GLhalfNV *c) {
	m_pglex->glVertexAttribs3hvNV(a,b,c);
}

inline void glex::glVertexAttribs4hvNV(GLuint a, GLsizei b, const GLhalfNV *c) {
	m_pglex->glVertexAttribs4hvNV(a,b,c);
}

inline void glex::glPixelDataRangeNV(GLenum a, GLsizei b, GLvoid *c) {
	m_pglex->glPixelDataRangeNV(a,b,c);
}

inline void glex::glFlushPixelDataRangeNV(GLenum a) {
	m_pglex->glFlushPixelDataRangeNV(a);
}

inline void glex::glPrimitiveRestartNV(void) {
	m_pglex->glPrimitiveRestartNV();
}

inline void glex::glPrimitiveRestartIndexNV(GLuint a) {
	m_pglex->glPrimitiveRestartIndexNV(a);
}

inline GLvoid* glex::glMapObjectBufferATI(GLuint a) {
	return m_pglex->glMapObjectBufferATI(a);
}

inline void glex::glUnmapObjectBufferATI(GLuint a) {
	m_pglex->glUnmapObjectBufferATI(a);
}

inline void glex::glStencilOpSeparateATI(GLenum a, GLenum b, GLenum c, GLenum d) {
	m_pglex->glStencilOpSeparateATI(a,b,c,d);
}

inline void glex::glStencilFuncSeparateATI(GLenum a, GLenum b, GLint c, GLuint d) {
	m_pglex->glStencilFuncSeparateATI(a,b,c,d);
}

inline void glex::glVertexAttribArrayObjectATI(GLuint a, GLint b, GLenum c, GLboolean d, GLsizei e, GLuint f, GLuint g) {
	m_pglex->glVertexAttribArrayObjectATI(a,b,c,d,e,f,g);
}

inline void glex::glGetVertexAttribArrayObjectfvATI(GLuint a, GLenum b, GLfloat *c) {
	m_pglex->glGetVertexAttribArrayObjectfvATI(a,b,c);
}

inline void glex::glGetVertexAttribArrayObjectivATI(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVertexAttribArrayObjectivATI(a,b,c);
}

inline void glex::glDepthBoundsEXT(GLclampd a, GLclampd b) {
	m_pglex->glDepthBoundsEXT(a,b);
}

inline void glex::glBlendEquationSeparateEXT(GLenum a, GLenum b) {
	m_pglex->glBlendEquationSeparateEXT(a,b);
}

inline GLboolean glex::glIsRenderbufferEXT(GLuint a) {
	return m_pglex->glIsRenderbufferEXT(a);
}

inline void glex::glBindRenderbufferEXT(GLenum a, GLuint b) {
	m_pglex->glBindRenderbufferEXT(a,b);
}

inline void glex::glDeleteRenderbuffersEXT(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteRenderbuffersEXT(a,b);
}

inline void glex::glGenRenderbuffersEXT(GLsizei a, GLuint *b) {
	m_pglex->glGenRenderbuffersEXT(a,b);
}

inline void glex::glRenderbufferStorageEXT(GLenum a, GLenum b, GLsizei c, GLsizei d) {
	m_pglex->glRenderbufferStorageEXT(a,b,c,d);
}

inline void glex::glGetRenderbufferParameterivEXT(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetRenderbufferParameterivEXT(a,b,c);
}

inline GLboolean glex::glIsFramebufferEXT(GLuint a) {
	return m_pglex->glIsFramebufferEXT(a);
}

inline void glex::glBindFramebufferEXT(GLenum a, GLuint b) {
	m_pglex->glBindFramebufferEXT(a,b);
}

inline void glex::glDeleteFramebuffersEXT(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteFramebuffersEXT(a,b);
}

inline void glex::glGenFramebuffersEXT(GLsizei a, GLuint *b) {
	m_pglex->glGenFramebuffersEXT(a,b);
}

inline GLenum glex::glCheckFramebufferStatusEXT(GLenum a) {
	return m_pglex->glCheckFramebufferStatusEXT(a);
}

inline void glex::glFramebufferTexture1DEXT(GLenum a, GLenum b, GLenum c, GLuint d, GLint e) {
	m_pglex->glFramebufferTexture1DEXT(a,b,c,d,e);
}

inline void glex::glFramebufferTexture2DEXT(GLenum a, GLenum b, GLenum c, GLuint d, GLint e) {
	m_pglex->glFramebufferTexture2DEXT(a,b,c,d,e);
}

inline void glex::glFramebufferTexture3DEXT(GLenum a, GLenum b, GLenum c, GLuint d, GLint e, GLint f) {
	m_pglex->glFramebufferTexture3DEXT(a,b,c,d,e,f);
}

inline void glex::glFramebufferRenderbufferEXT(GLenum a, GLenum b, GLenum c, GLuint d) {
	m_pglex->glFramebufferRenderbufferEXT(a,b,c,d);
}

inline void glex::glGetFramebufferAttachmentParameterivEXT(GLenum a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetFramebufferAttachmentParameterivEXT(a,b,c,d);
}

inline void glex::glGenerateMipmapEXT(GLenum a) {
	m_pglex->glGenerateMipmapEXT(a);
}

inline void glex::glStringMarkerGREMEDY(GLsizei a, const GLvoid *b) {
	m_pglex->glStringMarkerGREMEDY(a,b);
}

inline void glex::glStencilClearTagEXT(GLsizei a, GLuint b) {
	m_pglex->glStencilClearTagEXT(a,b);
}

inline void glex::glBlitFramebufferEXT(GLint a, GLint b, GLint c, GLint d, GLint e, GLint f, GLint g, GLint h, GLbitfield i, GLenum j) {
	m_pglex->glBlitFramebufferEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glRenderbufferStorageMultisampleEXT(GLenum a, GLsizei b, GLenum c, GLsizei d, GLsizei e) {
	m_pglex->glRenderbufferStorageMultisampleEXT(a,b,c,d,e);
}

inline void glex::glGetQueryObjecti64vEXT(GLuint a, GLenum b, GLint64EXT *c) {
	m_pglex->glGetQueryObjecti64vEXT(a,b,c);
}

inline void glex::glGetQueryObjectui64vEXT(GLuint a, GLenum b, GLuint64EXT *c) {
	m_pglex->glGetQueryObjectui64vEXT(a,b,c);
}

inline void glex::glProgramEnvParameters4fvEXT(GLenum a, GLuint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramEnvParameters4fvEXT(a,b,c,d);
}

inline void glex::glProgramLocalParameters4fvEXT(GLenum a, GLuint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramLocalParameters4fvEXT(a,b,c,d);
}

inline void glex::glBufferParameteriAPPLE(GLenum a, GLenum b, GLint c) {
	m_pglex->glBufferParameteriAPPLE(a,b,c);
}

inline void glex::glFlushMappedBufferRangeAPPLE(GLenum a, GLintptr b, GLsizeiptr c) {
	m_pglex->glFlushMappedBufferRangeAPPLE(a,b,c);
}

inline void glex::glProgramLocalParameterI4iNV(GLenum a, GLuint b, GLint c, GLint d, GLint e, GLint f) {
	m_pglex->glProgramLocalParameterI4iNV(a,b,c,d,e,f);
}

inline void glex::glProgramLocalParameterI4ivNV(GLenum a, GLuint b, const GLint *c) {
	m_pglex->glProgramLocalParameterI4ivNV(a,b,c);
}

inline void glex::glProgramLocalParametersI4ivNV(GLenum a, GLuint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramLocalParametersI4ivNV(a,b,c,d);
}

inline void glex::glProgramLocalParameterI4uiNV(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f) {
	m_pglex->glProgramLocalParameterI4uiNV(a,b,c,d,e,f);
}

inline void glex::glProgramLocalParameterI4uivNV(GLenum a, GLuint b, const GLuint *c) {
	m_pglex->glProgramLocalParameterI4uivNV(a,b,c);
}

inline void glex::glProgramLocalParametersI4uivNV(GLenum a, GLuint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramLocalParametersI4uivNV(a,b,c,d);
}

inline void glex::glProgramEnvParameterI4iNV(GLenum a, GLuint b, GLint c, GLint d, GLint e, GLint f) {
	m_pglex->glProgramEnvParameterI4iNV(a,b,c,d,e,f);
}

inline void glex::glProgramEnvParameterI4ivNV(GLenum a, GLuint b, const GLint *c) {
	m_pglex->glProgramEnvParameterI4ivNV(a,b,c);
}

inline void glex::glProgramEnvParametersI4ivNV(GLenum a, GLuint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramEnvParametersI4ivNV(a,b,c,d);
}

inline void glex::glProgramEnvParameterI4uiNV(GLenum a, GLuint b, GLuint c, GLuint d, GLuint e, GLuint f) {
	m_pglex->glProgramEnvParameterI4uiNV(a,b,c,d,e,f);
}

inline void glex::glProgramEnvParameterI4uivNV(GLenum a, GLuint b, const GLuint *c) {
	m_pglex->glProgramEnvParameterI4uivNV(a,b,c);
}

inline void glex::glProgramEnvParametersI4uivNV(GLenum a, GLuint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramEnvParametersI4uivNV(a,b,c,d);
}

inline void glex::glGetProgramLocalParameterIivNV(GLenum a, GLuint b, GLint *c) {
	m_pglex->glGetProgramLocalParameterIivNV(a,b,c);
}

inline void glex::glGetProgramLocalParameterIuivNV(GLenum a, GLuint b, GLuint *c) {
	m_pglex->glGetProgramLocalParameterIuivNV(a,b,c);
}

inline void glex::glGetProgramEnvParameterIivNV(GLenum a, GLuint b, GLint *c) {
	m_pglex->glGetProgramEnvParameterIivNV(a,b,c);
}

inline void glex::glGetProgramEnvParameterIuivNV(GLenum a, GLuint b, GLuint *c) {
	m_pglex->glGetProgramEnvParameterIuivNV(a,b,c);
}

inline void glex::glProgramVertexLimitNV(GLenum a, GLint b) {
	m_pglex->glProgramVertexLimitNV(a,b);
}

inline void glex::glFramebufferTextureEXT(GLenum a, GLenum b, GLuint c, GLint d) {
	m_pglex->glFramebufferTextureEXT(a,b,c,d);
}

inline void glex::glFramebufferTextureLayerEXT(GLenum a, GLenum b, GLuint c, GLint d, GLint e) {
	m_pglex->glFramebufferTextureLayerEXT(a,b,c,d,e);
}

inline void glex::glFramebufferTextureFaceEXT(GLenum a, GLenum b, GLuint c, GLint d, GLenum e) {
	m_pglex->glFramebufferTextureFaceEXT(a,b,c,d,e);
}

inline void glex::glProgramParameteriEXT(GLuint a, GLenum b, GLint c) {
	m_pglex->glProgramParameteriEXT(a,b,c);
}

inline void glex::glVertexAttribI1iEXT(GLuint a, GLint b) {
	m_pglex->glVertexAttribI1iEXT(a,b);
}

inline void glex::glVertexAttribI2iEXT(GLuint a, GLint b, GLint c) {
	m_pglex->glVertexAttribI2iEXT(a,b,c);
}

inline void glex::glVertexAttribI3iEXT(GLuint a, GLint b, GLint c, GLint d) {
	m_pglex->glVertexAttribI3iEXT(a,b,c,d);
}

inline void glex::glVertexAttribI4iEXT(GLuint a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glVertexAttribI4iEXT(a,b,c,d,e);
}

inline void glex::glVertexAttribI1uiEXT(GLuint a, GLuint b) {
	m_pglex->glVertexAttribI1uiEXT(a,b);
}

inline void glex::glVertexAttribI2uiEXT(GLuint a, GLuint b, GLuint c) {
	m_pglex->glVertexAttribI2uiEXT(a,b,c);
}

inline void glex::glVertexAttribI3uiEXT(GLuint a, GLuint b, GLuint c, GLuint d) {
	m_pglex->glVertexAttribI3uiEXT(a,b,c,d);
}

inline void glex::glVertexAttribI4uiEXT(GLuint a, GLuint b, GLuint c, GLuint d, GLuint e) {
	m_pglex->glVertexAttribI4uiEXT(a,b,c,d,e);
}

inline void glex::glVertexAttribI1ivEXT(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI1ivEXT(a,b);
}

inline void glex::glVertexAttribI2ivEXT(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI2ivEXT(a,b);
}

inline void glex::glVertexAttribI3ivEXT(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI3ivEXT(a,b);
}

inline void glex::glVertexAttribI4ivEXT(GLuint a, const GLint *b) {
	m_pglex->glVertexAttribI4ivEXT(a,b);
}

inline void glex::glVertexAttribI1uivEXT(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI1uivEXT(a,b);
}

inline void glex::glVertexAttribI2uivEXT(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI2uivEXT(a,b);
}

inline void glex::glVertexAttribI3uivEXT(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI3uivEXT(a,b);
}

inline void glex::glVertexAttribI4uivEXT(GLuint a, const GLuint *b) {
	m_pglex->glVertexAttribI4uivEXT(a,b);
}

inline void glex::glVertexAttribI4bvEXT(GLuint a, const GLbyte *b) {
	m_pglex->glVertexAttribI4bvEXT(a,b);
}

inline void glex::glVertexAttribI4svEXT(GLuint a, const GLshort *b) {
	m_pglex->glVertexAttribI4svEXT(a,b);
}

inline void glex::glVertexAttribI4ubvEXT(GLuint a, const GLubyte *b) {
	m_pglex->glVertexAttribI4ubvEXT(a,b);
}

inline void glex::glVertexAttribI4usvEXT(GLuint a, const GLushort *b) {
	m_pglex->glVertexAttribI4usvEXT(a,b);
}

inline void glex::glVertexAttribIPointerEXT(GLuint a, GLint b, GLenum c, GLsizei d, const GLvoid *e) {
	m_pglex->glVertexAttribIPointerEXT(a,b,c,d,e);
}

inline void glex::glGetVertexAttribIivEXT(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVertexAttribIivEXT(a,b,c);
}

inline void glex::glGetVertexAttribIuivEXT(GLuint a, GLenum b, GLuint *c) {
	m_pglex->glGetVertexAttribIuivEXT(a,b,c);
}

inline void glex::glGetUniformuivEXT(GLuint a, GLint b, GLuint *c) {
	m_pglex->glGetUniformuivEXT(a,b,c);
}

inline void glex::glBindFragDataLocationEXT(GLuint a, GLuint b, const GLchar *c) {
	m_pglex->glBindFragDataLocationEXT(a,b,c);
}

inline GLint glex::glGetFragDataLocationEXT(GLuint a, const GLchar *b) {
	return m_pglex->glGetFragDataLocationEXT(a,b);
}

inline void glex::glUniform1uiEXT(GLint a, GLuint b) {
	m_pglex->glUniform1uiEXT(a,b);
}

inline void glex::glUniform2uiEXT(GLint a, GLuint b, GLuint c) {
	m_pglex->glUniform2uiEXT(a,b,c);
}

inline void glex::glUniform3uiEXT(GLint a, GLuint b, GLuint c, GLuint d) {
	m_pglex->glUniform3uiEXT(a,b,c,d);
}

inline void glex::glUniform4uiEXT(GLint a, GLuint b, GLuint c, GLuint d, GLuint e) {
	m_pglex->glUniform4uiEXT(a,b,c,d,e);
}

inline void glex::glUniform1uivEXT(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform1uivEXT(a,b,c);
}

inline void glex::glUniform2uivEXT(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform2uivEXT(a,b,c);
}

inline void glex::glUniform3uivEXT(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform3uivEXT(a,b,c);
}

inline void glex::glUniform4uivEXT(GLint a, GLsizei b, const GLuint *c) {
	m_pglex->glUniform4uivEXT(a,b,c);
}

inline void glex::glDrawArraysInstancedEXT(GLenum a, GLint b, GLsizei c, GLsizei d) {
	m_pglex->glDrawArraysInstancedEXT(a,b,c,d);
}

inline void glex::glDrawElementsInstancedEXT(GLenum a, GLsizei b, GLenum c, const GLvoid *d, GLsizei e) {
	m_pglex->glDrawElementsInstancedEXT(a,b,c,d,e);
}

inline void glex::glTexBufferEXT(GLenum a, GLenum b, GLuint c) {
	m_pglex->glTexBufferEXT(a,b,c);
}

inline void glex::glDepthRangedNV(GLdouble a, GLdouble b) {
	m_pglex->glDepthRangedNV(a,b);
}

inline void glex::glClearDepthdNV(GLdouble a) {
	m_pglex->glClearDepthdNV(a);
}

inline void glex::glDepthBoundsdNV(GLdouble a, GLdouble b) {
	m_pglex->glDepthBoundsdNV(a,b);
}

inline void glex::glRenderbufferStorageMultisampleCoverageNV(GLenum a, GLsizei b, GLsizei c, GLenum d, GLsizei e, GLsizei f) {
	m_pglex->glRenderbufferStorageMultisampleCoverageNV(a,b,c,d,e,f);
}

inline void glex::glProgramBufferParametersfvNV(GLenum a, GLuint b, GLuint c, GLsizei d, const GLfloat *e) {
	m_pglex->glProgramBufferParametersfvNV(a,b,c,d,e);
}

inline void glex::glProgramBufferParametersIivNV(GLenum a, GLuint b, GLuint c, GLsizei d, const GLint *e) {
	m_pglex->glProgramBufferParametersIivNV(a,b,c,d,e);
}

inline void glex::glProgramBufferParametersIuivNV(GLenum a, GLuint b, GLuint c, GLsizei d, const GLuint *e) {
	m_pglex->glProgramBufferParametersIuivNV(a,b,c,d,e);
}

inline void glex::glColorMaskIndexedEXT(GLuint a, GLboolean b, GLboolean c, GLboolean d, GLboolean e) {
	m_pglex->glColorMaskIndexedEXT(a,b,c,d,e);
}

inline void glex::glGetBooleanIndexedvEXT(GLenum a, GLuint b, GLboolean *c) {
	m_pglex->glGetBooleanIndexedvEXT(a,b,c);
}

inline void glex::glGetIntegerIndexedvEXT(GLenum a, GLuint b, GLint *c) {
	m_pglex->glGetIntegerIndexedvEXT(a,b,c);
}

inline void glex::glEnableIndexedEXT(GLenum a, GLuint b) {
	m_pglex->glEnableIndexedEXT(a,b);
}

inline void glex::glDisableIndexedEXT(GLenum a, GLuint b) {
	m_pglex->glDisableIndexedEXT(a,b);
}

inline GLboolean glex::glIsEnabledIndexedEXT(GLenum a, GLuint b) {
	return m_pglex->glIsEnabledIndexedEXT(a,b);
}

inline void glex::glBeginTransformFeedbackNV(GLenum a) {
	m_pglex->glBeginTransformFeedbackNV(a);
}

inline void glex::glEndTransformFeedbackNV(void) {
	m_pglex->glEndTransformFeedbackNV();
}

inline void glex::glTransformFeedbackAttribsNV(GLuint a, const GLint *b, GLenum c) {
	m_pglex->glTransformFeedbackAttribsNV(a,b,c);
}

inline void glex::glBindBufferRangeNV(GLenum a, GLuint b, GLuint c, GLintptr d, GLsizeiptr e) {
	m_pglex->glBindBufferRangeNV(a,b,c,d,e);
}

inline void glex::glBindBufferOffsetNV(GLenum a, GLuint b, GLuint c, GLintptr d) {
	m_pglex->glBindBufferOffsetNV(a,b,c,d);
}

inline void glex::glBindBufferBaseNV(GLenum a, GLuint b, GLuint c) {
	m_pglex->glBindBufferBaseNV(a,b,c);
}

inline void glex::glTransformFeedbackVaryingsNV(GLuint a, GLsizei b, const GLchar* *c, GLenum d) {
	m_pglex->glTransformFeedbackVaryingsNV(a,b,c,d);
}

inline void glex::glActiveVaryingNV(GLuint a, const GLchar *b) {
	m_pglex->glActiveVaryingNV(a,b);
}

inline GLint glex::glGetVaryingLocationNV(GLuint a, const GLchar *b) {
	return m_pglex->glGetVaryingLocationNV(a,b);
}

inline void glex::glGetActiveVaryingNV(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLsizei *e, GLenum *f, GLchar *g) {
	m_pglex->glGetActiveVaryingNV(a,b,c,d,e,f,g);
}

inline void glex::glGetTransformFeedbackVaryingNV(GLuint a, GLuint b, GLint *c) {
	m_pglex->glGetTransformFeedbackVaryingNV(a,b,c);
}

inline void glex::glUniformBufferEXT(GLuint a, GLint b, GLuint c) {
	m_pglex->glUniformBufferEXT(a,b,c);
}

inline GLint glex::glGetUniformBufferSizeEXT(GLuint a, GLint b) {
	return m_pglex->glGetUniformBufferSizeEXT(a,b);
}

inline GLintptr glex::glGetUniformOffsetEXT(GLuint a, GLint b) {
	return m_pglex->glGetUniformOffsetEXT(a,b);
}

inline void glex::glTexParameterIivEXT(GLenum a, GLenum b, const GLint *c) {
	m_pglex->glTexParameterIivEXT(a,b,c);
}

inline void glex::glTexParameterIuivEXT(GLenum a, GLenum b, const GLuint *c) {
	m_pglex->glTexParameterIuivEXT(a,b,c);
}

inline void glex::glGetTexParameterIivEXT(GLenum a, GLenum b, GLint *c) {
	m_pglex->glGetTexParameterIivEXT(a,b,c);
}

inline void glex::glGetTexParameterIuivEXT(GLenum a, GLenum b, GLuint *c) {
	m_pglex->glGetTexParameterIuivEXT(a,b,c);
}

inline void glex::glClearColorIiEXT(GLint a, GLint b, GLint c, GLint d) {
	m_pglex->glClearColorIiEXT(a,b,c,d);
}

inline void glex::glClearColorIuiEXT(GLuint a, GLuint b, GLuint c, GLuint d) {
	m_pglex->glClearColorIuiEXT(a,b,c,d);
}

inline void glex::glFrameTerminatorGREMEDY(void) {
	m_pglex->glFrameTerminatorGREMEDY();
}

inline void glex::glBeginConditionalRenderNV(GLuint a, GLenum b) {
	m_pglex->glBeginConditionalRenderNV(a,b);
}

inline void glex::glEndConditionalRenderNV(void) {
	m_pglex->glEndConditionalRenderNV();
}

inline void glex::glPresentFrameKeyedNV(GLuint a, GLuint64EXT b, GLuint c, GLuint d, GLenum e, GLenum f, GLuint g, GLuint h, GLenum i, GLuint j, GLuint k) {
	m_pglex->glPresentFrameKeyedNV(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glPresentFrameDualFillNV(GLuint a, GLuint64EXT b, GLuint c, GLuint d, GLenum e, GLenum f, GLuint g, GLenum h, GLuint i, GLenum j, GLuint k, GLenum l, GLuint m) {
	m_pglex->glPresentFrameDualFillNV(a,b,c,d,e,f,g,h,i,j,k,l,m);
}

inline void glex::glGetVideoivNV(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetVideoivNV(a,b,c);
}

inline void glex::glGetVideouivNV(GLuint a, GLenum b, GLuint *c) {
	m_pglex->glGetVideouivNV(a,b,c);
}

inline void glex::glGetVideoi64vNV(GLuint a, GLenum b, GLint64EXT *c) {
	m_pglex->glGetVideoi64vNV(a,b,c);
}

inline void glex::glGetVideoui64vNV(GLuint a, GLenum b, GLuint64EXT *c) {
	m_pglex->glGetVideoui64vNV(a,b,c);
}

inline void glex::glBeginTransformFeedbackEXT(GLenum a) {
	m_pglex->glBeginTransformFeedbackEXT(a);
}

inline void glex::glEndTransformFeedbackEXT(void) {
	m_pglex->glEndTransformFeedbackEXT();
}

inline void glex::glBindBufferRangeEXT(GLenum a, GLuint b, GLuint c, GLintptr d, GLsizeiptr e) {
	m_pglex->glBindBufferRangeEXT(a,b,c,d,e);
}

inline void glex::glBindBufferOffsetEXT(GLenum a, GLuint b, GLuint c, GLintptr d) {
	m_pglex->glBindBufferOffsetEXT(a,b,c,d);
}

inline void glex::glBindBufferBaseEXT(GLenum a, GLuint b, GLuint c) {
	m_pglex->glBindBufferBaseEXT(a,b,c);
}

inline void glex::glTransformFeedbackVaryingsEXT(GLuint a, GLsizei b, const GLchar* *c, GLenum d) {
	m_pglex->glTransformFeedbackVaryingsEXT(a,b,c,d);
}

inline void glex::glGetTransformFeedbackVaryingEXT(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLsizei *e, GLenum *f, GLchar *g) {
	m_pglex->glGetTransformFeedbackVaryingEXT(a,b,c,d,e,f,g);
}

inline void glex::glClientAttribDefaultEXT(GLbitfield a) {
	m_pglex->glClientAttribDefaultEXT(a);
}

inline void glex::glPushClientAttribDefaultEXT(GLbitfield a) {
	m_pglex->glPushClientAttribDefaultEXT(a);
}

inline void glex::glMatrixLoadfEXT(GLenum a, const GLfloat *b) {
	m_pglex->glMatrixLoadfEXT(a,b);
}

inline void glex::glMatrixLoaddEXT(GLenum a, const GLdouble *b) {
	m_pglex->glMatrixLoaddEXT(a,b);
}

inline void glex::glMatrixMultfEXT(GLenum a, const GLfloat *b) {
	m_pglex->glMatrixMultfEXT(a,b);
}

inline void glex::glMatrixMultdEXT(GLenum a, const GLdouble *b) {
	m_pglex->glMatrixMultdEXT(a,b);
}

inline void glex::glMatrixLoadIdentityEXT(GLenum a) {
	m_pglex->glMatrixLoadIdentityEXT(a);
}

inline void glex::glMatrixRotatefEXT(GLenum a, GLfloat b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glMatrixRotatefEXT(a,b,c,d,e);
}

inline void glex::glMatrixRotatedEXT(GLenum a, GLdouble b, GLdouble c, GLdouble d, GLdouble e) {
	m_pglex->glMatrixRotatedEXT(a,b,c,d,e);
}

inline void glex::glMatrixScalefEXT(GLenum a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glMatrixScalefEXT(a,b,c,d);
}

inline void glex::glMatrixScaledEXT(GLenum a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glMatrixScaledEXT(a,b,c,d);
}

inline void glex::glMatrixTranslatefEXT(GLenum a, GLfloat b, GLfloat c, GLfloat d) {
	m_pglex->glMatrixTranslatefEXT(a,b,c,d);
}

inline void glex::glMatrixTranslatedEXT(GLenum a, GLdouble b, GLdouble c, GLdouble d) {
	m_pglex->glMatrixTranslatedEXT(a,b,c,d);
}

inline void glex::glMatrixFrustumEXT(GLenum a, GLdouble b, GLdouble c, GLdouble d, GLdouble e, GLdouble f, GLdouble g) {
	m_pglex->glMatrixFrustumEXT(a,b,c,d,e,f,g);
}

inline void glex::glMatrixOrthoEXT(GLenum a, GLdouble b, GLdouble c, GLdouble d, GLdouble e, GLdouble f, GLdouble g) {
	m_pglex->glMatrixOrthoEXT(a,b,c,d,e,f,g);
}

inline void glex::glMatrixPopEXT(GLenum a) {
	m_pglex->glMatrixPopEXT(a);
}

inline void glex::glMatrixPushEXT(GLenum a) {
	m_pglex->glMatrixPushEXT(a);
}

inline void glex::glMatrixLoadTransposefEXT(GLenum a, const GLfloat *b) {
	m_pglex->glMatrixLoadTransposefEXT(a,b);
}

inline void glex::glMatrixLoadTransposedEXT(GLenum a, const GLdouble *b) {
	m_pglex->glMatrixLoadTransposedEXT(a,b);
}

inline void glex::glMatrixMultTransposefEXT(GLenum a, const GLfloat *b) {
	m_pglex->glMatrixMultTransposefEXT(a,b);
}

inline void glex::glMatrixMultTransposedEXT(GLenum a, const GLdouble *b) {
	m_pglex->glMatrixMultTransposedEXT(a,b);
}

inline void glex::glTextureParameterfEXT(GLuint a, GLenum b, GLenum c, GLfloat d) {
	m_pglex->glTextureParameterfEXT(a,b,c,d);
}

inline void glex::glTextureParameterfvEXT(GLuint a, GLenum b, GLenum c, const GLfloat *d) {
	m_pglex->glTextureParameterfvEXT(a,b,c,d);
}

inline void glex::glTextureParameteriEXT(GLuint a, GLenum b, GLenum c, GLint d) {
	m_pglex->glTextureParameteriEXT(a,b,c,d);
}

inline void glex::glTextureParameterivEXT(GLuint a, GLenum b, GLenum c, const GLint *d) {
	m_pglex->glTextureParameterivEXT(a,b,c,d);
}

inline void glex::glTextureImage1DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLsizei e, GLint f, GLenum g, GLenum h, const GLvoid *i) {
	m_pglex->glTextureImage1DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glTextureImage2DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLint g, GLenum h, GLenum i, const GLvoid *j) {
	m_pglex->glTextureImage2DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glTextureSubImage1DEXT(GLuint a, GLenum b, GLint c, GLint d, GLsizei e, GLenum f, GLenum g, const GLvoid *h) {
	m_pglex->glTextureSubImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glTextureSubImage2DEXT(GLuint a, GLenum b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLenum h, GLenum i, const GLvoid *j) {
	m_pglex->glTextureSubImage2DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glCopyTextureImage1DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLint e, GLint f, GLsizei g, GLint h) {
	m_pglex->glCopyTextureImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glCopyTextureImage2DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLint e, GLint f, GLsizei g, GLsizei h, GLint i) {
	m_pglex->glCopyTextureImage2DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCopyTextureSubImage1DEXT(GLuint a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLsizei g) {
	m_pglex->glCopyTextureSubImage1DEXT(a,b,c,d,e,f,g);
}

inline void glex::glCopyTextureSubImage2DEXT(GLuint a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLint g, GLsizei h, GLsizei i) {
	m_pglex->glCopyTextureSubImage2DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glGetTextureImageEXT(GLuint a, GLenum b, GLint c, GLenum d, GLenum e, GLvoid *f) {
	m_pglex->glGetTextureImageEXT(a,b,c,d,e,f);
}

inline void glex::glGetTextureParameterfvEXT(GLuint a, GLenum b, GLenum c, GLfloat *d) {
	m_pglex->glGetTextureParameterfvEXT(a,b,c,d);
}

inline void glex::glGetTextureParameterivEXT(GLuint a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetTextureParameterivEXT(a,b,c,d);
}

inline void glex::glGetTextureLevelParameterfvEXT(GLuint a, GLenum b, GLint c, GLenum d, GLfloat *e) {
	m_pglex->glGetTextureLevelParameterfvEXT(a,b,c,d,e);
}

inline void glex::glGetTextureLevelParameterivEXT(GLuint a, GLenum b, GLint c, GLenum d, GLint *e) {
	m_pglex->glGetTextureLevelParameterivEXT(a,b,c,d,e);
}

inline void glex::glTextureImage3DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLsizei g, GLint h, GLenum i, GLenum j, const GLvoid *k) {
	m_pglex->glTextureImage3DEXT(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glTextureSubImage3DEXT(GLuint a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLsizei g, GLsizei h, GLsizei i, GLenum j, GLenum k, const GLvoid *l) {
	m_pglex->glTextureSubImage3DEXT(a,b,c,d,e,f,g,h,i,j,k,l);
}

inline void glex::glCopyTextureSubImage3DEXT(GLuint a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLint g, GLint h, GLsizei i, GLsizei j) {
	m_pglex->glCopyTextureSubImage3DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glMultiTexParameterfEXT(GLenum a, GLenum b, GLenum c, GLfloat d) {
	m_pglex->glMultiTexParameterfEXT(a,b,c,d);
}

inline void glex::glMultiTexParameterfvEXT(GLenum a, GLenum b, GLenum c, const GLfloat *d) {
	m_pglex->glMultiTexParameterfvEXT(a,b,c,d);
}

inline void glex::glMultiTexParameteriEXT(GLenum a, GLenum b, GLenum c, GLint d) {
	m_pglex->glMultiTexParameteriEXT(a,b,c,d);
}

inline void glex::glMultiTexParameterivEXT(GLenum a, GLenum b, GLenum c, const GLint *d) {
	m_pglex->glMultiTexParameterivEXT(a,b,c,d);
}

inline void glex::glMultiTexImage1DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLsizei e, GLint f, GLenum g, GLenum h, const GLvoid *i) {
	m_pglex->glMultiTexImage1DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glMultiTexImage2DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLint g, GLenum h, GLenum i, const GLvoid *j) {
	m_pglex->glMultiTexImage2DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glMultiTexSubImage1DEXT(GLenum a, GLenum b, GLint c, GLint d, GLsizei e, GLenum f, GLenum g, const GLvoid *h) {
	m_pglex->glMultiTexSubImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glMultiTexSubImage2DEXT(GLenum a, GLenum b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLenum h, GLenum i, const GLvoid *j) {
	m_pglex->glMultiTexSubImage2DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glCopyMultiTexImage1DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLint e, GLint f, GLsizei g, GLint h) {
	m_pglex->glCopyMultiTexImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glCopyMultiTexImage2DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLint e, GLint f, GLsizei g, GLsizei h, GLint i) {
	m_pglex->glCopyMultiTexImage2DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCopyMultiTexSubImage1DEXT(GLenum a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLsizei g) {
	m_pglex->glCopyMultiTexSubImage1DEXT(a,b,c,d,e,f,g);
}

inline void glex::glCopyMultiTexSubImage2DEXT(GLenum a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLint g, GLsizei h, GLsizei i) {
	m_pglex->glCopyMultiTexSubImage2DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glGetMultiTexImageEXT(GLenum a, GLenum b, GLint c, GLenum d, GLenum e, GLvoid *f) {
	m_pglex->glGetMultiTexImageEXT(a,b,c,d,e,f);
}

inline void glex::glGetMultiTexParameterfvEXT(GLenum a, GLenum b, GLenum c, GLfloat *d) {
	m_pglex->glGetMultiTexParameterfvEXT(a,b,c,d);
}

inline void glex::glGetMultiTexParameterivEXT(GLenum a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetMultiTexParameterivEXT(a,b,c,d);
}

inline void glex::glGetMultiTexLevelParameterfvEXT(GLenum a, GLenum b, GLint c, GLenum d, GLfloat *e) {
	m_pglex->glGetMultiTexLevelParameterfvEXT(a,b,c,d,e);
}

inline void glex::glGetMultiTexLevelParameterivEXT(GLenum a, GLenum b, GLint c, GLenum d, GLint *e) {
	m_pglex->glGetMultiTexLevelParameterivEXT(a,b,c,d,e);
}

inline void glex::glMultiTexImage3DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLsizei g, GLint h, GLenum i, GLenum j, const GLvoid *k) {
	m_pglex->glMultiTexImage3DEXT(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glMultiTexSubImage3DEXT(GLenum a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLsizei g, GLsizei h, GLsizei i, GLenum j, GLenum k, const GLvoid *l) {
	m_pglex->glMultiTexSubImage3DEXT(a,b,c,d,e,f,g,h,i,j,k,l);
}

inline void glex::glCopyMultiTexSubImage3DEXT(GLenum a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLint g, GLint h, GLsizei i, GLsizei j) {
	m_pglex->glCopyMultiTexSubImage3DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glBindMultiTextureEXT(GLenum a, GLenum b, GLuint c) {
	m_pglex->glBindMultiTextureEXT(a,b,c);
}

inline void glex::glEnableClientStateIndexedEXT(GLenum a, GLuint b) {
	m_pglex->glEnableClientStateIndexedEXT(a,b);
}

inline void glex::glDisableClientStateIndexedEXT(GLenum a, GLuint b) {
	m_pglex->glDisableClientStateIndexedEXT(a,b);
}

inline void glex::glMultiTexCoordPointerEXT(GLenum a, GLint b, GLenum c, GLsizei d, const GLvoid *e) {
	m_pglex->glMultiTexCoordPointerEXT(a,b,c,d,e);
}

inline void glex::glMultiTexEnvfEXT(GLenum a, GLenum b, GLenum c, GLfloat d) {
	m_pglex->glMultiTexEnvfEXT(a,b,c,d);
}

inline void glex::glMultiTexEnvfvEXT(GLenum a, GLenum b, GLenum c, const GLfloat *d) {
	m_pglex->glMultiTexEnvfvEXT(a,b,c,d);
}

inline void glex::glMultiTexEnviEXT(GLenum a, GLenum b, GLenum c, GLint d) {
	m_pglex->glMultiTexEnviEXT(a,b,c,d);
}

inline void glex::glMultiTexEnvivEXT(GLenum a, GLenum b, GLenum c, const GLint *d) {
	m_pglex->glMultiTexEnvivEXT(a,b,c,d);
}

inline void glex::glMultiTexGendEXT(GLenum a, GLenum b, GLenum c, GLdouble d) {
	m_pglex->glMultiTexGendEXT(a,b,c,d);
}

inline void glex::glMultiTexGendvEXT(GLenum a, GLenum b, GLenum c, const GLdouble *d) {
	m_pglex->glMultiTexGendvEXT(a,b,c,d);
}

inline void glex::glMultiTexGenfEXT(GLenum a, GLenum b, GLenum c, GLfloat d) {
	m_pglex->glMultiTexGenfEXT(a,b,c,d);
}

inline void glex::glMultiTexGenfvEXT(GLenum a, GLenum b, GLenum c, const GLfloat *d) {
	m_pglex->glMultiTexGenfvEXT(a,b,c,d);
}

inline void glex::glMultiTexGeniEXT(GLenum a, GLenum b, GLenum c, GLint d) {
	m_pglex->glMultiTexGeniEXT(a,b,c,d);
}

inline void glex::glMultiTexGenivEXT(GLenum a, GLenum b, GLenum c, const GLint *d) {
	m_pglex->glMultiTexGenivEXT(a,b,c,d);
}

inline void glex::glGetMultiTexEnvfvEXT(GLenum a, GLenum b, GLenum c, GLfloat *d) {
	m_pglex->glGetMultiTexEnvfvEXT(a,b,c,d);
}

inline void glex::glGetMultiTexEnvivEXT(GLenum a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetMultiTexEnvivEXT(a,b,c,d);
}

inline void glex::glGetMultiTexGendvEXT(GLenum a, GLenum b, GLenum c, GLdouble *d) {
	m_pglex->glGetMultiTexGendvEXT(a,b,c,d);
}

inline void glex::glGetMultiTexGenfvEXT(GLenum a, GLenum b, GLenum c, GLfloat *d) {
	m_pglex->glGetMultiTexGenfvEXT(a,b,c,d);
}

inline void glex::glGetMultiTexGenivEXT(GLenum a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetMultiTexGenivEXT(a,b,c,d);
}

inline void glex::glGetFloatIndexedvEXT(GLenum a, GLuint b, GLfloat *c) {
	m_pglex->glGetFloatIndexedvEXT(a,b,c);
}

inline void glex::glGetDoubleIndexedvEXT(GLenum a, GLuint b, GLdouble *c) {
	m_pglex->glGetDoubleIndexedvEXT(a,b,c);
}

inline void glex::glGetPointerIndexedvEXT(GLenum a, GLuint b, GLvoid* *c) {
	m_pglex->glGetPointerIndexedvEXT(a,b,c);
}

inline void glex::glCompressedTextureImage3DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLsizei g, GLint h, GLsizei i, const GLvoid *j) {
	m_pglex->glCompressedTextureImage3DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glCompressedTextureImage2DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLint g, GLsizei h, const GLvoid *i) {
	m_pglex->glCompressedTextureImage2DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCompressedTextureImage1DEXT(GLuint a, GLenum b, GLint c, GLenum d, GLsizei e, GLint f, GLsizei g, const GLvoid *h) {
	m_pglex->glCompressedTextureImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glCompressedTextureSubImage3DEXT(GLuint a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLsizei g, GLsizei h, GLsizei i, GLenum j, GLsizei k, const GLvoid *l) {
	m_pglex->glCompressedTextureSubImage3DEXT(a,b,c,d,e,f,g,h,i,j,k,l);
}

inline void glex::glCompressedTextureSubImage2DEXT(GLuint a, GLenum b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLenum h, GLsizei i, const GLvoid *j) {
	m_pglex->glCompressedTextureSubImage2DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glCompressedTextureSubImage1DEXT(GLuint a, GLenum b, GLint c, GLint d, GLsizei e, GLenum f, GLsizei g, const GLvoid *h) {
	m_pglex->glCompressedTextureSubImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glGetCompressedTextureImageEXT(GLuint a, GLenum b, GLint c, GLvoid *d) {
	m_pglex->glGetCompressedTextureImageEXT(a,b,c,d);
}

inline void glex::glCompressedMultiTexImage3DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLsizei g, GLint h, GLsizei i, const GLvoid *j) {
	m_pglex->glCompressedMultiTexImage3DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glCompressedMultiTexImage2DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLsizei e, GLsizei f, GLint g, GLsizei h, const GLvoid *i) {
	m_pglex->glCompressedMultiTexImage2DEXT(a,b,c,d,e,f,g,h,i);
}

inline void glex::glCompressedMultiTexImage1DEXT(GLenum a, GLenum b, GLint c, GLenum d, GLsizei e, GLint f, GLsizei g, const GLvoid *h) {
	m_pglex->glCompressedMultiTexImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glCompressedMultiTexSubImage3DEXT(GLenum a, GLenum b, GLint c, GLint d, GLint e, GLint f, GLsizei g, GLsizei h, GLsizei i, GLenum j, GLsizei k, const GLvoid *l) {
	m_pglex->glCompressedMultiTexSubImage3DEXT(a,b,c,d,e,f,g,h,i,j,k,l);
}

inline void glex::glCompressedMultiTexSubImage2DEXT(GLenum a, GLenum b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLenum h, GLsizei i, const GLvoid *j) {
	m_pglex->glCompressedMultiTexSubImage2DEXT(a,b,c,d,e,f,g,h,i,j);
}

inline void glex::glCompressedMultiTexSubImage1DEXT(GLenum a, GLenum b, GLint c, GLint d, GLsizei e, GLenum f, GLsizei g, const GLvoid *h) {
	m_pglex->glCompressedMultiTexSubImage1DEXT(a,b,c,d,e,f,g,h);
}

inline void glex::glGetCompressedMultiTexImageEXT(GLenum a, GLenum b, GLint c, GLvoid *d) {
	m_pglex->glGetCompressedMultiTexImageEXT(a,b,c,d);
}

inline void glex::glNamedProgramStringEXT(GLuint a, GLenum b, GLenum c, GLsizei d, const GLvoid *e) {
	m_pglex->glNamedProgramStringEXT(a,b,c,d,e);
}

inline void glex::glNamedProgramLocalParameter4dEXT(GLuint a, GLenum b, GLuint c, GLdouble d, GLdouble e, GLdouble f, GLdouble g) {
	m_pglex->glNamedProgramLocalParameter4dEXT(a,b,c,d,e,f,g);
}

inline void glex::glNamedProgramLocalParameter4dvEXT(GLuint a, GLenum b, GLuint c, const GLdouble *d) {
	m_pglex->glNamedProgramLocalParameter4dvEXT(a,b,c,d);
}

inline void glex::glNamedProgramLocalParameter4fEXT(GLuint a, GLenum b, GLuint c, GLfloat d, GLfloat e, GLfloat f, GLfloat g) {
	m_pglex->glNamedProgramLocalParameter4fEXT(a,b,c,d,e,f,g);
}

inline void glex::glNamedProgramLocalParameter4fvEXT(GLuint a, GLenum b, GLuint c, const GLfloat *d) {
	m_pglex->glNamedProgramLocalParameter4fvEXT(a,b,c,d);
}

inline void glex::glGetNamedProgramLocalParameterdvEXT(GLuint a, GLenum b, GLuint c, GLdouble *d) {
	m_pglex->glGetNamedProgramLocalParameterdvEXT(a,b,c,d);
}

inline void glex::glGetNamedProgramLocalParameterfvEXT(GLuint a, GLenum b, GLuint c, GLfloat *d) {
	m_pglex->glGetNamedProgramLocalParameterfvEXT(a,b,c,d);
}

inline void glex::glGetNamedProgramivEXT(GLuint a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetNamedProgramivEXT(a,b,c,d);
}

inline void glex::glGetNamedProgramStringEXT(GLuint a, GLenum b, GLenum c, GLvoid *d) {
	m_pglex->glGetNamedProgramStringEXT(a,b,c,d);
}

inline void glex::glNamedProgramLocalParameters4fvEXT(GLuint a, GLenum b, GLuint c, GLsizei d, const GLfloat *e) {
	m_pglex->glNamedProgramLocalParameters4fvEXT(a,b,c,d,e);
}

inline void glex::glNamedProgramLocalParameterI4iEXT(GLuint a, GLenum b, GLuint c, GLint d, GLint e, GLint f, GLint g) {
	m_pglex->glNamedProgramLocalParameterI4iEXT(a,b,c,d,e,f,g);
}

inline void glex::glNamedProgramLocalParameterI4ivEXT(GLuint a, GLenum b, GLuint c, const GLint *d) {
	m_pglex->glNamedProgramLocalParameterI4ivEXT(a,b,c,d);
}

inline void glex::glNamedProgramLocalParametersI4ivEXT(GLuint a, GLenum b, GLuint c, GLsizei d, const GLint *e) {
	m_pglex->glNamedProgramLocalParametersI4ivEXT(a,b,c,d,e);
}

inline void glex::glNamedProgramLocalParameterI4uiEXT(GLuint a, GLenum b, GLuint c, GLuint d, GLuint e, GLuint f, GLuint g) {
	m_pglex->glNamedProgramLocalParameterI4uiEXT(a,b,c,d,e,f,g);
}

inline void glex::glNamedProgramLocalParameterI4uivEXT(GLuint a, GLenum b, GLuint c, const GLuint *d) {
	m_pglex->glNamedProgramLocalParameterI4uivEXT(a,b,c,d);
}

inline void glex::glNamedProgramLocalParametersI4uivEXT(GLuint a, GLenum b, GLuint c, GLsizei d, const GLuint *e) {
	m_pglex->glNamedProgramLocalParametersI4uivEXT(a,b,c,d,e);
}

inline void glex::glGetNamedProgramLocalParameterIivEXT(GLuint a, GLenum b, GLuint c, GLint *d) {
	m_pglex->glGetNamedProgramLocalParameterIivEXT(a,b,c,d);
}

inline void glex::glGetNamedProgramLocalParameterIuivEXT(GLuint a, GLenum b, GLuint c, GLuint *d) {
	m_pglex->glGetNamedProgramLocalParameterIuivEXT(a,b,c,d);
}

inline void glex::glTextureParameterIivEXT(GLuint a, GLenum b, GLenum c, const GLint *d) {
	m_pglex->glTextureParameterIivEXT(a,b,c,d);
}

inline void glex::glTextureParameterIuivEXT(GLuint a, GLenum b, GLenum c, const GLuint *d) {
	m_pglex->glTextureParameterIuivEXT(a,b,c,d);
}

inline void glex::glGetTextureParameterIivEXT(GLuint a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetTextureParameterIivEXT(a,b,c,d);
}

inline void glex::glGetTextureParameterIuivEXT(GLuint a, GLenum b, GLenum c, GLuint *d) {
	m_pglex->glGetTextureParameterIuivEXT(a,b,c,d);
}

inline void glex::glMultiTexParameterIivEXT(GLenum a, GLenum b, GLenum c, const GLint *d) {
	m_pglex->glMultiTexParameterIivEXT(a,b,c,d);
}

inline void glex::glMultiTexParameterIuivEXT(GLenum a, GLenum b, GLenum c, const GLuint *d) {
	m_pglex->glMultiTexParameterIuivEXT(a,b,c,d);
}

inline void glex::glGetMultiTexParameterIivEXT(GLenum a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetMultiTexParameterIivEXT(a,b,c,d);
}

inline void glex::glGetMultiTexParameterIuivEXT(GLenum a, GLenum b, GLenum c, GLuint *d) {
	m_pglex->glGetMultiTexParameterIuivEXT(a,b,c,d);
}

inline void glex::glProgramUniform1fEXT(GLuint a, GLint b, GLfloat c) {
	m_pglex->glProgramUniform1fEXT(a,b,c);
}

inline void glex::glProgramUniform2fEXT(GLuint a, GLint b, GLfloat c, GLfloat d) {
	m_pglex->glProgramUniform2fEXT(a,b,c,d);
}

inline void glex::glProgramUniform3fEXT(GLuint a, GLint b, GLfloat c, GLfloat d, GLfloat e) {
	m_pglex->glProgramUniform3fEXT(a,b,c,d,e);
}

inline void glex::glProgramUniform4fEXT(GLuint a, GLint b, GLfloat c, GLfloat d, GLfloat e, GLfloat f) {
	m_pglex->glProgramUniform4fEXT(a,b,c,d,e,f);
}

inline void glex::glProgramUniform1iEXT(GLuint a, GLint b, GLint c) {
	m_pglex->glProgramUniform1iEXT(a,b,c);
}

inline void glex::glProgramUniform2iEXT(GLuint a, GLint b, GLint c, GLint d) {
	m_pglex->glProgramUniform2iEXT(a,b,c,d);
}

inline void glex::glProgramUniform3iEXT(GLuint a, GLint b, GLint c, GLint d, GLint e) {
	m_pglex->glProgramUniform3iEXT(a,b,c,d,e);
}

inline void glex::glProgramUniform4iEXT(GLuint a, GLint b, GLint c, GLint d, GLint e, GLint f) {
	m_pglex->glProgramUniform4iEXT(a,b,c,d,e,f);
}

inline void glex::glProgramUniform1fvEXT(GLuint a, GLint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramUniform1fvEXT(a,b,c,d);
}

inline void glex::glProgramUniform2fvEXT(GLuint a, GLint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramUniform2fvEXT(a,b,c,d);
}

inline void glex::glProgramUniform3fvEXT(GLuint a, GLint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramUniform3fvEXT(a,b,c,d);
}

inline void glex::glProgramUniform4fvEXT(GLuint a, GLint b, GLsizei c, const GLfloat *d) {
	m_pglex->glProgramUniform4fvEXT(a,b,c,d);
}

inline void glex::glProgramUniform1ivEXT(GLuint a, GLint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramUniform1ivEXT(a,b,c,d);
}

inline void glex::glProgramUniform2ivEXT(GLuint a, GLint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramUniform2ivEXT(a,b,c,d);
}

inline void glex::glProgramUniform3ivEXT(GLuint a, GLint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramUniform3ivEXT(a,b,c,d);
}

inline void glex::glProgramUniform4ivEXT(GLuint a, GLint b, GLsizei c, const GLint *d) {
	m_pglex->glProgramUniform4ivEXT(a,b,c,d);
}

inline void glex::glProgramUniformMatrix2fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix2fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix3fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix3fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix4fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix4fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix2x3fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix2x3fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix3x2fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix3x2fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix2x4fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix2x4fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix4x2fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix4x2fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix3x4fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix3x4fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniformMatrix4x3fvEXT(GLuint a, GLint b, GLsizei c, GLboolean d, const GLfloat *e) {
	m_pglex->glProgramUniformMatrix4x3fvEXT(a,b,c,d,e);
}

inline void glex::glProgramUniform1uiEXT(GLuint a, GLint b, GLuint c) {
	m_pglex->glProgramUniform1uiEXT(a,b,c);
}

inline void glex::glProgramUniform2uiEXT(GLuint a, GLint b, GLuint c, GLuint d) {
	m_pglex->glProgramUniform2uiEXT(a,b,c,d);
}

inline void glex::glProgramUniform3uiEXT(GLuint a, GLint b, GLuint c, GLuint d, GLuint e) {
	m_pglex->glProgramUniform3uiEXT(a,b,c,d,e);
}

inline void glex::glProgramUniform4uiEXT(GLuint a, GLint b, GLuint c, GLuint d, GLuint e, GLuint f) {
	m_pglex->glProgramUniform4uiEXT(a,b,c,d,e,f);
}

inline void glex::glProgramUniform1uivEXT(GLuint a, GLint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramUniform1uivEXT(a,b,c,d);
}

inline void glex::glProgramUniform2uivEXT(GLuint a, GLint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramUniform2uivEXT(a,b,c,d);
}

inline void glex::glProgramUniform3uivEXT(GLuint a, GLint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramUniform3uivEXT(a,b,c,d);
}

inline void glex::glProgramUniform4uivEXT(GLuint a, GLint b, GLsizei c, const GLuint *d) {
	m_pglex->glProgramUniform4uivEXT(a,b,c,d);
}

inline void glex::glNamedBufferDataEXT(GLuint a, GLsizeiptr b, const GLvoid *c, GLenum d) {
	m_pglex->glNamedBufferDataEXT(a,b,c,d);
}

inline void glex::glNamedBufferSubDataEXT(GLuint a, GLintptr b, GLsizeiptr c, const GLvoid *d) {
	m_pglex->glNamedBufferSubDataEXT(a,b,c,d);
}

inline GLvoid* glex::glMapNamedBufferEXT(GLuint a, GLenum b) {
	return m_pglex->glMapNamedBufferEXT(a,b);
}

inline GLboolean glex::glUnmapNamedBufferEXT(GLuint a) {
	return m_pglex->glUnmapNamedBufferEXT(a);
}

inline void glex::glGetNamedBufferParameterivEXT(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetNamedBufferParameterivEXT(a,b,c);
}

inline void glex::glGetNamedBufferPointervEXT(GLuint a, GLenum b, GLvoid* *c) {
	m_pglex->glGetNamedBufferPointervEXT(a,b,c);
}

inline void glex::glGetNamedBufferSubDataEXT(GLuint a, GLintptr b, GLsizeiptr c, GLvoid *d) {
	m_pglex->glGetNamedBufferSubDataEXT(a,b,c,d);
}

inline void glex::glTextureBufferEXT(GLuint a, GLenum b, GLenum c, GLuint d) {
	m_pglex->glTextureBufferEXT(a,b,c,d);
}

inline void glex::glMultiTexBufferEXT(GLenum a, GLenum b, GLenum c, GLuint d) {
	m_pglex->glMultiTexBufferEXT(a,b,c,d);
}

inline void glex::glNamedRenderbufferStorageEXT(GLuint a, GLenum b, GLsizei c, GLsizei d) {
	m_pglex->glNamedRenderbufferStorageEXT(a,b,c,d);
}

inline void glex::glGetNamedRenderbufferParameterivEXT(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetNamedRenderbufferParameterivEXT(a,b,c);
}

inline GLenum glex::glCheckNamedFramebufferStatusEXT(GLuint a, GLenum b) {
	return m_pglex->glCheckNamedFramebufferStatusEXT(a,b);
}

inline void glex::glNamedFramebufferTexture1DEXT(GLuint a, GLenum b, GLenum c, GLuint d, GLint e) {
	m_pglex->glNamedFramebufferTexture1DEXT(a,b,c,d,e);
}

inline void glex::glNamedFramebufferTexture2DEXT(GLuint a, GLenum b, GLenum c, GLuint d, GLint e) {
	m_pglex->glNamedFramebufferTexture2DEXT(a,b,c,d,e);
}

inline void glex::glNamedFramebufferTexture3DEXT(GLuint a, GLenum b, GLenum c, GLuint d, GLint e, GLint f) {
	m_pglex->glNamedFramebufferTexture3DEXT(a,b,c,d,e,f);
}

inline void glex::glNamedFramebufferRenderbufferEXT(GLuint a, GLenum b, GLenum c, GLuint d) {
	m_pglex->glNamedFramebufferRenderbufferEXT(a,b,c,d);
}

inline void glex::glGetNamedFramebufferAttachmentParameterivEXT(GLuint a, GLenum b, GLenum c, GLint *d) {
	m_pglex->glGetNamedFramebufferAttachmentParameterivEXT(a,b,c,d);
}

inline void glex::glGenerateTextureMipmapEXT(GLuint a, GLenum b) {
	m_pglex->glGenerateTextureMipmapEXT(a,b);
}

inline void glex::glGenerateMultiTexMipmapEXT(GLenum a, GLenum b) {
	m_pglex->glGenerateMultiTexMipmapEXT(a,b);
}

inline void glex::glFramebufferDrawBufferEXT(GLuint a, GLenum b) {
	m_pglex->glFramebufferDrawBufferEXT(a,b);
}

inline void glex::glFramebufferDrawBuffersEXT(GLuint a, GLsizei b, const GLenum *c) {
	m_pglex->glFramebufferDrawBuffersEXT(a,b,c);
}

inline void glex::glFramebufferReadBufferEXT(GLuint a, GLenum b) {
	m_pglex->glFramebufferReadBufferEXT(a,b);
}

inline void glex::glGetFramebufferParameterivEXT(GLuint a, GLenum b, GLint *c) {
	m_pglex->glGetFramebufferParameterivEXT(a,b,c);
}

inline void glex::glNamedRenderbufferStorageMultisampleEXT(GLuint a, GLsizei b, GLenum c, GLsizei d, GLsizei e) {
	m_pglex->glNamedRenderbufferStorageMultisampleEXT(a,b,c,d,e);
}

inline void glex::glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint a, GLsizei b, GLsizei c, GLenum d, GLsizei e, GLsizei f) {
	m_pglex->glNamedRenderbufferStorageMultisampleCoverageEXT(a,b,c,d,e,f);
}

inline void glex::glNamedFramebufferTextureEXT(GLuint a, GLenum b, GLuint c, GLint d) {
	m_pglex->glNamedFramebufferTextureEXT(a,b,c,d);
}

inline void glex::glNamedFramebufferTextureLayerEXT(GLuint a, GLenum b, GLuint c, GLint d, GLint e) {
	m_pglex->glNamedFramebufferTextureLayerEXT(a,b,c,d,e);
}

inline void glex::glNamedFramebufferTextureFaceEXT(GLuint a, GLenum b, GLuint c, GLint d, GLenum e) {
	m_pglex->glNamedFramebufferTextureFaceEXT(a,b,c,d,e);
}

inline void glex::glTextureRenderbufferEXT(GLuint a, GLenum b, GLuint c) {
	m_pglex->glTextureRenderbufferEXT(a,b,c);
}

inline void glex::glMultiTexRenderbufferEXT(GLenum a, GLenum b, GLuint c) {
	m_pglex->glMultiTexRenderbufferEXT(a,b,c);
}

inline void glex::glGetMultisamplefvNV(GLenum a, GLuint b, GLfloat *c) {
	m_pglex->glGetMultisamplefvNV(a,b,c);
}

inline void glex::glSampleMaskIndexedNV(GLuint a, GLbitfield b) {
	m_pglex->glSampleMaskIndexedNV(a,b);
}

inline void glex::glTexRenderbufferNV(GLenum a, GLuint b) {
	m_pglex->glTexRenderbufferNV(a,b);
}

inline void glex::glBindTransformFeedbackNV(GLenum a, GLuint b) {
	m_pglex->glBindTransformFeedbackNV(a,b);
}

inline void glex::glDeleteTransformFeedbacksNV(GLsizei a, const GLuint *b) {
	m_pglex->glDeleteTransformFeedbacksNV(a,b);
}

inline void glex::glGenTransformFeedbacksNV(GLsizei a, GLuint *b) {
	m_pglex->glGenTransformFeedbacksNV(a,b);
}

inline GLboolean glex::glIsTransformFeedbackNV(GLuint a) {
	return m_pglex->glIsTransformFeedbackNV(a);
}

inline void glex::glPauseTransformFeedbackNV(void) {
	m_pglex->glPauseTransformFeedbackNV();
}

inline void glex::glResumeTransformFeedbackNV(void) {
	m_pglex->glResumeTransformFeedbackNV();
}

inline void glex::glDrawTransformFeedbackNV(GLenum a, GLuint b) {
	m_pglex->glDrawTransformFeedbackNV(a,b);
}

inline void glex::glGetPerfMonitorGroupsAMD(GLint *a, GLsizei b, GLuint *c) {
	m_pglex->glGetPerfMonitorGroupsAMD(a,b,c);
}

inline void glex::glGetPerfMonitorCountersAMD(GLuint a, GLint *b, GLint *c, GLsizei d, GLuint *e) {
	m_pglex->glGetPerfMonitorCountersAMD(a,b,c,d,e);
}

inline void glex::glGetPerfMonitorGroupStringAMD(GLuint a, GLsizei b, GLsizei *c, GLchar *d) {
	m_pglex->glGetPerfMonitorGroupStringAMD(a,b,c,d);
}

inline void glex::glGetPerfMonitorCounterStringAMD(GLuint a, GLuint b, GLsizei c, GLsizei *d, GLchar *e) {
	m_pglex->glGetPerfMonitorCounterStringAMD(a,b,c,d,e);
}

inline void glex::glGetPerfMonitorCounterInfoAMD(GLuint a, GLuint b, GLenum c, void *d) {
	m_pglex->glGetPerfMonitorCounterInfoAMD(a,b,c,d);
}

inline void glex::glGenPerfMonitorsAMD(GLsizei a, GLuint *b) {
	m_pglex->glGenPerfMonitorsAMD(a,b);
}

inline void glex::glDeletePerfMonitorsAMD(GLsizei a, GLuint *b) {
	m_pglex->glDeletePerfMonitorsAMD(a,b);
}

inline void glex::glSelectPerfMonitorCountersAMD(GLuint a, GLboolean b, GLuint c, GLint d, GLuint *e) {
	m_pglex->glSelectPerfMonitorCountersAMD(a,b,c,d,e);
}

inline void glex::glBeginPerfMonitorAMD(GLuint a) {
	m_pglex->glBeginPerfMonitorAMD(a);
}

inline void glex::glEndPerfMonitorAMD(GLuint a) {
	m_pglex->glEndPerfMonitorAMD(a);
}

inline void glex::glGetPerfMonitorCounterDataAMD(GLuint a, GLenum b, GLsizei c, GLuint *d, GLint *e) {
	m_pglex->glGetPerfMonitorCounterDataAMD(a,b,c,d,e);
}

inline void glex::glTessellationFactorAMD(GLfloat a) {
	m_pglex->glTessellationFactorAMD(a);
}

inline void glex::glTessellationModeAMD(GLenum a) {
	m_pglex->glTessellationModeAMD(a);
}

inline void glex::glProvokingVertexEXT(GLenum a) {
	m_pglex->glProvokingVertexEXT(a);
}

inline void glex::glBlendFuncIndexedAMD(GLuint a, GLenum b, GLenum c) {
	m_pglex->glBlendFuncIndexedAMD(a,b,c);
}

inline void glex::glBlendFuncSeparateIndexedAMD(GLuint a, GLenum b, GLenum c, GLenum d, GLenum e) {
	m_pglex->glBlendFuncSeparateIndexedAMD(a,b,c,d,e);
}

inline void glex::glBlendEquationIndexedAMD(GLuint a, GLenum b) {
	m_pglex->glBlendEquationIndexedAMD(a,b);
}

inline void glex::glBlendEquationSeparateIndexedAMD(GLuint a, GLenum b, GLenum c) {
	m_pglex->glBlendEquationSeparateIndexedAMD(a,b,c);
}

inline void glex::glTextureRangeAPPLE(GLenum a, GLsizei b, const GLvoid *c) {
	m_pglex->glTextureRangeAPPLE(a,b,c);
}

inline void glex::glGetTexParameterPointervAPPLE(GLenum a, GLenum b, GLvoid* *c) {
	m_pglex->glGetTexParameterPointervAPPLE(a,b,c);
}

inline void glex::glEnableVertexAttribAPPLE(GLuint a, GLenum b) {
	m_pglex->glEnableVertexAttribAPPLE(a,b);
}

inline void glex::glDisableVertexAttribAPPLE(GLuint a, GLenum b) {
	m_pglex->glDisableVertexAttribAPPLE(a,b);
}

inline GLboolean glex::glIsVertexAttribEnabledAPPLE(GLuint a, GLenum b) {
	return m_pglex->glIsVertexAttribEnabledAPPLE(a,b);
}

inline void glex::glMapVertexAttrib1dAPPLE(GLuint a, GLuint b, GLdouble c, GLdouble d, GLint e, GLint f, const GLdouble *g) {
	m_pglex->glMapVertexAttrib1dAPPLE(a,b,c,d,e,f,g);
}

inline void glex::glMapVertexAttrib1fAPPLE(GLuint a, GLuint b, GLfloat c, GLfloat d, GLint e, GLint f, const GLfloat *g) {
	m_pglex->glMapVertexAttrib1fAPPLE(a,b,c,d,e,f,g);
}

inline void glex::glMapVertexAttrib2dAPPLE(GLuint a, GLuint b, GLdouble c, GLdouble d, GLint e, GLint f, GLdouble g, GLdouble h, GLint i, GLint j, const GLdouble *k) {
	m_pglex->glMapVertexAttrib2dAPPLE(a,b,c,d,e,f,g,h,i,j,k);
}

inline void glex::glMapVertexAttrib2fAPPLE(GLuint a, GLuint b, GLfloat c, GLfloat d, GLint e, GLint f, GLfloat g, GLfloat h, GLint i, GLint j, const GLfloat *k) {
	m_pglex->glMapVertexAttrib2fAPPLE(a,b,c,d,e,f,g,h,i,j,k);
}

inline GLenum glex::glObjectPurgeableAPPLE(GLenum a, GLuint b, GLenum c) {
	return m_pglex->glObjectPurgeableAPPLE(a,b,c);
}

inline GLenum glex::glObjectUnpurgeableAPPLE(GLenum a, GLuint b, GLenum c) {
	return m_pglex->glObjectUnpurgeableAPPLE(a,b,c);
}

inline void glex::glGetObjectParameterivAPPLE(GLenum a, GLuint b, GLenum c, GLint *d) {
	m_pglex->glGetObjectParameterivAPPLE(a,b,c,d);
}

inline HANDLE glex::wglCreateBufferRegionARB(HDC a, int b, UINT c) {
	return m_pglex->wglCreateBufferRegionARB(a,b,c);
}

inline VOID glex::wglDeleteBufferRegionARB(HANDLE a) {
	m_pglex->wglDeleteBufferRegionARB(a);
}

inline BOOL glex::wglSaveBufferRegionARB(HANDLE a, int b, int c, int d, int e) {
	return m_pglex->wglSaveBufferRegionARB(a,b,c,d,e);
}

inline BOOL glex::wglRestoreBufferRegionARB(HANDLE a, int b, int c, int d, int e, int f, int g) {
	return m_pglex->wglRestoreBufferRegionARB(a,b,c,d,e,f,g);
}

inline const char * glex::wglGetExtensionsStringARB(HDC a) {
	return m_pglex->wglGetExtensionsStringARB(a);
}

inline BOOL glex::wglGetPixelFormatAttribivARB(HDC a, int b, int c, UINT d, const int *e, int *f) {
	return m_pglex->wglGetPixelFormatAttribivARB(a,b,c,d,e,f);
}

inline BOOL glex::wglGetPixelFormatAttribfvARB(HDC a, int b, int c, UINT d, const int *e, FLOAT *f) {
	return m_pglex->wglGetPixelFormatAttribfvARB(a,b,c,d,e,f);
}

inline BOOL glex::wglChoosePixelFormatARB(HDC a, const int *b, const FLOAT *c, UINT d, int *e, UINT *f) {
	return m_pglex->wglChoosePixelFormatARB(a,b,c,d,e,f);
}

inline BOOL glex::wglMakeContextCurrentARB(HDC a, HDC b, HGLRC c) {
	return m_pglex->wglMakeContextCurrentARB(a,b,c);
}

inline HDC glex::wglGetCurrentReadDCARB(void) {
	return m_pglex->wglGetCurrentReadDCARB();
}

inline HPBUFFERARB glex::wglCreatePbufferARB(HDC a, int b, int c, int d, const int *e) {
	return m_pglex->wglCreatePbufferARB(a,b,c,d,e);
}

inline HDC glex::wglGetPbufferDCARB(HPBUFFERARB a) {
	return m_pglex->wglGetPbufferDCARB(a);
}

inline int glex::wglReleasePbufferDCARB(HPBUFFERARB a, HDC b) {
	return m_pglex->wglReleasePbufferDCARB(a,b);
}

inline BOOL glex::wglDestroyPbufferARB(HPBUFFERARB a) {
	return m_pglex->wglDestroyPbufferARB(a);
}

inline BOOL glex::wglQueryPbufferARB(HPBUFFERARB a, int b, int *c) {
	return m_pglex->wglQueryPbufferARB(a,b,c);
}

inline BOOL glex::wglBindTexImageARB(HPBUFFERARB a, int b) {
	return m_pglex->wglBindTexImageARB(a,b);
}

inline BOOL glex::wglReleaseTexImageARB(HPBUFFERARB a, int b) {
	return m_pglex->wglReleaseTexImageARB(a,b);
}

inline BOOL glex::wglSetPbufferAttribARB(HPBUFFERARB a, const int *b) {
	return m_pglex->wglSetPbufferAttribARB(a,b);
}

inline HGLRC glex::wglCreateContextAttribsARB(HDC a, HGLRC b, const int *c) {
	return m_pglex->wglCreateContextAttribsARB(a,b,c);
}

inline GLboolean glex::wglCreateDisplayColorTableEXT(GLushort a) {
	return m_pglex->wglCreateDisplayColorTableEXT(a);
}

inline GLboolean glex::wglLoadDisplayColorTableEXT(const GLushort *a, GLuint b) {
	return m_pglex->wglLoadDisplayColorTableEXT(a,b);
}

inline GLboolean glex::wglBindDisplayColorTableEXT(GLushort a) {
	return m_pglex->wglBindDisplayColorTableEXT(a);
}

inline VOID glex::wglDestroyDisplayColorTableEXT(GLushort a) {
	m_pglex->wglDestroyDisplayColorTableEXT(a);
}

inline const char * glex::wglGetExtensionsStringEXT(void) {
	return m_pglex->wglGetExtensionsStringEXT();
}

inline BOOL glex::wglMakeContextCurrentEXT(HDC a, HDC b, HGLRC c) {
	return m_pglex->wglMakeContextCurrentEXT(a,b,c);
}

inline HDC glex::wglGetCurrentReadDCEXT(void) {
	return m_pglex->wglGetCurrentReadDCEXT();
}

inline HPBUFFEREXT glex::wglCreatePbufferEXT(HDC a, int b, int c, int d, const int *e) {
	return m_pglex->wglCreatePbufferEXT(a,b,c,d,e);
}

inline HDC glex::wglGetPbufferDCEXT(HPBUFFEREXT a) {
	return m_pglex->wglGetPbufferDCEXT(a);
}

inline int glex::wglReleasePbufferDCEXT(HPBUFFEREXT a, HDC b) {
	return m_pglex->wglReleasePbufferDCEXT(a,b);
}

inline BOOL glex::wglDestroyPbufferEXT(HPBUFFEREXT a) {
	return m_pglex->wglDestroyPbufferEXT(a);
}

inline BOOL glex::wglQueryPbufferEXT(HPBUFFEREXT a, int b, int *c) {
	return m_pglex->wglQueryPbufferEXT(a,b,c);
}

inline BOOL glex::wglGetPixelFormatAttribivEXT(HDC a, int b, int c, UINT d, int *e, int *f) {
	return m_pglex->wglGetPixelFormatAttribivEXT(a,b,c,d,e,f);
}

inline BOOL glex::wglGetPixelFormatAttribfvEXT(HDC a, int b, int c, UINT d, int *e, FLOAT *f) {
	return m_pglex->wglGetPixelFormatAttribfvEXT(a,b,c,d,e,f);
}

inline BOOL glex::wglChoosePixelFormatEXT(HDC a, const int *b, const FLOAT *c, UINT d, int *e, UINT *f) {
	return m_pglex->wglChoosePixelFormatEXT(a,b,c,d,e,f);
}

inline BOOL glex::wglSwapIntervalEXT(int a) {
	return m_pglex->wglSwapIntervalEXT(a);
}

inline int glex::wglGetSwapIntervalEXT(void) {
	return m_pglex->wglGetSwapIntervalEXT();
}

inline void* glex::wglAllocateMemoryNV(GLsizei a, GLfloat b, GLfloat c, GLfloat d) {
	return m_pglex->wglAllocateMemoryNV(a,b,c,d);
}

inline void glex::wglFreeMemoryNV(void *a) {
	m_pglex->wglFreeMemoryNV(a);
}

inline BOOL glex::wglGetSyncValuesOML(HDC a, INT64 *b, INT64 *c, INT64 *d) {
	return m_pglex->wglGetSyncValuesOML(a,b,c,d);
}

inline BOOL glex::wglGetMscRateOML(HDC a, INT32 *b, INT32 *c) {
	return m_pglex->wglGetMscRateOML(a,b,c);
}

inline INT64 glex::wglSwapBuffersMscOML(HDC a, INT64 b, INT64 c, INT64 d) {
	return m_pglex->wglSwapBuffersMscOML(a,b,c,d);
}

inline INT64 glex::wglSwapLayerBuffersMscOML(HDC a, int b, INT64 c, INT64 d, INT64 e) {
	return m_pglex->wglSwapLayerBuffersMscOML(a,b,c,d,e);
}

inline BOOL glex::wglWaitForMscOML(HDC a, INT64 b, INT64 c, INT64 d, INT64 *e, INT64 *f, INT64 *g) {
	return m_pglex->wglWaitForMscOML(a,b,c,d,e,f,g);
}

inline BOOL glex::wglWaitForSbcOML(HDC a, INT64 b, INT64 *c, INT64 *d, INT64 *e) {
	return m_pglex->wglWaitForSbcOML(a,b,c,d,e);
}

inline BOOL glex::wglGetDigitalVideoParametersI3D(HDC a, int b, int *c) {
	return m_pglex->wglGetDigitalVideoParametersI3D(a,b,c);
}

inline BOOL glex::wglSetDigitalVideoParametersI3D(HDC a, int b, const int *c) {
	return m_pglex->wglSetDigitalVideoParametersI3D(a,b,c);
}

inline BOOL glex::wglGetGammaTableParametersI3D(HDC a, int b, int *c) {
	return m_pglex->wglGetGammaTableParametersI3D(a,b,c);
}

inline BOOL glex::wglSetGammaTableParametersI3D(HDC a, int b, const int *c) {
	return m_pglex->wglSetGammaTableParametersI3D(a,b,c);
}

inline BOOL glex::wglGetGammaTableI3D(HDC a, int b, USHORT *c, USHORT *d, USHORT *e) {
	return m_pglex->wglGetGammaTableI3D(a,b,c,d,e);
}

inline BOOL glex::wglSetGammaTableI3D(HDC a, int b, const USHORT *c, const USHORT *d, const USHORT *e) {
	return m_pglex->wglSetGammaTableI3D(a,b,c,d,e);
}

inline BOOL glex::wglEnableGenlockI3D(HDC a) {
	return m_pglex->wglEnableGenlockI3D(a);
}

inline BOOL glex::wglDisableGenlockI3D(HDC a) {
	return m_pglex->wglDisableGenlockI3D(a);
}

inline BOOL glex::wglIsEnabledGenlockI3D(HDC a, BOOL *b) {
	return m_pglex->wglIsEnabledGenlockI3D(a,b);
}

inline BOOL glex::wglGenlockSourceI3D(HDC a, UINT b) {
	return m_pglex->wglGenlockSourceI3D(a,b);
}

inline BOOL glex::wglGetGenlockSourceI3D(HDC a, UINT *b) {
	return m_pglex->wglGetGenlockSourceI3D(a,b);
}

inline BOOL glex::wglGenlockSourceEdgeI3D(HDC a, UINT b) {
	return m_pglex->wglGenlockSourceEdgeI3D(a,b);
}

inline BOOL glex::wglGetGenlockSourceEdgeI3D(HDC a, UINT *b) {
	return m_pglex->wglGetGenlockSourceEdgeI3D(a,b);
}

inline BOOL glex::wglGenlockSampleRateI3D(HDC a, UINT b) {
	return m_pglex->wglGenlockSampleRateI3D(a,b);
}

inline BOOL glex::wglGetGenlockSampleRateI3D(HDC a, UINT *b) {
	return m_pglex->wglGetGenlockSampleRateI3D(a,b);
}

inline BOOL glex::wglGenlockSourceDelayI3D(HDC a, UINT b) {
	return m_pglex->wglGenlockSourceDelayI3D(a,b);
}

inline BOOL glex::wglGetGenlockSourceDelayI3D(HDC a, UINT *b) {
	return m_pglex->wglGetGenlockSourceDelayI3D(a,b);
}

inline BOOL glex::wglQueryGenlockMaxSourceDelayI3D(HDC a, UINT *b, UINT *c) {
	return m_pglex->wglQueryGenlockMaxSourceDelayI3D(a,b,c);
}

inline LPVOID glex::wglCreateImageBufferI3D(HDC a, DWORD b, UINT c) {
	return m_pglex->wglCreateImageBufferI3D(a,b,c);
}

inline BOOL glex::wglDestroyImageBufferI3D(HDC a, LPVOID b) {
	return m_pglex->wglDestroyImageBufferI3D(a,b);
}

inline BOOL glex::wglAssociateImageBufferEventsI3D(HDC a, const HANDLE *b, const LPVOID *c, const DWORD *d, UINT e) {
	return m_pglex->wglAssociateImageBufferEventsI3D(a,b,c,d,e);
}

inline BOOL glex::wglReleaseImageBufferEventsI3D(HDC a, const LPVOID *b, UINT c) {
	return m_pglex->wglReleaseImageBufferEventsI3D(a,b,c);
}

inline BOOL glex::wglEnableFrameLockI3D(void) {
	return m_pglex->wglEnableFrameLockI3D();
}

inline BOOL glex::wglDisableFrameLockI3D(void) {
	return m_pglex->wglDisableFrameLockI3D();
}

inline BOOL glex::wglIsEnabledFrameLockI3D(BOOL *a) {
	return m_pglex->wglIsEnabledFrameLockI3D(a);
}

inline BOOL glex::wglQueryFrameLockMasterI3D(BOOL *a) {
	return m_pglex->wglQueryFrameLockMasterI3D(a);
}

inline BOOL glex::wglGetFrameUsageI3D(float *a) {
	return m_pglex->wglGetFrameUsageI3D(a);
}

inline BOOL glex::wglBeginFrameTrackingI3D(void) {
	return m_pglex->wglBeginFrameTrackingI3D();
}

inline BOOL glex::wglEndFrameTrackingI3D(void) {
	return m_pglex->wglEndFrameTrackingI3D();
}

inline BOOL glex::wglQueryFrameTrackingI3D(DWORD *a, DWORD *b, float *c) {
	return m_pglex->wglQueryFrameTrackingI3D(a,b,c);
}

inline BOOL glex::wglSetStereoEmitterState3DL(HDC a, UINT b) {
	return m_pglex->wglSetStereoEmitterState3DL(a,b);
}

inline int glex::wglEnumerateVideoDevicesNV(HDC a, HVIDEOOUTPUTDEVICENV *b) {
	return m_pglex->wglEnumerateVideoDevicesNV(a,b);
}

inline BOOL glex::wglBindVideoDeviceNV(HDC a, unsigned int b, HVIDEOOUTPUTDEVICENV c, const int *d) {
	return m_pglex->wglBindVideoDeviceNV(a,b,c,d);
}

inline BOOL glex::wglQueryCurrentContextNV(int a, int *b) {
	return m_pglex->wglQueryCurrentContextNV(a,b);
}

inline BOOL glex::wglGetVideoDeviceNV(HDC a, int b, HPVIDEODEV *c) {
	return m_pglex->wglGetVideoDeviceNV(a,b,c);
}

inline BOOL glex::wglReleaseVideoDeviceNV(HPVIDEODEV a) {
	return m_pglex->wglReleaseVideoDeviceNV(a);
}

inline BOOL glex::wglBindVideoImageNV(HPVIDEODEV a, HPBUFFERARB b, int c) {
	return m_pglex->wglBindVideoImageNV(a,b,c);
}

inline BOOL glex::wglReleaseVideoImageNV(HPBUFFERARB a, int b) {
	return m_pglex->wglReleaseVideoImageNV(a,b);
}

inline BOOL glex::wglSendPbufferToVideoNV(HPBUFFERARB a, int b, unsigned long *c, BOOL d) {
	return m_pglex->wglSendPbufferToVideoNV(a,b,c,d);
}

inline BOOL glex::wglGetVideoInfoNV(HPVIDEODEV a, unsigned long *b, unsigned long *c) {
	return m_pglex->wglGetVideoInfoNV(a,b,c);
}

inline BOOL glex::wglJoinSwapGroupNV(HDC a, GLuint b) {
	return m_pglex->wglJoinSwapGroupNV(a,b);
}

inline BOOL glex::wglBindSwapBarrierNV(GLuint a, GLuint b) {
	return m_pglex->wglBindSwapBarrierNV(a,b);
}

inline BOOL glex::wglQuerySwapGroupNV(HDC a, GLuint *b, GLuint *c) {
	return m_pglex->wglQuerySwapGroupNV(a,b,c);
}

inline BOOL glex::wglQueryMaxSwapGroupsNV(HDC a, GLuint *b, GLuint *c) {
	return m_pglex->wglQueryMaxSwapGroupsNV(a,b,c);
}

inline BOOL glex::wglQueryFrameCountNV(HDC a, GLuint *b) {
	return m_pglex->wglQueryFrameCountNV(a,b);
}

inline BOOL glex::wglResetFrameCountNV(HDC a) {
	return m_pglex->wglResetFrameCountNV(a);
}

inline BOOL glex::wglEnumGpusNV(UINT a, HGPUNV *b) {
	return m_pglex->wglEnumGpusNV(a,b);
}

inline BOOL glex::wglEnumGpuDevicesNV(HGPUNV a, UINT b, PGPU_DEVICE c) {
	return m_pglex->wglEnumGpuDevicesNV(a,b,c);
}

inline HDC glex::wglCreateAffinityDCNV(const HGPUNV *a) {
	return m_pglex->wglCreateAffinityDCNV(a);
}

inline BOOL glex::wglEnumGpusFromAffinityDCNV(HDC a, UINT b, HGPUNV *c) {
	return m_pglex->wglEnumGpusFromAffinityDCNV(a,b,c);
}

inline BOOL glex::wglDeleteDCNV(HDC a) {
	return m_pglex->wglDeleteDCNV(a);
}

inline UINT glex::wglGetGPUIDsAMD(UINT a, UINT *b) {
	return m_pglex->wglGetGPUIDsAMD(a,b);
}

inline INT glex::wglGetGPUInfoAMD(UINT a, int b, GLenum c, UINT d, void *e) {
	return m_pglex->wglGetGPUInfoAMD(a,b,c,d,e);
}

inline UINT glex::wglGetContextGPUIDAMD(HGLRC a) {
	return m_pglex->wglGetContextGPUIDAMD(a);
}

inline HGLRC glex::wglCreateAssociatedContextAMD(UINT a) {
	return m_pglex->wglCreateAssociatedContextAMD(a);
}

inline HGLRC glex::wglCreateAssociatedContextAttribsAMD(UINT a, HGLRC b, const int *c) {
	return m_pglex->wglCreateAssociatedContextAttribsAMD(a,b,c);
}

inline BOOL glex::wglDeleteAssociatedContextAMD(HGLRC a) {
	return m_pglex->wglDeleteAssociatedContextAMD(a);
}

inline BOOL glex::wglMakeAssociatedContextCurrentAMD(HGLRC a) {
	return m_pglex->wglMakeAssociatedContextCurrentAMD(a);
}

inline HGLRC glex::wglGetCurrentAssociatedContextAMD(void) {
	return m_pglex->wglGetCurrentAssociatedContextAMD();
}

inline VOID glex::wglBlitContextFramebufferAMD(HGLRC a, GLint b, GLint c, GLint d, GLint e, GLint f, GLint g, GLint h, GLint i, GLbitfield j, GLenum k) {
	m_pglex->wglBlitContextFramebufferAMD(a,b,c,d,e,f,g,h,i,j,k);
}

//----------------------------------------------------------------------------

#endif//__glex_h
