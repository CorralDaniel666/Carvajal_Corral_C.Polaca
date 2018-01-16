#pragma once
#include <stdlib.h>

using namespace std;

class NodoGenericoD {
public:
	NodoGenericoD* siguiente;
	double elemento;
	double numero;
	NodoGenericoD(double x) {
		elemento = x;
		siguiente = NULL;
	}
};
NodoGenericoD* cimaGen;