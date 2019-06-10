#include "Objeto.h"



Objeto::Objeto()
{
	miColor.r=0;
	miColor.g=0;
	miColor.b=0;

	radio = 1.0f;
	this->posicion = Vector3D(0, 0, 0);
	this->velocidad = Vector3D(0, 0, 0);
	this->aceleracion = Vector3D(0, 0, 0);
}

void Objeto::mueve(float t)
{
	posicion.x += velocidad.x * t + aceleracion.x * t * t * 0.5f;
	posicion.y += velocidad.y * t + aceleracion.y * t * t * 0.5f;
	posicion.z += velocidad.z * t + aceleracion.z * t * t * 0.5f;
	velocidad.x += aceleracion.x * t;
	velocidad.y += aceleracion.y * t;
	velocidad.z += aceleracion.z * t;
}

Objeto::~Objeto()
{
}
