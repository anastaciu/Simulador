#include "Autodromo.h"

Autodromo::Autodromo(string name, int pistas, int comprimento) : name(name), pista(pistas, comprimento), garagem(80, 15), tempo(0), it(0), finish(3)
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
	exception e;
	vector<Carro*>::iterator it;
	while ((*tempo)--) {
		plusOneSecond();
		finish = 3;
		for (Carro* c : pista.getCarrosPista()) {
			if (c->getEmergency()) {
				emergency(c->getId().at(0), &c->getPiloto(), c);
			}
			if (c->passatempo(pista.getComprimento(), pista.getComprimentoNormal(), this->tempo)) {
				finish--;
			}
			if (finish <= 0) {
				pista.setPontos();
				sort(pilotos.begin(), pilotos.end(), sortPilotosByPosition);
				throw e;
			}
		}
		pilotIfProb();
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

void Autodromo::pilotIfProb()
{
	for(int i = 0; i < pista.getCarrosPista().size(); i++){
		if (pista.getCarrosPista().at(i)->getPiloto().getCrazyProb() && pista.getCarrosPista().at(i)->getSpeed() > 0) {
			Log::addLog(name + ": Probabilidade de 5% de dano positiva para " + pista.getCarrosPista().at(i)->getPiloto().getName() + " no carro "
				+ pista.getCarrosPista().at(i)->getId() + " - " + currentTime());
			pista.getCarrosPista().erase(pista.getCarrosPista().begin() + i);
			if (pista.getCarrosPista().begin() + i < pista.getCarrosPista().end() - 1) {
				pista.getCarrosPista().erase(pista.getCarrosPista().begin() + i + 1);
			}
		}
		if (pista.getCarrosPista().at(i)->getPiloto().getSlowProb() && pista.getCarrosPista().at(i)->getPiloto().getFirst()) {
			pista.getCarrosPista().at(i)->setEmergency(true);
			Log::addLog(name + ": Probabilidade de 10% de emergencia positiva para " + pista.getCarrosPista().at(i)->getPiloto().getName() + " no carro "
				+ pista.getCarrosPista().at(i)->getId() + " - " + currentTime());
		}


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
		for (Piloto* p : this->pilotos) {
			if (str.str() == p->getName() && &p->getCarro() == nullptr) {
				for (Carro* c : this->garagem.getCarrosGaragem()) {
					if (tolower(c->getId().at(0)) == tolower(arguments->at(0).at(0)) && &c->getPiloto() == nullptr && tempo == 0) {
						if (addCarroToPista(c->getId().at(0))) {
							c->setPiloto(p);
							p->setCarro(c);
							c->setId(toupper(c->getId().at(0)));
							c->getPiloto().setPosition(0, false, false);
							c->getPiloto().setLag();
							c->setSpeedManually(0);
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool Autodromo::saiDoCarro(char id)
{
	for (Carro* c : pista.getCarrosPista()) {
		if (tolower(id) == tolower(c->getId().at(0)) && &c->getPiloto() != nullptr && &c->getPiloto().getCarro() != nullptr && tempo == 0) {
			c->setId(tolower(c->getId().at(0)));
			c->getPiloto().setCarro(nullptr);
			c->setPiloto(nullptr);
			addCarroToGaragem(id);
			return true;
		}
	}		
	return false;
}

bool Autodromo::emergency(char id, Piloto* piloto, Carro* carro)
{
		if (piloto != nullptr && &piloto->getCarro() != nullptr) {
			carro->setId(tolower(carro->getId().at(0)));
			carro->getPiloto().setCarro(nullptr);
			carro->setPiloto(nullptr);
			addCarroToGaragem(id);
			return true;
		}
	return false;
}

bool Autodromo::addCarroToPista(char id) {
	vector<Carro*>::iterator it = garagem.getCarrosGaragem().begin();
	bool isValid = false;
	
	for (Carro* c : garagem.getCarrosGaragem()) {
		if (tolower(c->getId().at(0)) == tolower(id) && pista.getCarrosPista().size() < pista.getPistas()) {
			for (int i = 0; i < pista.getCarrosPista().size(); i++) {
				if (pista.getCarrosPista().at(i)->getYPosition() != i) {
					c->setPosition(0, i);
					pista.getCarrosPista().insert(pista.getCarrosPista().begin() + i, c);
					isValid = true;
					break;
				}
			}
			if (!isValid) {
				pista.getCarrosPista().push_back(c);
				c->setPosition(0, static_cast<int>(pista.getCarrosPista().size()) - 1);
				isValid = true;
			}
			it = garagem.getCarrosGaragem().erase(it);
		}
		else
			it++;
	}
	return isValid;
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

vector<string> Autodromo::getLog()
{
	return log;
}

const string Autodromo::currentTime()
{
	time_t now = time(0);
	struct tm timeStruct;
	char dataProb[80];
	localtime_s(&timeStruct, &now);
	strftime(dataProb, sizeof(dataProb), "%d-%m-%Y, %X", &timeStruct);
	return dataProb;
}

bool Autodromo::sortPilotosByPosition(Piloto* p1, Piloto* p2)
{
	return p1->getPontos() > p2->getPontos();
}






