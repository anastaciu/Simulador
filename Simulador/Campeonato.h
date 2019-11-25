#pragma once
#include "Autodromo.h"
#include "DGV.h"
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

class Campeonato
{
public:
private:
	vector<Autodromo> autodromos;
	DGV dgv;

public:
	Campeonato();
	void addAutodromo(Autodromo autodromo);
	bool isNameValid(Autodromo& autodromo);
	string random_string(size_t length);
	void operator +=(Autodromo autodromo);
	vector<Autodromo> getAutodromos();
	bool adicionaObjecto(vector<string> *arguments);
	bool criaObjecto(vector<Carro*> &carros, vector<string>* arguments);
	bool criaObjecto(vector<string>* arguments);
	bool criaObjecto(vector<Piloto*>& pilotos, vector<string>* arguments);
	DGV &getDGV();
};

