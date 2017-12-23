#include <iostream>
#include <conio.h>
#include <string>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void menuTeclas();

int main(){
	menuTeclas();
	return 0;
}

void menuTeclas() {
	system("color f0");
	system("cls");
	string menu[] = {
    "1.- Insertar Expresion",
	"2.- Ver datos (QR)    ",
	"3.- Calcular          ",
	"4.- Pdf               ",
	"5.- About             ",
	"6.- Salir             " };
	int cursor = 0;
	char tecla;
	for (;;){
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		cout << "                         CALCULADORA POLACA" << endl;
		cout << "                 Daniel Corral  -  Abigail Carvajal" << endl << endl;
		for (int i = 0; i < 6; i++){
			if (cursor == i){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				cout << menu[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
			}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << menu[i] << endl;
			}
		}
		for (;;){
			tecla = _getch();
			if (tecla == 80){
				cursor++;
				if (cursor == 6)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72){
				cursor--;
				if (cursor == -1)
				{
					cursor = 5;
				}
				break;
			}
			if (tecla == 13){
				switch (cursor){
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
					exit(1);
					break;
				}
				break;
			}
		}
	}
}
