#!BPY

"""
Name: 'C++ Model Export 2 (.h)'
Blender: 249
Group: 'Export'
Tooltip: 'Exports header file for use with the OpenGL VBO '
"""
import Blender
from Blender import *
import bpy
import bpy
import os

        
def write_obj(filepath):    
    out = file(filepath, 'w')
    sce = bpy.data.scenes.active
    ob = sce.objects.active
    mesh = Mesh.New()        
    mesh.getFromObject(ob.name)

    editmode = Window.EditMode()
    if editmode: Window.EditMode(0)
    has_quads = False
    for f in mesh.faces:
        if len(f) == 4:
            has_quads = True
            break
    
    if has_quads:
        oldmode = Mesh.Mode()
        Mesh.Mode(Mesh.SelectModes['FACE'])
        
        mesh.sel = True
        tempob = sce.objects.new(mesh)
        mesh.quadToTriangle(0) # more=0 shortest length
        oldmode = Mesh.Mode(oldmode)
        sce.objects.unlink(tempob)
        
        Mesh.Mode(oldmode)
    
    objectname = ob.getData(True)
    basename = objectname.capitalize()

    out.write('A\t%i\n' % ( len(mesh.faces) * 3 ) )
    out.write('B\t%i\n' % ( len(mesh.faces)  ) )
    numofvertex = 0
    for face in mesh.faces:
	for vert in face.verts:
            out.write('v\t%i\t%f\t%f\t%f\n' % ( numofvertex, vert.co.x, vert.co.y, vert.co.z) )
	    numofvertex = numofvertex + 1

    numofvertex = 0
    for face in mesh.faces:
        for vert in face.verts:
            out.write('n\t%i\t%f\t%f\t%f\n' % ( numofvertex, vert.no.x, vert.no.y, vert.no.z))
            numofvertex = numofvertex + 1

    if (mesh.faceUV):
        numofvertex = 0
        for face in mesh.faces:
            for (vert, uvert) in zip(face.verts, face.uv):
                out.write('u\t%i\t%f\t%f\n' % ( numofvertex, uvert.x, uvert.y ) )
                numofvertex = numofvertex + 1

    if (mesh.vertexColors):
        numofvertex = 0
        for face in mesh.faces:
	    for (vert, color) in zip(face.verts, face.col):
                out.write('c\t%i\t%f\t%f\t%f\t%f\n' % ( numofvertex, color.r / 255.0, color.g / 255.0, color.b / 255.0, color.a / 255.0) )
                numofvertex = numofvertex + 1

    out.close()


filename = os.path.splitext(Blender.Get('filename'))[0]
Blender.Window.FileSelector(write_obj, "Export", '%s.mxy' % filename)
