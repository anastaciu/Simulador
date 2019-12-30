#pragma once
#include <string>
#include <sstream>
#include <iterator>
#include "Pista.h"
#include "Garagem.h"
#include "DGV.h"


using namespace std;

class Autodromo
{
private:
	string name;
	Garagem garagem;
	Pista pista;
	int tempo, it;
	vector<Piloto*> pilotos;

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
	void removeCrazyIfProb();
	int getTempo() const;
	void plusOneSecond();
	bool entraNocarro(vector<string>* arguments);
	bool saiDoCarro(vector<string>* arguments);
	bool addCarroToPista(char id);
	bool addCarroToGaragem(char id);
	bool destroi(char id);
};

