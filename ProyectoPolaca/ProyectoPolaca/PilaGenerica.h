#pragma once
#include "NodoGenerico.h"

class PilaGenerica {
public:
	PilaGenerica() {
		cima = NULL;
	}
	void push(char elemento);
	char pop();
	char cimaPila();
	bool pilaVacia();
	void limpiarPila();
};

bool PilaGenerica::pilaVacia() {
	return cima == NULL;
}

void PilaGenerica::push(char x) {
	NodoGenerico* nuevo;
	nuevo = new NodoGenerico(x);
	nuevo->siguiente = cima;
	cima = nuevo;
}

char PilaGenerica::pop() {
	if (pilaVacia())
		throw "Pila vacía...";
	int aux = cima->elemento;
	cima = cima->siguiente;
	return aux;
}

char PilaGenerica::cimaPila() {
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