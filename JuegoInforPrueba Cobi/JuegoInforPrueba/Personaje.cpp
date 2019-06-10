#include <iostream>
#include "Personaje.h"
#include "glut.h"

Personaje::Personaje(void):sprite("resources/textures/personaje.png",6,4)
{
	sprite.setCenter(2.5, 1);
	sprite.setSize(5, 5);

	subiendo = false;
	bajando = false;
	moviendoDerecha = false;
	moviendoIzquierda = false;

	altura=1.0f;
	this->setPos(Vector3D(0, 2.0f, 7.0f));
	this->setVel(Vector3D(0, 0, 0));
	this->setAccel(Vector3D(0, GLOBAL_ACCEL, 0));
	//miColor.r = 255;
}

void Personaje::dibuja()
{
	glPushMatrix();
	glTranslatef(this->getPos().x, this->getPos().y, this->getPos().z);
	sprite.draw();
	/*glColor3ub(miColor.r, miColor.g, miColor.b);
		glutSolidTeapot(altura);*/
	glPopMatrix();
}

void Personaje::mueve(float t)
{
	Objeto::mueve(t);
	int estado = sprite.getState();

			
	if (subiendo)
		this->sumVel(Vector3D(0, 5.0f, 0));
	if (bajando && estaEnElSuelo()) {
		bajando = false;
	}
	if (!bajando && !subiendo && moviendoDerecha) {
		this->sumVel(Vector3D(1.0f, 0, 0));
	}
	if (!bajando && !subiendo && moviendoIzquierda) {
		this->sumVel(Vector3D(-1.0f, 0, 0));
	}
	
	if (getVel().x== 0 && getVel().z==0) {
			if ((estado != 12 && estado != 13 && estado != 14 && estado != 15 && estado != 16 && estado != 17) || estado == 17)
				sprite.setState(12, false);

		}
	else if (getVel().x > 0) {
			if ((estado != 6 && estado != 7 && estado != 8 && estado != 9 && estado != 10 && estado != 11 ) || estado == 11)
				sprite.setState(6, false);

		}
	else if (getVel().x < 0) {
			if ((estado != 18 && estado != 19 && estado != 20 && estado != 21 && estado != 22 && estado != 23) || estado == 23)
				sprite.setState(18, false);

		}
	/*else if(subiendo && !estaEnElSuelo){
		if ((estado != 0 && estado != 1 && estado != 2 && estado != 3 && estado != 4 && estado != 5) || estado == 5)
				sprite.setState(0, false);
	}*/
		sprite.loop();
}

void Personaje::salta()
{
	if (!subiendo && estaEnElSuelo()) {
		subiendo = true;
		bajando = false;
	}
}

void Personaje::derecha()
{
	if (!subiendo && !bajando && !moviendoIzquierda) {
		this->sumVel(Vector3D(5.0f, 0, 0));
		moviendoDerecha = true;
	}
		
}

void Personaje::izquierda()
{
	if (!subiendo && !bajando && !moviendoDerecha) {
		this->sumVel(Vector3D(-5.0f, 0, 0));
		moviendoIzquierda = true;
	}
}

Personaje::~Personaje(void)
{
}

