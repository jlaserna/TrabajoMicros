#include "Escenario.h"
#include "Pared.h"

#define MAX_ESCENARIO 3

class ListaEscenario
{
private:
	Escenario *escenario[MAX_ESCENARIO];
	int numero;
	//Vector3D posSpawn[9];

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


	/*ListaEscenario();
	int getNumero() { return numero; }
	bool agregar(Escenario *es);
	void dibuja();
	//void cogerBonus(Coche *c);
	void eliminar(Escenario *e);
	void eliminar(int index);
	void destruirBloque();
	void inicializa();
	//void setPos();

		~ListaEscenario();*/
	/*bool agregar(T *d);
	void destruirContenido();
	bool existeElemento(T *d);
	void eliminar(int index);
	void eliminar(T *d);
	T* operator [](int i);
	int getNumero() { return numero; }*/
};