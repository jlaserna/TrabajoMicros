#include <iostream>
#include "MundoJuego.h"
#include "glut.h"
#include <math.h>
#include "Interaccion.h"
#include "Timer.h"

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

	listaEscenario.dibuja();
	personaje.dibuja();
	listaBloques.dibuja();

	int a[3] = { 0,0,5 };

	miHUD.dibuja(personaje, tiempoJuego, a);
}

void Mundo::Mueve()
{
	if (!jugando)
		return;
	personaje.mueve(0.075f);
	listaBloques.mueve(0.025f);
	listaEscenario.mueve(0.025f);
	listaBloques.alctualizarBloques(personaje.getPos());
	listaEscenario.actualizarEscenario(personaje.getPos());

	Interaccion::colisionEscenario(personaje);
	if (const Celda * miCeldaColison = listaBloques.colision(personaje))
		personaje.miColor = miCeldaColison->miColor;
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=7.5;
	z_ojo=30;

	jugando = false;

	w = 800;
	h = 600;

}

void Mundo::tecla(bool keystates[])
{
	switch (jugando) {

	case true:
		if (keystates[27]) {
			miHUD.parar();
			jugando = false;
			tiempoJuego.stop();
		}
		break;

	case false:
		if (keystates[13]) {
			miHUD.volverAJugar();
			jugando = true;
			tiempoJuego.start();
		}
		break;
	}

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
	else if (keystates['+'])
	{
		if (!jugando) {
			tiempoJuego.start();
			miHUD.iniciar();
			jugando = true;
		}
	}
	else if (keystates['-'])
	{
		miHUD.gameOver();
		jugando = false;
		tiempoJuego.stop();
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

void Mundo::ratonClick(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && miHUD.getEstado() == INICIO) {
		if (state == GLUT_DOWN) {
			if (x > w/2 && y > h/2) {
				listaBloques.setVelMax(10.0f);
			}

			if (x > w / 2 && y < h / 2) {
				listaBloques.setVelMax(50.0f);
			}

			if (x < w / 2 && y > h / 2) {
				listaBloques.setVelMax(100.0f);
			}

			if (x < w / 2 && y < h / 2) {
				listaBloques.setVelMax(200.0f);
			}

			tiempoJuego.start();
			miHUD.iniciar();
			jugando = true;
		}
	}

}