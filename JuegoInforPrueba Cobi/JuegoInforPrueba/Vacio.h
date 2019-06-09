#pragma once
#include "Celda.h"
class Vacio :
	public Celda
{
public:
	Vacio();
	void dibuja() {};
	virtual ~Vacio();
	tipoCelda getTipoCelda() { return VACIO; }

	friend class Interaccion;
};

