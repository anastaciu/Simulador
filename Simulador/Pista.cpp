#include "Pista.h"
#include <iostream>

Pista::Pista(int pistas, int comprimento) : pistas(pistas), comprimento(comprimento)
{
}

Pista::~Pista()
{
	carros.clear();
}

int Pista::getPistas() const
{
	return pistas;
}

int Pista::getComprimento() const
{
	return comprimento;
}

vector<Carro*>& Pista::getCarrosPista()
{
	return carros;
}

void Pista::addCarroPista(Carro* carro)
{
		carros.push_back(carro);
}

const double Pista::getComprimentoNormal()
{
	return COMPRIMENTO_PISTA;
}

bool Pista::sortCarrosByPosition(Carro* p1, Carro* p2)
{
	return p1->getXPosition() > p2->getXPosition();
}

void Pista::setPontos()
{
	if (carros.size() > 1)
		sort(carros.begin(), carros.end(), sortCarrosByPosition);
	if (carros.size() > 0)
		carros.at(0)->getPiloto().addPontos(&carros.at(0)->getPiloto() != nullptr ? 10 : 0);
	if (carros.size() > 1)
		carros.at(1)->getPiloto().addPontos(&carros.at(1)->getPiloto() != nullptr ? 5 : 0);
	if (carros.size() > 2)
		carros.at(2)->getPiloto().addPontos(&carros.at(2)->getPiloto() != nullptr ? 2 : 0);
}

void Pista::setFirstAndLast()
{
	vector<Carro*>::iterator it;
	if (carros.size() > 1) {
		sort(carros.begin(), carros.end(), sortCarrosByPosition);
		it = carros.end() - 1;
		(*it)->getPiloto().setPrevPosition();
		(*it)->getPiloto().setPosition(static_cast<int>(carros.size()), false, true);
	}
	if (carros.size() > 0) {
		it = carros.begin();
		(*it)->getPiloto().setPosition(1, true, false);
	}
} 

void Pista::setPilotosPosition()
{
	int i = 2;
	vector<Carro*>::iterator it;
	if (carros.size() > 2) {
		for (it = carros.begin() + 1; it != carros.end() - 1; it++) {
			(*it)->getPiloto().setPrevPosition();
			(*it)->getPiloto().setPosition(i++, false, false);
		}
	}
}

void Pista::carregaTudo()
{
	for (Carro* c : carros) {
		c->carregaMax();
	}
}

bool Pista::carregaBat(double energia, char carro)
{
	for (Carro* c : carros) {
		if (tolower(carro) == tolower(c->getId().at(0))) {
			c->manivela(energia);
			return true;
		}
	}
	return false;
}

void Pista::removeCrazyIfProb()
{	
	vector<Carro*>::iterator it;
	it = carros.begin();
	while (it != carros.end()) {
		if ((*it)->getPiloto().getCrazyProb()) {
			it = carros.erase(it);
			if (it != carros.end())
				it = carros.erase(it);
		}
		else it++;
	}
}

bool Pista::stop(string piloto)
{
	for (Carro* c : carros) {
		if (&c->getPiloto() != nullptr) {
			if (piloto == c->getPiloto().getName()) {
				c->setStop(true); 
				return true;
			}
		}
	}
	return false;
}



