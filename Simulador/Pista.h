#pragma once
#include "Carro.h"
#include <vector>

class Pista
{
private:
	int pistas, comprimento;
	vector<Carro*> carros;

public:
	Pista(int pistas, int comprimento);
	~Pista();
	int getPistas() const;
	int getComprimento() const;
	vector<Carro*>& getCarrosPista();
	void addCarroPista(Carro* carro);
};

