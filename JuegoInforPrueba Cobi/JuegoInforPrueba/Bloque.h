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
	Celda* getCelda(int i);
	void desactivar(int index) { listaCeldas[index]->desactivar(); }
	bool estaActivo(int index) { return listaCeldas[index]->estaActivo(); }
	void dibuja();
	void mueve(float t);
	~Bloque();

	friend class Interaccion;
};

