#include "Slow.h"

Slow::Slow(string name) : Piloto(name)
{
	this->tipo = "surpresa";
}

Slow::~Slow()
{
}

Piloto* Slow::duplica() const
{
	return new Slow(*this);
}

void Slow::passatempo()
{
	if (this->getCarro().getEnergy() > 0) {
		if (this->getCarro().getSpeed() < this->getCarro().getMaxSpeed() / 2) {
			this->getCarro().accelerate();
		}
		if (position > prev_position) {
			getCarro().brake();
		}		
	}
}

void Slow::setLag()
{
}

bool Slow::getCrazyProb()
{
	return false;
}

bool Slow::getFastProb()
{
	return false;
}

bool Slow::getSlowProb()
{
	return randomEmergencyGenerator(1, 100) < 11;
}

int Slow::randomEmergencyGenerator(int start, int finish)
{
	thread_local static mt19937 rand_gen{ random_device{}() };
	thread_local static uniform_int_distribution<int> generate(start, finish);
	int value = generate(rand_gen);
	return value;
}

