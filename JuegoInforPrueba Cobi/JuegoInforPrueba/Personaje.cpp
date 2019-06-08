#include <iostream>
#include "Personaje.h"
#include "glut.h"
#include <ctime>

Personaje::Personaje(void)
{
	altura=1.0f;
	this->setPos(Vector3D(0, 2.0f, 7.0f));
	this->setVel(Vector3D(0, 0, 0));
	this->setAccel(Vector3D(0, GLOBAL_ACCEL, 0));
}

void Personaje::dibuja()
{
	glPushMatrix();
	glTranslatef(this->getPos().x, this->getPos().y, this->getPos().z);
	glColor3f(1.0f,0.0f,0.0f);
		glutSolidTeapot(altura);
	glPopMatrix();
}

void Personaje::mueve(float t)
{
	Objeto::mueve(t);	
	if (subiendo)
		this->sumVel(Vector3D(0, 5.0f, 0));
	if (bajando && estaEnElSuelo()) {
		bajando = false;
	}
}

void Personaje::salta()
{
	if (!subiendo && estaEnElSuelo()) {
		subiendo = true;
		bajando = false;
	}
}

void Personaje::derecha()
{
	if (!subiendo && !bajando)
		this->sumVel(Vector3D(1.0f, 0, 0));
}

void Personaje::izquierda()
{
	if (!subiendo && !bajando)
		this->sumVel(Vector3D(-1.0f, 0, 0));
}


Personaje::~Personaje(void)
{
}

