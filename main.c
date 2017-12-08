#include <GL/GL.h>
#include <GL/GLUT.h>


void init_gl(int argc, char * argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(50, 100);
  glutInitWindowSize(600, 300);
  glutCreateWindow("RECORTES");
  glClearColor(1.0, 1.0, 1.0, 0.0);
}

typedef struct _Point {
	GLfloat x;	
	GLfloat y;
	
} Point;

void draw_triangles(){
	Point triangle1[3] = {{-0.5, -0.25},{0.5, -0.25},{0.0,0.8}};
	Point triangle2[3] = {{0.0, -0.5},{0.5, 0.25},{-0.5,0.25}};
	
	glColor3f(0.0, 0.2, 1.0);
	glBegin(GL_TRIANGLES);
	int i =0;
	for (i = 0; i< 3 ; i++ ){
		glVertex2f(triangle1[i].x, triangle1[i].y );
	}
	glEnd();
	glColor3f(1.0, 0.2, 0.0);
	glBegin(GL_TRIANGLES);
	int k = 0;
	for ( k = 0; k< 3 ; k++ ){
		glVertex2f(triangle2[k].x, triangle2[k].y );
	}
	glEnd();
}

void display_func() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0,0,300,300);
	draw_triangles();
	gluOrtho2D(-5,5,-5,5);
	glViewport(300,0,300,300);
	glRotatef(90.0,0.0,0.0,1.0);
	draw_triangles();
  	glFlush();
}

int main(int arg, char * argv[]){
	init_gl(arg, argv);
	glutDisplayFunc(display_func);
	glutMainLoop();
	return 0;
}

