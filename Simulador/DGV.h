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
	bool criaObjecto(vector<string>* arguments);
	bool criaObjecto(DGV& dgv, vector<string>* arguments);
	bool apagaObjeto(vector<string>* arguments);
	bool apagaObjeto(vector<Piloto*>& pilotos, vector<string>* arguments);
	bool entraNoCarro(vector<string>* arguments);
	bool saiDoCarro(vector<string>* arguments);
};

