#include "Bloque.h"
#include "Obstaculo.h"
#include "BonusVelocidad.h"
#include "BonusMoneda.h"
#include "BonusFantasma.h"
#include "Vacio.h"
#include "ETSIDI.h"


void Bloque::generarBloqueAleatorio(Bloque b)
{
	tipoCelda tipoNuevoBloque[3];
	
	do {
		for (int i = 0; i < 3; i++) {
			switch (ETSIDI::lanzaDado(30)) {
			case 1: case 2: case 3: case 4: case 5: case 10: case 11: case 12: case 13: case 14: case 15: case 23: case 24:
				tipoNuevoBloque[i] = OBSTACULO;
				break;
			case 6: case 16: case 21: case 22: case 29: case 30:
				tipoNuevoBloque[i] = BONUSMONEDA;
				break;
			case 19:
				tipoNuevoBloque[i] = BONUSVELOCIDAD;
				break;
			case 20:
				tipoNuevoBloque[i] = BONUSFANTASMA;
				break;
			case 7: case 8: case 9: case 17: case 18: case 25: case 26: case 27: case 28:
				tipoNuevoBloque[i] = VACIO;
				break;

			}
		}

	} while (!sonCompatibles(b, tipoNuevoBloque));

	for (int i = 0; i < 3; i++) {
		switch (tipoNuevoBloque[i]) {
		case OBSTACULO:
			listaCeldas[i] = new Obstaculo();
			break;
		case BONUSMONEDA:
			listaCeldas[i] = new BonusMoneda();
			break;
		case BONUSVELOCIDAD:
			listaCeldas[i] = new BonusVelocidad();
			break;
		case BONUSFANTASMA:
			listaCeldas[i] = new BonusFantasma();
			break;
		case VACIO:
			listaCeldas[i] = new Vacio();
			break;

		}
	}

}

Bloque::Bloque()
{
	this->setPos(Vector3D(0, 2.0f, -50.0f));
	this->setVel(Vector3D(0, 0, 0.0f));
	this->setAccel(Vector3D(0, 0, 1.0f));
	listaCeldas[0] = new Vacio();
	listaCeldas[0]->setPos(this->getPos() + Vector3D(-6.5, 0,0));
	listaCeldas[1] = new Vacio();
	listaCeldas[1]->setPos(this->getPos() + Vector3D(0, 0, 0));
	listaCeldas[2] = new Vacio();
	listaCeldas[2]->setPos(this->getPos() + Vector3D(6.5, 0, 0));
}

Bloque::Bloque(Bloque b, Vector3D v)
{
	this->setPos(b.getPos() + v);
	this->setVel(b.getVel());
	this->setAccel(Vector3D(0, 0, 1.0f));
	
	generarBloqueAleatorio(b);

	listaCeldas[0]->setPos(this->getPos() + Vector3D(-6.5, 0, 0));
	listaCeldas[1]->setPos(this->getPos() + Vector3D(0, 0, 0));
	listaCeldas[2]->setPos(this->getPos() + Vector3D(6.5, 0, 0));
}

bool Bloque::sonCompatibles(Bloque b, tipoCelda* mTipoCelda)
{
	for (int i = 0; i < 3; i++) {
		switch (mTipoCelda[i]) {
		case OBSTACULO:
			break;
		case BONUSVELOCIDAD:
			if (b.getCelda(i)->getTipoCelda() == (BONUSVELOCIDAD || BONUSFANTASMA || BONUSMONEDA||  VACIO));
				return true;
			break;
		case BONUSFANTASMA:
			if (b.getCelda(i)->getTipoCelda() == (BONUSVELOCIDAD || BONUSFANTASMA || BONUSMONEDA || VACIO));
				return true;
			break;
		case BONUSMONEDA:
			if (b.getCelda(i)->getTipoCelda() == (BONUSVELOCIDAD || BONUSFANTASMA || BONUSMONEDA || VACIO));
				return true;
			break;
		case VACIO:
			if (b.getCelda(i)->getTipoCelda() == (BONUSVELOCIDAD || BONUSFANTASMA || BONUSMONEDA || VACIO));
				return true;
			break;
		}
	}
	return false;
}

Celda* Bloque::getCelda(int i)
{
	return listaCeldas[i];
}

void Bloque::dibuja()
{
	for (int i = 0; i < 3; i++) {
		listaCeldas[i]->dibuja();
	}
}

void Bloque::mueve(float t)
{
	Objeto::mueve(t);
	listaCeldas[0]->setPos(this->getPos() + Vector3D(-6.5, 0, 0));
	listaCeldas[1]->setPos(this->getPos() + Vector3D(0, 0, 0));
	listaCeldas[2]->setPos(this->getPos() + Vector3D(6.5, 0, 0));
}

Bloque::~Bloque()
{
}
