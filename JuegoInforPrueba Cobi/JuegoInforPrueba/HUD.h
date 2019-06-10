#pragma once

#include <sstream>
#include <iomanip>
#include "Timer.h"
#include "Personaje.h"
#include "ETSIDI.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

enum estadoJuego { INICIO, JUGANDO, PARADO, FIN };

class HUD
{
private:
	int frame;
	Timer miContador;
	int colorActual;
	Timer contadorColor;
	std::stringstream ss;
	std::stringstream ssf;
	SpriteSequence* bonusF;
	SpriteSequence* bonusV;
	Sprite*contMon;
	Sprite* cF;
	Sprite* cM;
	Sprite* cD;
	Sprite* menu;
	estadoJuego miEstadoJuego;

public:
	HUD();
	void dibuja(Personaje p, Timer tJugando, int nMonedas);
	void parar() { if (miEstadoJuego == JUGANDO) miEstadoJuego = PARADO; }
	void iniciar() { if (miEstadoJuego == INICIO) miEstadoJuego = JUGANDO; }
	void volverAJugar() { if (miEstadoJuego == PARADO) miEstadoJuego = JUGANDO; }
	void gameOver() { if (miEstadoJuego == JUGANDO) miEstadoJuego = FIN; }
};


