#pragma once
#include "Celda.h"
class Vacio :
	public Celda
{
public:
	Vacio();
	void dibuja() {};
	virtual ~Vacio();

	friend class Interaccion;
};

