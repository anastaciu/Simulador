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
	~Campeonato();
	bool passaTempo(int* tempo, int *i);

};

