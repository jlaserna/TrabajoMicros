#include "Interaccion.h"
#include "glut.h"
#include "math.h"


Interaccion::Interaccion(void)
{
}

void Interaccion::rebote(Personaje &h, Bloque c)
{
	float xmax=c.suelo.esquina2.x-3.33f;
	float xmin=c.suelo.esquina1.x+3.33f;
	float ymax=c.techo.esquina2.y-1;
	float ymin=c.suelo.esquina1.y+1;
	//float zmax=c.techo.esquina2.y;
	//float zmin=c.suelo.esquina1.y;
	if(h.posicion.x>xmax)h.posicion.x=xmax;
	if(h.posicion.x<xmin)h.posicion.x=xmin;
	if(h.posicion.y>ymax)h.posicion.y=ymax;
	if(h.posicion.y<ymin)h.posicion.y=ymin;
	
}

/*bool Interaccion::rebote(Esfera &e, Pared p)
{
	Vector2D dir;
	float dif=p.distancia(e.posicion,&dir)-e.radio;
	if(dif<=0.0f)
	{
		Vector2D v_inicial=e.velocidad;
		e.velocidad=v_inicial-dir*2.0*(v_inicial*dir);
		e.posicion=e.posicion-dir*dif;
		return true;
	}
	return false;
} 

void Interaccion::rebote(Esfera &e, Caja c)
{
	rebote(e, c.suelo);
	rebote(e, c.techo);
	rebote(e, c.pared_izq);
	rebote(e, c.pared_dcha);
}

bool Interaccion::rebote(Esfera &esfera, Esfera &esfera2)
{
	/*float dif=sqrt(((e.posicion.x-e2.posicion.x)*(e.posicion.x-e2.posicion.x))+((e.posicion.y-e2.posicion.y)*(e.posicion.y-e2.posicion.y)));
	if (dif<=(e.radio+e2.radio))
		{
			float area1=3.14*(e.radio*e.radio);
			float area2=3.14*(e2.radio*e2.radio);
			Vector2D vel_inic1, vel_inic2, vel_fin1, vel_fin2;
			vel_inic1=sqrt(e.velocidad.x);
			vel_inic2=e2.velocidad;
			//vel_fin1=((vel_inic1*(area1-area2)+(vel_inic2*area2*2))/(area1+area2));
			//vel_fin2=((vel_inic2*(area1+area2)+(2*vel_inic2*area2))/(area1+area2));

		}
	return false;
	Vector2D dir;
	float dif=sqrt((e.posicion*e.posicion)+(e2.posicion*e2.posicion));
	if(dif<=(e.radio+e2.radio))
	{
		Vector2D v_inicial=e.velocidad;
		e.velocidad=v_inicial-dir*2.0*(v_inicial*dir);
		e.posicion=e.posicion-dir*dif;
		Vector2D v_inicial2=e2.velocidad;
		e2.velocidad=v_inicial2-dir*2.0*(v_inicial2*dir);
		e2.posicion=e2.posicion-dir*dif;
		return true;
	}
	Vector2D dif=esfera2.posicion-esfera.posicion;
	float d=dif.modulo();
	float dentro=d-(esfera.radio+esfera2.radio);

	if(dentro<0.0f)//si hay colision
	{
		//El modulo y argumento de la velocidad de la pelota1
		float v1=esfera.velocidad.modulo();
		float ang1=esfera.velocidad.argumento();

		//El modulo y argumento de la velocidad de la pelota2
		float v2=esfera2.velocidad.modulo();
		float ang2=esfera2.velocidad.argumento();
	
		//el argumento del vector que une los centros
		float angd=dif.argumento();	
		
		//Separamos las esferas, lo que se han incrustado
		//la mitad cada una
		Vector2D desp(dentro/2*cos(angd),dentro/2*sin(angd));	
		esfera.posicion=esfera.posicion+desp;
		esfera2.posicion=esfera2.posicion-desp;

		angd=angd-3.14159f/2;//la normal al choque
	
		//El angulo de las velocidades en el sistema relativo antes del choque
		float th1=ang1-angd;	
		float th2=ang2-angd;
		
		//Las componentes de las velocidades en el sistema relativo ANTES del choque
		float u1x=v1*cos(th1);
		float u1y=v1*sin(th1);
		float u2x=v2*cos(th2);
		float u2y=v2*sin(th2);	
	
		//Las componentes de las velocidades en el sistema relativo DESPUES del choque
		//la componente en X del sistema relativo no cambia
		float v1x=u1x;
		float v2x=u2x;

		//en el eje Y, rebote elastico
		float m1=esfera.radio;
		float m2=esfera2.radio;
		float py=m1*u1y+m2*u2y;//Cantidad de movimiento inicial ejey
		float ey=m1*u1y*u1y+m2*u2y*u2y;//Energia cinetica inicial ejey
	
		//los coeficientes y discriminante de la ecuacion cuadrada
		float a=m2*m2+m1*m2;
		float b=-2*py*m2;
		float c=py*py-m1*ey;	
		float disc=b*b-4*a*c;
		if(disc<0)disc=0;

		//las nuevas velocidades segun el eje Y relativo
		float v2y=(-b+sqrt(disc))/(2*a);
		float v1y=(py-m2*v2y)/m1;
		
		//Modulo y argumento de las velocidades en coordenadas absolutas
		float modv1,modv2,fi1,fi2;
		modv1=sqrt(v1x*v1x+v1y*v1y);
		modv2=sqrt(v2x*v2x+v2y*v2y);
		fi1=angd+atan2(v1y,v1x);
		fi2=angd+atan2(v2y,v2x);
		
		//Velocidades en absolutas despues del choque en componentes
		esfera.velocidad.x=modv1*cos(fi1);
		esfera.velocidad.y=modv1*sin(fi1);
		esfera2.velocidad.x=modv2*cos(fi2);
		esfera2.velocidad.y=modv2*sin(fi2);	
	}
	return false;
}*/

Interaccion::~Interaccion(void)
{
}
