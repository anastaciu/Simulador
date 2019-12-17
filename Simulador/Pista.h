#pragma once
#include "Carro.h"
#include <vector>

class Pista
{
private:
	int pistas, comprimento;
	vector<Carro*> carros;
	const double COMPRIMENTO_PISTA = 160.0;

public:
	Pista(int pistas, int comprimento);
	~Pista();
	int getPistas() const;
	int getComprimento() const;
	vector<Carro*>& getCarrosPista();
	void addCarroPista(Carro* carro);
	bool passatempo(int* tempo);

};

