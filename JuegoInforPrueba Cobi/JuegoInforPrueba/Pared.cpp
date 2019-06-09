#include "Pared.h"
#include "glut.h"

Pared::Pared(void)
{
	rojo=verde=azul=255;
}

void Pared::dibuja()
{
	/*glDisable(GL_LIGHTING);
	glColor3ub(rojo,verde,azul);
	glBegin(GL_POLYGON);
		//glColor3ub(255,0,0); 
		glVertex3d(limite1.x,limite1.y,limite3.z);
		//glColor3ub(255,0,0); 
		glVertex3d(limite2.x,limite2.y,limite3.z);
		//glColor3ub(0,0,255); 
		glVertex3d(limite2.x,limite2.y,limite4.z);// el valor de esta z es para cambiar la profundidad del bloque
		//glColor3ub(0,0,255); 
		glVertex3d(limite1.x,limite1.y,limite4.z);// el valor de esta z es para cambiar la profundidad del bloque
glEnd();
glEnable(GL_LIGHTING);*/

	glDisable(GL_LIGHTING);
	glColor3ub(rojo,verde,azul);
	glBegin(GL_POLYGON);
		//glColor3ub(255,0,0); 
		glVertex3d(esquina1.x,esquina1.y,esquina1.z);
		//glColor3ub(255,0,0); 
		glVertex3d(esquina2.x,esquina2.y,esquina2.z);
		//glColor3ub(0,0,255); 
		glVertex3d(esquina3.x,esquina3.y,esquina3.z);// el valor de esta z es para cambiar la profundidad del bloque
		//glColor3ub(0,0,255); 
		glVertex3d(esquina4.x,esquina4.y,esquina4.z);// el valor de esta z es para cambiar la profundidad del bloque
glEnd();
glEnable(GL_LIGHTING);
}

Pared::~Pared(void)
{
}

void Pared::SetColor( unsigned char r,unsigned char v, unsigned char a)
{
	rojo=r;
	verde=v;
	azul=a;
}





	////////////////////////////////////////////////////////////

	/*PARA PROBAR CON ESQUINAS
	glDisable(GL_LIGHTING);
	glColor3ub(rojo,verde,azul);
	glBegin(GL_POLYGON);
		//glColor3ub(255,0,0); 
		glVertex3d(esquina1.x,esquina1.y,esquina1.z);
		//glColor3ub(255,0,0); 
		glVertex3d(esquina2.x,esquina.y,esquina.z);
		//glColor3ub(0,0,255); 
		glVertex3d(esquina3.x,esquina3.y,esquina3.z);// el valor de esta z es para cambiar la profundidad del bloque
		//glColor3ub(0,0,255); 
		glVertex3d(esquina4.x,esquina4.y,esquina4.z);// el valor de esta z es para cambiar la profundidad del bloque
glEnd();
glEnable(GL_LIGHTING);
*/