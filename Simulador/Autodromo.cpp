#include "Autodromo.h"


Autodromo::Autodromo(string name, int pistas, int comprimento) : name(name), pista(pistas, comprimento), garagem(80, 20)
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

Garagem Autodromo::getGaragem() const
{
	return garagem;
}

bool Autodromo::passaTempo(int* tempo)
{
	int i = 0;
	exception e;
	//cout << carros.at(0)->getXPosition() << "teste" << endl;
	//system("pause");
	while ((*tempo)--) {
		for (Carro* c : this->pista.getCarrosPista()) {
			if (&c->getPiloto() != nullptr) {
				c->setPosition(c->getXPosition() + ((160.0 / getPista().getComprimento()) * i++), c->getYPosition());
				//cout << c->getXPosition();
				//system("pause");
				if (c->getXPosition() > 160.0) {
					throw e;
				}
			}
		}
		return true;
	}
	return false;

}