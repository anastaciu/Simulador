#pragma once
#include <string>
#include <sstream>
#include <iterator>
#include <ctime>
#include "Pista.h"
#include "Garagem.h"
#include "DGV.h"
#include "Log.h"
#include "MessageLog.h"



using namespace std;

class Autodromo
{
private:
	string name;
	Garagem garagem;
	Pista pista;
	int tempo, it, finish;
	vector<Piloto*> pilotos;
	MessageLog errorLog;

public:
	Autodromo(string name, int pistas, int comprimento);
	bool operator == (Autodromo& autodromo);
	vector<Piloto*>& getPilotos();
	void setName(string name);
	string getName();
	string getAsString() const;
	Pista& getPista();
	Garagem& getGaragem();
	bool passaTempo(int* tempo);
	void carregaTudo();
	bool carregabat(double energia, char carro);
	void pilotIfProb();
	int getTempo() const;
	void plusOneSecond();
	bool entraNocarro(string nome, char id);
	bool saiDoCarro(char id);
	bool addCarroToPista(char id);
	bool addCarroToGaragem(char id);
	bool destroi(char id);
	Piloto* acidente(char id);
	const string currentTime();
	static bool sortPilotosByPosition(Piloto* p1, Piloto* p2);
	void removeEmergency();
	void removeStop();
	bool stopPiloto(char id);
	void removeIfDamaged();
};

