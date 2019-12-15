#include "Campeonato.h"
#include "DGV.h"
#include <iostream>


vector<Autodromo*>& Campeonato::getAutodromosCampeonato()
{
	return autodromos_campeonat;
}

bool Campeonato::passaTempo(vector<string>* arguments, vector<Carro*> carros)
{
	int pista = 210;
	int tempo;
	cout << carros.at(0)->getXPosition() << "merda" << endl;
	system("pause");
	stringstream ss(arguments->at(0));
	ss >> tempo;
	for (Carro* c :carros) {
		if (&c->getPiloto() != nullptr) {
			c->setPosition(c->getXPosition() + ((160.0/autodromos_campeonat.at(0)->getPista().getComprimento()) * tempo), c->getYPosition());
			cout << c->getXPosition();
			system("pause");
			if (c->getXPosition() > 160.0 + 4) {
				return false;
			}
		}
	}
	return true;
}