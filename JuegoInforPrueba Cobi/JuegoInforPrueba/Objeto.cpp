#include "Objeto.h"



Objeto::Objeto()
{
	this->posicion = Vector3D(0, 0, 0);
	this->velocidad = Vector3D(0, 0, 0);
	this->aceleracion = Vector3D(0, 0, 0);
}


Objeto::~Objeto()
{
}
