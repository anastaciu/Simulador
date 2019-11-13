#include "Carro.h"
#include <iostream>


char Carro::id_global = 'a';
const string Carro::modelo_base = "modelo base";

Carro::Carro(double energy, double capacity, string marca, string modelo)
{
	if (id_global > 'z') {
		id = '?';
	} else {
		id = id_global++;
	}
	this->marca = marca;
	this->modelo = modelo;
	this->capacity = capacity;
	this->energy = energy;
	if (!energyLimitsInbound()) {
		this->energy = this->capacity;
	}
}

Carro::Carro(double energy, double capacity, string marca)
{
	if (id_global > 'z') {
		id = '?';
	}
	else {
		id = id_global++;
	}
	this->marca = marca;
	this->modelo = modelo_base;
	this->capacity = capacity;
	this->energy = energy;
	if (!energyLimitsInbound()) {
		this->energy = this->capacity;
	}
}

Carro::~Carro()
{
}

char Carro::getId() const
{
	return id;
}

string Carro::getBrand() const
{
	return marca;
}

string Carro::getModel() const
{
	return modelo;
}

double Carro::getEnergy() const
{
	return energy;
}

double Carro::getMaxEnergy() const
{
	return capacity;
}

bool Carro::energyLimitsInbound() const
{
	return energy < capacity;
}

