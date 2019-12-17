#pragma once
#include "MessageLog.h"
#include "Consola.h"
#include "Simulador.h"
#include <iostream>

using namespace std;

class GameGraphics
{
private:
	MessageLog log;
	
public:
	void gameInit();
	void commandLine();
	void commandLineFase2();
	bool listaElementos(Simulador& Simulador) const;
	bool listaElementosFase2(Simulador& Simulador) const;
	void printPista(Pista& pista);
	void printCarros(Autodromo& autodromo);
	void printGarage(Autodromo& autodromo);
	void printAll(Autodromo& autodromo, int *tempo);
	int endRace();
	void printCommandLine(int& i, Simulador& Simulador, bool* passaTempo);
	void printLog(string& log, Simulador &Simulador, int& i);
	void printTempo(int posY, int *tempo);
};

