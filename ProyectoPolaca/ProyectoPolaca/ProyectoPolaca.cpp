// ProyectoPolaca.cpp: define el punto de entrada de la aplicación de consola.//
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <direct.h>//mkdir
#include <time.h>
#include <ctime>
#include "PilaGenerica.h"
#include "PilaGenericaD.h"
#include "qrcodegen.h"

struct Elemento {
	string ope;
	bool operador;
};

struct Expresion {
	Elemento* expr;
	int n;
};

using namespace std;

void asignar(string);
bool valido(string);
bool operando(string c);
int prdadDentro(string operador);
int prdadFuera(string operando);
string postfija(string, int);
string separarDato(string , char *dato, int &pos);
void guardar(string , char *archivo);
double Evalua(Expresion postfija, double v[]);
void  generarQr(char *);
static void generarQrBasico(char dato1[]);
static void printQr(const uint8_t qrcode[]);
string Prefija(string expresion, int num);
int prdadDentroPre(string operador);
int prdadFueraPre(string operando);
void crear_carpeta();
void menuMouse();
void leertxt();
string leertxt1();
void caratula();
void guardarAg(string expresion, char *archivo);
bool valido2(string expresion[25]);
void menuPrefija();


int main() {
	caratula();
	menuMouse();
	return 0;
}

void caratula()
{
	printf("\t|_____________________________________________________________|\n");
	printf("\t||___________________________________________________________||\n");
	printf("\t|||_________________________________________________________|||\n");
	printf("\t|||                                                         |||\n");
	printf("\t|||          Universidad de las Fuerzas Armadas             |||\n");
	printf("\t|||                       E.S.P.E.                          |||\n");
	printf("\t|||                                                         |||\n");
	printf("\t|||                Estructuras de Datos                     |||\n");
	printf("\t|||                   Ing. Edgar Solis                      |||\n");
	printf("\t|||                      NRC: 2479                          |||\n");
	printf("\t|||                                                         |||\n");
	printf("\t|||                  Calculadora Polaca                     |||\n");
	printf("\t|||                                                         |||\n");
	printf("\t|||                   Desarrollado por:                     |||\n");
	printf("\t|||           Abigail Carvajal y Daniel Corral              |||\n");
	printf("\t|||_________________________________________________________|||\n");
	printf("\t||___________________________________________________________||\n");
	printf("\t|_____________________________________________________________|\n");
	getch();
}

void guardarAg(string expresion, char *archivo) {
	FILE *ptr;
	string nombre;

	ptr = fopen(archivo, "w"); //REALIZO LA APERTURA DEL ARCHIVO
	if (ptr == NULL)
	{
		printf("ERROR.\n");
	}
	else
	{
		nombre = expresion.c_str();
		//fputs(nombre,ptr);
		fprintf(ptr, "%s \n", nombre.c_str());
		fclose(ptr);
	}
}

void menuMouse() {
	string palabra1;
	system("cls");
	system("color f0");
	cout << "**************************************************************\n\t\t\t ";
	cout << " CALCULADORA POLACA\n" << endl;
	printf(" 1. Conversion \n\n");
	printf(" 2. Leer Backup\n\n");
	printf(" 3. Ayuda\n\n");
	printf(" 4. Sobre nosotros\n\n");
	printf(" 5. Salir\n\n");
	HANDLE paraEntrada = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD regEntrada;
	DWORD evento;
	COORD coordenadas;
	SetConsoleMode(paraEntrada, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		ReadConsoleInput(paraEntrada, &regEntrada, 1, &evento);
		if (regEntrada.EventType == MOUSE_EVENT)
		{
			if (regEntrada.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				coordenadas.X = regEntrada.Event.MouseEvent.dwMousePosition.X;
				coordenadas.Y = regEntrada.Event.MouseEvent.dwMousePosition.Y;
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 3)
				{
					system("cls");
					printf("\n*******************Conversion ****************\n");
					//menuTeclasPre();
					menuPrefija();
					menuMouse();
				}

				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 5)
				{
					system("cls");
					printf("\n***************Recuperado desde Backup*****************\n");
					leertxt();
					system("cls");
					menuMouse();
				}

				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 7)
				{
					system("cls");
					ShellExecute(NULL, L"open", L"C:/Users/Administrador1/Desktop/pp1/Carvajal_Corral_C.Polaca/Carvajal_Corral_C.Polaca/ProyectoPolaca/ManualdeUsuario.chm", NULL, NULL, SW_SHOWNORMAL);
					system("pause");
					system("cls");
					menuMouse();
				}

				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 9)
				{
					system("cls");
					printf("\n****************SOBRE NOSOTROS******************");
					system("imagen.jpg");
					system("pause");
					system("cls");
					menuMouse();
				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 11)
				{
					system("cls");
					printf("6");
					system("cls");
					printf("\n\n\t****************************\n");
					printf("\tGracias por usar el programa\n");
					printf("\t****************************\n");
					system("Start C:/Users/Administrador1/Desktop/pp1/Carvajal_Corral_C.Polaca/Carvajal_Corral_C.Polaca/ProyectoPolaca/ProyectoPolaca/PDF.jar");
					crear_carpeta();
					getch();
					exit(0);
				}
			}
		}
	}
}

