#include "Autodromo.h"
#include <iostream>



Autodromo::Autodromo(string name, int pistas, int comprimento) : name(name), pista(pistas, comprimento), garagem(80, 15), tempo(0), it(0)
{

}

bool Autodromo::operator==(Autodromo& autodromo)
{
	return this->name == autodromo.name;
}

vector<Piloto*>& Autodromo::getPilotos()
{
	return pilotos;
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
	vector<Carro*>::iterator it;
	while ((*tempo)--) {
		plusOneSecond();
		for (Carro* c : pista.getCarrosPista()) {
			try {
				c->passatempo(pista.getComprimento(), pista.getComprimentoNormal(), this->tempo);
			}
			catch (exception e) {
				pista.setPontos();
				throw e;
			}
		}
		removeCrazyIfProb();
		pista.setFirstAndLast();
		pista.setPilotosPosition();
		return true;
	}
	return false;
}

void Autodromo::carregaTudo()
{
	pista.carregaTudo();
	garagem.carregaTudo();
}

bool Autodromo::carregabat(double energia, char carro)
{
	return garagem.carregaBat(energia, carro) || pista.carregaBat(energia, carro);
}

void Autodromo::removeCrazyIfProb()
{
	vector<Carro*>::iterator it;
	it = pista.getCarrosPista().begin();
	while (it != pista.getCarrosPista().end()) {
		if ((*it)->getPiloto().getDamageProb() && (*it)->getSpeed() > 0) {
			it = pista.getCarrosPista().erase(it);
			if (it != pista.getCarrosPista().end()) {
				it = pista.getCarrosPista().erase(it);
			}
		}
		else it++;
	}
}


int Autodromo::getTempo() const
{
	return tempo;
}

void Autodromo::plusOneSecond()
{
	this->tempo++;
}

bool Autodromo::entraNocarro(vector<string>* arguments)
{
	if (arguments->size() > 1) {
		ostringstream str;
		copy(arguments->begin() + 1, arguments->end() - 1, ostream_iterator<string>(str, " "));
		str << arguments->back();
		cout << str.str();
		for (Piloto* p : this->pilotos) {
			if (str.str() == p->getName() && &p->getCarro() == nullptr) {
				for (Carro* c : this->garagem.getCarrosGaragem()) {
					if (tolower(c->getId().at(0)) == tolower(arguments->at(0).at(0)) && &c->getPiloto() == nullptr && tempo == 0) {
						c->setPiloto(p);
						p->setCarro(c);
						c->setId(toupper(c->getId().at(0)));
						addCarroToPista(c->getId().at(0));
						return true;
					}
				}
			}
		}

	}
	return false;
}

bool Autodromo::saiDoCarro(vector<string>* arguments)
{
	if (!arguments->empty()) {
		if (arguments->size() == 1 && arguments->at(0).length() == 1) {
			for (Carro* c : pista.getCarrosPista()) {
				int id = arguments->at(0).at(0);
				if ((id == tolower(c->getId().at(0)) || id == c->getId().at(0)) && &c->getPiloto() != nullptr && &c->getPiloto().getCarro() != nullptr && tempo == 0) {
					c->setId(tolower(c->getId().at(0)));
					c->getPiloto().setCarro(nullptr);
					c->setPiloto(nullptr);
					addCarroToGaragem(id);
					return true;
				}
			}
		}
	}
	return false;
}

bool Autodromo::addCarroToPista(char id) {
	bool isValid = false;
	vector<Carro*>::iterator it = garagem.getCarrosGaragem().begin();
	for (Carro* c : garagem.getCarrosGaragem()) {
		if (&c->getPiloto() != nullptr && tolower(c->getId().at(0)) == tolower(id) && pista.getPistas() > pista.getCarrosPista().size()) {
			pista.addCarroPista(c);
			c->getPiloto().setPosition(0, false, false);
			c->getPiloto().setLag();
			c->setSpeedManually(0);
			c->setPosition(0, static_cast<int>(pista.getCarrosPista().size() - 1));
			it = garagem.getCarrosGaragem().erase(it);
			return true;
		}
		if (it < garagem.getCarrosGaragem().end())
			it++;
	}
	return false;
}

bool Autodromo::addCarroToGaragem(char id)
{
	__int64 size = static_cast<__int64>(garagem.getHeight())* static_cast<__int64>(garagem.getWidth());
	vector<Carro*>::iterator it = pista.getCarrosPista().begin();
	vector<Carro*>::iterator it2 = garagem.getCarrosGaragem().end() - 1;
	for (Carro* c : pista.getCarrosPista()) {
		if (&c->getPiloto() == nullptr && tolower(c->getId().at(0)) == tolower(id) && size > static_cast<__int64>(garagem.getCarrosGaragem().size())) {
			garagem.addCarroToGaragem(c);
			c->setPosition((*it2)->getXPosition(), (*it2)->getYPosition() + 1);
			it = pista.getCarrosPista().erase(it);
			return true;
		}
		else
			it++;
	}
	return false;
}

bool Autodromo::destroi(char id)
{
	vector<Carro*>::iterator it = pista.getCarrosPista().begin();
	while (it < pista.getCarrosPista().end()) {
		if (tolower(id) == tolower((*it)->getId().at(0))) {
			(*it)->getPiloto().setCarro(nullptr);
			(*it)->setPiloto(nullptr);
			it = pista.getCarrosPista().erase(it);
			return true;
		}
		else
			it++;
	}
	it = garagem.getCarrosGaragem().begin();
	while (it < garagem.getCarrosGaragem().end()) {
		if (tolower(id) == tolower((*it)->getId().at(0))) {
			if (&(*it)->getPiloto() != nullptr) {
				(*it)->getPiloto().setCarro(nullptr);
				(*it)->setPiloto(nullptr);
			}
			it = garagem.getCarrosGaragem().erase(it);
			return true;
		}
		else
			it++;
	}
	return false;
}

Piloto* Autodromo::acidente(char id)
{
	Piloto* p = nullptr;
	vector<Carro*>::iterator it = pista.getCarrosPista().begin();
	while (it < pista.getCarrosPista().end()) {
		if (tolower(id) == tolower((*it)->getId().at(0))) {
			p = &(*it)->getPiloto();
			it = pista.getCarrosPista().erase(it);
		}
		else
			it++;
	}
	it = garagem.getCarrosGaragem().begin();
	while (it < garagem.getCarrosGaragem().end()) {
		if (tolower(id) == tolower((*it)->getId().at(0))) {
			if (&(*it)->getPiloto() != nullptr) {
				p = &(*it)->getPiloto();
				vector<Piloto*>::iterator itp = pilotos.begin();
				while (itp < pilotos.end()) {
					if (*itp == p) {
						itp = pilotos.erase(itp);
						break;
					}
					else
						itp++;
				}
				return p;
			}
			it = garagem.getCarrosGaragem().erase(it);
		}
		else
			it++;
	}
	return p;
}





