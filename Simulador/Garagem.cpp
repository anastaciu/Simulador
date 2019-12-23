#include "Garagem.h"

Garagem::Garagem(int width, int height): width(width), height(height)
{
}

Garagem::~Garagem()
{

}

int Garagem::getWidth() const
{
	return width;
}

int Garagem::getHeight() const
{
	return height;
}

vector<Carro*>& Garagem::getCarrosGaragem()
{
	return carros;
}

void Garagem::addCarroToGaragem(Carro* carro)
{
	carros.push_back(carro);
}

void Garagem::carregaTudo()
{
	for (Carro* c : carros) {
		c->carregaMax();
	}
}

bool Garagem::carregaBat(double energia, string carro)
{
	for (Carro* c : carros) {
		if (carro == c->getId()) {
			c->manivela(energia);
			return true;
		}
	}
	return false;
}
