#include "Escenario.h"
#include "Personaje.h"
#include "ListaEscenario.h"
#include "ListaBloques.h"
#include "Bonus.h"
#include "Obstaculo.h"

class Mundo
{
public: 
	/*Disparo disparo;
	Esfera esfera;
	Caja caja;
	Bonus bonus;*/
	//Pared plataforma;
	Escenario escenario;
	Personaje personaje;
	ListaEscenario listaEscenario;

	void tecla(bool keystates[]);
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char key);
	void movPers();

	float x_ojo;
	float y_ojo;
	float z_ojo;
};