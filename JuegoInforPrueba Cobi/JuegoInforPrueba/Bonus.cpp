#include "Bonus.h"
#include "glut.h"


Bonus::Bonus()
{
	miColor.r = 0;
	miColor.g = 0;
	miColor.b = 255;
}

void Bonus::dibuja()
{
	glPushMatrix();
	glTranslatef(this->getPos().x, this->getPos().y, this->getPos().z);
	glColor3ub(miColor.r, miColor.g, miColor.b);
	glutSolidSphere(1.0f, 20.0f, 10.0f);
	glPopMatrix();
}


void Bonus::aplicarBonus(Personaje& per)
{
}

Bonus::~Bonus()
{
}
