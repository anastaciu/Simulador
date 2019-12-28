#include "Slow.h"
#include "Carro.h"

Slow::Slow(string name): Piloto(name)
{
	this->tipo = "surpresa";
}

Slow::~Slow()
{
}

void Slow::passatempo()
{
	if (this->getCarro().getEnergy() > 0) {
		if (this->getCarro().getSpeed() < this->getCarro().getMaxSpeed() / 2) {
			this->getCarro().accelerate();
		}
	}
}

void Slow::setLag()
{
}

bool Slow::getDamageProb()
{
	return false;
}
