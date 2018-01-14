#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>

using namespace std;

class NodoGenerico {
public:
	NodoGenerico* siguiente;
	string elemento;
	double numero;
	NodoGenerico(string x) {
		elemento = x;
		siguiente = NULL;
	}
};
NodoGenerico* cima;