#pragma once
#include "Autodromo.h"
#include "DGV.h"
#include "Crazy.h"
#include "Slow.h"
#include "Fast.h"
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

class Campeonato
{
private:
	vector<Autodromo> autodromos;
	DGV dgv;

public:
	Campeonato();
	DGV& getDGV();
	void addAutodromo(Autodromo autodromo);
	bool isNameValid(Autodromo& autodromo);
	string random_string(size_t length);
	void operator +=(Autodromo autodromo);
	vector<Autodromo> &getAutodromos();
	bool adicionaObjecto(vector<string> *arguments);
	bool criaObjecto(vector<Carro*> &carros, vector<string>* arguments);
	bool criaObjecto(vector<string>* arguments);
	bool criaObjecto(DGV& dgv, vector<string>* arguments);
	bool removeObjecto(vector<string>* arguments);
	bool apagaObjeto(vector<Carro*>& carros, vector<string>* arguments);
	bool apagaObjeto(vector<string>* arguments);
	bool apagaObjeto(vector<Piloto*>& pilotos, vector<string>* arguments);
	bool entraNoCarro(vector<Piloto*> pilotos, vector<Carro*> carros, vector<string>* arguments);
};

