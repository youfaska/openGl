#include "stdio.h"
#include "solution.h"
#include <assert.h>

#define LEFT 8
#define RIGHT 4
#define BOTTOM 2
#define TOP 1

int LRBT(Point* p, GLfloat wxmin, GLfloat wymin, GLfloat wxmax, GLfloat wymax) {
	int result = 0;
	
	if (p->x < wxmin){
		result = 8; // LEFT
	}
	if (p->x > wxmax){
		result = 4; // RIGHT
	}
	if (p->y < wymin){
		result = 2; // BOTTOM
	}
	if (p->y > wymax){
		result = 1; // TOP
	}
  return result;
}

void cut_p1_side(Point* p1, const Point* p2, GLfloat wxmin, GLfloat wymin, GLfloat wxmax, GLfloat wymax) {
	float m = ( p2->y - p1->y ) / ( p2->x - p1->x );
	if (LRBT(p1,   wxmin,  wymin,  wxmax,  wymax) == 8){ // si esta la izquierda de mi vista
		p1->y = p1->y + m*(wxmin-p1->x);
		p1->x =  wxmin;
	}
	if (LRBT(p1,   wxmin,  wymin,  wxmax,  wymax) == 4){// si esta la derecha de mi vista
		p1->y = p1->y + m*(wxmax-p1->x);
		p1->x =  wxmax;
	}
	if (LRBT(p1,   wxmin,  wymin,  wxmax,  wymax) == 2){// si esta abajo de mi vista
		p1->x = p1->x + (1.0/m)*(wymin-p1->y);
		p1->y =  wymin;
	}
	if (LRBT(p1,   wxmin,  wymin,  wxmax,  wymax) == 1){// si esta arriba de mi vista
		p1->x = p1->x + (1.0/m)*(wymax-p1->y);
		p1->y =  wymax;
	}
}

/*
 * Returns a boolean indicating if the line is completely discarded, or not
 */
int cohen_sutherland(Point* p1, Point* p2, GLfloat wxmin, GLfloat wymin, GLfloat wxmax, GLfloat wymax) {
	if(LRBT( p1,  wxmin,  wymin,  wxmax,  wymax) & LRBT( p2,  wxmin,  wymin,  wxmax,  wymax)){
		return (int) NULL;
	}
	if((LRBT( p1,  wxmin,  wymin,  wxmax,  wymax) | LRBT( p2,  wxmin,  wymin,  wxmax,  wymax)) == 0){
		return (p1,p2);
	}
	if(LRBT( p1,  wxmin,  wymin,  wxmax,  wymax)  == 0){
		return cohen_sutherland( p2,p1,  wxmin,  wymin,  wxmax,  wymax);
	}
  cut_p1_side(p1,  p2,  wxmin,  wymin,  wxmax,  wymax);
  return cohen_sutherland( p1,p2,  wxmin,  wymin,  wxmax,  wymax); 
}

/*
 * Returns a boolean indicating if the line is completely discarded, or not
 */
int sutherland_hodgman(Point* polygon,int* p_n_vertices, GLfloat wxmin, GLfloat wymin, GLfloat wxmax, GLfloat wymax) {
  return 0;
}


