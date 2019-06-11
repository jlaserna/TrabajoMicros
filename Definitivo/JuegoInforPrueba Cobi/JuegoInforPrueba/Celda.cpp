#include "Celda.h"
#include "glut.h"


Celda::Celda()
{
	miTipoCelda = NONE;
	activo = true;
	this->setPos(Vector3D(0, 0, 0));
	this->setVel(Vector3D(0, 0, 0));
	this->setAccel(Vector3D(0, 0, 0));
}

void Celda::dibuja()
{
}

Celda::~Celda()
{
	Objeto::~Objeto();
}
