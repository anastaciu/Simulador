#pragma once
#include "Piloto.h"
#include <vector>
#include "Carro.h"


using namespace std;

class DGV
{
private:
	vector<Piloto*> pilotos;
	vector<Carro*> carros;
public:
	vector<Carro*>& getCars();
	vector<Piloto*> &getPilotos();

};

