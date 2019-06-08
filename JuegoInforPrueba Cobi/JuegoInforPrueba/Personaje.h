#include "Objeto.h"

#pragma once
class Personaje : public Objeto
{
	float altura;

public:
	Personaje(void);
	
	int saltos();	//compruebo si est� en el suelo, en dicho caso me deja saltar, sin� no me permite realizar un soble salto
	int giro();		//con este parametro se obtiene si va hacia la derecha o a la izquierda
	int jump();		//comprobamos si est� saltando

	void dibuja();

	friend class Interaccion;

	virtual ~Personaje(void);
};