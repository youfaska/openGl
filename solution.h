#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <GL/GL.h>
#include <GL/GLUT.h>

#define MAX_POLYGON_VERTICES 256

typedef struct _Point {
  GLfloat x;
  GLfloat y;
} Point;

// Cohen-Sutherland
int LRBT(Point* p, GLfloat wxmin, GLfloat wymin, GLfloat wxmax, GLfloat wymax);
void cut_p1_side(Point* p1, const Point* p2, GLfloat wxmin, GLfloat wymin, GLfloat wxmax, GLfloat wymax);
int cohen_sutherland(Point* p1, Point* p2, GLfloat wxmin, GLfloat wymin, GLfloat wxmax, GLfloat wymax);


// Sutherland-Hodgman
int sutherland_hodgman(Point* polygon,int* p_n_vertices, GLfloat wxmin, GLfloat wymin, GLfloat wxmax, GLfloat wymax);

#endif

