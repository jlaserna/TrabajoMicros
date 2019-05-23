//
//  BloqueAlternativo.cpp
//  Juego
//
//  Created by Javier Laserna Moratalla on 23/05/2019.
//  Copyright © 2019 Javier Laserna Moratalla. All rights reserved.
//

#include "BloqueAlternativo.h"
#include <GLUT/glut.h>

void BloqueAlternativo::init(int izq, int mid, int der) {
    celdas[0] = new Obstaculo(posicion.x-ancho/3, posicion.y, posicion.z, izq);
    celdas[1] = new Obstaculo(posicion.x, posicion.y, posicion.z, mid);
    celdas[2] = new Obstaculo(posicion.x+ancho/3, posicion.y, posicion.z, der);
}

void BloqueAlternativo::Dibuja() {
    glPushMatrix();
    glTranslatef(posicion.x,posicion.y,posicion.z);
   
    for(int i = 0; i < 3; i++) {
        celdas[i]->Dibuja();
    }
    
    glPopMatrix();
}

void BloqueAlternativo::Mueve(float t) {
    posicion.z = posicion.z + velocidad.z * t + 0.5*t*t*aceleracion.z;
}
