#include "Crazy.h"

Crazy::Crazy(string name) : Piloto(name) 
{
}

string Crazy::getAsString() const
{
	ostringstream os;
	os << "Piloto: " << this->getName() << " (crazy)" << endl;
	return os.str();
}


