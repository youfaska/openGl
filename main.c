#include <GL/GL.h>
#include <GL/GLUT.h>


void init_gl(int argc, char * argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(50, 100);
  glutInitWindowSize(400, 300);
  glutCreateWindow("TRANSFORMACIONES");
  glClearColor(1.0, 1.0, 1.0, 0.0);
}

void trans_func() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-300,300,-300,300);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(-300,0);
	glVertex2i(300,0);
	glVertex2i(0,-300);
	glVertex2i(0,300);
    glEnd();
  	glColor3f(0.0, 0.1, 0.9);
	glRecti(50, 100, 200, 150);
	
	//Lo trasladamos...
	glTranslatef(-300.0, 0.0, 0.0 );
	glColor3f(1.0, 0.1, 0.2);
	glRecti(50, 100, 200, 150);
	
	//Rotar
	glLoadIdentity();
	gluOrtho2D(-300,300,-300,300);
	glRotatef(180, 0.0, 0.0, 1.0);
	glColor3f(0.2, 1.0, 0.2);
	glRecti(50, 100, 200, 150);
	
	//Lo escalamos...
	glLoadIdentity();
	gluOrtho2D(-300,300,-300,300);
	glScalef(0.5, 0.5, 1.0);
	glTranslatef(0.0, -300.0, 0.0 );
	glColor3f(0.2, 1.0, 1.2);
	glRecti(50, 100, 200, 150);
  	glFlush();
}

int main(int arg, char * argv[]){
	init_gl(arg, argv);
	glutDisplayFunc(trans_func);
	glutMainLoop();
	return 0;
}

