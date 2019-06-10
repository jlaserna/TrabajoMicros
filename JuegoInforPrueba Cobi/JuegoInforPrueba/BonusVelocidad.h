#pragma once

#include "Bonus.h"
//#include "ETSIDI.h"
//using ETSIDI::SpriteSequence;

class BonusVelocidad : public Bonus {
public:
	BonusVelocidad();
	//tipoCelda getTipoCelda(){return BONUSVELOCIDAD;}
	void ponerBonus(Personaje &p);
};