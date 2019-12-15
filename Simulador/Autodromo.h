#pragma once
#include <string>
#include <sstream>
#include "Pista.h"
#include "Garagem.h"
#include "Corrida.h"


using namespace std;

class Autodromo
{
private:
	string name;
	Garagem garagem;
	Pista pista;
	Corrida corrida;

public:
	//construtor
	Autodromo(string name, int pistas, int comprimento);

	//compara Autódromos por nome
	bool operator == (Autodromo& autodromo);

	//Estabelece o nome dos autodrómos
	void setName(string name);

	//Devolve o nome do autódromo
	string getName();

	//devolve uma string com os detalhes do autódromo
	string getAsString() const;

	Pista& getPista();
	Garagem getGaragem() const;
};

