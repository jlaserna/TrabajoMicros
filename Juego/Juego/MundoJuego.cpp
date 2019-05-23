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
	/*hombre.Mueve(0.025f);
	esfera.Mueve(0.025f);
	bonus.Mueve(0.025f);
	disparo.Mueve(0.025f);*/
	//bloque.Mueve(0.025f);
	personaje.Mueve(0.075f);
	/////////-***-***************************************************
	Interaccion::rebote(personaje,bloque);
    bloque.Mueve(0.075f);
    miBloqueAlternativo1->Mueve(0.075f);
    miBloqueAlternativo2->Mueve(0.075f);
    miBloqueAlternativo3->Mueve(0.075f);
	/*Interaccion::rebote(esfera,caja);
	Interaccion::rebote(esfera,plataforma);
	Interaccion::rebote(esfera2,caja);
	Interaccion::rebote(esfera2,plataforma); 
	Interaccion::rebote(esfera,esfera2);*/
	
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=7.5;
	z_ojo=30;
	personaje.SetVel(0.0f,0.0f,0.0f);
	personaje.SetPos(0,2,7);

    miBloqueAlternativo1->init(0, 1, 2);
    miBloqueAlternativo2->init(2, 1, 0);
    miBloqueAlternativo3->init(1, 1, 2);
    miBloqueAlternativo1->SetVel(0, 0, 5);
    miBloqueAlternativo2->SetVel(0, 0, 5);
    miBloqueAlternativo3->SetVel(0, 0, 5);
    miBloqueAlternativo1->SetAcel(0, 0, 0);
    miBloqueAlternativo2->SetAcel(0, 0, 0);
    miBloqueAlternativo3->SetAcel(0, 0, 0);
    
	/*esfera.posicion.x=2;
	esfera.posicion.y=4;
	esfera.radio=1.5f;
	esfera.rojo=0;
	esfera.verde=0;
	esfera.azul=255;*/

	/* ESTO MAS TARDE
	esfera.SetColor(0,0,255);
	esfera.SetRadio(1.5f);
	esfera.SetPos(2,8); 

	bonus.lado=0.45f;
	bonus.posicion.x=-5.0f;
	bonus.posicion.y=5.0f;

	disparo.posicion.x=0.0f;
	disparo.posicion.y=0.0f;
	disparo.origen.x=0.0f;
	disparo.origen.y=0.0f;*/

	/*plataforma.limite1.x=-5.0f;
	plataforma.limite2.x=5.0f;
	plataforma.limite1.y=9.0f;
	plataforma.limite2.y=9.0f;
	plataforma.rojo=255;
	plataforma.verde=255;
	plataforma.azul=0;
	plataforma.SetColor(255,255,0);*/
}

void Mundo::tecla(unsigned char key)
{
	/*if (key == 'w')
	{
		int salto;
		salto = personaje.saltos();
		if (salto == 0)
			personaje.SetVel(personaje.giro(),15.0f, 0.0f);
	}*/
}

void Mundo::Tecla(bool keystates[])
{
	if (keystates['a'])
	{
		personaje.SetVel(-5.0f, personaje.jump(), 0.0f);
	}
	else if (keystates['d'])
	{
		personaje.SetVel(5.0f, personaje.jump(), 0.0f);
	}
	else if (keystates['w'])
	{
		int salto;
		salto = personaje.saltos();
		if (salto == 0)
			personaje.SetVel(personaje.giro(), 15.0f, 0.0f);
	}
	else
		personaje.SetVel(0.0f, personaje.jump(), 0.0f);
}

