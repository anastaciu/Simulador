#include "Campeonato.h"
#include "DGV.h"
#include "Consola.h"


vector<Autodromo*>& Campeonato::getAutodromosCampeonato()
{
	return autodromos_campeonat;
}

bool Campeonato::passaTempo(int *tempo, int *i)
{
	return autodromos_campeonat.at(*i)->passaTempo(tempo);
}