void menuPrefija() {
	string palabra1;
	string cad;
	char tecla;
	char nombreArchivo[14] = "prefija.txt";
	PilaGenerica pila;
	Expresion post;
	string cadena, cverdad;
	char cadena1[30];
	bool desapila;
	int n = -1, i = 0, num;
	system("cls");
	system("color f0");
	cout << "\t\t\t ";
	cout << "\n\t\tCONVERSION \n" << endl;
	printf(" 1. Insertar Expresion\n\n");
	printf(" 2. Ayuda\n\n");
	printf(" 3. Regresar al Menu Principal\n\n");
	HANDLE paraEntrada = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD regEntrada;
	DWORD evento;
	COORD coordenadas;
	SetConsoleMode(paraEntrada, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		ReadConsoleInput(paraEntrada, &regEntrada, 1, &evento);
		if (regEntrada.EventType == MOUSE_EVENT)
		{
			if (regEntrada.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				coordenadas.X = regEntrada.Event.MouseEvent.dwMousePosition.X;
				coordenadas.Y = regEntrada.Event.MouseEvent.dwMousePosition.Y;
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 3)
				{
					system("cls");
					printf("\n\n*******************Conversion Prefijo****************\n");
					cout << "Ingrese funcion: " << endl;
					cin >> cadena;
					num = cadena.size();
					cverdad = Prefija(cadena, num);
					guardar(cadena, nombreArchivo);
					for (i = 0; i < cverdad.size(); i++)
						cadena1[i] = cverdad[i];
					cadena1[i] = '\0';
					system("Start C:/Users/Administrador1/Desktop/pp1/Carvajal_Corral_C.Polaca/Carvajal_Corral_C.Polaca/ProyectoPolaca/ProyectoPolaca/Mongo.jar");
					generarQr(cadena1);
					pila.limpiarPila();
					getch();
					menuPrefija();
				}

				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 5)
				{
					system("cls");
					printf("\n**********MANUAL DE USUARIO**********");
					ShellExecute(NULL, L"open", L"C:/Users/Administrador1/Desktop/pp1/Carvajal_Corral_C.Polaca/Carvajal_Corral_C.Polaca/ProyectoPolaca/ManualdeUsuario.chm", NULL, NULL, SW_SHOWNORMAL);
					getch();
					menuPrefija();

				}
				if (coordenadas.X >0 && coordenadas.X <= 50 && coordenadas.Y == 7)
				{
					menuMouse();
				}
			}
		}
	}
}

void leertxt()
{
	char cadena[20];
	FILE *fichero;
	fichero = fopen("respaldo.txt", "r");
	while (!feof(fichero)) {
		fgets(cadena, 20, fichero);
	}
	fclose(fichero);
	cout << "Expresion =" << cadena;
	system("pause");
}

string leertxt1()
{
	char cadena[40],aux[20];
	FILE *fichero;
	fichero = fopen("respaldo.txt", "r");
	while (!feof(fichero)) {
		fgets(cadena, 20, fichero);
	}
	fclose(fichero);

	return cadena;
}

