#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "NodoGenericoD.h"

using namespace std;
class PilaGenericaD {
public:
	PilaGenericaD() {
		cimaGen = NULL;
	}
	void push(double elemento);
	double pop();
	double cimaPila();
	double cimaPila2();
	bool pilaVacia();
	void limpiarPila();

};


bool PilaGenericaD::pilaVacia() {
	return cimaGen == NULL;
}

void PilaGenericaD::push(double x) {
	NodoGenericoD* nuevo;
	nuevo = new NodoGenericoD(x);
	nuevo->siguiente = cimaGen;
	cimaGen = nuevo;
}

double PilaGenericaD::pop() {
	if (pilaVacia())
		throw "Pila vacía...";
	double aux = cimaGen->elemento;
	cimaGen = cimaGen->siguiente;
	return aux;
}

double PilaGenericaD::cimaPila() {
	if (pilaVacia())
		throw "Pila vacia...";
	return cimaGen->elemento;
}

double PilaGenericaD::cimaPila2() {
	if (pilaVacia()) {
		throw "Pila vacia";
	}
	return cimaGen->numero;
}

void PilaGenericaD::limpiarPila() {
	NodoGenericoD* n;
	while (!pilaVacia()) {
		n = cimaGen;
		cimaGen = cimaGen->siguiente;
		delete n;
	}
}