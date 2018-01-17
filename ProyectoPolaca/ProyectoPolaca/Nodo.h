#pragma once
#include "stdafx.h"
#include"Pila.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include <sstream>

using namespace std;


Pila *pila = NULL;
void poner(string dat)
{
	Pila *nuevo = new Pila();
	if (pila == NULL)
	{
		nuevo->setDat(dat);
		nuevo->setSgt(NULL);
		pila = nuevo;
	}
	else
	{
		nuevo->setDat(dat);
		nuevo->setSgt(pila);
		pila = nuevo;
	}
}
string pop()
{
	Pila *aux = pila;
	string retu;
	retu = aux->getDat();
	aux = aux->getSgt();
	pila = aux;
	return aux->getDat();
}
void imprimir()
{
	Pila *aux = pila;
	if (pila != NULL)
	{
		do
		{
			cout << aux->getDat() << endl;
			if (aux->getSgt() != NULL)
			{
				aux = aux->getSgt();
			}
		} while (aux != NULL);
	}

}
