#include "Slow.h"
#include "Carro.h"

Slow::Slow(string name): Piloto(name)
{
	this->tipo = "surpresa";
}

Slow::~Slow()
{
}

void Slow::passatempo()
{
}

void Slow::setLag()
{
}

int Slow::getLag() const
{
	return 0;
}

void Slow::iterateLag()
{
}

bool Slow::getDamageProb()
{
	return false;
}
