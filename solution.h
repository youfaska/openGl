#ifndef _SOLUTION_H_
#define _SOLUTION_H_
 
#include <GL/GL.h>
#include <GL/GLUT.h>
 
void draw_hoop(GLuint center_x, GLuint center_y, GLuint radius);
void draw_marks(GLuint center_x, GLuint center_y, GLuint radius);
void draw_hands(GLuint center_x, GLuint center_y, GLuint radius, GLuint hour, GLuint minute);
 
#endif
