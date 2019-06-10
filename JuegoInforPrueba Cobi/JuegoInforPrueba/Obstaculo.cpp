#include "Obstaculo.h"
#include "glut.h"



Obstaculo::Obstaculo()//:sprite("resources/textures/obstaculo.png",1,1)
{
	/*sprite.setCenter(2.5, 2.5);
	sprite.setSize(5, 5);*/
	miColor.r = 0;
	miColor.g = 255;
	miColor.b = 0;
	miTipoCelda = OBSTACULO;
	/*lPared[0] = new Pared();//suelo
	lPared[0]->setPos(this->getPos() + Vector3D(0, 0, 0));
	lPared[0]->setLim(Vector3D(-10.0f, 0, 165.0f),Vector3D(10.0f, 0, -10.0f));*/
}

/*void Obstaculo::setTextura(string lTexturas[5]) {
	for (int i = 0; i <= NUM_CARAS - 2; i++)
		lPared[i].setTextura(lTexturas[i]);
}*/

void Obstaculo::dibuja()
{
	glPushMatrix();
	glTranslatef(this->getPos().x, this->getPos().y, this->getPos().z);
	/*for (int i = 0; i <= NUM_CARAS - 1; i++) {
		lPared[i].dibuja();
	}*/
	/*glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(tSuperior.getTexture().c_str()).id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2d(1, 0); glVertex3f(ladoX, altura, ladoZ);
	glTexCoord2d(0, 0); glVertex3f(ladoX, altura, -ladoZ);
	glTexCoord2d(0, 1); glVertex3f(-ladoX, altura, -ladoZ);
	glTexCoord2d(1, 1); glVertex3f(-ladoX, altura, ladoZ);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);*/
	//sprite.draw();
	glColor3ub(miColor.r, miColor.g, miColor.b);
	glutSolidCube(2.0f);
	glPopMatrix();
}

Obstaculo::~Obstaculo()
{
}
