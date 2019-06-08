#include "Objeto.h"

#define GLOBAL_ACCEL -9.81f

#pragma once
class Personaje : public Objeto
{
	float altura;
	bool subiendo = false;
	bool bajando = false;

public:
	Personaje();
	
	void salta();
	void derecha();
	void izquierda();

	bool estaEnElSuelo() { return this->getPos().y <= 1.0f; };

	void dibuja();

	void mueve(float t);

	friend class Interaccion;

	virtual ~Personaje();
};