#include "Bonus.h"
#include "glut.h"


Bonus::Bonus()
{
	miColor.r = 0;
	miColor.g = 0;
	miColor.b = 255;
	miTipoCelda = BONUS;
}

void Bonus::dibuja()
{
	glPushMatrix();
	glTranslatef(this->getPos().x, this->getPos().y, this->getPos().z);
	glColor3ub(miColor.r, miColor.g, miColor.b);
	sprite->draw();
	glPopMatrix();
}


void Bonus::ponerBonus(Personaje& per)
{

}

Bonus::~Bonus()
{
}
