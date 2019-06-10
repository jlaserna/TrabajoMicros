#include "ListaEscenario.h"
#include "Interaccion.h"



ListaEscenario::ListaEscenario()
{
	numero = 0;
	velMax = 30.0f;
	for (int i = 0; i < MAX_ESCENARIO; i++)
		escenario[i] = 0;
	
	agregar(new Escenario());
	for (int i = 0; i < MAX_ESCENARIO-1; i++){
		generarNuevoEscenario();
	}
}


bool ListaEscenario::agregar(Escenario *es){
	if(numero<MAX_ESCENARIO && !existeElemento(es))
		escenario[numero++]=es;
	else return false;
	return true;
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
	if (pos.z + 170.0f <= escenario[0]->getPos().z) { //+300.0f
		destruirUltimoEscenario();
		generarNuevoEscenario();
	}
	//añadido para probar velocidad
	if(escenario[numero-1]->getVel().z >= velMax)
		for (int i = 0; i < numero; i++) {
			escenario[i]->setAccel(Vector3D(0, 0, 0));
			escenario[i]->setVel(Vector3D(0, 0, velMax));
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
		int aux= numero-1;
		Escenario* nuevoEscenario = new Escenario(*escenario[aux], Vector3D(0, 0, -175.0f));//-270 original
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