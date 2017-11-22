#include <math.h>
#include "solution.h"
#include <stdio.h>
 
/*Dibujar una circunferencia*/ 
void draw_hoop(GLuint center_x, GLuint center_y, GLuint radius) {
	float calx = 0.0, caly = 0.0;
 
	glColor3f(1.0,0.0,1.0); // rojo, verde, azul
	glBegin(GL_LINE_LOOP); // hay que usar el loop para enlace con todos los puntos, si no deja huecos...
	//glBegin(GL_LINES);
	double i = 0.0, angulo = 0.0;
	double max = 0.5;
	for ( i = 0; i < max ; i+=0.01  ){ // vamos dibujando pixel a pixel
		angulo = 2*M_PI*i/max;
		calx = radius * cos(angulo);
		caly = radius * sin(angulo);
		glVertex2f(calx,caly);
	}
	glEnd();

}
/* Dibujar las marcas del reloj */
void draw_marks(GLuint center_x, GLuint center_y, GLuint radius) {
	glColor3f(1.0,0.0,1.0); // rojo, verde, azul
	glBegin(GL_LINES); // dibujamos  la linea, para ello necesitamos con GL_LINES tener dos puntos...
	int separacionCircunferencia = 6;
	glVertex2i(radius-separacionCircunferencia,center_y);glVertex2i(radius,center_y);
	glVertex2i(center_x,radius-separacionCircunferencia);glVertex2i(center_x,radius);
	glVertex2i(center_x,separacionCircunferencia-radius);glVertex2i(center_x,-radius);
	glVertex2i(-radius+separacionCircunferencia,center_y);glVertex2i(-radius,center_y);
	glEnd();

}
void draw_hands(GLuint center_x, GLuint center_y, GLuint radius, GLuint hour, GLuint minute) {
 	glColor3f(0.0,0.0,0.0); // rojo, verde, azul
 	glLineWidth(2.0);
	glBegin(GL_LINES);
	int aumentarTamanio = 90;
	glVertex2i(center_x,center_x);glVertex2i(minute+aumentarTamanio,center_y);
	glEnd();
	aumentarTamanio = aumentarTamanio + 30;
	glLineWidth(1.0);
	glBegin(GL_LINES);
	glVertex2i(center_x,center_y);glVertex2i(center_x,hour+aumentarTamanio);
	glEnd();
}
