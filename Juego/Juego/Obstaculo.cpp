//
//  Obstaculo.cpp
//  Juego
//
//  Created by Javier Laserna Moratalla on 23/05/2019.
//  Copyright © 2019 Javier Laserna Moratalla. All rights reserved.
//

#include "Obstaculo.h"
#include <GLUT/glut.h>

void Obstaculo::Mueve(float t) {
    
}

void Obstaculo::Dibuja() {
    glPushMatrix();
    glTranslatef(posicion.x,posicion.y,posicion.z);
    switch (tipo) {
        case 0:
            glColor3f(0.0f,1.0f,0.0f);
            break;
            
        case 1:
            glColor3f(0.0f,1.0f,1.0f);
            break;
            
        case 2:
            glColor3f(1.0f,0.5f,0.5f);
            break;
    }
    
    glutSolidSphere(1.0, 20.0, 20.0);
    glPopMatrix();}

Obstaculo::~Obstaculo() {
    
}
