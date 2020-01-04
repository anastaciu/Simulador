#include "Fast.h"
#include "Carro.h"

Fast::Fast(string name) : Piloto(name), accelerateCounter(3)
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
	if (getCarro().getEnergy() > 0) {
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
	return false;
}

bool Fast::getSlowProb()
{
	return false;
}
