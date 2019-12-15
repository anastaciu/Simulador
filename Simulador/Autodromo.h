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

	//compara Aut�dromos por nome
	bool operator == (Autodromo& autodromo);

	//Estabelece o nome dos autodr�mos
	void setName(string name);

	//Devolve o nome do aut�dromo
	string getName();

	//devolve uma string com os detalhes do aut�dromo
	string getAsString() const;

	Pista& getPista();
	Garagem getGaragem() const;
};

