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

	glDisable(GL_LIGHTING);
	glColor3ub(rojo,verde,azul);
	glPushMatrix();
	glTranslatef(this->getPos().x, this->getPos().y, this->getPos().z);
	glBegin(GL_POLYGON);
		glVertex3d(limite1.x,limite1.y,limite1.z);
		glVertex3d(limite2.x,limite2.y,limite1.z);
		glVertex3d(limite2.x,limite2.y,limite2.z);// el valor de esta z es para cambiar la profundidad del bloque
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
