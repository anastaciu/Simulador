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
	if (pista.getCarrosPista().size() < 2)
		throw errorLog.getError() + errorLog.poucosCarros();
	exception e;
	while ((*tempo)--) {
		
		removeIfDamaged();
		removeEmergency();
		plusOneSecond();
		
		finish = 3;
		sort(pista.getCarrosPista().begin(), pista.getCarrosPista().end(), pista.sortCarrosByPosition);
		for (Carro* c : pista.getCarrosPista()) {
			if (c->passatempo(pista.getComprimento(), pista.getComprimentoNormal(), this->tempo)) {
				finish--;
			}
			if (finish <= 0) {
				pista.setPontos();
				sort(pilotos.begin(), pilotos.end(), sortPilotosByPosition);
				throw e;
			}
			else if (finish == 2 && pista.getCarrosPista().size() == 1) {
				pista.setPontos();
				sort(pilotos.begin(), pilotos.end(), sortPilotosByPosition);
				throw e;
			}
			else if (finish == 1 && pista.getCarrosPista().size() == 2) {
				pista.setPontos();
				sort(pilotos.begin(), pilotos.end(), sortPilotosByPosition);
				throw e;
			}
		}
		pilotIfProb();
		removeStop();
		pista.setFirstAndLast();
		pista.setPilotosPosition();
		return true;
	}
	return false;
}

void Autodromo::carregaTudo()
{
	pista.carregaTudo();
}

bool Autodromo::carregabat(double energia, char carro)
{
	return pista.carregaBat(energia, carro);
}

