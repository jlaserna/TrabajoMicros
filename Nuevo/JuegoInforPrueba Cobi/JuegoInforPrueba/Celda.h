#pragma once
#include "Objeto.h"

enum tipoCelda { OBSTACULO, BONUS, VACIO , NONE};

class Celda :
	public Objeto
{
public:
	Celda();
	void dibuja();
	virtual ~Celda();
	virtual tipoCelda getTipoCelda() { return NONE; };
	friend class Interaccion;
};

