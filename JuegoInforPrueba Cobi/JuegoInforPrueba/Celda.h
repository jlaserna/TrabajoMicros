#pragma once
#include "Objeto.h"

enum tipoCelda { OBSTACULO, BONUS, VACIO , NONE, BONUSMONEDA, BONUSVELOCIDAD, BONUSFANTASMA};

class Celda :
	public Objeto
{
public:
	tipoCelda miTipoCelda = NONE;
public:
	Celda();
	void dibuja();
	virtual ~Celda();
	tipoCelda getTipoCelda() { return miTipoCelda; };
	friend class Interaccion;
};

