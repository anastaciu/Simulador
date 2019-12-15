#include "Simulador.h"


Simulador::Simulador() : fase(1)
{
}

Simulador::~Simulador()
{
	autodromos.clear();
}

DGV& Simulador::getDGV()
{
	return dgv;
}

Campeonato& Simulador::getCampeonato()
{
	return campeonato;
}

void Simulador::addAutodromo(Autodromo autodromo)
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

bool Simulador::setFase(int fase, vector<string>* arguments)
{
	if (arguments->size() < 1)
		return false;
	for (Autodromo a : autodromos) {
		if (arguments->at(0) == a.getName()) {
			campeonato.getAutodromosCampeonato().push_back(a);
			cout << campeonato.getAutodromosCampeonato().at(0).getName();
			system("pause");
			this->fase = fase;
			return true;
		}	
	}
	return false;
}

void Simulador::setFaseAbort(int fase)
{
	this->fase = fase;
	if(campeonato.getAutodromosCampeonato().size() > 0)
		this->campeonato.getAutodromosCampeonato().clear();
}

int Simulador::getSimFase() const
{
	return this->fase;
}

bool Simulador::isNameValid(Autodromo& autodromo)
{
	for (Autodromo a : autodromos) {
		if (a == autodromo) {
			return false;
		}
	}
	return true;
}

string Simulador::random_string(size_t length)
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

void Simulador::operator+= (Autodromo autodromo)
{
	autodromos.push_back(autodromo);
}

vector<Autodromo>& Simulador::getAutodromos()
{
	return autodromos;
}

bool Simulador::adicionaObjecto(vector<string>* arguments)
{
	if (!arguments->at(0).compare("c") && dgv.criaObjecto(arguments)) {
		return true;
	}
	else if (!arguments->at(0).compare("a") && criaObjecto(arguments)) {
		return true;
	}
	else if (!arguments->at(0).compare("p") && dgv.criaObjecto(dgv, arguments)) {
		return true;
	}
	return false;
}

bool Simulador::criaObjecto(vector<string>* arguments)
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

bool Simulador::apagaObjeto(vector<string>* arguments)
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

bool Simulador::removeObjecto(vector<string>* arguments)
{
	exception e;

	if (!arguments->at(0).compare("c")) {
		if (dgv.apagaObjeto(arguments))
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
		if (dgv.apagaObjeto(dgv.getPilotos(), arguments))
			return true;
		else
			return false;
	}
	else throw e;
	return false;

}

bool Simulador::entraNoCarro(vector<string>* arguments)
{
	return dgv.entraNoCarro(arguments);
}

bool Simulador::saiDoCarro(vector<string>* arguments)
{
	return dgv.saiDoCarro(arguments);
}

bool Simulador::passaTempo(vector<string>* arguments)
{
	int tempo;
	stringstream ss(arguments->at(0));
	ss >> tempo;
	for (Carro* c : this->getDGV().getCars()) {
		if (&c->getPiloto() != nullptr) {
			c->setPosition(c->getXPosition() + 1 * tempo, c->getYPosition());
			if (c->getXPosition() > campeonato.getAutodromosCampeonato().at(0).getPista().getComprimento() + 4) {
				return false;
			}
		}
	}
	return true;
}















