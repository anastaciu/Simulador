#pragma once
#include <string>
#include <sstream>
#include "Pista.h"
#include "Garagem.h"


using namespace std;

class Autodromo
{
private:
	string name;
	Garagem garagem;
	Pista pista;

public:
	//construtor
	Autodromo(string name, int pistas, int comprimento);

	//compara Autódromos por nome
	bool operator == (Autodromo& autodromo);

	//Estabelece o nome do autodrómos
	void setName(string name);

	//Devolve o nome do autódromo
	string getName();

	//devolve uma string com os detalhes do autódromo
	string getAsString() const;
};

