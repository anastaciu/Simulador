#include "Crazy.h"
#include "Carro.h"

Crazy::Crazy(string name) : Piloto(name) 
{
}

string Crazy::getAsString() const
{
	ostringstream os;
	os << "Piloto: " << this->getName() << " (crazy)" << (&this->getCarro() != nullptr ? ", Carro: " + this->getCarro().getId() + ", " + this->getCarro().getBrand() + " " + this->getCarro().getModel() : "") << endl;
	return os.str();
}

string Crazy::getPilotDetais() const
{
	ostringstream os;
	os << "Piloto: " << this->getName() << " (crazy)" << endl;
	return os.str();
}


