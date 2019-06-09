#pragma once
#include "Celda.h"
class Obstaculo :
	public Celda
{
public:
	Obstaculo();
	void dibuja();
	tipoCelda getTipoCelda() { return OBSTACULO; }
	virtual ~Obstaculo();
};

