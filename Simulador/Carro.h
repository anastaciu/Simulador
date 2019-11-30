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
	bool is_moving, emergency, in_garage, is_damaged;
	int speed, max_speed, positionX, positionY;
	Piloto *condutor = nullptr;

public:
	//construtor
	Carro(int v_max, double energy, double capacity, string marca, string modelo);

	//construtor
	Carro(int v_max, double energy, double capacity, string marca);

	//Destrutor
	~Carro();

	//Devolve id do carro
	string getId();

	//Estabelece o id do carro
	void setId(char id);

	//Devolve marca do carro
	string getBrand() const;

	//devolve modelo do carro
	string getModel() const;

	//devolve energia do carro
	double getEnergy() const;

	//devolve energia máxima
	double getMaxEnergy() const;

	//verifica se a energia fornecida ao carro não ultrapassa o limite
	bool energyLimitsInbound() const;

	//devolve o piloto do carro
	Piloto &getPiloto();

	//estabelece o condutor do carro
	void setPiloto(Piloto* condutor);

	//fornece energia ao carro
	void manivela(int n);

	//devolve detalhes do carro
	string getAsString() const;

	//devolve a posição x do carro
	int getXPosition() const;

	// devolve a posição Y do carro
	int getYPosition() const;

	//estabelece a posição do carro;
	void setPosition(int x, int y);
	
	void setGarage(bool);
	bool getGarage() const;
};

