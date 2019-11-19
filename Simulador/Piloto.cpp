#include "Piloto.h"
#include <iostream>




Piloto::Piloto(string name) : name(name), carro(nullptr)
{
	this->name = name;
	cout << "ctor piloto with name" << endl;
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

Carro& Piloto::getCarro()
{
	return *carro;
}

void Piloto::setCarro(Carro& carro)
{
	this->carro = &carro;
}

bool Piloto::operator== (Piloto *piloto)
{
	return this->name == piloto->name;
}
