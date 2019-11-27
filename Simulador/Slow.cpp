#include "Slow.h"

Slow::Slow(string name): Piloto(name)
{
}

Slow::~Slow()
{
}

string Slow::getAsString() const
{
	ostringstream os;
	os << "Piloto: " << this->getName() << " (surpresa)" << endl;
	return os.str();
}
