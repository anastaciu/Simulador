#include "Crazy.h"
#include "Carro.h"
#include <random>

Crazy::Crazy(string name) : Piloto(name)
{
	this->tipo = "crazy";
}

Piloto* Crazy::duplica() const
{
	return new Crazy(*this);
}

void Crazy::passatempo()
{
	if (lag == 0 && getCarro().getEnergy() > 0 && !getCarro().getStop()) {
		if (getLast()) {
			getCarro().brake();
		}
		if (!getFirst() && !getLast()) {
			getCarro().accelerate();
		}
		if (position > prev_position && !getLast()) {
			lost_position_accelerate = 2;
		}
		if (lost_position_accelerate > 0) {
			lost_position_accelerate--;
			getCarro().accelerate();
		}	
		if (getFirst()) {
			getCarro().stopAccelerating();
		}
	}
	else {
		if(lag > 0)
			lag--;
	}	
	if (getCarro().getStop()) {
		getCarro().brake();
	}
	if (getCarro().getEnergy() == 0) {
		getCarro().setEmergency(true);
	}
}

void Crazy::setLag()
{
	lag = randomLagGenerator(1, 5);
}

bool Crazy::getCrazyProb()
{ 
	if (!getCarro().getDamage())
		return (randomIntGenerator(1, 100) < 6);
	else 
		return false;
}

bool Crazy::getFastProb()
{
	return false;
}

bool Crazy::getSlowProb()
{
	return false;
}

int Crazy::randomLagGenerator(int start, int finish)
{
	thread_local static mt19937 rand_gen{ random_device{}() };
	thread_local static uniform_int_distribution<int> generate(start, finish);
	int value = generate(rand_gen);
	return value;
}

string Crazy::getProbLog() const
{
	return ": Probabilidade de 5% de dano positiva para " + getName() + " (" + tipo + ") " + " no carro ";
}




