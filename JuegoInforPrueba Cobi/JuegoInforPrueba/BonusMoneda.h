#pragma once

#include "Bonus.h"
//#include "ETSIDI.h"
//using ETSIDI::SpriteSequence;

class BonusMoneda : public Bonus {
public:
	BonusMoneda();
	//tipoCelda getTipoCelda(){return BONUSMONEDA;}
	void ponerBonus(Personaje &p);
};