bool valido(char expr[20]) {
	bool sw = true;
	for (int i = 0; (i<strlen(expr) && sw); i++) {
		char c;
		c = expr[i];
		sw = sw && (
			(c >= 'A' && c <= 'Z') ||
			(c >= 'a' && c <= 'z') ||
			(c >= '0' && c <= '9') ||
			(c == '^') || (c == '/') || (c == '*') ||
			(c == '+') || (c == '-') || (c == '\n') ||
			(c == '(') || (c == ')')
			);
	}
	return sw;
}

bool operando(char c) { //determina si el caracter es un operando
	return(c >= '0'&& c <= '9');
}

int prdadDentro(char operador) { //prioridad del operador en la expresion
	int pdp=0;
	switch (operador) {
	case '^':
		pdp = 3;
		break;
	case '*': case '/':
		pdp = 2;
		break;
	case '+': case '-':
		pdp = 1;
		break;
	case '(':
		pdp = 0;

	}
	return pdp;
}

int prdadFuera(char operando) { //prioridad del operador en la expresion infija
	int pfp=0;
	switch (operando)
	{
	case '^':
		pfp = 4;
		break;
	case '*': case '/':
		pfp = 2;
		break;
	case '+': case '-':
		pfp = 1;
		break;
	case '(':
		pfp = 5;
	}
	return pfp;
}

string postfija(string expresion, int num) {
	PilaGenerica pila;
	Expresion post;
	Elemento elemento[25];
	string tokens[25];
	char nombreArchivo[14] = "polaca.txt";
	string ch, opeCima;
	char dato[25] = "";
	int cont = 0, n = -1, i = 0;
	bool desapila,val;

		for (int j = 0; j < num; j++) {
			tokens[j] = separarDato(expresion, dato, j);
			ch = tokens[j];
			//cout << "\ntoken = " << ch.c_str();
			//printf("\n");
			if (operando(ch.c_str())) {
				n++;
				elemento[n].ope = ch.c_str();
				elemento[n].operador = false;
				guardar("Expresion :", nombreArchivo);
				guardar(elemento[n].ope.c_str(), nombreArchivo);
				//printf("\nELEMENTO = %s Operando = %d\n", elemento[n].ope.c_str(), elemento[n].operador);
			}
			else if (ch.compare(")")) {
				desapila = true;
				while (desapila) {
					opeCima = " ";
					if (!pila.pilaVacia()) {
						opeCima = pila.cimaPila();
					}
					if (pila.pilaVacia() || (prdadFuera(ch.c_str()) > prdadDentro(opeCima))) { //si la pila esta vacia o si la prioridad del caracter de fuera > prioridad que el que esta dentro
																							   //printf("\naqui llego 4 ch = %s", ch.c_str());
						pila.push(ch.c_str());
						desapila = false;

					}
					else if (prdadFuera(ch.c_str()) <= prdadDentro(opeCima)) {
						elemento[++n].ope = pila.pop();
						elemento[n].operador = true;
						guardar("Pila :", nombreArchivo);
						guardar(elemento[n].ope.c_str(), nombreArchivo);
						//printf("\naqui llego 5");
					}
				}
			}

			else { //si es )
				opeCima = pila.pop();
				if (opeCima.compare("(")) {
					//printf("\n\nOPECIMA = %s", opeCima.c_str());
					do {
						if (!pila.pilaVacia()) {
							elemento[++n].ope = opeCima;
							elemento[n].operador = true;
							opeCima = pila.pop();
							guardar("Pila :", nombreArchivo);
							guardar(elemento[n].ope.c_str(), nombreArchivo);
						}
						//printf("\n\nOPECIMA = %s",opeCima.c_str());
					} while (opeCima != "(");
				}
			}

		}

		while (!pila.pilaVacia()) {
			elemento[++n].ope = pila.pop();
			elemento[n].operador = true;
			guardar("Expresion :", nombreArchivo);
			guardar(elemento[n].ope.c_str(), nombreArchivo);
		}
		//Expresion post;
		post.expr = elemento;
		post.n = n;
		string cverdad;
		double valor, v[26];
		//printf("\ntotal elementos %d\n", n);
		cout << "\n\n\tExpresion Postfija:\t";
		for (int i = 0; i <= post.n; i++)
		{
			printf("%s ", post.expr[i].ope.c_str());
			cverdad.append(post.expr[i].ope.c_str());
		}
		guardarAg(cverdad, nombreArchivo);
		//system("Start C:/Users/Administrador1/Desktop/pp1/Carvajal_Corral_C.Polaca/Carvajal_Corral_C.Polaca/ProyectoPolaca/ProyectoPolaca/WinAppMSAgentsManagement/WinAppMSAgentsManagement/bin/Debug/WinAppMSAgentsManagement.exe");
		valor = Evalua(post, v);
		cout << "\n\n\tValor de la expresion =  " << valor;
		printf("\n");
		return cverdad;
	
}

