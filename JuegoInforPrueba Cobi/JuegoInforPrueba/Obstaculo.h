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
	SpriteSequence sprite;
public:
	Obstaculo();
	void dibuja();
	virtual ~Obstaculo();

};

