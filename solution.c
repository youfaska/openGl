
#include <math.h>
#include "solution.h"
 
void draw_hoop(GLuint center_x, GLuint center_y, GLuint radius) {
	float calx = 0.0, caly = 0.0;
 	//Dibujar una circunferencia
	glColor3f(1.0,0.0,1.0); // rojo verde azul
	glBegin(GL_POINTS);
	double i = 0.0;
	for ( i = 0.0; i < 10 ; i+=0.001  ){
		calx = radius * cos(i);
		caly = radius * sin(i);
		glVertex2f(calx,caly);
	}
	glEnd();	
}
void draw_marks(GLuint center_x, GLuint center_y, GLuint radius) {
 
}
void draw_hands(GLuint center_x, GLuint center_y, GLuint radius, GLuint hour, GLuint minute) {
 
}
