#include <iostream>
#include "Personaje.h"
#include <GLUT/glut.h>
#include <ctime>

Personaje::Personaje(void)
{
	altura=1.0f;
	aceleracion.x=0;
	aceleracion.y=-20.0f;
	//aceleracion.z=0;
	/*posicion.x=0;
	posicion.y=0.5;
	posicion.z=7;*/
}

void Personaje::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x,posicion.y,7);
	glColor3f(1.0f,0.0f,0.0f);
		glutSolidTeapot(altura);
	glPopMatrix();
}

void Personaje::SetPos(float ix,float iy,float iz)
{
	posicion.x=ix;
	posicion.y=iy;
	posicion.z=iz;
}

Vector3D Personaje::GetPos()
{
	return posicion;
}

void Personaje::Mueve(float t)
{
	/*posicion.x=posicion.x+velocidad.x*t+0.5f*aceleracion.x*t*t;
	posicion.y=posicion.y+velocidad.y*t+0.5f*aceleracion.y*t*t;
	//posicion.z=posicion.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	velocidad.x=velocidad.x+aceleracion.x*t;
	velocidad.y=velocidad.y+aceleracion.y*t;
	//velocidad.z=velocidad.z+aceleracion.z*t;*/
	
	//posicion=posicion+velocidad*t+aceleracion*(0.5f*t*t);
	//velocidad=velocidad+aceleracion*t;
}

void Personaje::SetVel(float vx, float vy, float vz)
{
	velocidad.x=vx;
	velocidad.y=vy;
	velocidad.z=vz;
} 

int Personaje::saltos()
{
	int sr=0;
	if (posicion.y <= 1)
		sr = 0;
	else
		sr = 1;
	return sr;
}
int Personaje::giro()
{
	return velocidad.x;
}
int Personaje::jump()
{
	return velocidad.y;
}


Personaje::~Personaje(void)
{
}

