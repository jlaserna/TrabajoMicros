#pragma once
#include "Celda.h"
#include "Personaje.h"
using ETSIDI::SpriteSequence;

class Bonus :public Celda
{
protected:
	SpriteSequence *sprite;
public:
	Bonus();
	/*virtual*/ void dibuja();
	virtual void ponerBonus(Personaje& per);
	virtual ~Bonus();
	//virtual void ponerBonus(Personaje &p) = 0;
};

