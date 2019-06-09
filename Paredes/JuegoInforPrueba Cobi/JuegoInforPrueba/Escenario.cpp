#include "Escenario.h"
#include "Pared.h"
#include "glut.h"

Escenario::Escenario(void)
{
	this->setPos(Vector3D(0, 0, 0));
	this->setVel(Vector3D(0, 0, 30.0f));
	this->setAccel(Vector3D(0, 0, 0));
	
	paredes[0] = new Pared();//suelo
	paredes[0]->setPos(this->getPos() + Vector3D(0, 0, 0));
	paredes[0]->setLim(Vector3D(-10.0f, 0, 165.0f),Vector3D(10.0f, 0, -105.0f));
	paredes[0]->setColor(255,0,0);

	paredes[1] = new Pared();//techo
	paredes[1]->setPos(this->getPos() + Vector3D(0, 15.0f, 0));
	paredes[1]->setColor(255,0,0);
	paredes[1]->setLim(Vector3D(-10.0f, 0, 165.0f),Vector3D(10.0f, 0, -105.0f));

	paredes[2] = new Pared();//pared derecha
	paredes[2]->setPos(this->getPos() + Vector3D(-10.0, 7.5, 0));
	paredes[2]->setColor(255,0,0);
	paredes[2]->setLim(Vector3D(0, -7.5f, 165.0f),Vector3D(0, 7.5f, -105.0f));

	paredes[3] = new Pared();//pared izquierda
	paredes[3]->setPos(this->getPos() + Vector3D(10.0, 7.5, 0));
	paredes[3]->setColor(255,0,0);
	paredes[3]->setLim(Vector3D(0, -7.5f, 165.0f),Vector3D(0, 7.5f, -105.0f));

	//Primer Escenario
	/*paredes[0]=new Pared();
	paredes[0]->setColor(255,0,0);
	paredes[0]->setPos(Vector3D(0, 0, -155.0f));
	paredes[0]->setLim(Vector3D(-10.0f, 0, 165.0f),Vector3D(10.0f, 0, -105.0f));

	paredes[1]=new Pared();
	paredes[1]->setColor(255,0,0);
	paredes[1]->setPos(Vector3D(0, 15.0f, -155.0f));
	paredes[1]->setLim(Vector3D(-10.0f, 0, 165.0f),Vector3D(10.0f, 0, -105.0f));

	paredes[2]=new Pared();
	paredes[2]->setColor(255,0,0);
	paredes[2]->setPos(Vector3D(10.0f, 7.5f, -155.0f));
	paredes[2]->setLim(Vector3D(0, -7.5f, 165.0f),Vector3D(0, 7.5f, -105.0f));

	paredes[3]=new Pared();
	paredes[3]->setColor(255,0,0);
	paredes[3]->setPos(Vector3D(-10.0f, 7.5f, -155.0f));
	paredes[3]->setLim(Vector3D(0, -7.5f, 165.0f),Vector3D(0, 7.5f, -105.0f));*/
	//---------------------
	//Segundo Escenario
	/*paredes[4].setColor(0,255,0);
	paredes[4].setPos(Vector3D(10.0f, 0, -425.0f));
	paredes[4].setLim(Vector3D(-10.0f, 0, 165.0f),Vector3D(10.0f, 0, -105.0f));

	paredes[5].setColor(0,255,0);
	paredes[5].setPos(Vector3D(10.0f, 15.0f, -425.0f));
	paredes[5].setLim(Vector3D(-10.0f, 0, 165.0f),Vector3D(10.0f, 0, -105.0f));


	paredes[6].setColor(0,255,0);
	paredes[6].setPos(Vector3D(20.0f, 7.5f, -425.0f));
	paredes[6].setLim(Vector3D(0, -7.5f, 165.0f),Vector3D(0, 7.5f, -105.0f));

	paredes[7].setColor(0,255,0);
	paredes[7].setPos(Vector3D(0, 7.5f, -425.0f));
	paredes[7].setLim(Vector3D(0, -7.5f, 165.0f),Vector3D(0, 7.5f, -105.0f));
	//----------------------
	//Tercer Escenario
	paredes[8].setColor(0,0,255);
	paredes[8].setPos(Vector3D(10.0f, 0, -695.0f));
	paredes[8].setLim(Vector3D(-10.0f, 0, 165.0f),Vector3D(10.0f, 0, -105.0f));

	paredes[9].setColor(0,0,255);
	paredes[9].setPos(Vector3D(10.0f, 15.0f, -695.0f));
	paredes[9].setLim(Vector3D(-10.0f, 0, 165.0f),Vector3D(10.0f, 0, -105.0f));


	paredes[10].setColor(0,0,255);
	paredes[10].setPos(Vector3D(20.0f, 7.5f, -695.0f));
	paredes[10].setLim(Vector3D(0, -7.5f, 165.0f),Vector3D(0, 7.5f, -105.0f));

	paredes[11].setColor(0,0,255);
	paredes[11].setPos(Vector3D(0, 7.5f, -695.0f));
	paredes[11].setLim(Vector3D(0, -7.5f, 165.0f),Vector3D(0, 7.5f, -105.0f));
	*/


	//COLORES PAREDES ORIGINALES
	/*suelo.setColor(141,73,37);
	techo.setColor(135,207,235);
	pared_dcha.setColor(20,200,20);
	pared_izq.setColor(20,200,20);*/

	//suelo.setPos(Vector3D(10.0f, 0, -155.0f));
	//techo.setPos(Vector3D(10.0f, 15.0f, -155.0f));
	//pared_dcha.setPos(Vector3D(20.0f, 7.5f, -155.0f));
	//pared_izq.setPos(Vector3D(0, 7.5f, -155.0f));

	/*suelo.setLim(Vector3D(-10.0f, 0, 170.0f),Vector3D(10.0f, 0, -155.0f));
	techo.setLim(Vector3D(-10.0f, 0, 170.0f),Vector3D(10.0f, 0, -155.0f));
	pared_dcha.setLim(Vector3D(0, -7.5f, 170.0f),Vector3D(0, 7.5f, -155.0f));
	pared_izq.setLim(Vector3D(0, -7.5f, 170.0f),Vector3D(0, 7.5f, -155.0f));*/

}

