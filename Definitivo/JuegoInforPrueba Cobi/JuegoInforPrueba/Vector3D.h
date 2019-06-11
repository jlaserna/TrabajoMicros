/* Clase que contiene todas las posibles operaciones con las coordenadas x, y, z*/

#pragma once
class Vector3D
{
public: //atributos
	float x;
	float y;
	float z;
public: //metodos
	Vector3D(float xv=0.0f,float yv=0.0f, float zv=0.0f);
	~Vector3D(void);
	
	float modulo();						// modulo del vector
	float argumento();					// argumento del vector
	Vector3D Unitario();				// devuelve un vector unitario
	Vector3D operator - (Vector3D &);	// resta de vectores
	Vector3D operator + (Vector3D &);	// suma de vectores
	float operator *(Vector3D &);		// producto escalar
	Vector3D operator *(float);			// producto por un escalar
	Vector3D operator +=(Vector3D &);	// 
	bool operator == (Vector3D);		// operador de igualdad que compara dos vectores para comprobar si son iguales
	bool operator !=(Vector3D);			// operador de desigualdad que compara dos vectores para comprobar si son distintos
};