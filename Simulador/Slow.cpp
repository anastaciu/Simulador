#include "Slow.h"
#include "Carro.h"

Slow::Slow(string name): Piloto(name)
{
}

Slow::~Slow()
{
}


string Slow::getAsString() const
{
	ostringstream os;
	os << "Piloto: " << this->getName() << " (surpresa)" << (&this->getCarro() != nullptr ? ", Carro: " + this->getCarro().getId() + ", " + this->getCarro().getBrand() + " " + this->getCarro().getModel() : "") << endl;
	return os.str();
}

string Slow::getPilotDetais() const
{
	ostringstream os;
	os << "Piloto: " << this->getName() << " (surpresa)" << endl;
	return os.str();
}