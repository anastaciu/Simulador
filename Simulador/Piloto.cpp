#include "Piloto.h"
#include "Carro.h"
#include <iostream>
#include <random>




Piloto::Piloto(string name) : name(name), position(0), first(false), last(false), lag(0), prev_position(0), pontos(0)
{
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

string Piloto::getAsString() const
{
	ostringstream os;
	os << "Piloto: " << this->getName() << " (" << tipo << ")" << (&this->getCarro() != nullptr ? ", Carro: " + this->getCarro().getId() + ", " + this->getCarro().getBrand() + " " + this->getCarro().getModel() : "") << endl;
	return os.str();
}

string Piloto::getPilotDetais() const
{
	ostringstream os;
	os << "Piloto: " << this->getName() << " (" << tipo << ")" << endl;
	return os.str();
}

string Piloto::gerDriverDetails() const
{
	ostringstream os;
	os << "Piloto: " << this->getName() << " (" << tipo << ")";
	return os.str();
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

void Piloto::nullifyCarro()
{
	this->carro = nullptr;
}

int Piloto::getLag()
{
	return lag;
}

void Piloto::setPrevPosition()
{
	prev_position = position;
}