Escenario::Escenario(Escenario e, Vector3D v)
{
	this->setPos(e.getPos() + v);
	this->setVel(Vector3D(0, 0, 30.0f));
	this->setAccel(Vector3D(0, 0, 0));
	
	paredes[0] = new Pared();
	paredes[0]->setPos(this->getPared(0).getPos() + Vector3D(0, 0, -270.0));
	paredes[0]->setLim(Vector3D(-10.0f, 0, 165.0f),Vector3D(10.0f, 0, -105.0f));
	paredes[0]->setColor(255,0,0);
	paredes[1] = new Pared();
	paredes[1]->setPos(this->getPared(1).getPos() + Vector3D(0, 0, -270.0));
	paredes[1]->setColor(0,255,0);
	paredes[1]->setLim(Vector3D(-10.0f, 0, 165.0f),Vector3D(10.0f, 0, -105.0f));
	paredes[2] = new Pared();
	paredes[2]->setPos(this->getPared(2).getPos() + Vector3D(0, 0, -270.0));
	paredes[2]->setColor(0,0,255);
	paredes[2]->setLim(Vector3D(0, -7.5f, 165.0f),Vector3D(0, 7.5f, -105.0f));
	paredes[3] = new Pared();
	paredes[3]->setPos(this->getPared(3).getPos() + Vector3D(0, 0, -270.0));
	paredes[3]->setColor(255,255,255);
	paredes[3]->setLim(Vector3D(0, -7.5f, 165.0f),Vector3D(0, 7.5f, -105.0f));

}

Pared Escenario::getPared(int i)
{
	return *paredes[i];
}

void Escenario::dibuja()
{
	for(int i=0; i<MAX_PAREDES; i++)
	{
		paredes[i]->dibuja();
	}
	/*suelo.dibuja();
	techo.dibuja();
	pared_dcha.dibuja();
	pared_izq.dibuja();*/
}

void Escenario::mueve(float t)
{
	Objeto::mueve(t);
	paredes[0]->setPos(this->getPos() + Vector3D(0, 0, -270.0));
	paredes[1]->setPos(this->getPos() + Vector3D(0, 0, -270.0));
	paredes[2]->setPos(this->getPos() + Vector3D(0, 0, -270.0));
	paredes[3]->setPos(this->getPos() + Vector3D(0, 0, -270.0));
}

Escenario::~Escenario(void)
{

}

/*void Caja::SetColor( unsigned char r,unsigned char v, unsigned char a)
{
	rojo=r;
	verde=v;
	azul=a;
}*/

/*void Escenario::mueve(float t)
{
	for(int i=0; i<MAX_PAREDES;i++)
	{
		paredes[i].mueve(t);
	}
	suelo.mueve(t);
	techo.mueve(t);
	pared_dcha.mueve(t);
	pared_izq.mueve(t);*/


	/*posicion.y=posicion.y+velocidad.y*t+0.5f*aceleracion.y*t*t;
	velocidad.x=velocidad.x+aceleracion.x*t;
	velocidad.y=velocidad.y+aceleracion.y*t;*/
	
	
		/*suelo.limite1.z=suelo.limite1.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
		suelo.limite2.z=suelo.limite2.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
		techo.limite1.z=techo.limite1.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
		techo.limite2.z=techo.limite2.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
		pared_dcha.limite1.z=pared_dcha.limite1.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
		pared_dcha.limite2.z=pared_dcha.limite2.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
		pared_izq.limite1.z=pared_izq.limite1.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
		pared_izq.limite2.z=pared_izq.limite2.z+velocidad.z*t+0.5f*aceleracion.z*t*t;*/
		
	
//}





/*void Escenario::setVel(float vx, float vy, float vz)
{
	velocidad.x=vx;
	velocidad.y=vy;
	velocidad.z=vz;
} */


/*bool Bloque::operator +=(Pared *pa){
	if(num_pared<MAX_PAREDES){
		pa[num_pared++]=paredes;
		return true;
	}
	else return false;
}*/

