#pragma once
#include "Objeto.h"

enum tipoCelda { OBSTACULO, BONUS, VACIO , NONE, BONUSMONEDA, BONUSVELOCIDAD, BONUSFANTASMA};

class Celda :
	public Objeto
{
public:
	tipoCelda miTipoCelda;
	bool activo;
public:
	Celda();
	void dibuja();
	virtual ~Celda();
	tipoCelda getTipoCelda() { return miTipoCelda; };
	void desactivar() { activo = false; }
	bool estaActivo() { return activo; }
	friend class Interaccion;
};

