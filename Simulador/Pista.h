#pragma once
#include "Carro.h"
#include <vector>
#include <algorithm>

using namespace std;

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
	const double getComprimentoNormal();
	static bool sortCarrosByPosition(Carro* p1, Carro* p2);
	void setPontos();
	void setFirstAndLast();
	void setPilotosPosition();
	void carregaTudo();
	bool carregaBat(double energia, string carro);
};

