#include "Escenario.h"
#include "glut.h"

Escenario::Escenario(void)
{
	aceleracion.z=0.0f;
	velocidad.z=30.0f;

	suelo.SetColor(141,73,37);
	techo.SetColor(135,207,235);
	pared_dcha.SetColor(20,200,20);
	pared_izq.SetColor(20,200,20);

	/*suelo.limite1.x=-10.0f;
	suelo.limite1.y=0.0f;
	suelo.limite2.x=10.0f;
	suelo.limite2.y=0.0f;
	suelo.limite3.z=10.0f;
	suelo.limite4.z=-1000.0f;

	techo.limite1.x=-10.0f;
	techo.limite1.y=15.0f;
	techo.limite2.x=10.0f;
	techo.limite2.y=15.0f;
	techo.limite3.z=10.0f;
	techo.limite4.z=-1000.0f;

	pared_dcha.limite1.x=10.0f;
	pared_dcha.limite1.y=0.0f;
	pared_dcha.limite2.x=10.0f;
	pared_dcha.limite2.y=15.0f;
	pared_dcha.limite3.z=10.0f;
	pared_dcha.limite4.z=-1000.0f;

	pared_izq.limite1.x=-10.0f;
	pared_izq.limite1.y=0.0f;
	pared_izq.limite2.x=-10.0f;
	pared_izq.limite2.y=15.0f;
	pared_izq.limite3.z=10.0f;
	pared_izq.limite4.z=-1000.0f;*/

	suelo.esquina1.x= -10.0f;
	suelo.esquina1.y= 0.0f;
	suelo.esquina1.z= 10.0f;
	suelo.esquina2.x= 10.0f;
	suelo.esquina2.y= 0.0f;
	suelo.esquina2.z= 10.0f;
	suelo.esquina3.x= 10.0f;
	suelo.esquina3.y= 0.0f;
	suelo.esquina3.z= -300.0f;
	suelo.esquina4.x= -10.0f;
	suelo.esquina4.y= 0.0f;
	suelo.esquina4.z= -300.0f;


	techo.esquina1.x= -10.0f;
	techo.esquina1.y= 15.0f;
	techo.esquina1.z= 10.0f;
	techo.esquina2.x= 10.0f;
	techo.esquina2.y= 15.0f;
	techo.esquina2.z= 10.0f;
	techo.esquina3.x= 10.0f;
	techo.esquina3.y= 15.0f;
	techo.esquina3.z= -300.0f;
	techo.esquina4.x= -10.0f;
	techo.esquina4.y= 15.0f;
	techo.esquina4.z= -300.0f;

	pared_dcha.esquina1.x= 10.0f;
	pared_dcha.esquina1.y= 0.0f;
	pared_dcha.esquina1.z= 10.0f;
	pared_dcha.esquina2.x= 10.0f;
	pared_dcha.esquina2.y= 15.0f;
	pared_dcha.esquina2.z= 10.0f;
	pared_dcha.esquina3.x= 10.0f;
	pared_dcha.esquina3.y= 15.0f;
	pared_dcha.esquina3.z= -300.0f;
	pared_dcha.esquina4.x= 10.0f;
	pared_dcha.esquina4.y= 0.0f;
	pared_dcha.esquina4.z= -300.0f;

	pared_izq.esquina1.x= -10.0f;
	pared_izq.esquina1.y= 0.0f;
	pared_izq.esquina1.z= 10.0f;
	pared_izq.esquina2.x= -10.0f;
	pared_izq.esquina2.y= 15.0f;
	pared_izq.esquina2.z= 10.0f;
	pared_izq.esquina3.x= -10.0f;
	pared_izq.esquina3.y= 15.0f;
	pared_izq.esquina3.z= -300.0f;
	pared_izq.esquina4.x= -10.0f;
	pared_izq.esquina4.y= 0.0f;
	pared_izq.esquina4.z= -300.0f;




	/*pared_dcha.verde=255;
	pared_izq.verde=255;

		suelo.verde=150;
	suelo.rojo=0;
	suelo.azul=0;
	techo.rojo=0;
	techo.verde=150;
	techo.azul=0;
	pared_dcha.rojo=0;
	pared_dcha.verde=50;
	pared_dcha.azul=0;
	pared_izq.rojo=0;
	pared_izq.verde=50;
	pared_izq.azul=0;*/

}

