#pragma once
#include <vector>
#include "Autodromo.h"
#include "DGV.h"


class Campeonato
{

	vector<Autodromo> autodromos_campeonat;

public:
	vector<Autodromo>& getAutodromosCampeonato();

	//comando passatempo
	bool passaTempo(vector<string>* arguments, vector<Carro*> carros);
};

