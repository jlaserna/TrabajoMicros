#include <iostream>
#include "MundoJuego.h"
#include "glut.h"
#include <math.h>
#include "Interaccion.h"
#include "Timer.h"
#include "Vacio.h"

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

	miHUD.dibuja(personaje, tiempoJuego, contadorMonedas, bonusActivos);
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
	switch (listaBloques.colision(personaje)) {
		case OBSTACULO:
			if (!jugadorInvencible) {
				miHUD.gameOver();
				tiempoJuego.congelar();
				jugando = false;
			}
			break;
		case BONUSFANTASMA:
			bonusActivos[1] = true;
			jugadorInvencible = true;
			tiempoBonusFantasma.start();
			break;
		case BONUSMONEDA:
			contadorMonedas++;
			break;
		case BONUSVELOCIDAD:
			bonusActivos[0] = true;
			listaBloques.setVelMax(10.0f);
			listaEscenario.setVelMax(10.0f);
			tiempoBonusVelocidad.start();
			break;
	}
	if (tiempoBonusFantasma.isTriger()) {
		bonusActivos[1] = false;
		jugadorInvencible = false;
		tiempoBonusFantasma.stop();
	}
	if (tiempoBonusVelocidad.isTriger()) {
		bonusActivos[0] = false;
		listaBloques.setVelMax(50.0f);
		listaEscenario.setVelMax(50.0f);
		tiempoBonusVelocidad.stop();
	}
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=7.5;
	z_ojo=20;

	jugadorInvencible = false;
	jugando = false;
	contadorMonedas = 0;
	tiempoBonusFantasma.setInterval(10000);
	tiempoBonusVelocidad.setInterval(10000);
	tiempoBonusFantasma.stop();
	tiempoBonusVelocidad.stop();
	tiempoJuego.reset();
}

void Mundo::tecla(bool keystates[])
{
	switch (jugando) {

	case true:
		if (keystates[27]) {
			miHUD.parar();
			jugando = false;
			tiempoJuego.congelar();
		}
		break;

	case false:
		if (keystates[13]) {
			miHUD.volverAJugar();
			jugando = true;
			tiempoJuego.desCongelar();
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
}
