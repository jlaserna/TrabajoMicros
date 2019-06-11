#include "Obstaculo.h"
#include "glut.h"



Obstaculo::Obstaculo() : sprite("resources/textures/obstaculo.png", 1, 1)
{
	sprite.setCenter(1, 1);
	sprite.setSize(2, 2);
	miColor.r = 206;
	miColor.g = 93;
	miColor.b = 55;
	miTipoCelda = OBSTACULO;
}

void Obstaculo::dibuja()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(this->getPos().x, this->getPos().y, this->getPos().z);
	sprite.draw();
	glTranslatef(0, 0, -1.05f);
	glColor3ub(miColor.r, miColor.g, miColor.b);
	glutSolidCube(2.0f);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

Obstaculo::~Obstaculo()
{
}
