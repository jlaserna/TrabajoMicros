#include "BonusMoneda.h"


BonusMoneda::BonusMoneda() {
	sprite = new SpriteSequence("resources/textures/MonUnica.png", 1, 1);
	sprite->setCenter(1.1, 0);
	sprite->setSize(2.5, 2.5);
	miTipoCelda = BONUSMONEDA;
}

BonusMoneda::~BonusMoneda()
{
}
