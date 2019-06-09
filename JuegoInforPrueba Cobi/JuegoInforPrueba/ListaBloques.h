#pragma once
#include "Bloque.h"
#include "Vector3D.h"

#define MAX_ELEMENTOS 8

class ListaBloques
{
private:
	Bloque* lista[MAX_ELEMENTOS];
	int numero;

public:
	ListaBloques();
	bool agregar(Bloque* d);
	bool generarNuevoBloque();
	void destruirUltimoBloque();
	void destruirContenido();
	void alctualizarBloques(Vector3D pos);
	bool existeElemento(Bloque* d);
	void dibuja();
	void mueve(float t);
	void eliminar(int index);
	void eliminar(Bloque* d);
	Bloque* operator [](int i);
	int getNumero() { return numero; }
	~ListaBloques();

};
