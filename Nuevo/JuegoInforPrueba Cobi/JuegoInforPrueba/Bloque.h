#pragma once
#include "Objeto.h"
#include "Celda.h"
#include "ETSIDI.h"

//enum tipoCelda { OBSTACULO, BONUS, VACIO , NONE};

class Bloque :
	public Objeto
{
private:
	Celda *listaCeldas[3];
	void generarBloqueAleatorio(Bloque b);

public:
	Bloque();
	Bloque(Bloque b, Vector3D v);
	bool sonCompatibles(Bloque b, tipoCelda* mTipoCelda);
	Celda getCelda(int i);
	void dibuja();
	void mueve(float t);
	~Bloque();
};

