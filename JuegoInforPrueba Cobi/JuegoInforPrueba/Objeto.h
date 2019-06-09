#include "Vector3D.h"

#pragma once
class Objeto
{
private:
	Vector3D posicion;
	Vector3D velocidad;
	Vector3D aceleracion;

	float radio;

public:
	void setVel(Vector3D velocidad) { this->velocidad = velocidad; };
	void setPos(Vector3D posicion) { this->posicion = posicion; };
	void setAccel(Vector3D aceleracion) { this->aceleracion = aceleracion; };
	void setVel(float vx, float vy, float vz) { velocidad = Vector3D(vx, vy, vz); };
	void setPos(float px, float py, float pz) { posicion = Vector3D(px, py, pz); };
	void setAccel(float ax, float ay, float az) { aceleracion = Vector3D(ax, ay, az); };
	void sumPos(Vector3D posicion) { setPos(getPos().x + posicion.x, getPos().y + posicion.y, getPos().z + posicion.z); };
	void sumVel(Vector3D velocidad) { setVel(getVel().x + velocidad.x, getVel().y + velocidad.y, getVel().z + velocidad.z); };
	void sumAccel(Vector3D aceleracion) { setAccel(getAccel().x + aceleracion.x, getAccel().y + aceleracion.y, getAccel().z + aceleracion.z); };
	Vector3D getVel() { return velocidad; };
	Vector3D getPos() { return posicion; };
	Vector3D getAccel() { return aceleracion; };
	void setRadio(float r) { this->radio = radio; };
	float getRadio() { return radio; }

	struct color
	{
		int r;
		int g;
		int b;
	} miColor;

	Objeto();
	virtual void mueve(float t);
	virtual void dibuja() = 0;
	virtual ~Objeto();
};

