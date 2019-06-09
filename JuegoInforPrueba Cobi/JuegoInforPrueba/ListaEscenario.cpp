#include "ListaEscenario.h"



ListaEscenario::ListaEscenario()
{
	numero = 0;
	for (int i = 0; i < MAX_ESCENARIO; i++) escenario[i] = 0;
	agregar(new Escenario());
	for (int i = 0; i < MAX_ESCENARIO-1; i++){
		generarNuevoEscenario();
	}
}


bool ListaEscenario::agregar(Escenario *es){
	if(numero<MAX_ESCENARIO && !existeElemento(es)){
		escenario[numero++]=es;
		return true;
	}
	else return false;
}

bool ListaEscenario::existeElemento(Escenario* es) {
	for (int i = 0; i < MAX_ESCENARIO; i++)
		if (escenario[i] == es)
			return true;
	return false;
}

void ListaEscenario::eliminar(int index) {
	if ((index < 0) || (index >= numero))
		return;
	delete escenario[index];
	numero--;
	for (int i = index; i < numero; i++)
		escenario[i] = escenario[i + 1];
}

void ListaEscenario::eliminar(Escenario* es) {
	for (int i = 0; i < numero; i++)
		if (escenario[i] == es) {
			eliminar(i);
			return;
		}
}

void ListaEscenario::destruirContenido() {
	for (int i = 0; i < numero; i++)
		delete escenario[i];
	numero = 0;
}

void ListaEscenario::actualizarEscenario(Vector3D pos)
{
	if (pos.z + 300.0f <= escenario[0]->getPos().z) {
		destruirUltimoEscenario();
		generarNuevoEscenario();
	}
}

Escenario* ListaEscenario::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;
	return escenario[i];
}

void ListaEscenario::dibuja()
{
	for (int i = 0; i < numero; i++)
		escenario[i]->dibuja();
}

void ListaEscenario::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		escenario[i]->mueve(t);
}

bool ListaEscenario::generarNuevoEscenario()
{
	if (numero == MAX_ESCENARIO)
		return false;
	else {
		Escenario* nuevoEscenario = new Escenario(*escenario[numero-1], Vector3D(0, 0, -270.0f));
		agregar(nuevoEscenario);
		return true;
	}
}

void ListaEscenario::destruirUltimoEscenario()
{
	if(numero > 1)
		eliminar(0);
}

ListaEscenario::~ListaEscenario()
{
}