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
	string id, marca, modelo;
	double energy, capacity, positionX;
	Pedals pedals;
	bool emergency, is_damaged, stop;
	int speed, max_speed, positionY, distancia;
	Piloto *condutor = nullptr;

public:
	Carro(int v_max, double energy, double capacity, string marca, string modelo);
	Carro(int v_max, double energy, double capacity, string marca);
	~Carro();
	Pedals getPedals() const;
	bool getStop() const;
	void setStop(bool stop);
	string getId();
	void setId(char id);
	string getBrand() const;
	string getModel() const;
	int getMaxSpeed() const;
	double getEnergy() const;
	double getMaxEnergy() const;
	bool energyLimitsInbound() const;
	Piloto &getPiloto();
	void setPiloto(Piloto* condutor);
	void manivela(double n);
	string getAsString() const;
	double getXPosition() const;
	int getYPosition() const;
	void setPosition(double x, int y);
	int getSpeed() const;
	void setSpeed();
	bool getEmergency() const;
	void setEmergency(bool emergency);
	bool passatempo(int comprimento, double const comprimentoPista, int tempo);
	bool operator== (Carro* carro);
	void carregaMax();
	void nullifyPiloto();
	void accelerate();
	void brake();
	void stopBraking();
	void stopAccelerating();
	void gastaEnergia();
	void setSpeedManually(int speed);
	void resetPedals();
	string getRaceDetails();
	void semEnergia();
	int getDistance() const;
	void resetCarro();
	Carro* duplica() const;
};

