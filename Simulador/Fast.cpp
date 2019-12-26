#include "Fast.h"
#include "Carro.h"

Fast::Fast(string name) : Piloto(name)
{
	this->tipo = "rapido";
}

Fast::~Fast()
{
}

void Fast::passatempo()
{
}

void Fast::setLag()
{
}

int Fast::getLag() const
{
	return 0;
}

void Fast::iterateLag()
{
}

bool Fast::getDamageProb()
{
	return false;
}
