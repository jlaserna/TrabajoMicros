#include "Objeto.h"
#include "ETSIDI.h"
#include "Textura.h"
//using ETSIDI::SpriteSequence;

#pragma once
class Pared: public Objeto
{
protected:
	/*unsigned char rojo;
	unsigned char verde;
	unsigned char azul;*/
	//SpriteSequence sprite;
	Textura textura;

public:
	Pared(void);
	virtual ~Pared(void);
	Vector3D limite1;
	Vector3D limite2;
	void setTextura(string path) { textura.setTextura(path); }




	void dibuja();
	void setColor(unsigned char r,unsigned char v, unsigned char a);
	void setLim(Vector3D l1, Vector3D l2){limite1=l1; limite2=l2;}
	Vector3D* getLim() { Vector3D* lims[2]; lims[0] = &limite1; lims[1] = &limite2; return lims[0]; }

};