string Prefija(string expresion,int num) {
	PilaGenerica pila;
	Expresion pre;
	Elemento elemento[25];
	string tokens[25];
	string ch, opeCima, expresionV;
	char dato[25] = "";
	int cont = 0, n = -1, i = 0,h;
	bool desapila,val;
	char nombreArchivo[13] = "respaldo.txt";

	//Valido que la expresion sea valida
	for (int j = 0; j < num; j++) {
		//separo la expresion
		tokens[j] = separarDato(expresion, dato, j);
	}
	val=valido2(tokens);
	
	if (val==false) {
		system("cls");
		printf("\nCaracter no valido en la expresion\nIntente ingresando nuevamente la cadena");
		getch();
		menuPrefija();
	}
	else {
		for (int k = num - 1; k >= 0; k--) {
			ch = tokens[k];
			//cout << "\ntoken = " << ch.c_str();
			//printf("\n");
			if (operando(ch.c_str())) {
				n++;
				elemento[n].ope = ch.c_str();
				elemento[n].operador = false;
				guardar("Expresion :", nombreArchivo);
				guardar(elemento[n].ope.c_str(), nombreArchivo);
				//printf("\nELEMENTO = %s Operando = %d\n", elemento[n].ope.c_str(), elemento[n].operador);
			}
			else if (ch.compare("(")) {
				desapila = true;
				while (desapila) {
					opeCima = " ";
					if (!pila.pilaVacia()) {
						opeCima = pila.cimaPila();
					}
					if (pila.pilaVacia() || (prdadFueraPre(ch.c_str()) >= prdadDentroPre(opeCima))) { //si la pila esta vacia o si la prioridad del caracter de fuera > prioridad que el que esta dentro
																									  //printf("\naqui llego 4 ch = %s", ch.c_str());
						pila.push(ch.c_str());
						desapila = false;

					}
					else if (prdadFueraPre(ch.c_str()) < prdadDentroPre(opeCima)) {
						elemento[++n].ope = pila.pop();
						elemento[n].operador = true;
						guardar("Pila :", nombreArchivo);
						guardar(elemento[n].ope.c_str(), nombreArchivo);
						//printf("\naqui llego 5");
					}
				}
			}

			else { //si es (
				opeCima = pila.pop();
				if (opeCima.compare(")")) {
					//printf("\n\nOPECIMA = %s", opeCima.c_str());
					do {
						elemento[++n].ope = opeCima;
						elemento[n].operador = true;
						opeCima = pila.pop();
						guardar("Expresion :", nombreArchivo);
						guardar(elemento[n].ope.c_str(), nombreArchivo);
						//printf("\n\nOPECIMA = %s",opeCima.c_str());
					} while (opeCima != ")");
				}
			}
		}

		while (!pila.pilaVacia()) {
			elemento[++n].ope = pila.pop();
			elemento[n].operador = true;
			guardar("Expresion :", nombreArchivo);
			guardar(elemento[n].ope.c_str(), nombreArchivo);
		}
		//Expresion pre;
		pre.expr = elemento;
		pre.n = n;
		string cverdad;
		double valor, v[26];
		//printf("\ntotal elementos %d\n", n);
		cout << "\n\tExpresion Prefija:\t";
		for (int i = pre.n; i >= 0; i--)
		{
			printf("%s ", pre.expr[i].ope.c_str());
			cverdad.append(pre.expr[i].ope.c_str());
		}

		postfija(expresion, num);
		guardarAg(cverdad, nombreArchivo);
		system("Start C:/Users/Administrador1/Desktop/pp1/Carvajal_Corral_C.Polaca/Carvajal_Corral_C.Polaca/ProyectoPolaca/ProyectoPolaca/WinAppMSAgentsManagement/WinAppMSAgentsManagement/bin/Debug/WinAppMSAgentsManagement.exe");
		system("Start C:/Users/Administrador1/Desktop/pp1/Carvajal_Corral_C.Polaca/Carvajal_Corral_C.Polaca/ProyectoPolaca/ProyectoPolaca/Mongo.jar");
		return cverdad;
	}

	
}

