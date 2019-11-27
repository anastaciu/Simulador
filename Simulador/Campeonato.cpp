#include "Campeonato.h"


Campeonato::Campeonato()
{

}

DGV& Campeonato::getDGV()
{
	return dgv;
}

void Campeonato::addAutodromo(Autodromo autodromo)
{
	size_t str_length = 10;
	if (!isNameValid(autodromo)) {
		autodromo.setName(random_string(str_length));
		*this += autodromo;
	}
	else
	{
		*this += autodromo;
	}

}

bool Campeonato::isNameValid(Autodromo& autodromo)
{
	for (Autodromo a : autodromos) {
		if (a == autodromo) {
			return false;
		}
	}
	return true;
}

string Campeonato::random_string(size_t length)
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

void Campeonato::operator+= (Autodromo autodromo)
{
	autodromos.push_back(autodromo);
}

vector<Autodromo>& Campeonato::getAutodromos()
{
	return autodromos;
}

bool Campeonato::adicionaObjecto(vector<string>* arguments)
{
	exception e;

	if (!arguments->at(0).compare("c")) {
		if (criaObjecto(this->dgv.getCars(), arguments))
			return true;
		else
			return false;
	}
	else if (!arguments->at(0).compare("a")) {
		if (criaObjecto(arguments))
			return true;
		else
			return false;
	}
	else if (!arguments->at(0).compare("p")) {
		if (criaObjecto(dgv, arguments))
			return true;
		else
			return false;
	}
	else throw e;
	return false;

}

bool Campeonato::criaObjecto(vector<Carro*>& carros, vector<string>* arguments)
{
	int v_max;
	double energy, capacity;
	exception e;
	stringstream arg1(arguments->at(1));
	arg1 >> v_max;
	stringstream arg2(arguments->at(2));
	arg2 >> energy;
	stringstream arg3(arguments->at(3));
	arg3 >> capacity;
	if (arguments->size() == 6) {
		carros.push_back(new Carro(v_max, energy, capacity, arguments->at(4), arguments->at(5)));
		return true;
	}
	else if (arguments->size() == 5) {
		carros.push_back(new Carro(v_max, energy, capacity, arguments->at(4)));
		return true;
	}
	return false;
}

bool Campeonato::criaObjecto(vector<string>* arguments)
{
	int pistas, comprimento;
	if (arguments->size() == 4) {
		stringstream arg1(arguments->at(1));
		arg1 >> pistas;
		stringstream arg2(arguments->at(2));
		arg2 >> comprimento;
		Autodromo autodromo(arguments->at(3), pistas, comprimento);
		addAutodromo(autodromo);
		return true;
	}
	return false;
}

bool Campeonato::criaObjecto(DGV& dgv, vector<string>* arguments)
{
	ostringstream str;
	if (arguments->size() > 2)
	{
		copy(arguments->begin() + 2, arguments->end() - 1, ostream_iterator<string>(str, " "));
		str << arguments->back();

		if (!arguments->at(1).compare("crazy")) {
			dgv.addPiloto(new Crazy(str.str()));
			return true;
		}
		else if (!arguments->at(1).compare("rapido")) {
			dgv.addPiloto(new Fast(str.str()));
			return true;
		}
		else if (!arguments->at(1).compare("surpresa")) {
			dgv.addPiloto(new Slow(str.str()));
			return true;
		}
	}
	return false;
}

bool Campeonato::apagaObjeto(vector<Piloto*>& pilotos, vector<string>* arguments)
{
	vector<Piloto*>::iterator it;
	it = pilotos.begin();
	ostringstream str;
	copy(arguments->begin() + 1, arguments->end() - 1, ostream_iterator<string>(str, " "));
	str << arguments->back();
	cout << str.str();
	while (it != pilotos.end()) {
		if (str.str() == (*it)->getName()) {
			it = pilotos.erase(it);
			return true;
		}
		else {
			it++;
		}
	}
	return false;
}

bool Campeonato::apagaObjeto(vector<Carro*>& carros, vector<string>* arguments)
{
	vector<Carro*>::iterator it;
	it = carros.begin();
	while (it != carros.end()) {
		if (arguments->at(1) == (*it)->getId()) {
			it = carros.erase(it);
			return true;
		}
		else {
			it++;
		}
	}
	return false;
}

bool Campeonato::apagaObjeto(vector<string>* arguments)
{
	vector<Autodromo>::iterator it;
	it = autodromos.begin();
	while (it != autodromos.end()) {
		if (arguments->at(1) == (*it).getName()) {
			it = autodromos.erase(it);
			return true;
		}
		else {
			it++;
		}
	}
	return false;
}

bool Campeonato::removeObjecto(vector<string>* arguments)
{
	exception e;

	if (!arguments->at(0).compare("c")) {
		if (apagaObjeto(this->dgv.getCars(), arguments))
			return true;
		else
			return false;
	}
	else if (!arguments->at(0).compare("a")) {
		if (apagaObjeto(arguments))
			return true;
		else
			return false;
	}
	else if (!arguments->at(0).compare("p")) {
		if (apagaObjeto(dgv.getPilotos(), arguments))
			return true;
		else
			return false;
	}
	else throw e;
	return false;

}


bool Campeonato::entraNoCarro(vector<Piloto*> pilotos, vector<Carro*> carros, vector<string>* arguments)
{
	if (arguments->size() > 1) {
		ostringstream str;
		copy(arguments->begin() + 1, arguments->end() - 1, ostream_iterator<string>(str, " "));
		str << arguments->back();
		for (Piloto* p : pilotos) {
			if (str.str() == p->getName() && !(p->getCarro() != nullptr)) {
				for (Carro* c : carros) {
					if (c->getId() == arguments->at(0) && !(c->getPiloto() != nullptr)) {
						c->setPiloto(*p);
						p->setCarro(*c);
						return true;
					}
				}
			}
		}
	}

	return false;
}









