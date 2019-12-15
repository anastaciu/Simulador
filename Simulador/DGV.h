#pragma once
#include "Piloto.h"
#include "Crazy.h"
#include "Slow.h"
#include "Fast.h"
#include "Carro.h"
#include <vector>
#include <iterator>
#include <random>

using namespace std;

class DGV
{
private:
	vector<Piloto*> pilotos;
	vector<Carro*> carros;

public:
	DGV();
	~DGV();
	vector<Carro*> &getCars();
	vector<Piloto*> &getPilotos();
	void addPiloto(Piloto* piloto);
	void operator += (Piloto& piloto);
	void operator += (Carro& carro);
	string random_string(size_t length);
	bool isNameValid(Piloto& piloto);
	DGV *getDGV();


	//Cria carro, devolve true em caso de sucesso
	bool criaObjecto(vector<string>* arguments);

	//Cria piloto rápido, surpresa ou crazy, devolve true em caso de sucesso
	bool criaObjecto(DGV& dgv, vector<string>* arguments);

	//apaga carro, devolve true em caso de sucesso
	bool apagaObjeto(vector<string>* arguments);

	//apaga piloto, devolve true em caso de sucesso
	bool apagaObjeto(vector<Piloto*>& pilotos, vector<string>* arguments);

	//associa carro a piloto e vice versa, verifica se é possível piloto entrar no carro
	//Devolve true em caso de sucesso
	bool entraNoCarro(vector<string>* arguments);

	//Sai do carro por Id de carro ou por nome de piloto, devolve true em caso de sucesso
	bool saiDoCarro(vector<string>* arguments);
};

