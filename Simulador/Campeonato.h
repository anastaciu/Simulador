#pragma once
#include <vector>
#include "Autodromo.h"
#include "DGV.h"


class Campeonato
{
private:
	vector<Autodromo*> autodromos_campeonat;

public:
	vector<Autodromo*>& getAutodromosCampeonato();

	//comando passatempo
	bool passaTempo(int* tempo);
};