void Autodromo::pilotIfProb()
{
	for (size_t i = 0; i < pista.getCarrosPista().size() - 1; i++) {
		if (pista.getCarrosPista().at(i)->getPiloto().getCrazyProb() && pista.getCarrosPista().at(i)->getSpeed() > 0 
			&& pista.getComprimento() > pista.getCarrosPista().at(i)->getDistance()) {
			Log::addLog(name + pista.getCarrosPista().at(i)->getPiloto().getProbLog() + pista.getCarrosPista().at(i)->getId() + " - " + currentTime());
			sort(pista.getCarrosPista().begin(), pista.getCarrosPista().end(), pista.sortCarrosByPosition);
			pista.getCarrosPista().at(i)->setDamage(true);
			pista.getCarrosPista().at(i + 1)->setDamage(true);
		}
		if (pista.getCarrosPista().at(i)->getPiloto().getSlowProb() && pista.getCarrosPista().at(i)->getPiloto().getFirst() 
			&& pista.getCarrosPista().at(i)->getSpeed() > 0 && pista.getComprimento() > pista.getCarrosPista().at(i)->getDistance()) {
			pista.getCarrosPista().at(i)->setEmergency(true);
			Log::addLog(name + pista.getCarrosPista().at(i)->getPiloto().getProbLog() + pista.getCarrosPista().at(i)->getId() + " - " + currentTime());
		}
		if (pista.getCarrosPista().at(i)->getPiloto().getFastProb() && pista.getCarrosPista().at(i)->getSpeed() > 0
			&& pista.getComprimento() > pista.getCarrosPista().at(i)->getDistance()) {
			pista.getCarrosPista().at(i)->setEmergency(true);
			Log::addLog(name + pista.getCarrosPista().at(i)->getPiloto().getProbLog() + pista.getCarrosPista().at(i)->getId() + " - " + currentTime());

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

bool Autodromo::entraNocarro(string name, char id)
{
	for (Piloto* p : this->pilotos) {
		if (name == p->getName() && &p->getCarro() == nullptr) {
			for (Carro* c : this->garagem.getCarrosGaragem()) {
				if (tolower(c->getId().at(0)) == tolower(id) && &c->getPiloto() == nullptr && tempo == 0 && !c->getDamage()) {
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
	return false;
}

bool Autodromo::saiDoCarro(char id)
{
	for (Carro* c : pista.getCarrosPista()) {
		if (tolower(id) == tolower(c->getId().at(0)) && &c->getPiloto() != nullptr && &c->getPiloto().getCarro() != nullptr && tempo == 0 && !c->getDamage()) {
			c->setId(tolower(c->getId().at(0)));
			c->getPiloto().setCarro(nullptr);
			c->setPiloto(nullptr);
			addCarroToGaragem(id);
			return true;
		}
	}
	return false;
}

bool Autodromo::stopPiloto(char id)
{
	for (Carro* c : pista.getCarrosPista()) {
		if (tolower(id) == tolower(c->getId().at(0)) && &c->getPiloto() != nullptr && &c->getPiloto().getCarro() != nullptr) {
			c->setId(tolower(c->getId().at(0)));
			c->getPiloto().setCarro(nullptr);
			c->setPiloto(nullptr);
			addCarroToGaragem(id);
			return true;
		}
	}
	return false;
}

void Autodromo::removeEmergency()
{
	for (Carro* c : pista.getCarrosPista()) {
		if (c->getEmergency()) {
			c->setId(tolower(c->getId().at(0)));
			c->getPiloto().setCarro(nullptr);
			c->setPiloto(nullptr);
			addCarroToGaragem(c->getId().at(0));
		}
	}
}

void Autodromo::removeStop()
{
	vector<Piloto*>::iterator it = pilotos.begin();
	for (Carro* c : pista.getCarrosPista()) {
		if (c->getStop() && c->getSpeed() == 0) {
			*it = &c->getPiloto();
			stopPiloto(c->getId().at(0));
			pilotos.erase(it);
		}
	}
}

bool Autodromo::addCarroToPista(char id) {
	vector<Carro*>::iterator it = garagem.getCarrosGaragem().begin();
	bool isValid = false;

	for (Carro* c : garagem.getCarrosGaragem()) {
		if (tolower(c->getId().at(0)) == tolower(id) && pista.getCarrosPista().size() <static_cast<size_t>(pista.getPistas())) {
			for (int i = 0; i < static_cast<int>(pista.getCarrosPista().size()); i++) {
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
	vector<Carro*>::iterator it2;
	for (Carro* c : pista.getCarrosPista()) {
		if (&c->getPiloto() == nullptr && tolower(c->getId().at(0)) == tolower(id) && size > static_cast<__int64>(garagem.getCarrosGaragem().size())) {
			if (garagem.getCarrosGaragem().empty()) {						
				c->setPosition(0, 0);
			}
			else {
				it2 = garagem.getCarrosGaragem().end() - 1;
				if ((*it2)->getYPosition() < garagem.getHeight() - 1) {
					c->setPosition((*it2)->getXPosition(), (*it2)->getYPosition() + 1);
				}
				else {
					c->setPosition((*it2)->getXPosition() + 1, 0);
				}
			}
			garagem.addCarroToGaragem(c);
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
	vector<Piloto*>::iterator itp = pilotos.begin();
	while (it < pista.getCarrosPista().end()) {
		if (tolower(id) == tolower((*it)->getId().at(0))) {
			p = &(*it)->getPiloto();
			while (itp < pilotos.end()) {
				if (*itp == p) {
					itp = pilotos.erase(itp);
					break;
				}
				else
					itp++;
			}
			it = pista.getCarrosPista().erase(it);
			return p;
		}
		else
			it++;
	}
	it = garagem.getCarrosGaragem().begin();
	while (it < garagem.getCarrosGaragem().end()) {
		if (tolower(id) == tolower((*it)->getId().at(0))) {
			if (&(*it)->getPiloto() != nullptr) {
				p = &(*it)->getPiloto();
				itp = pilotos.begin();
				while (itp < pilotos.end()) {
					if (*itp == p) {
						itp = pilotos.erase(itp);
						break;
					}
					else
						itp++;
				}
			}
			it = garagem.getCarrosGaragem().erase(it);
			return p;
		}
		else
			it++;
	}
	return p;
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

void Autodromo::removeIfDamaged()
{
	vector<Carro*>::iterator it = pista.getCarrosPista().begin();
	vector<Piloto*>::iterator itp = pilotos.begin();
	while (it < pista.getCarrosPista().end()) {
		if ((*it)->getDamage()) {
			while (itp < pilotos.end()) {
				if (*itp == &(*it)->getPiloto()) {
					itp = pilotos.erase(itp);
					break;
				}
				else
					itp++;
			}
			it = pista.getCarrosPista().erase(it);
		}
		else
			it++;
	}
}



