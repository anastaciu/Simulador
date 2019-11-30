#include "Autodromo.h"


Autodromo::Autodromo(string name, int pistas, int comprimento) : name(name), garagem(), pista(pistas, comprimento)
{
	
}

bool Autodromo::operator==(Autodromo& autodromo)
{
	return this->name == autodromo.name;
}

void Autodromo::setName(string name)
{
	this->name = name;
}

string Autodromo::getName()
{
	return this->name;
}

string Autodromo::getAsString() const
{
	ostringstream os;
	os << "Autodromo: " << name << " Pistas: " << pista.getPistas() << " Comprimento: " << pista.getComprimento() << endl;
	return os.str();
}

Pista& Autodromo::getPista()
{
	return pista;
}
