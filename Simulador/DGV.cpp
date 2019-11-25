#include "DGV.h"

DGV::DGV()
{

}

vector<Carro*> &DGV::getCars()
{
	return carros;
}

vector<Piloto*> &DGV::getPilotos()
{
	return pilotos;
}

void DGV::operator += (Piloto &piloto)
{
	pilotos.push_back(&piloto);
}

void DGV::operator += (Carro& carro)
{
	carros.push_back(&carro);
}

string DGV::random_string(size_t length)
{
	static const string alphanum = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	thread_local static mt19937 rand_gen{ random_device{}() };
	thread_local static uniform_int_distribution<size_t> generate(0, sizeof(alphanum) - 2);
	string str;
	str.reserve(length);
	while (length--)
		str += alphanum[generate(rand_gen)];
	return str;
}

bool DGV::isNameValid(Piloto &piloto)
{
	for (Piloto* p : pilotos) {
		if (*p == &piloto) {
			return false;
		}
	}
	return true;
}

DGV* DGV::getDGV()
{
	return this;
}

void DGV::addPiloto(Piloto* piloto)
{
	size_t str_length = 10;
	if (!isNameValid(*piloto)) {
		piloto->setName(random_string(str_length));
		*this += *piloto;
	}
	else
	{
		*this += *piloto;
	}
	
}






