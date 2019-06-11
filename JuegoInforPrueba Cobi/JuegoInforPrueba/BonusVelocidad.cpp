#include "BonusVelocidad.h"


BonusVelocidad::BonusVelocidad() {
	sprite = new SpriteSequence("resources/textures/BonVelocidad.png", 1, 1);
	sprite->setCenter(1.1, 0);
	sprite->setSize(2.5, 5);

	miTipoCelda = BONUSVELOCIDAD;
}

BonusVelocidad::~BonusVelocidad()
{
}
