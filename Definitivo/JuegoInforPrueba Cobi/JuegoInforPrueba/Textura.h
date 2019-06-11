#pragma once

#include <sstream>

using namespace std;

class Textura {
private:
	string textura;

public:
	void setTextura(string textura) { this->textura = textura; }
	string getTextura() { return textura; }
};