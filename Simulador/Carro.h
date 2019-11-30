#pragma once
#include <string>
#include "Piloto.h"
#include "Pedals.h"

using namespace std;

class Carro
{
private:
	static const string MODELO_BASE;
	static char id_global;
	string id;
	string marca, modelo;
	double energy, capacity;
	Pedals pedals;
	bool is_moving, emergency, is_damaged, isOccupied;
	int speed, max_speed, positionX, positionY;
	Piloto *condutor = nullptr;

public:
	Carro(int v_max, double energy, double capacity, string marca, string modelo);
	Carro(int v_max, double energy, double capacity, string marca);
	~Carro();
	string getId();
	void setId(char id);
	string getBrand() const;
	string getModel() const;
	double getEnergy() const;
	double getMaxEnergy() const;
	bool energyLimitsInbound() const;
	Piloto &getPiloto();
	void setPiloto(Piloto* condutor);
	void manivela(int n);
	string getAsString() const;
	int getXPosition() const;
	int getYPosition() const;
	void setPosition(int x, int y);
	
};

