#include "BonusMoneda.h"


BonusMoneda::BonusMoneda() {
	sprite = new SpriteSequence("resources/textures/BonMoneda.png", 1, 1);
	sprite->setCenter(0, 0);
	sprite->setSize(2.5, 5);
	miTipoCelda = BONUSMONEDA;
}

BonusMoneda::~BonusMoneda()
{
}
