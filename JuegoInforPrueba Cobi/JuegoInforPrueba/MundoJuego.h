#include "Personaje.h"
#include "ListaBloques.h"
#include "ListaEscenario.h"
#include "Bloque.h"
#include "Bonus.h"
#include "Obstaculo.h"
#include "HUD.h"


class Mundo
{
private:
	Personaje personaje;
	ListaBloques listaBloques;
	ListaEscenario listaEscenario;
	HUD miHUD;
	Timer tiempoJuego;

	int w;
	int h;

	bool jugando;

public: 

	void tecla(bool keystates[]);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();
	void teclaEspecial(unsigned char key);
	void ratonClick(int button, int state, int x, int y);
	void setSize(int w, int h) { this->w = w; this->h = h; }

	float x_ojo;
	float y_ojo;
	float z_ojo;
};