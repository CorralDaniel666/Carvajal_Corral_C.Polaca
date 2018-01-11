#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>

class NodoGenerico {
public:
	NodoGenerico* siguiente;
	char elemento;
	float numero;
	NodoGenerico(char x) {
		elemento = x;
		siguiente = NULL;
	}
};
NodoGenerico* cima;