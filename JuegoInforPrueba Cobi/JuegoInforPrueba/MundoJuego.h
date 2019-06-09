
#include "Personaje.h"
#include "ListaBloques.h"
#include "ListaEscenario.h"
#include "Bloque.h"
#include "Bonus.h"
#include "Obstaculo.h"


class Mundo
{
public: 

	ListaEscenario listaEscenario;
	Personaje personaje;
	ListaBloques listaBloques;

	void tecla(bool keystates[]);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();
	void teclaEspecial(unsigned char key);

	float x_ojo;
	float y_ojo;
	float z_ojo;
};