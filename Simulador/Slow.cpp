#include "Slow.h"
#include "Carro.h"

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
		if (getFirst()) {
			getCarro().setEmergency(true);
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
