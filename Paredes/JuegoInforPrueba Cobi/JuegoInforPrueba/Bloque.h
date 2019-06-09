#pragma once
#include "Objeto.h"
#include "Celda.h"

class Bloque :
	public Objeto
{
private:
	Celda *listaCeldas[3];
public:
	Bloque();
	Bloque(Bloque b, Vector3D v);

	Celda getCelda(int i);
	void dibuja();
	void mueve(float t);
	~Bloque();
};