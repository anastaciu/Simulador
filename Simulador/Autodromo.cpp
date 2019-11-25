#include "Autodromo.h"
#include <locale.h>


Autodromo::Autodromo(string name): name(name)
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
