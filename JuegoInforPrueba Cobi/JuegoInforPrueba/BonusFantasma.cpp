#include "BonusFantasma.h"


BonusFantasma::BonusFantasma() {
	sprite = new SpriteSequence("resources/textures/BonFantasma.png", 1, 1);
	sprite->setCenter(2.5, 0);
	sprite->setSize(5, 10);
}

void BonusFantasma::ponerBonus(Personaje &p) {
	//p.setEscudo();
}