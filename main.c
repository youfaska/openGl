#include <GL/GL.h>
#include <GL/GLUT.h>
#include <time.h>
#include "solution.h"
#include <math.h>
 
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define MARGIN_WIDTH 40
 
GLint WindowWidth = WINDOW_WIDTH;
GLint WindowHeight = WINDOW_HEIGHT;
 
void init_gl(int argc, char * argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowPosition(50, 50);
  glutInitWindowSize(WindowWidth, WindowHeight);
  glutCreateWindow(argv[0]);
  glClearColor(1.0, 1.0, 1.0, 1.0);
}
 
void reshape_func(GLint width, GLint height) {
  glViewport(0, 0, WindowWidth=width, WindowHeight=height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-WindowWidth/2, WindowWidth/2, -WindowHeight/2, WindowHeight/2);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
 
void display_func() {
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  // Compute data
  GLuint radius = (WindowWidth<WindowHeight)?WindowWidth:WindowHeight;
  radius = (radius/2) - MARGIN_WIDTH;
  time_t rawtime;
  struct tm *timeinfo;
  time ( &rawtime );
  timeinfo = localtime (&rawtime);
  // Draw the clock
  draw_hoop(0, 0, radius);
  draw_marks(0, 0, radius);
  draw_hands(0, 0, radius, timeinfo->tm_hour, timeinfo->tm_min);
  glFlush();
}
 
int main(int argc, char * argv[]) {
  init_gl(argc, argv);
  glutReshapeFunc(reshape_func);
  glutDisplayFunc(display_func);
  glutMainLoop();
  return 0;
}
