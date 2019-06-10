#include "BonusVelocidad.h"


BonusVelocidad::BonusVelocidad() {
	sprite = new SpriteSequence("resources/textures/BonVelocidad.png", 1, 1);
	sprite->setCenter(2.5, 0);
	sprite->setSize(5, 10);
}

void BonusVelocidad::ponerBonus(Personaje &p) {
	//p.setEscudo();
}