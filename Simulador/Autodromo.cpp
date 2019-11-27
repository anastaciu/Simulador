#include "Autodromo.h"
#include <locale.h>


Autodromo::Autodromo(string name, int pistas, int comprimento) : name(name), pistas(pistas), comprimento(comprimento)
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
	os << "Autodromo: " << name << " Pistas: " << pistas << " Comprimento: " << comprimento << endl;
	return os.str();
}
