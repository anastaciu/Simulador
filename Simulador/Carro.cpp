#include "Carro.h"
#include <iostream>


char Carro::id_global = 'a';
const string Carro::MODELO_BASE = "modelo base";

Carro::Carro(int v_max, double energy, double capacity, string marca, string modelo) : marca(marca), modelo(modelo), max_speed(v_max), capacity(capacity)
{
	id = id_global > 'z' ? '?' : id_global++;
	this->energy = energy;
	if (!energyLimitsInbound()) {
		this->energy = this->capacity;
	}
}

Carro::Carro(int v_max, double energy, double capacity, string marca) : marca(marca), max_speed(v_max), capacity(capacity), modelo(MODELO_BASE)
{
	id = id_global > 'z' ? '?' : id_global++;
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

Piloto& Carro::getPiloto()
{
	return *condutor;
}

void Carro::setPiloto(Piloto& condutor)
{
	this->condutor = &condutor;
}

void Carro::manivela(int n)
{
	if (energyLimitsInbound() && n > 0) {
		this->energy += n;
	}
	if (!energyLimitsInbound()) {
		this->energy = this->capacity;
	}
}

