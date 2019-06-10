#include "Interaccion.h"
#include "glut.h"
#include "math.h"


Interaccion::Interaccion(void)
{
}

void Interaccion::colisionEscenario(Personaje &h)
{
	float xmax=10.0f-3.33f;
	float xmin=-10.0f+3.33f;
	float ymax=15.0f-1.0f;
	float ymin=0.0f+1.0f;

	if (h.getPos().x > xmax) {
		h.setPos(xmax, h.getPos().y, h.getPos().z);
		h.setVel(0.0f, h.getVel().y, h.getVel().z);
		h.moviendoDerecha = false;
	}
	if (h.getPos().x < xmin) {
		h.setPos(xmin, h.getPos().y, h.getPos().z);
		h.setVel(0.0f, h.getVel().y, h.getVel().z);
		h.moviendoIzquierda = false;
	}
	if (h.getPos().y > ymax) {
		h.setPos(h.getPos().x, ymax, h.getPos().z);
		h.setVel(h.getVel().x, 0.0f, h.getVel().z);
		h.subiendo = false;
		h.bajando = true;
	}
	if (h.getPos().y < ymin && !h.subiendo) {
		h.setPos(h.getPos().x, ymin, h.getPos().z);
		h.setVel(h.getVel().x, 0.0f, h.getVel().z);
	}
	if ((h.getPos().x > -0.7f && h.getPos().x < 0.7f) && (h.moviendoDerecha || h.moviendoIzquierda)) {
		h.setVel(0.0f, h.getVel().y, h.getVel().z);
		h.moviendoDerecha = false;
		h.moviendoIzquierda = false;
	}
	
}

bool Interaccion::colision(Personaje &p, Celda c)
{
	float dif = sqrt(((p.getPos().x - c.getPos().x) * (p.getPos().x - c.getPos().x)) + ((p.getPos().y - c.getPos().y) * (p.getPos().y - c.getPos().y)) + ((p.getPos().z - c.getPos().z) * (p.getPos().z - c.getPos().z)));
	if (dif <= (p.getRadio() + c.getRadio()))
	{
		return true;
	}
	return false;
}


Interaccion::~Interaccion(void)
{
}
