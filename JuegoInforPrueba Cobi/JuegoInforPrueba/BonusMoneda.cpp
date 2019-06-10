#include "BonusMoneda.h"


BonusMoneda::BonusMoneda() {
	sprite = new SpriteSequence("resources/textures/BonMoneda.png", 1, 1);
	sprite->setCenter(2.5, 0);
	sprite->setSize(5, 10);
}

void BonusMoneda::ponerBonus(Personaje &p) {
	//p.setEscudo();
}