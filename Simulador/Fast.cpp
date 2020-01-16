#include "Fast.h"
#include "Carro.h"

Fast::Fast(string name) : Piloto(name)
{
	this->tipo = "rapido";
}

Fast::~Fast()
{
}

Piloto* Fast::duplica() const
{
	return new Fast(*this);
}

void Fast::passatempo()
{
	if (getCarro().getEnergy() > 0 && !getCarro().getStop()) {
		if (getCarro().getEnergy() >= getCarro().getMaxEnergy() / 2) {
			getCarro().accelerate();
		}
		else {
			if (accelerateCounter == 0) {
				getCarro().accelerate();
				accelerateCounter = 3;
			}
			else
				accelerateCounter--;
		}
	}
	if (getCarro().getStop()) {
		getCarro().brake();
	}
}

void Fast::setLag()
{
}

bool Fast::getCrazyProb()
{
	return false;
}

bool Fast::getFastProb()
{
	if (panic_counter == 0) {		
		panic_counter = 9;
		if (randomPanicGenerator(1, 100) < 11) {
			return true;
		}
	}
	else {
		panic_counter--;
	}
	return false;
}

bool Fast::getSlowProb()
{
	return false;
}

int Fast::randomPanicGenerator(int start, int finish)
{
	thread_local static mt19937 rand_gen{ random_device{}() };
	thread_local static uniform_int_distribution<int> generate(start, finish);
	int value = generate(rand_gen);
	return value;
}

string Fast::getProbLog() const
{
	return ": Probabilidade de 10% de ataque de panico para " + getName() + " (" + tipo + ") " + " no carro ";
}
