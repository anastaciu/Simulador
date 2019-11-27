#include "Fast.h"

Fast::Fast(string name) : Piloto(name)
{
}

Fast::~Fast()
{
}

string Fast::getAsString() const
{
	ostringstream os;
	os << "Piloto: " << this->getName() << " (rapido)" << endl;
	return os.str();
}