double Evalua(Expresion postfija, double v[]) {
	PilaGenericaD pilaGen;
	double valor, a, b;
	int cont = 0;
	/*string ep = postfija.expr[0].ope;
	if (!ep.compare("+") || !ep.compare("-") || !ep.compare("*") || !ep.compare("/") || !ep.compare("^")) {
		printf("\t\nNo se puede evaluar un solo signo\n\tIntente ingresando nuevamente\n");
		getch();
		menuPrefija();
	}*/
		/*else {
			string aux1;
			string aux = postfija.expr[1].ope;
			if (!aux.compare("+") || !ep.compare("-")) {
				aux1.append(aux);
				aux1.append(ep);
				return atof(aux1.c_str());
			}
			else
				return atof(ep.c_str());
		}*/
	//else {
	for (int i = 0; i <= postfija.n; i++) {
			string op;
			if (postfija.expr[i].operador) {
				op = postfija.expr[i].ope;
				/*printf("operador: %s\n", op.c_str());*/
				if (!op.compare("sen") || !op.compare("cos") || !op.compare("tan") || !op.compare("sqrt")) {
					if (cont != 1) {
						b = pilaGen.pop();
						a = pilaGen.pop();
						/*printf(" \na: %f\n", a);
						printf(" \nb:%f\n", b);*/
						if (!op.compare("sen")) {
							valor = sin(b);
						}
						else if (!op.compare("cos")) {
							valor = cos(b);
						}
						else if (!op.compare("tan")) {
							valor = tan(b);
						}
						else if (!op.compare("sqrt")) {
							valor = sqrt(b);
						}
						pilaGen.push(a);
						pilaGen.push(valor);
					}
					else {
						a = pilaGen.pop();
						if (!op.compare("sen")) {
							valor = sin(a);
						}
						else if (!op.compare("cos")) {
							valor = cos(a);
						}
						else if (!op.compare("tan")) {
							valor = tan(a);
						}
						else if (!op.compare("sqrt")) {
							valor = sqrt(a);
						}
						pilaGen.push(valor);
					}


				}
				else if (!op.compare("+") || !op.compare("-") || !op.compare("*") || !op.compare("/") || !op.compare("^")) {
					b = pilaGen.pop();
					a = pilaGen.pop();
					/*printf(" \nImprimen en else a: %f\n", a);
					printf(" \nImprime en else b:%f\n", b);
					printf("operador: %s\n", op.c_str());*/
					if (!op.compare("^")) {
						valor = pow(a, b);
					}
					else if (!op.compare("*")) {
						valor = a*b;
					}
					else if (!op.compare("/")) {
						if (b != 0.0)
							valor = a / b;
						else {
							printf("\nNo se puede realizar division para cero\nIntente ingresando otra expresion!");
							getch();
							menuPrefija();
							break;
						}

					}
					else if (!op.compare("+")) {
						valor = a + b;
					}
					else if (!op.compare("-")) {
						valor = a - b;
					}
					pilaGen.push(valor);
				}

			}
			else {
				int indice;
				double aa;
				op = postfija.expr[i].ope;
				aa = atof(op.c_str());
				pilaGen.push(aa);
				cont++;
			}
		}
		return pilaGen.pop();
}

