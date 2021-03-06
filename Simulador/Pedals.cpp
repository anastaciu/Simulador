#include "Pedals.h"

Pedals::Pedals() : accelerator(false), brake(false)
{
}

Pedals::~Pedals()
{
}

bool Pedals::getAcceleratorState() const
{
	return accelerator;
}

void Pedals::setAccelerator(bool accelerator)
{
	this->accelerator = accelerator;
}

bool Pedals::getBrakeState() const
{
	return brake;
}

void Pedals::setBrake(bool brake)
{
	this->brake = brake;
}
