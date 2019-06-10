#include "Objeto.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

#define GLOBAL_ACCEL -9.81f

#pragma once
class Personaje : public Objeto
{
private:
	float altura;
	bool subiendo;
	bool bajando;
	bool moviendoDerecha;
	bool moviendoIzquierda;
	SpriteSequence sprite;

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