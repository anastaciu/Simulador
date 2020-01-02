#include "DGV.h"
#include <iostream>

DGV::DGV(const DGV& orig)
{
	*this = orig;
}

DGV::~DGV()
{
	for (Carro* c : carros) {
		delete c;
	}
	for (Piloto* p : pilotos) {
		delete p;
	}
	carros.clear();
	pilotos.clear();
}

DGV& DGV::operator=(const DGV& orig)
{
	if(this == &orig){
		return *this;
	}
	for (Carro* c : carros) {
		delete c;
	}
	for(Piloto* p: pilotos){
		delete p;
	}
	carros.clear();
	pilotos.clear();
	nome = orig.nome;
	for (int i = 0; i < orig.pilotos.size(); i++) {
		Piloto* p = orig.pilotos.at(i)->duplica();
		p->setCarro(nullptr);
		pilotos.push_back(p);
	}
	for (int i = 0; i < orig.carros.size(); i++) {
		Carro* c = orig.carros.at(i)->duplica();
		c->setPiloto(nullptr);
		carros.push_back(c);
	}


	return *this;
}

vector<Carro*>& DGV::getCars()
{
	return carros;
}

vector<Piloto*>& DGV::getPilotos()
{
	return pilotos;
}

void DGV::operator += (Piloto& piloto)
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

bool DGV::isNameValid(Piloto& piloto)
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

bool DGV::entraNoCarro(vector<string>* arguments)
{
	if (arguments->size() > 1) {
		ostringstream str;
		copy(arguments->begin() + 1, arguments->end() - 1, ostream_iterator<string>(str, " "));
		str << arguments->back();
		for (Piloto* p : this->pilotos) {
			if (str.str() == p->getName() && &p->getCarro() == nullptr) {
				for (Carro* c : this->carros) {
					if (c->getId() == arguments->at(0) && &c->getPiloto() == nullptr) {
						c->setPiloto(p);
						p->setCarro(c);
						c->setId(toupper(c->getId().at(0)));
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool DGV::saiDoCarro(vector<string>* arguments)
{
	if (!arguments->empty()) {
		if (arguments->size() == 1 && arguments->at(0).length() == 1) {
			for (Carro* c : carros) {
				int id = arguments->at(0).at(0);
				if ((id == tolower(c->getId().at(0)) || id == c->getId().at(0)) && &c->getPiloto() != nullptr && &c->getPiloto().getCarro() != nullptr) {
					c->setId(tolower(c->getId().at(0)));
					c->getPiloto().setCarro(nullptr);
					c->setPiloto(nullptr);
					return true;
				}
			}
		}
		ostringstream str;
		copy(arguments->begin(), arguments->end() - 1, ostream_iterator<string>(str, " "));
		str << arguments->back();
		for (Piloto* p : pilotos) {
			if (str.str() == p->getName() && &p->getCarro() != nullptr && &p->getCarro().getPiloto() != nullptr) {
				p->getCarro().setId(tolower(p->getCarro().getId().at(0)));
				p->getCarro().setPiloto(nullptr);
				p->setCarro(nullptr);
				return true;
			}
		}

	}
	return false;
}

void DGV::setName(string name)
{
	this->nome = name;
}

string DGV::getName() const
{
	return this->nome;
}

bool DGV::criaObjecto(vector<string>* arguments)
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


bool DGV::criaObjecto(DGV& dgv, vector<string>* arguments)
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

bool DGV::apagaObjeto(vector<Piloto*>& pilotos, vector<string>* arguments)
{
	vector<Piloto*>::iterator it;
	it = pilotos.begin();
	ostringstream str;
	copy(arguments->begin() + 1, arguments->end() - 1, ostream_iterator<string>(str, " "));
	str << arguments->back();
	while (it != pilotos.end()) {
		if (str.str() == (*it)->getName()) {
			if (&(*it)->getCarro() != nullptr) {
				(*it)->getCarro().nullifyPiloto();
				(*it)->getCarro().setId(tolower((*it)->getCarro().getId().at(0)));
			}
			delete* it;
			it = pilotos.erase(it);
			return true;
		}
		else {
			it++;
		}
	}
	return false;
}

bool DGV::apagaObjeto(vector<string>* arguments)
{
	vector<Carro*>::iterator it;
	it = carros.begin();
	while (it != carros.end()) {
		if (tolower(arguments->at(1).at(0)) == tolower((*it)->getId().at(0))) {
			if (&(*it)->getPiloto() != nullptr)
				(*it)->getPiloto().nullifyCarro();
			delete* it;
			it = carros.erase(it);
			return true;
		}
		else {
			it++;
		}
	}
	return false;
}



