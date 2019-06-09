#include "Personaje.h"
#include "EScenario.h"
#include "Pared.h"

#pragma once
class Interaccion
{
public:
	static void rebote(Personaje &h, Escenario e);
	/*static bool rebote(Esfera &e, Pared p);
	static void rebote(Esfera &e, Caja c);
	static bool rebote(Esfera &e, Esfera &e2);*/
	Interaccion(void);
	~Interaccion(void);
};
