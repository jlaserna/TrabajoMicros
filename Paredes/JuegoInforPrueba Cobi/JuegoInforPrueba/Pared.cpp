#include "Pared.h"
#include "glut.h"

Pared::Pared(void)
{
	rojo=verde=azul=255;
	//this->setPos(Vector3D(0, 0, 0));
	this->setVel(Vector3D(0, 0, 30.0f));		//velocidad del escenario 
	this->setAccel(Vector3D(0, 0, 0));		//aceleración del escenario
}

void Pared::dibuja()
{
	/*	glPushMatrix();
	glTranslatef(this->getPos().x, this->getPos().y, this->getPos().z);	//Revisar para quitar este 7
	glColor3f(1.0f,0.0f,0.0f);
		glutSolidTeapot(altura);
	glPopMatrix();*/

	glDisable(GL_LIGHTING);
	glColor3ub(rojo,verde,azul);
	glPushMatrix();
	glTranslatef(this->getPos().x, this->getPos().y, this->getPos().z);
	glBegin(GL_POLYGON);
		//glColor3ub(255,0,0); 
		glVertex3d(limite1.x,limite1.y,limite1.z);
		//glColor3ub(255,0,0); 
		glVertex3d(limite2.x,limite2.y,limite1.z);
		//glColor3ub(0,0,255); 
		glVertex3d(limite2.x,limite2.y,limite2.z);// el valor de esta z es para cambiar la profundidad del bloque
		//glColor3ub(0,0,255); 
		glVertex3d(limite1.x,limite1.y,limite2.z);// el valor de esta z es para cambiar la profundidad del bloque
glEnd();
	glPopMatrix();
glEnable(GL_LIGHTING);
}

Pared::~Pared(void)
{
}

void Pared::setColor( unsigned char r,unsigned char v, unsigned char a)
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