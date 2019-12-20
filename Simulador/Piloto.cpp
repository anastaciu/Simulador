#include "Piloto.h"
#include "Carro.h"
#include <iostream>
#include <random>




Piloto::Piloto(string name) : name(name), position(0), first(false), last(false)
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

void Piloto::addPontos(int pontos)
{
	this->pontos += pontos;
}

int Piloto::getPontos() const
{
	return pontos;
}

int Piloto::randomIntGenerator(int start, int finish)
{
	thread_local static mt19937 rand_gen{ random_device{}() };
	thread_local static uniform_int_distribution<int> generate(start, finish);
	int value = generate(rand_gen);
	return value;
}

void Piloto::setPosition(int position, bool first, bool last)
{
	this->position = position;
	this->first = first;
	this->last = last;
}

int Piloto::getPosition() const
{
	return position;
}

bool Piloto::getLast() const
{
	return last;
}

bool Piloto::getFirst() const
{
	return first;
}




