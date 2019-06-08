#include <iostream>
#include "Personaje.h"
#include "glut.h"
#include <ctime>

Personaje::Personaje(void)
{
	altura=1.0f;
	this->setPos(Vector3D(0, 2.0f, 7.0f));
	this->setVel(Vector3D(0, 0, 0));
	this->setAccel(Vector3D(0, 0, 0));
}

void Personaje::dibuja()
{
	glPushMatrix();
	glTranslatef(this->getPos().x, this->getPos().y, this->getPos().z);	//Revisar para quitar este 7
	glColor3f(1.0f,0.0f,0.0f);
		glutSolidTeapot(altura);
	glPopMatrix();
}

int Personaje::saltos()
{
	int sr=0;
	if (this->getPos().x <= 1)
		sr = 0;
	else
		sr = 1;
	return sr;
}
int Personaje::giro()
{
	return this->getVel().x;
}
int Personaje::jump()
{
	return this->getVel().y;
}

Personaje::~Personaje(void)
{
}

