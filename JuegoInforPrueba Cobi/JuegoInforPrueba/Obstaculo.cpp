#include "Obstaculo.h"
#include "glut.h"



Obstaculo::Obstaculo()
{
	miColor.r = 0;
	miColor.g = 255;
	miColor.b = 255;
}

void Obstaculo::dibuja()
{
	glPushMatrix();
	glTranslatef(this->getPos().x, this->getPos().y, this->getPos().z);
	glColor3ub(miColor.r, miColor.g, miColor.b);
	glutSolidCube(2.0f);
	glPopMatrix();
}

Obstaculo::~Obstaculo()
{
}
