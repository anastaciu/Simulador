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
	bool screenSet;
	
public:
	GameGraphics();
	void gameInit();
	void commandLine();
	void commandLineFase2();
	bool listaElementos(Simulador& Simulador) const;
	bool listaElementosFase2(Simulador& Simulador, int* it) const;
	void printPista(Pista& pista);
	void printCarros(Autodromo& autodromo);
	void printGarage(Autodromo& autodromo);
	void printAll(Autodromo& autodromo, int *tempo);
	int endRace(Campeonato campeonato, DGV dgv);
	void printCommandLine(int& i, Simulador& Simulador, bool* passaTempo, int* it);
	void printLog(string& log, Simulador &Simulador, int& i, int* it);
	void printTempo(int posY, int *tempo);
	void printAutodromoName(Autodromo autodromo);
	void printBackground();
	void setScreenSize();
	void listaCarros(Simulador& Simulador, int* it);
	void printPassatempo(Autodromo& autodromo, int* tempo);
	void printRaceDetails(Autodromo autodromo);
	void printEventLog(Autodromo autodromo);
	void mainMenu();
	void printAllNoRaceDetais(Autodromo& autodromo, int* tempo);
	void printFinalPositions(Autodromo autodromo, DGV dgv);
	void printRaceClassification(Autodromo autodromo);
	void printFinalClassification(DGV dgv);
};

