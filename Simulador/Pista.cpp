#include "Pista.h"
#include <iostream>

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

bool Pista::passatempo(int* tempo)
{
	double normalizedLength = COMPRIMENTO_PISTA / comprimento;
	while ((*tempo)--) {		
		for (Carro* c : this->carros) {
			try {
				c->passatempo(tempo, normalizedLength, COMPRIMENTO_PISTA);
			}
			catch (exception e) {
				throw e;
			}
		}
		return true;
	}
	return false;
}

int Pista::getComprimentoNormal()
{
	return COMPRIMENTO_PISTA;
}

