#pragma once
#include "Celda.h"
#include "ETSIDI.h"
#include "Pared.h"
#include "Textura.h"
using ETSIDI::SpriteSequence;

#define NUM_CARAS 5

class Obstaculo : public Celda
{
private:
	//Pared lPared[5];
	//Textura tSuperior;
	//SpriteSequence sprite;
public:
	//Pared lPared[5];
	Obstaculo();
	void dibuja();
	//void setTextura(string lTexturas[5]);
	virtual ~Obstaculo();

};

