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
	bool listaElementos(Campeonato& campeonato) const;
	void printPista(Pista& pista);
	void printCarros(Pista& pista, vector<Carro*>& carros);
	void printGarage(Pista& pista, vector<Carro*>& carros);



};

