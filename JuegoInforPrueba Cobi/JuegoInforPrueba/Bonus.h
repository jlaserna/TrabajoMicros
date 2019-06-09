#pragma once
#include "Celda.h"
#include "Personaje.h"

class Bonus :
	public Celda
{
public:
	Bonus();
	void dibuja();
	tipoCelda getTipoCelda() { return BONUS; }
	virtual void aplicarBonus(Personaje& per);
	virtual ~Bonus();
};

