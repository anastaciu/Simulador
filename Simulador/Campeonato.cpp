#include "Campeonato.h"
#include "DGV.h"
#include "Consola.h"


vector<Autodromo*>& Campeonato::getAutodromosCampeonato()
{
	return autodromos_campeonat;
}

bool Campeonato::passaTempo(int *tempo)
{
	return autodromos_campeonat.at(0)->passaTempo(tempo);
}


