#include "Personaje.h"
#include "Escenario.h"
#include "Pared.h"
#include "Celda.h"

#pragma once
class Interaccion
{
public:
	static bool colision(Personaje &h, Celda c);
	Interaccion(void);
	~Interaccion(void);
};
