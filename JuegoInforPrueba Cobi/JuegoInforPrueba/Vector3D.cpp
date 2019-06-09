#include "Vector3D.h"
#include <math.h>

Vector3D::Vector3D(float xv,float yv, float zv)
{
	x=xv;
	y=yv;
	z=zv;
}

float Vector3D::modulo()
{
	return (float)sqrt(x*x+y*y+z*z);
} 

Vector3D Vector3D::Unitario()
{
	Vector3D retorno(x,y,z);
	float mod=modulo();
		if(mod>0.00001)
		{
			retorno.x/=mod;
			 retorno.y/=mod;
			 retorno.z/=mod;
		}  
		return retorno;
}

Vector3D Vector3D::operator - (Vector3D &v)
{
	Vector3D res;
	res.x=x-v.x;
	res.y=y-v.y;
	res.z=z-v.z;
	return res;
} 
 
Vector3D Vector3D::operator + (Vector3D &v)
{
	Vector3D res;
	res.x=x+v.x;
	res.y=y+v.y;
	res.z=z+v.z;
	return res;
}

 float Vector3D::operator *(Vector3D &v)
 {
	Vector3D res;
	float resultado;
	res.x=x*v.x;
	res.y=y*v.y;
	res.z=z*v.z;
	return resultado= res.x+res.y+res.z;
 }

 Vector3D Vector3D::operator *(float e)
 {
	Vector3D res;
	res.x=x*e;
	res.y=y*e;
	res.z=z*e;
	return res;
 }

 Vector3D Vector3D::operator +=(Vector3D& v)
 {
	 this->x += v.x;
	 this->y += v.y;
	 this->z += v.z;
	 return *this;
 }

 bool Vector3D::operator == (Vector3D v)
 {
	 if(this->x == v.x && this->y == v.y && this->z == v.z) return true;
	 else return false;
 }

Vector3D::~Vector3D(void)
{
}
