// ProyectoPolaca.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


using namespace std;

void menuTeclas();
void menu();

int main() {
	menu();
	return 0;
}

void menu() {
	int cont = 3;
	system("color f0");
	system("cls");
	string menu[] = {
		"1.- Conversion prefijo",
		"2.- Conversion postfijo",
		"3.- Salir             " };
	int cursor = 0;
	char tecla;
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		cout << "                         CALCULADORA POLACA" << endl;
		cout << "                 Daniel Corral  -  Abigail Carvajal" << endl << endl;
		for (int i = 0; i < 3; i++) {
			if (cursor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				cout << menu[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << menu[i] << endl;
			}
		}
		for (;;) {
			tecla = _getch();
			if (tecla == 80) {
				cursor++;
				if (cursor == cont)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) {
				cursor--;
				if (cursor == -1)
				{
					cursor = cont-1;
				}
				break;
			}
			if (tecla == 13) {
				switch (cursor) {
				case 0:
					system("cls");
					printf("\n*******************Conversion Prefijo****************\n");
					menuTeclas();
					break;
				case 1:
					system("cls");
					printf("\n*******************Conversion Postfijo****************\n");
					menuTeclas();
					break;
				case 2:
					system("cls");
					printf("\n GRACIAS POR UTILIZAR ESTE PROGRAMA...\n");
					exit(1);
					break;
				}
			}
		}
	}
}

void menuTeclas() {
	system("color f0");
	//system("cls");
	string menu1[] = {
		"1.- Insertar Expresion",
		"2.- Ver datos (QR)    ",
		"3.- Calcular          ",
		"4.- Pdf               ",
		"5.- About             ",
		"6.- Regresar             " };
	int cursor = 0;
	char tecla;
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		cout << "                         CALCULADORA POLACA" << endl;
		cout << "                 Daniel Corral  -  Abigail Carvajal" << endl << endl;
		for (int i = 0; i < 6; i++) {
			if (cursor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				cout << menu1[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << menu1[i] << endl;
			}
		}
		for (;;) {
			tecla = _getch();
			if (tecla == 80) {
				cursor++;
				if (cursor == 6)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) {
				cursor--;
				if (cursor == -1)
				{
					cursor = 5;
				}
				break;
			}
			if (tecla == 13) {
				switch (cursor) {
				case 0:
					system("cls");
					menuTeclas();
					break;
				case 1:
					system("cls");
					;
					menuTeclas();
					break;
				case 2:
					system("cls");

					menuTeclas();
					break;
				case 3:
					system("cls");
					menuTeclas();
					break;
				case 4:
					menuTeclas();
					break;
				case 5:
					menu();//exit(1);
					break;
				}
				break;
			}
		}
	}
}


