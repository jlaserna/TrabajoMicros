#include "Personaje.h"
#include "Escenario.h"
#include "Pared.h"
#include "Celda.h"

#pragma once
class Interaccion
{
public:
	//static void colision(Personaje &h, Escenario c);
	static bool colision(Personaje &h, Celda c);
	/*static bool rebote(Esfera &e, Pared p);
	static void rebote(Esfera &e, Caja c);
	static bool rebote(Esfera &e, Esfera &c);*/
	Interaccion(void);
	~Interaccion(void);
};
