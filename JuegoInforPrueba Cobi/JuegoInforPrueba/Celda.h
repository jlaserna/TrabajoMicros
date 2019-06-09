#pragma once
#include "Objeto.h"
class Celda :
	public Objeto
{
public:
	Celda();
	void dibuja();
	virtual ~Celda();

	friend class Interaccion;
};

