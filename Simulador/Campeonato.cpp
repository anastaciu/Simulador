#include "Campeonato.h"
#include "DGV.h"


vector<Autodromo>& Campeonato::getAutodromosCampeonato()
{
	return autodromos_campeonat;
}

bool Campeonato::passaTempo(vector<string>* arguments, vector<Carro*> carros)
{
	int tempo;
	stringstream ss(arguments->at(0));
	ss >> tempo;
	for (Carro* c :carros) {
		if (&c->getPiloto() != nullptr) {
			c->setPosition(c->getXPosition() + 1 * tempo, c->getYPosition());
			if (c->getXPosition() > this->autodromos_campeonat.at(0).getPista().getComprimento() + 4) {
				return false;
			}
		}
	}
	return true;
}