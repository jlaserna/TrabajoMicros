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

	miHUD.dibuja(personaje, tiempoJuego, contadorMonedas);
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
	Celda* miCeldaColison = listaBloques.colision(personaje);
	if( miCeldaColison != NULL)
		switch (miCeldaColison->getTipoCelda())
		{
		case BONUSVELOCIDAD:
			listaBloques.setVelMax(10.0f);
			listaEscenario.setVelMax(10.0f);
			break;
		case BONUSMONEDA:
			contadorMonedas++;
			break;
		case BONUSFANTASMA:
			break;
		case OBSTACULO:
			miHUD.gameOver();//!personajeInvencible
			break;
		}
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=7.5;
	z_ojo=30;

	jugando = false;
	contadorMonedas = 0;

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

void Mundo::setBonusActivo(int index) {
	bonusActivos[index] = true;

	if (bonusActivos[0]) {
		listaBloques.setVelMax(10.0f);
		//bonusTimer.reset();
	}

	if (bonusActivos[1]) {
		jugadorInvencible = true;
		//bonusTimer.reset();
	}

}