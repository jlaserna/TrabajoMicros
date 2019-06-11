#include "BonusFantasma.h"


BonusFantasma::BonusFantasma() {
	sprite = new SpriteSequence("resources/textures/BonFantasma.png", 1, 1);
	sprite->setCenter(0, 0);
	sprite->setSize(2.5, 5);
	miTipoCelda = BONUSFANTASMA;
}

BonusFantasma::~BonusFantasma()
{
}
