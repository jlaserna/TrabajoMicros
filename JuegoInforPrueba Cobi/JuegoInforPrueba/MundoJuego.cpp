#include <iostream>
#include "MundoJuego.h"
#include "glut.h"
#include <math.h>
#include "Interaccion.h"

void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	escenario.dibuja();
	personaje.dibuja();
	listaBloques.dibuja();
}

void Mundo::Mueve()
{
	escenario.Mueve(0.025f);
	personaje.mueve(0.075f);
	listaBloques.mueve(0.025f);
	listaBloques.alctualizarBloques(personaje.getPos());

	Interaccion::colision(personaje,escenario);
	if (const Celda * miCeldaColison = listaBloques.colision(personaje))
		personaje.miColor = miCeldaColison->miColor;
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=7.5;
	z_ojo=30;

}

void Mundo::tecla(bool keystates[])
{
	if (keystates['a'])
	{
		personaje.izquierda();
	}
	else if (keystates['d'])
	{
		personaje.derecha();
	}
	else if (keystates['w'])
	{
		personaje.salta();
	}

}

void Mundo::teclaEspecial(unsigned char key)
{
	switch(key)
	{
	case (GLUT_KEY_LEFT):
	
		personaje.izquierda();
		break;
	
	case (GLUT_KEY_RIGHT):
		
		personaje.derecha();
		break;

	case GLUT_KEY_UP:
		
		personaje.izquierda();
		break;

	}
}