void Mundo::teclaEspecial(unsigned char key)
{
	Vector3D carril1=(-6.67f,2.0f,0.0f);
	Vector3D carril2=(0.0f,2.0f,0.0f);
	Vector3D carril3=(6.67f,2.0f,0.0f);
	Vector3D pos_pers;
	pos_pers=personaje.GetPos();

	switch(key)
	{
	case (GLUT_KEY_LEFT):
	
		personaje.SetVel(-5.0f, personaje.jump(), 0.0f);
		
		break;
	
	case (GLUT_KEY_RIGHT):
		
		personaje.SetVel(5.0f, personaje.jump(), 0.0f);
		
		break;

	case GLUT_KEY_UP:
		
		int salto;
		salto = personaje.saltos();
		if (salto == 0)
			personaje.SetVel(personaje.giro(), 10.0f, 0.0f);
		break;
	case GLUT_KEY_DOWN:
		break;
	}
}

/*void Mundo::teclaEspecial(unsigned char key)
{
	Vector3D carril1=(-6.67f,2.0f,0.0f);
	Vector3D carril2=(0.0f,2.0f,0.0f);
	Vector3D carril3=(6.67f,2.0f,0.0f);
	Vector3D pos_pers;
	pos_pers=personaje.GetPos();
	
	int carril=0;
	if(pos_pers.x==carril1.x)
		carril=1;
	if(pos_pers.x==carril2.x)
		carril=2;
	if(pos_pers.x==carril3.x)
		carril=3;
	
	switch(key)
	{
	case GLUT_KEY_LEFT:
		switch(carril)
		{
		case 1:
			personaje.SetVel(0.0f,personaje.jump(),0.0f);
			break;
		case 2:
			personaje.SetVel(-5.0f,personaje.jump(),0.0f);
			break;
		case 3:
			personaje.SetVel(-5.0f,personaje.jump(),0.0f);
			break;
		}
	break;

	/*if(pos_pers.x==carril2.x)
			{
			personaje.SetVel(-5.0f,personaje.jump(),0.0f);
			}

		if(pos_pers.x==carril1.x)
			{
			personaje.SetVel(0.0f,personaje.jump(),0.0f);
			}
		
		if(pos_pers.x==carril3.x)
			{
		do{
			personaje.SetVel(-5.0f,personaje.jump(),0.0f);
		}while(pos_pers.x!=carril2.x);
		}break;

	case GLUT_KEY_RIGHT:
		switch(carril)
		{
		case 1:
			personaje.SetVel(5.0f,personaje.jump(),0.0f);
			break;
		case 2:
			personaje.SetVel(5.0f,personaje.jump(),0.0f);
			break;
		case 3:
			personaje.SetVel(5.0f,personaje.jump(),0.0f);
			break;
		}
	break;
		/*if(pos_pers.x==carril2.x)
			{
			personaje.SetVel(5.0f,personaje.jump(),0.0f);
			}
		if(pos_pers.x==carril3.x)
			{
			personaje.SetVel(0.0f,personaje.jump(),0.0f);
			}
		if(pos_pers.x==carril1.x)
			{
		do{
			personaje.SetVel(5.0f,personaje.jump(),0.0f);
		}while(pos_pers.x!=carril2.x);
		}break;

	case GLUT_KEY_UP:
		
		int salto;
		salto = personaje.saltos();
		if (salto == 0)
			personaje.SetVel(personaje.giro(), 10.0f, 0.0f);
		break;
	case GLUT_KEY_DOWN:
		break;

}
}*/


/*void Mundo::MovPers()
{
	//Vector3D carril[3]={(-6.67,2,0),(0,2,0),(6.67,2,0)};
	Vector3D carril1=(-6.67,2,0);
	Vector3D carril2=(0,2,0);
	Vector3D carril3=(6.67,2,0);
	
	Vector3D pos_pers;
	int carril=0;
	if(pos_pers.x==carril1.x)
		carril=1;
	if(pos_pers.x==carril2.x)
		carril=2;
	if(pos_pers.x==carril3.x)
		carril=3;

	

	
	pos_pers=personaje.GetPos();
	
	switch(carril)
	{
	case 1:
		personaje.SetVel(0.0f,personaje.jump(),0.0f);
		break;
	case 2:
		personaje.SetVel(-5.0f,personaje.jump(),0.0f);
		break;
	case 3:
		personaje.SetVel(-5.0f,personaje.jump(),0.0f);
		break;
	}*/

		
