#include <iostream>
#include <math.h>
#include "glut.h"
#include "ETSIDI.h"
#include "HUD.h"

HUD::HUD()
{
	miEstadoJuego = INICIO;
	frame = 0;
	miContador.setInterval(1000);
	contadorColor.setInterval(500);
	colorActual = 0;
	cF = new Sprite("resources/textures/HUDzombie3.png", 565, -450, 60, 100);
	cM = new Sprite("resources/textures/HUDzombie2.png", 565, -550, 50, 100);
	cD = new Sprite("resources/textures/HUDzombie1.png", 565, -650, 40, 100);
	menu = new Sprite("resources/textures/MenuInicio.png");
	bonusV = new SpriteSequence("resources/textures/BonusVelocidad.png", 2, 1, 10, true, -565, 750, 70, 100);
	bonusE = new SpriteSequence("resources/textures/BonusDisparo.png", 2, 1, 10, true, -565, 650, 70, 100);
}

void HUD::dibuja(Personaje p, Timer tJugando, int* nEnemigos)
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(-600, 600, -800, 800);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_LIGHTING);

	if (miEstadoJuego == INICIO) {
		menu->setCenter(620, 860);
		menu->setSize(1280, 1920);
		menu->draw();
	}

	else if (miEstadoJuego == JUGANDO) {

		//Tiempo
		ss.str("");
		ss << tJugando.getTimeM() << ":" << tJugando.getTimeS() << endl;
		setTextColor(255, 255, 255);
		setFont("resources/fonts/Bitwise.ttf", 20);
		printxy(ss.str().c_str(), -60, 700, 0);

		
		//Bonus velocidad
		//if (j.getBonusActivo(0))
			//bonusV->setState(0);
		//else
			bonusV->setState(1);
		bonusV->draw();

		//Bonus disparo
		//if (j.getBonusActivo(1))
			//bonusE->setState(0);
		//else
			bonusE->setState(1);
		bonusE->draw();

		//Contador enemigo tocho
		cF->draw();
		ss.str("");
		ss << nEnemigos[2] << endl;
		setFont("resources/fonts/Bitwise.ttf", 12);
		printxy(ss.str().c_str(), 485, -465, 0);

		//Contador enemigo equilibrado
		cM->draw();
		ss.str("");
		ss << nEnemigos[1] << endl;
		setFont("resources/fonts/Bitwise.ttf", 12);
		printxy(ss.str().c_str(), 485, -565, 0);

		//Contador enemigo 
		cD->draw();
		ss.str("");
		ss << nEnemigos[0] << endl;
		setFont("resources/fonts/Bitwise.ttf", 12);
		printxy(ss.str().c_str(), 485, -660, 0);
	}
	else if (miEstadoJuego == PARADO) {
		menu = new Sprite("resources/textures/Pause.png");
		menu->setCenter(300, 400);
		menu->setSize(600, 800);
		menu->draw();
	}

	else if (miEstadoJuego == FIN) {			//GAME OVER
		if (contadorColor.isTriger()) {
			switch (colorActual % 5) {
			case 0:
				setTextColor(255, 0, 0);
				break;
			case 1:
				setTextColor(0, 255, 0);
				break;
			case 2:
				setTextColor(0, 0, 255);
				break;
			case 3:
				setTextColor(255, 255, 0);
				break;
			case 4:
				setTextColor(255, 0, 255);
				break;
			}
			colorActual++;
		}

		menu = new Sprite("resources/textures/gameOver.png");
		menu->setCenter(960, 960);
		menu->setSize(1920, 1920);
		menu->draw();

		//Contador enemigo tocho
		cF->draw();
		ss.str("");
		ss << nEnemigos[2] << endl;
		setFont("resources/fonts/Bitwise.ttf", 12);
		printxy(ss.str().c_str(), 485, -465, 0);

		//Contador enemigo equilibrado
		cM->draw();
		ss.str("");
		ss << nEnemigos[1] << endl;
		setFont("resources/fonts/Bitwise.ttf", 12);
		printxy(ss.str().c_str(), 485, -565, 0);

		//Contador enemigo 
		cD->draw();
		ss.str("");
		ss << nEnemigos[0] << endl;
		setFont("resources/fonts/Bitwise.ttf", 12);
		printxy(ss.str().c_str(), 485, -660, 0);

		//Tiempo
		ss.str("");
		ss << tJugando.getTimeM() << ":" << tJugando.getTimeS() << endl;
		setFont("resources/fonts/Bitwise.ttf", 20);
		printxy(ss.str().c_str(), -60, 700, 0);
	}

	//FPS
	frame++;

	if (miContador.isTriger()) {
		ssf.str("");
		ssf << "FPS: " << setprecision(5) << frame * 1000.0 / miContador.getElapsedTime() << endl;
		frame = 0;
	}

	if (miEstadoJuego == JUGANDO) {
		setTextColor(255, 0, 0);
		setFont("resources/fonts/Bitwise.ttf", 12);
		printxy(ssf.str().c_str(), 460, 750, 0);
	}

	glEnable(GL_LIGHTING);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}