#include "Carro.h"
#include <iostream>


char Carro::id_global = 'a';
const string Carro::MODELO_BASE = "modelo base";

Carro::Carro(int v_max, double energy, double capacity, string marca, string modelo) : marca(marca), modelo(modelo), max_speed(v_max), capacity(capacity), pedals(), is_moving(false),
emergency(false), in_garage(false), is_damaged(false), speed(0), positionX(0), positionY(0)
{
	id = id_global > 'z' ? '?' : id_global++;
	this->energy = energy;
	if (!energyLimitsInbound()) {
		this->energy = this->capacity;
	}
}

Carro::Carro(int v_max, double energy, double capacity, string marca) : marca(marca), max_speed(v_max), capacity(capacity), modelo(MODELO_BASE), pedals(), is_moving(false),
emergency(false), in_garage(false), is_damaged(false), speed(0), positionX(0), positionY(0)
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

string Carro::getId()
{
	return id;
}

void Carro::setId(char id)
{
	this->id = id;
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

void Carro::setPiloto(Piloto* condutor)
{
	this->condutor = condutor;
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

string Carro::getAsString() const
{
	ostringstream os;
	os << "Carro: " << id << ", " << marca << " " << modelo << ", Velocidade Maxima: " << max_speed << ", Capacidade Maxima: " 
		<< capacity << ", Energia: " << energy << (condutor ? ", " + condutor->getPilotDetais() : "\n");
	return os.str();
}

double Carro::getXPosition() const
{
	return positionX;
}

int Carro::getYPosition() const
{
	return positionY;
}

void Carro::setPosition(double x, int y)
{
	this->positionX = x;
	this->positionY = y;
}

int Carro::getSpeed() const
{
	return speed;
}

void Carro::passatempo(int* tempo, double comprimento, double const comprimentoPista)
{
	int i = 5;
	exception e;
	if (condutor != nullptr) {
		setPosition(positionX + (comprimento * ++i) , positionY);
		if (getXPosition() > comprimentoPista) {
			throw e;
		}
	}
}



