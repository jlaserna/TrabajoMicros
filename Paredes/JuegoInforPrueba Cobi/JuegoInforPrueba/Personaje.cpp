#include <iostream>
#include "Personaje.h"
#include "glut.h"
#include <ctime>


Personaje::Personaje(void)
{
	subiendo = false;
	bajando = false;
	moviendoDerecha = false;
	moviendoIzquierda = false;

	altura=1.0f;
	this->setPos(Vector3D(0, 2.0f, 7.0f));
	this->setVel(Vector3D(0, 0, 0));
	this->setAccel(Vector3D(0, GLOBAL_ACCEL, 0));
	miColor.r = 255;
}

void Personaje::dibuja()
{
	glPushMatrix();
	glTranslatef(this->getPos().x, this->getPos().y, this->getPos().z);
	glColor3ub(miColor.r, miColor.g, miColor.b);
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
	if (!bajando && !subiendo && moviendoDerecha) {
		this->sumVel(Vector3D(1.0f, 0, 0));
	}
	if (!bajando && !subiendo && moviendoIzquierda) {
		this->sumVel(Vector3D(-1.0f, 0, 0));
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
	if (!subiendo && !bajando && !moviendoIzquierda) {
		this->sumVel(Vector3D(5.0f, 0, 0));
		moviendoDerecha = true;
	}
		
}

void Personaje::izquierda()
{
	if (!subiendo && !bajando && !moviendoDerecha) {
		this->sumVel(Vector3D(-5.0f, 0, 0));
		moviendoIzquierda = true;
	}
}

Personaje::~Personaje(void)
{
}


/*Personaje::Personaje(void)
{
	altura=1.0f;
	this->setPos(Vector3D(10, 2.0f, 7.0f));
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
}*/

