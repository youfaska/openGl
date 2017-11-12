#include <GL/GL.h>
#include <GL/GLUT.h>
#include <time.h>
#include "solution.h"
#include <math.h>
 
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define MARGIN_WIDTH 40


//info para la circunferencia
float px=2 , py=5, radio=50, calx, caly; 
 
void dibujar_circunferencia() {
	//Dibujar una circunferencia
	glColor3f(1.0,0.0,1.0); // rojo verde azul
	glBegin(GL_POINTS);
	double i = 0.0;
	for ( i = 0.0; i < 10 ; i+=0.001  ){
		calx = radio * cos(i);
		caly = radio * sin(i);
		glVertex2f(calx,caly);
	}
	glEnd();	
}

 