string separarDato(string expresion, char *dato, int &pos)
{
	string aux;
	char p, p1[2];
	p = expresion[pos];
	//printf("\np : %c\n", p);
	if (p == '+' || p == '-' || p == '*' || p == '/' || p == '^' || p == '(' || p == ')')
	{
		p1[0] = p;
		p1[1] = '\0';
		strcpy(dato, p1);
		//pos++;
		aux = dato;
		//cout << "\nen if dato: " << dato<<"posicion ="<<pos;
		return aux;
	}
	else
	{
		p1[0] = '\0';
		strcpy(dato, p1);
		do
		{
			p = expresion[pos];
			if (p == '\0' || p == '+' || p == '-' || p == '*' || p == '/' || p == '^' || p == '(' || p == ')')break;
			p1[0] = p;
			p1[1] = '\0';
			strcat(dato, p1);
			//printf(" \np es: %c \n", p);
			pos++;
		} while (true);
		pos--;
		//if (strcmp(dato, "sen") == 0) strcpy(dato, "sen");
		//if (strcmp(dato, "cos") == 0) strcpy(dato, "cos");
		//if (strcmp(dato, "tan") == 0) strcpy(dato, "tan");
	}

	//cout << "\ndato: " << dato<< "posicion"<< pos;
	aux = dato;
	return aux;
}

bool valido(string expr) {
	bool sw = true;
	printf("expresion %s:", expr.c_str());
	system("pause");
	for (int i = 0; (i<expr.size() && sw); i++) {
		string c;
		c = expr[i];
		sw = sw && (
			(c >= "a" ||c <= "z")||
			(c >= "0" && c <= "9") ||
			(c == "^") || (c == "/") || (c == "*") ||
			(c == "+") || (c == "-") || (c == "\n") ||
			(c == "(") || (c == ")")
			);
	}
	return sw;
}

bool valido2(string expresion[25]) {
	bool sw = true;
	for (int i = 0; i<25; i++) {
		if (!expresion[i].compare("sen") || !expresion[i].compare("0") || !expresion[i].compare("1") || !expresion[i].compare("2") || !expresion[i].compare("3") ||
			!expresion[i].compare("4") || !expresion[i].compare("5") || !expresion[i].compare("6") || !expresion[i].compare("7") || !expresion[i].compare("8") ||
			!expresion[i].compare("(") || !expresion[i].compare(")") || !expresion[i].compare("+") || !expresion[i].compare("-") || !expresion[i].compare("*") ||
			!expresion[i].compare("/") || !expresion[i].compare("cos") || !expresion[i].compare("tan")||!expresion[i].compare("\0")|| !expresion[i].compare("^")|| !expresion[i].compare("sqrt"))
		{
			sw = sw && true;
			//printf("validar en funcion = %d", sw);
		}
		else if (operando(expresion[i])) {
			sw = sw && true;
		}
		else {
			sw = sw && false;
			printf("validar en funcion = %d", sw);
		}
	}
	
	return sw;
}

bool operando(string c) { //determina si el caracter es un operando
	
	return(c >= "0" && c <= "999");
}

int prdadDentro(string operador) { //prioridad del operador en la expresion (dentro de la pila)
	int pdp = 0;

	if (operador == "^" || operador == "sen" || operador =="cos" || operador =="tan")
		pdp = 3;
	else if (operador == "*" || operador == "/")
		pdp = 2;
	else if (operador == "+" || operador == "-")
		pdp = 1;
	else if (operador == "(")
		pdp = 0;
	return pdp;
}

int prdadFuera(string operando) { //prioridad del operador en la expresion infija
	int pfp = 0;
	if (operando == "^" || operando == "sen" || operando=="cos"|| operando=="tan")
		pfp = 4;
	else if (operando == "*" || operando == "/")
		pfp = 2;
	else if (operando == "+" || operando == "-")
		pfp = 1;
	else if (operando == "(")
		pfp = 5;
	return pfp;
}

