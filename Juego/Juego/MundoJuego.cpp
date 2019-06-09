#include <iostream>
#include "MundoJuego.h"
#include <GLUT/glut.h>
#include <math.h>
#include "Interaccion.h"
#include "BloqueAlternativo.h"


/*void Mundo::Dibuja(Esfera e)
{
glColor3ub(e.rojo, e.verde, e.azul);
glTranslatef(e.posicion.x, e.posicion.y,0);
glutSolidSphere(e.radio,20,20);
glTranslatef(-e.posicion.x,- e.posicion.y,0);
}*/

BloqueAlternativo *miBloqueAlternativo1 = new BloqueAlternativo(0, 1, -5);
BloqueAlternativo *miBloqueAlternativo2 = new BloqueAlternativo(0, 1, -15);
BloqueAlternativo *miBloqueAlternativo3 = new BloqueAlternativo(0, 1, -25);


void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	
	bloque.Dibuja();
	personaje.Dibuja();
    
    miBloqueAlternativo1->Dibuja();
    miBloqueAlternativo2->Dibuja();
    miBloqueAlternativo3->Dibuja();

	/*esfera.Dibuja();
	hombre.Dibuja();
	bonus.Dibuja();
	disparo.Dibuja();*/
	//plataforma.Dibuja();

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	/*glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glColor3ub(255,0,0);
		glVertex3f(-5.0f,0,-5.0f);
		glVertex3f(-5.0f,0,5.0f);
		glColor3ub(255,255,0);
		glVertex3f(5.0f,0,5.0f);	
		glVertex3f(5.0f,0,-5.0f);
	glEnd();
	glEnable(GL_LIGHTING);*/
}

void Mundo::Mueve()
{

	
}

void Mundo::Inicializa()
{

    
	
}

void Mundo::tecla(unsigned char key)
{

}

void Mundo::Tecla(bool keystates[])
{
	

}

void Mundo::teclaEspecial(unsigned char key)
{

}

