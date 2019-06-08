#include "Vector3D.h"

#pragma once
class Objeto
{
private:
	Vector3D posicion;
	Vector3D velocidad;
	Vector3D aceleracion;

protected:
	void setVel(Vector3D velocidad) { this->velocidad = velocidad; };
	void setPos(Vector3D posicion) { this->posicion = posicion; };
	void setAccel(Vector3D aceleracion) { this->aceleracion = aceleracion; };
	void setVel(float vx, float vy, float vz) { velocidad = Vector3D(vx, vy, vz); };
	void setPos(float px, float py, float pz) { posicion = Vector3D(px, py, pz); };
	void setAccel(float ax, float ay, float az) { aceleracion = Vector3D(ax, ay, az); };
	Vector3D getVel() { return velocidad; };
	Vector3D getPos() { return posicion; };
	Vector3D getAccel() { return aceleracion; };

public:
	Objeto();
	virtual void mueve(float t) { posicion += velocidad * t + aceleracion * t * t * 0.5f; velocidad += aceleracion * t; };
	virtual void dibuja() = 0;
	virtual ~Objeto();
};

