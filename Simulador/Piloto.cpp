#include "Piloto.h"
#include "Carro.h"
#include <iostream>




Piloto::Piloto(string name) : name(name)
{
	this->name = name;
}

Piloto::~Piloto()
{
}

string Piloto::getName() const
{
	return name;
}

void Piloto::setName(string name)
{
	this->name = name;
}

Carro& Piloto::getCarro() const
{
	return *carro;
}

void Piloto::setCarro(Carro* carro)
{
	this->carro = carro;
}

bool Piloto::operator== (Piloto *piloto)
{
	return this->name == piloto->name;
}




