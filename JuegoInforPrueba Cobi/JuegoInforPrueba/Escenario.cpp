#include "Escenario.h"
#include "Pared.h"
#include "glut.h"

Escenario::Escenario(void)
{
	this->setPos(Vector3D(0, 0, 0));
	this->setVel(Vector3D(0, 0, 30.0f));
	this->setAccel(Vector3D(0, 0, 0));
	
	paredes[0] = new Pared();//suelo
	paredes[0]->setPos(this->getPos() + Vector3D(0, 0, 0));
	paredes[0]->setLim(Vector3D(-10.0f, 0, 165.0f),Vector3D(10.0f, 0, -105.0f));
	paredes[0]->setColor(255,0,0);

	paredes[1] = new Pared();//techo
	paredes[1]->setPos(this->getPos() + Vector3D(0, 15.0f, 0));
	paredes[1]->setColor(0, 255,0);
	paredes[1]->setLim(Vector3D(-10.0f, 0, 165.0f),Vector3D(10.0f, 0, -105.0f));

	paredes[2] = new Pared();//pared derecha
	paredes[2]->setPos(this->getPos() + Vector3D(-10.0, 7.5, 0));
	paredes[2]->setColor(0,0,255);
	paredes[2]->setLim(Vector3D(0, -7.5f, 165.0f),Vector3D(0, 7.5f, -105.0f));

	paredes[3] = new Pared();//pared izquierda
	paredes[3]->setPos(this->getPos() + Vector3D(10.0, 7.5, 0));
	paredes[3]->setColor(0, 0, 255);
	paredes[3]->setLim(Vector3D(0, -7.5f, 165.0f),Vector3D(0, 7.5f, -105.0f));

}

Escenario::Escenario(Escenario e, Vector3D v)
{
	this->setPos(e.getPos() + v);
	this->setVel(Vector3D(0, 0, 30.0f));
	this->setAccel(Vector3D(0, 0, 0));
	
	paredes[0] = new Pared();
	paredes[0]->setPos(e.getPared(0).getPos() + v);
	paredes[0]->setLim(Vector3D(-10.0f, 0, 165.0f),Vector3D(10.0f, 0, -105.0f));
	paredes[0]->setColor(255,0,0);
	paredes[1] = new Pared();
	paredes[1]->setPos(e.getPared(1).getPos() + v);
	paredes[1]->setColor(0,255,0);
	paredes[1]->setLim(Vector3D(-10.0f, 0, 165.0f),Vector3D(10.0f, 0, -105.0f));
	paredes[2] = new Pared();
	paredes[2]->setPos(e.getPared(2).getPos() + v);
	paredes[2]->setColor(0,0,255);
	paredes[2]->setLim(Vector3D(0, -7.5f, 165.0f),Vector3D(0, 7.5f, -105.0f));
	paredes[3] = new Pared();
	paredes[3]->setPos(e.getPared(3).getPos() + v);
	paredes[3]->setColor(0,0,255);
	paredes[3]->setLim(Vector3D(0, -7.5f, 165.0f),Vector3D(0, 7.5f, -105.0f));

}

Pared Escenario::getPared(int i)
{
	return *paredes[i];
}

void Escenario::dibuja()
{
	for(int i=0; i<MAX_PAREDES; i++)
	{
		paredes[i]->dibuja();
	}
	/*suelo.dibuja();
	techo.dibuja();
	pared_dcha.dibuja();
	pared_izq.dibuja();*/
}

void Escenario::mueve(float t)
{
	Objeto::mueve(t);
	for (int i = 0; i < MAX_PAREDES; i++)
	{
		paredes[i]->mueve(t);
	}
}

Escenario::~Escenario(void)
{

}