#include "Fast.h"
#include "Carro.h"

Fast::Fast(string name) : Piloto(name)
{
	
}

Fast::~Fast()
{
}

string Fast::getAsString() const
{
	ostringstream os;
	os << "Piloto: " << this->getName() << " (rapido)" << (&this->getCarro() != nullptr ? ", Carro: " + this->getCarro().getId() + ", " + this->getCarro().getBrand() + " " + this->getCarro().getModel(): "") << endl;
	return os.str();
}

string Fast::getPilotDetais() const
{
	ostringstream os;
	os << "Piloto: " << this->getName() << " (rapido)" << endl;
	return os.str();
}