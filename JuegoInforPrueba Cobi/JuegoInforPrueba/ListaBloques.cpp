#include "ListaBloques.h"
#include "Bloque.h"
#include "Vector3D.h"


ListaBloques::ListaBloques() {
	numero = 0;
	for (int i = 0; i < MAX_ELEMENTOS; i++)
		lista[i] = 0;
}

bool ListaBloques::agregar(Bloque* d) {

	if (numero < MAX_ELEMENTOS && !existeElemento(d))
		lista[numero++] = d;
	else
		return false;
	return true;
}

bool ListaBloques::existeElemento(Bloque* d) {
	for (int i = 0; i < MAX_ELEMENTOS; i++)
		if (lista[i] == d)
			return true;
	return false;
}

void ListaBloques::eliminar(int index) {
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaBloques::eliminar(Bloque* d) {
	for (int i = 0; i < numero; i++)
		if (lista[i] == d) {
			eliminar(i);
			return;
		}
}

void ListaBloques::destruirContenido() {
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;

}

void ListaBloques::alctualizarBloques(Vector3D pos)
{
	if (pos.z + 30.0f <= lista[0]->getPos().z) {
		destruirUltimoBloque();
		generarNuevoBloque();
	}
}

Bloque* ListaBloques::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;
	return lista[i];
}

void ListaBloques::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaBloques::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

bool ListaBloques::generarNuevoBloque()
{
	if (numero == MAX_ELEMENTOS)
		return false;
	else {
		Bloque* nuevoBloque = new Bloque(*lista[numero-1], Vector3D(0, 0, -30.0f));
		agregar(nuevoBloque);
		return true;
	}
}

void ListaBloques::destruirUltimoBloque()
{
	if(numero > 1)
		eliminar(0);
}

ListaBloques::~ListaBloques()
{
}