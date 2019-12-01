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
	void printCarros(Pista& pista, vector<Carro*>& carros);
	void printGarage(Pista& pista, vector<Carro*>& carros);
	void printAll(Pista& pista, vector<Carro*>& carros);
	int endRace();
	void printCommandLine(int& i, Simulador& Simulador);
	void printLog(string& log, Simulador &Simulador, int& i);
};

