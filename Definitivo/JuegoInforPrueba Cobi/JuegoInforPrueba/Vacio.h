#pragma once
#include "Celda.h"
class Vacio :
	public Celda
{
public:
	Vacio();
	Vacio(Vector3D pos, Vector3D vel, Vector3D acel) { setPos(pos); setVel(vel); setAccel(acel); }
	virtual ~Vacio();

	friend class Interaccion;
};

