#include "solution.h"
#include "stdio.h"
#include "conio.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

GLint WindowWidth = WINDOW_WIDTH;
GLint WindowHeight = WINDOW_HEIGHT;


void init_gl(int argc, char * argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowPosition(50, 50);
  glutInitWindowSize(WindowWidth, WindowHeight);
  glutCreateWindow(argv[0]);
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glEnable(GL_LINE_SMOOTH);
}

void reshape_func(GLint width, GLint height) {
  glViewport(0, 0, WindowWidth=width, WindowHeight=height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-WindowWidth/2, WindowWidth/2, -WindowHeight/2, WindowHeight/2);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void draw_line(Point* p1, Point*p2, GLfloat width, GLfloat red, GLfloat green, GLfloat blue) {
  glColor3f(red, green, blue);
  glLineWidth(width);
  glBegin(GL_LINES);
  glVertex2fv((GLfloat*)p1);
  glVertex2fv((GLfloat*)p2);
  glEnd();
}

void draw_cohen_sutherland() {
  // Draw clipping window
  GLfloat wxmin=-230, wymin=-70, wxmax=-50, wymax=70;
  glColor3f(0.0f, 0.3f, 1.0f);
  glRectf(wxmin, wymin, wxmax, wymax);
  // Draw line
  Point p1={-280,40};
  Point p2={-150,-60};
  draw_line(&p1, &p2, 1.0f, 0.1f, 1.0f, 0.0f);
  //Draw clipped line
 // printf("El valor del p1.x es : %f ", p1.x);
  //printf("El valor del p1.y es : %f ", p1.y);
  int discarded = cohen_sutherland(&p1,&p2,wxmin,wymin,wxmax,wymax);
  //printf("DESPUES DEL ALGORITMO....");
  //printf("El valor del p1.x es : %f ", p1.x);
  //printf("El valor del p1.y es : %f ", p1.y);
  if (!discarded) {
    draw_line(&p1, &p2, 5.0f, 1.0f, 0.1f, 0.0f);
  }
}

void draw_polygon(Point* vertices, int n_vertices, GLfloat width, GLenum mode, GLfloat red, GLfloat green, GLfloat blue) {
  glPolygonMode(GL_FRONT, mode);
  glColor3f(red, green, blue);
  glLineWidth(width);
  glBegin(GL_POLYGON);
  int i;
  for (i=0;i<n_vertices;i++) {
    glVertex2fv((GLfloat*)vertices++);
  }
  glEnd();
}

void draw_sutherland_hodgman() {
  GLfloat wxmin=50, wymin=-70, wxmax=230, wymax=70;
  glColor3f(0.0f, 0.3f, 1.0f);
  glRectf(wxmin, wymin, wxmax, wymax);
  // Draw polygon
  Point polygon[MAX_POLYGON_VERTICES] = {{70,120}, {160,-120}, {280,0}};
  int n_vertices = 3;
  draw_polygon(polygon, n_vertices, 1, GL_LINE, 0.0f, 0.9f, 0.2f);
  // Draw clipped polygon
  int discarded = sutherland_hodgman(polygon,&n_vertices,wxmin,wymin,wxmax,wymax);
  if (!discarded) {
    draw_polygon(polygon, n_vertices, 1, GL_FILL, 1.0f, 0.1f, 0.0f);
  }
}

void display_func() {
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  draw_cohen_sutherland();
  draw_sutherland_hodgman();
  glFlush();
}

int main(int argc, char * argv[]) {
  init_gl(argc, argv);
  glutReshapeFunc(reshape_func);
  glutDisplayFunc(display_func);
  glutMainLoop();
  return 0;
}

