#pragma once
#include "Bloque.h"
#include "Personaje.h"
#include "Vector3D.h"

#define MAX_ELEMENTOS 19

class ListaBloques
{
private:
	Bloque* lista[MAX_ELEMENTOS];
	int numero;
	float velMax;

public:
	ListaBloques();
	bool agregar(Bloque* d);
	bool generarNuevoBloque();
	void destruirUltimoBloque();
	void destruirContenido();
	Celda* colision(Personaje per);
	void alctualizarBloques(Vector3D pos);
	bool existeElemento(Bloque* d);
	void dibuja();
	void mueve(float t);
	void eliminar(int index);
	void eliminar(Bloque* d);
	Bloque* operator [](int i);
	int getNumero() { return numero; }
	void setVelMax(float velMax) { this->velMax = velMax; }
	~ListaBloques();

};
