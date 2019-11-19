#pragma once
#include "Piloto.h"
#include "Carro.h"
#include <vector>
#include <random>

using namespace std;

class DGV
{
private:
	vector<Piloto*> pilotos;
	vector<Carro*> carros;
public:
	vector<Carro*> &getCars();
	vector<Piloto*> &getPilotos();
	void addPiloto(Piloto* piloto);
	void operator += (Piloto& piloto);
	void operator += (Carro& carro);
	string random_string(size_t length);
	bool isNameValid(Piloto& piloto);
};

