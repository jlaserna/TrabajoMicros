#include "Bloque.h"
#include "Obstaculo.h"
#include "Bonus.h"



Bloque::Bloque()
{
	this->setPos(Vector3D(0, 2.0f, -50.0f));
	this->setVel(Vector3D(0, 0, 30.0f));
	this->setAccel(Vector3D(0, 0, 0));
	listaCeldas[0] = new Obstaculo();
	listaCeldas[0]->setPos(this->getPos() + Vector3D(-5.0, 0,0));
	listaCeldas[1] = new Bonus();
	listaCeldas[1]->setPos(this->getPos() + Vector3D(0, 0, 0));
	listaCeldas[2] = new Obstaculo();
	listaCeldas[2]->setPos(this->getPos() + Vector3D(5.0, 0, 0));
}

Bloque::Bloque(Bloque b, Vector3D v)
{
	this->setPos(b.getPos() + v);
	this->setVel(Vector3D(0, 0, 30.0f));
	this->setAccel(Vector3D(0, 0, 0));
	listaCeldas[0] = new Obstaculo();
	listaCeldas[0]->setPos(this->getPos() + Vector3D(-5.0, 0, 0));
	listaCeldas[1] = new Bonus();
	listaCeldas[1]->setPos(this->getPos() + Vector3D(0, 0, 0));
	listaCeldas[2] = new Obstaculo();
	listaCeldas[2]->setPos(this->getPos() + Vector3D(5.0, 0, 0));
}

Celda Bloque::getCelda(int i)
{
	return *listaCeldas[i];
}

void Bloque::dibuja()
{
	for (int i = 0; i < 3; i++) {
		listaCeldas[i]->dibuja();
	}
}

void Bloque::mueve(float t)
{
	Objeto::mueve(t);
	listaCeldas[0]->setPos(this->getPos() + Vector3D(-5.0, 0, 0));
	listaCeldas[1]->setPos(this->getPos() + Vector3D(0, 0, 0));
	listaCeldas[2]->setPos(this->getPos() + Vector3D(5.0, 0, 0));
}

Bloque::~Bloque()
{
}
