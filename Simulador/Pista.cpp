#include "Pista.h"

Pista::Pista(int pistas, int comprimento) : pistas(pistas), comprimento(comprimento)
{
}

Pista::~Pista()
{
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