void Escenario::dibuja()
{
	suelo.dibuja();
	techo.dibuja();
	pared_dcha.dibuja();
	pared_izq.dibuja();
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

void Escenario::Mueve(float t)
{

	suelo.esquina1.z=suelo.esquina1.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	techo.esquina1.z=techo.esquina1.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	pared_dcha.esquina1.z=pared_dcha.esquina1.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	pared_izq.esquina1.z=pared_izq.esquina1.z+velocidad.z*t+0.5f*aceleracion.z*t*t;

	suelo.esquina2.z=suelo.esquina2.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	techo.esquina2.z=techo.esquina2.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	pared_dcha.esquina2.z=pared_dcha.esquina2.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	pared_izq.esquina2.z=pared_izq.esquina2.z+velocidad.z*t+0.5f*aceleracion.z*t*t;

	suelo.esquina3.z=suelo.esquina3.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	techo.esquina3.z=techo.esquina3.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	pared_dcha.esquina3.z=pared_dcha.esquina3.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	pared_izq.esquina3.z=pared_izq.esquina3.z+velocidad.z*t+0.5f*aceleracion.z*t*t;

	suelo.esquina4.z=suelo.esquina4.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	techo.esquina4.z=techo.esquina4.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	pared_dcha.esquina4.z=pared_dcha.esquina4.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	pared_izq.esquina4.z=pared_izq.esquina4.z+velocidad.z*t+0.5f*aceleracion.z*t*t;

	/*suelo.limite4.z=suelo.limite4.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	techo.limite4.z=techo.limite4.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	pared_dcha.limite4.z=pared_dcha.limite4.z+velocidad.z*t+0.5f*aceleracion.z*t*t;
	pared_izq.limite4.z=pared_izq.limite4.z+velocidad.z*t+0.5f*aceleracion.z*t*t;*/

	/*posicion.y=posicion.y+velocidad.y*t+0.5f*aceleracion.y*t*t;
	velocidad.x=velocidad.x+aceleracion.x*t;
	velocidad.y=velocidad.y+aceleracion.y*t;*/
}





void Escenario::SetVel(float vx, float vy, float vz)
{
	velocidad.x=vx;
	velocidad.y=vy;
	velocidad.z=vz;
} 





//////////////////////////////////////////////////////
/*
PARA PROBAR CON ESQUINAS

	suelo.esquina1.x= -10.0f;
	suelo.esquina1.y= 0.0f;
	suelo.esquina1.z= 10.0f;
	suelo.esquina2.x= 10.0f;
	suelo.esquina2.y= 0.0f;
	suelo.esquina2.z= 10.0f;
	suelo.esquina3.x= 10.0f;
	suelo.esquina3.y= 0.0f;
	suelo.esquina3.z= -1000.0f;
	suelo.esquina4.x= -10.0f;
	suelo.esquina4.y= 0.0f;
	suelo.esquina4.z= -1000.0f;


	techo.esquina1.x= -10.0f;
	techo.esquina1.y= 15.0f;
	techo.esquina1.z= 10.0f;
	techo.esquina2.x= 10.0f;
	techo.esquina2.y= 15.0f;
	techo.esquina2.z= 10.0f;
	techo.esquina3.x= 10.0f;
	techo.esquina3.y= 15.0f;
	techo.esquina3.z= -1000.0f;
	techo.esquina4.x= -10.0f;
	techo.esquina4.y= 15.0f;
	techo.esquina4.z= -1000.0f;

	pared_dcha.esquina1.x= 10.0f;
	pared_dcha.esquina1.y= 0.0f;
	pared_dcha.esquina1.z= 10.0f;
	pared_dcha.esquina2.x= 10.0f;
	pared_dcha.esquina2.y= 15.0f;
	pared_dcha.esquina2.z= 10.0f;
	pared_dcha.esquina3.x= 10.0f;
	pared_dcha.esquina3.y= 15.0f;
	pared_dcha.esquina3.z= -1000.0f;
	pared_dcha.esquina4.x= 10.0f;
	pared_dcha.esquina4.y= 0.0f;
	pared_dcha.esquina4.z= -1000.0f;

	pared_izq.esquina1.x= -10.0f;
	pared_izq.esquina1.y= 0.0f;
	pared_izq.esquina1.z= 10.0f;
	pared_izq.esquina2.x= -10.0f;
	pared_izq.esquina2.y= 15.0f;
	pared_izq.esquina2.z= 10.0f;
	pared_izq.esquina3.x= -10.0f;
	pared_izq.esquina3.y= 15.0f;
	pared_izq.esquina3.z= -1000.0f;
	pared_izq.esquina4.x= -10.0f;
	pared_izq.esquina4.y= 0.0f;
	pared_izq.esquina4.z= -1000.0f;

	*/