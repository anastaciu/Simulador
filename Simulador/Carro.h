#pragma once
#include <string>
#include "Piloto.h"

using namespace std;

class Carro
{
private:
	static const string modelo_base;
	static char id_global;
	char id;
	string marca;
	string modelo;
	double energy;
	double capacity;
	bool isMoving;
	int positionX;
	int positionY;
	Piloto *condutor;

public:
	Carro(double energy, double capacity, string marca, string modelo);
	Carro(double energy, double capacity, string marca);
	~Carro();
	char getId() const;
	string getBrand() const;
	string getModel() const;
	double getEnergy() const;
	double getMaxEnergy() const;
	bool energyLimitsInbound() const;
	Piloto &getPiloto();
	void setPiloto(Piloto &condutor);
		
	
};

