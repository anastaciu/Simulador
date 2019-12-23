#include "Autodromo.h"


Autodromo::Autodromo(string name, int pistas, int comprimento) : name(name), pista(pistas, comprimento), garagem(80, 15)
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

Garagem& Autodromo::getGaragem()
{
	return garagem;
}

bool Autodromo::passaTempo(int* tempo)
{
	try {
		return pista.passatempo(tempo);
	}
	catch (exception e) {
		throw e;
	}
}

void Autodromo::carregaTudo()
{
	pista.carregaTudo();
	garagem.carregaTudo();
}

bool Autodromo::carregabat(double energia, string carro)
{
	return garagem.carregaBat(energia, carro) || pista.carregaBat(energia, carro);
}






