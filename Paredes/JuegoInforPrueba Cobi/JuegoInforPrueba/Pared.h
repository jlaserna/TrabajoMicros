#include "Objeto.h"

#pragma once
class Pared: public Objeto
{
protected:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	//Vector3D centro;	//centro geométrico de las paredes
public:
	Pared(void);
	virtual ~Pared(void);
	/*unsigned char rojo;
	unsigned char verde;
	unsigned char azul;*/
	Vector3D limite1;
	Vector3D limite2;




	void dibuja();
	void setColor(unsigned char r,unsigned char v, unsigned char a);
	void setLim(Vector3D l1, Vector3D l2){limite1=l1; limite2=l2;}

};




///////////////////////////////////////////////////////////////
/*PARA PROBAR CON ESQUINAS
	Vector3D esquina1;
	Vector3D esquina2;
	Vector3D esquina3;
	Vector3D esquina4;
	*/