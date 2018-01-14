#pragma once
#include "NodoGenerico.h"

using namespace std;

class PilaGenerica {
public:
	PilaGenerica() {
		cima = NULL;
	}
	//void push(string elemento);
	void push(string elemento);
	string pop();
	string cimaPila();
	bool pilaVacia();
	void limpiarPila();
};

bool PilaGenerica::pilaVacia() {
	return cima == NULL;
}

void PilaGenerica::push(string x) {
	NodoGenerico* nuevo;
	nuevo = new NodoGenerico(x);
	nuevo->siguiente = cima;
	cima = nuevo;
}

string PilaGenerica::pop() {
	if (pilaVacia())
		throw "Pila vacía...";
	string aux = cima->elemento;
	cima = cima->siguiente;
	return aux;
}

string PilaGenerica::cimaPila() {
	if (pilaVacia())
		throw "Pila vacia...";
	return cima->elemento;
}

void PilaGenerica::limpiarPila() {
	NodoGenerico* n;
	while (!pilaVacia()) {
		n = cima;
		cima = cima->siguiente;
		delete n;
	}
}