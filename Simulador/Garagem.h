#pragma once
#include "Carro.h"
#include <vector>

class Garagem
{
private:
	int width, height;
	vector<Carro*> carros;

public:
	Garagem(int width, int height);
	~Garagem();
	int getWidth() const;
	int getHeight() const;
	vector<Carro*>& getCarrosGaragem();
	void addCarroToGaragem(Carro* carro);
	void carregaTudo();
	bool carregaBat(double energia, char carro);
};

