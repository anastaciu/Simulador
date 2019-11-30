#pragma once
#include "MessageLog.h"
#include "Consola.h"
#include "Campeonato.h"
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
	bool listaElementos(Campeonato& campeonato) const;
	bool listaElementosFase2(Campeonato& campeonato) const;
	void printPista(Pista& pista);
	void printCarros(Pista& pista, vector<Carro*>& carros);
	void printGarage(Pista& pista, vector<Carro*>& carros);
	void printAll(Pista& pista, vector<Carro*>& carros);
	int endRace();
};

