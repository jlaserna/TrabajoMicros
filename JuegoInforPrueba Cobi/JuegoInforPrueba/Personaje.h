#include "Objeto.h"

#pragma once
class Personaje : public Objeto
{
	float altura;

public:
	Personaje(void);
	
	int saltos();	//compruebo si está en el suelo, en dicho caso me deja saltar, sinó no me permite realizar un soble salto
	int giro();		//con este parametro se obtiene si va hacia la derecha o a la izquierda
	int jump();		//comprobamos si está saltando

	void dibuja();

	friend class Interaccion;

	virtual ~Personaje(void);
};