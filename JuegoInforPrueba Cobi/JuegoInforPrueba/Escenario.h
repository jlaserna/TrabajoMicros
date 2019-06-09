#include "Objeto.h"
#include "Pared.h"   //el include no es necesario que ponga “dominio”
					//porque ya estamos en dicha carpeta.
#define MAX_PAREDES 4
#pragma once
class Escenario: public Objeto
{
private:
	Pared *paredes[MAX_PAREDES];
public:
	/*Pared *suelos[MAX_PAREDES];
	Pared *techos[MAX_PAREDES];
	Pared *pared_dchas[MAX_PAREDES];
	Pared *pared_izqs[MAX_PAREDES];*/
	//Pared paredes[MAX_PAREDES];
	//int num_pared;

	Escenario(void);
	Escenario(Escenario e, Vector3D v);
	Pared getPared(int i);
	~Escenario(void);

	/*Pared suelo;
	Pared techo;
	Pared pared_izq;
	Pared pared_dcha;*/

	//void SetColor(unsigned char r,unsigned char v, unsigned char a);
	//bool operator +=(Pared *pa);
	void dibuja();
	void mueve(float t);
	//void setVel(float vx, float vy, float vz);

};