#include "BonusFantasma.h"


BonusFantasma::BonusFantasma() {
	sprite = new SpriteSequence("resources/textures/BonFantasma.png", 1, 1);
	sprite->setCenter(1.2, 0);
	sprite->setSize(3.5, 3.5);
	miTipoCelda = BONUSFANTASMA;
}

BonusFantasma::~BonusFantasma()
{
}
