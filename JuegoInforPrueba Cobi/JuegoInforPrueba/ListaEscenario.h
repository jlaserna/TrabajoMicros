#include "Escenario.h"
#include "Pared.h"
#include "Personaje.h"

#define MAX_ESCENARIO 6

class ListaEscenario
{
private:
	Escenario *escenario[MAX_ESCENARIO];
	int numero;

public:
	ListaEscenario();
	bool agregar(Escenario* es);
	bool generarNuevoEscenario();
	void destruirUltimoEscenario();
	void destruirContenido();
	void actualizarEscenario(Vector3D pos);
	bool existeElemento(Escenario* es);
	void dibuja();
	void mueve(float t);
	void eliminar(int index);
	void eliminar(Escenario* es);
	Escenario* operator [](int i);
	int getNumero() { return numero; }
	~ListaEscenario();

};