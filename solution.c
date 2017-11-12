
#include <math.h>
#include "solution.h"
#include <stdio.h>
 
/*Dibujar una circunferencia*/ 
void draw_hoop(GLuint center_x, GLuint center_y, GLuint radius) {

	float calx = 0.0, caly = 0.0;
 
	glColor3f(1.0,0.0,1.0); // rojo, verde, azul
	glBegin(GL_POINTS);
	double i = 0.0;
	for ( i = 0.0; i < 10 ; i+=0.001  ){
		calx = radius * cos(i);
		caly = radius * sin(i);
		glVertex2f(calx,caly);
	}
	glEnd();

}
/* Dibujar las marcas del reloj */
void draw_marks(GLuint center_x, GLuint center_y, GLuint radius) {
	glColor3f(1.0,0.0,1.0); 
	glBegin(GL_LINES);
	glVertex2i(radius-5,0);glVertex2i(radius,0);
	glVertex2i(0,radius-5);glVertex2i(0,radius);
	glVertex2i(0,5-radius);glVertex2i(0,-radius);
	glVertex2i(-radius+5,0);glVertex2i(-radius,0);
	glEnd();

}
void draw_hands(GLuint center_x, GLuint center_y, GLuint radius, GLuint hour, GLuint minute) {
 
}
