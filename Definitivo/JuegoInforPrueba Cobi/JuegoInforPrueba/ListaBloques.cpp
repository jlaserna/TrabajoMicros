#include "ListaBloques.h"
#include "Bloque.h"
#include "Vector3D.h"
#include "Interaccion.h"


ListaBloques::ListaBloques() {
	numero = 0;
	velMax = 50.0f;
	for (int i = 0; i < MAX_ELEMENTOS; i++)
		lista[i] = 0;

	agregar(new Bloque());
	for (int i = 0; i < MAX_ELEMENTOS - 1; i++)
		generarNuevoBloque();
	
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

tipoCelda ListaBloques::colision(Personaje per)
{
	for (int i = 0; i < numero; i++) {//cambiar numero por 2
		for (int j = 0; j < 3; j++) {
			if (Interaccion::colision(per, *lista[i]->getCelda(j))) {
				switch (lista[i]->getCelda(j)->getTipoCelda()) {
				case OBSTACULO: 
					return OBSTACULO;
					break;
				case BONUSFANTASMA:
					if (lista[i]->estaActivo(j)) {
						lista[i]->desactivar(j);
						return BONUSFANTASMA;
					}
					else
						return NONE;
					break;
				case BONUSMONEDA:
					if (lista[i]->estaActivo(j)) {
						lista[i]->desactivar(j);
						return BONUSMONEDA;
					}
					else
						return NONE;
					break;
				case BONUSVELOCIDAD:
					if (lista[i]->estaActivo(j)) {
						lista[i]->desactivar(j);
						return BONUSVELOCIDAD;
					}
					else
						return NONE;
					break;
				}
			}
		}
	}
}

void ListaBloques::alctualizarBloques(Vector3D pos)
{
	if (pos.z + 60.0f <= lista[0]->getPos().z) {
		destruirUltimoBloque();
		generarNuevoBloque();
	}
	if(lista[numero-1]->getVel().z >= velMax)
		for (int i = 0; i < numero; i++) {
			lista[i]->setVel(Vector3D(0, 0, velMax));
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
		int aux = numero - 1;
		Bloque* nuevoBloqueArriba = new Bloque(*lista[aux], Vector3D(0, 7.0f, 0.0f));
		Bloque* nuevoBloqueAbajo = new Bloque(*lista[aux], Vector3D(0, 0, -30.0f));
		agregar(nuevoBloqueArriba);
		agregar(nuevoBloqueAbajo);
		return true;
	}
}

void ListaBloques::destruirUltimoBloque()
{
	if (numero > 1) {
		eliminar(1);
		eliminar(0);
	}
}

ListaBloques::~ListaBloques()
{
}