void guardar(string expresion, char *archivo) {
	FILE *ptr;
	string nombre;

	ptr = fopen(archivo, "a"); //REALIZO LA APERTURA DEL ARCHIVO
	if (ptr == NULL)
	{
		printf("ERROR.\n");
	}
	else
	{
		expresion += "\n";
		nombre = expresion.c_str();
		//fputs(nombre,ptr);
		fprintf(ptr, " %s", nombre.c_str());
		
		fclose(ptr);
	}
}

void generarQrBasico(char dato1[]) {
	char *dato = dato1;  // User-supplied text
	enum qrcodegen_Ecc errCorLvl = qrcodegen_Ecc_LOW;  // Error correction level

													   // Make and print the QR Code symbol
	uint8_t qrcode[qrcodegen_BUFFER_LEN_MAX];
	uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];
	bool ok = qrcodegen_encodeText(dato, tempBuffer, qrcode, errCorLvl,
		qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, qrcodegen_Mask_AUTO, true);
	if (ok)
		printQr(qrcode);
}

static void printQr(const uint8_t qrcode[]) {
	int size = qrcodegen_getSize(qrcode);
	int border = 4;
	for (int y = -border; y < size + border; y++) {
		for (int x = -border; x < size + border; x++) {
			fputs((qrcodegen_getModule(qrcode, x, y) ? "\333\333" : "  "), stdout);
		}
		fputs("\n", stdout);
	}
}

static void generarQr(char *mensaje)
{
	printf("\n\tGENERADOR DE QR\n");
	generarQrBasico(mensaje);
	system("pause");
}

int prdadDentroPre(string operador) { //prioridad del operador en la expresion (dentro de la pila)
	int pdp = 0;

	if (operador == "^" || operador == "sen" || operador == "cos" || operador == "tan")
		pdp = 3;
	else if (operador == "*" || operador == "/")
		pdp = 2;
	else if (operador == "+" || operador == "-")
		pdp = 1;
	else if (operador == ")")
		pdp = 0;
	return pdp;
}

int prdadFueraPre(string operando) { //prioridad del operador en la expresion infija
	int pfp = 0;
	if (operando == "^" || operando == "sen" || operando == "cos" || operando == "tan")
		pfp = 4;
	else if (operando == "*" || operando == "/")
		pfp = 2;
	else if (operando == "+" || operando == "-")
		pfp = 1;
	else if (operando == ")")
		pfp = 5;
	return pfp;
}

void crear_carpeta()
{
	//genera dia mes año
	time_t t;
	struct tm *tm;
	char fechayhora[100];

	t = time(NULL);
	tm = localtime(&t);
	strftime(fechayhora, 100, "%d-%m-%Y", tm);

	//genera hora minutos segundos
	time_t current_time;
	struct tm * time_info;
	char timeString[9];

	time(&current_time);
	time_info = localtime(&current_time);

	strftime(timeString, sizeof(timeString), "%H-%M-%S", time_info);
	//puts(timeString);

	//creacion de carpeta en directorio especifico
	string ruta, nombre_carpeta, ruta_absoluta,rutaprueba;

	rutaprueba += "C:\\Users\\Administrador1\\Desktop\\pp1\\Carvajal_Corral_C.Polaca\\Carvajal_Corral_C.Polaca\\ProyectoPolaca\\Respaldos\\";
	ruta_absoluta = rutaprueba + "Hora " + timeString + " Fecha " + fechayhora;
	if (mkdir(ruta_absoluta.c_str()) == 0)//para comprobar si se cre la carpeta 0 si esta correcta
	{
		//printf("\ncarpeta creada correctamente\n");
	}
	else {
		//printf("\nerror al crear carpeta\n");
	}
	//creacion de archivo en la carpeta creada
	string nombre_archivo = "rsp", ruta_absoluta_archivo, o,cad;
	
	// getline(cin,nombre_archivo);
	ruta_absoluta_archivo = ruta_absoluta + "\\" + nombre_archivo + "-" + timeString + " - " + fechayhora + ".txt";
	FILE *arch;
	if (arch = fopen(ruta_absoluta_archivo.c_str(), "a"))
	{
		//printf("\nArchivo creado ");
		cad=leertxt1();
		fprintf(arch, " %s", cad.c_str());
	}
	else {
		printf("error al crear archivo");
	}
}