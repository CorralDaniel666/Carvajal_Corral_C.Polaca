#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

class Pila {
private:
	string dat;
	Pila *sgt;
	Pila *ant;
public:
	void setDat(string dat);
	void setSgt(Pila *sgt);
	string getDat();
	Pila * getSgt();

};
void Pila::setDat(string dat)
{
	this->dat = dat;
}
void Pila::setSgt(Pila *sgt)
{
	this->sgt = sgt;
}
string Pila::getDat()
{

	return dat;
}
Pila *  Pila::getSgt()
{
	return sgt;
}