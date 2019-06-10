#include "Pared.h"
#include "glut.h"


Pared::Pared(void)
{
	//rojo=verde=azul=0;
	//this->setPos(Vector3D(0, 0, 0));
	this->setVel(Vector3D(0, 0, 0));	//velocidad del escenario   30.0f
	this->setAccel(Vector3D(0, 0, 1.0f));		//aceleración del escenario
}

void Pared::dibuja()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(textura.getTextura().c_str()).id);
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(this->getPos().x, this->getPos().y, this->getPos().z);
	glBegin(GL_POLYGON);
	glTexCoord2d(1, 0); glVertex3d(limite1.x,limite1.y,limite1.z);
	glTexCoord2d(0, 0); glVertex3d(limite2.x,limite2.y,limite1.z);
	glTexCoord2d(0, 1); glVertex3d(limite2.x,limite2.y,limite2.z);
	glTexCoord2d(1, 1); glVertex3d(limite1.x,limite1.y,limite2.z);
	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	/*glDisable(GL_LIGHTING);
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
glEnable(GL_LIGHTING);*/
}

Pared::~Pared(void)
{
}

/*void Pared::setColor( unsigned char r,unsigned char v, unsigned char a)
{
	rojo=r;
	verde=v;
	azul=a;
}*/
