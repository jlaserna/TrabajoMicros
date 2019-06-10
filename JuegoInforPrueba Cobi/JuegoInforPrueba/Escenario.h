#include "Objeto.h"
#include "Pared.h"   //el include no es necesario que ponga “dominio”
					//porque ya estamos en dicha carpeta.
#include "Obstaculo.h"

#define MAX_PAREDES 4
#pragma once
class Escenario: public Objeto
{
private:
	Pared *paredes[MAX_PAREDES];
	//Obstaculo misObstaculos;
public:

	Escenario(void);
	Escenario(Escenario e, Vector3D v);
	Pared getPared(int i);
	~Escenario(void);

	void dibuja();
	void mueve(float t);

};