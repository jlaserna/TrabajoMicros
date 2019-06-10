#pragma once

#include "Bonus.h"
//#include "ETSIDI.h"
//using ETSIDI::SpriteSequence;

class BonusFantasma : public Bonus {
public:
	BonusFantasma();
	//tipoCelda getTipoCelda(){return BONUSFANTASMA;}
	void ponerBonus(Personaje &p);
};