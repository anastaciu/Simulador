#include "Simulador.h"


Simulador::Simulador() : fase(1)
{
}

Simulador::~Simulador()
{
	for (Autodromo* a : autodromos) {
		delete a;
	}
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

void Simulador::addAutodromo(Autodromo* autodromo)
{
	size_t str_length = 10;
	if (!isNameValid(*autodromo)) {
		autodromo->setName(random_string(str_length));
		*this += autodromo;
	}
	else
	{
		*this += autodromo;
	}

}

bool Simulador::setFase(int fase, vector<string>* arguments, int* i)
{
	return addAutodromosToCampeonato(fase, arguments) && addCarrosToAutodromo(i) && addPilotosToAutodromo(i);
}

void Simulador::setFaseAbort(int fase)
{
	this->fase = fase;
	if (campeonato.getAutodromosCampeonato().size() > 0)
		this->campeonato.getAutodromosCampeonato().clear();
}

int Simulador::getSimFase() const
{
	return this->fase;
}

bool Simulador::isNameValid(Autodromo& autodromo)
{
	for (Autodromo* a : autodromos) {
		if (*a == autodromo) {
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

void Simulador::operator+= (Autodromo* autodromo)
{
	autodromos.push_back(autodromo);
}

vector<Autodromo*>& Simulador::getAutodromos()
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
		Autodromo* autodromo = new Autodromo(arguments->at(3), pistas, comprimento);
		addAutodromo(autodromo);
		return true;
	}
	return false;
}

bool Simulador::apagaObjeto(vector<string>* arguments)
{
	vector<Autodromo*>::iterator it;
	it = autodromos.begin();
	while (it != autodromos.end()) {
		if (arguments->at(1) == (*it)->getName()) {
			delete *it;
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
		return dgv.apagaObjeto(arguments);
	}
	else if (!arguments->at(0).compare("a")) {
		return apagaObjeto(arguments);
	}
	else if (!arguments->at(0).compare("p")) {
		return dgv.apagaObjeto(dgv.getPilotos(), arguments);
	}

	return false;
}

bool Simulador::entraNoCarro(vector<string>* arguments)
{
	return dgv.entraNoCarro(arguments);
}

void Simulador::entranocarro(vector<string>* arguments)
{
	if (entraNoCarro(arguments)) {
		throw log.entrou();
	}
	else
		throw log.getError() + log.getBadArgumentError();
}

bool Simulador::saiDoCarro(vector<string>* arguments)
{
	return dgv.saiDoCarro(arguments);
}

void Simulador::saidocarro(vector<string>* arguments) {
	if (saiDoCarro(arguments)) {
		throw log.saiu();
	}
	else
		throw log.getError() + log.getBadArgumentError();
}

bool Simulador::passaTempo(int* tempo, int* i)
{
	return campeonato.passaTempo(tempo, i);
}


bool Simulador::addCarrosToAutodromo(int* i) {
	bool isValid = false;
	int j = 0, x = 0, y = 0;
	for (Carro* c : dgv.getCars()) {
		if (&c->getPiloto() != nullptr && campeonato.getAutodromosCampeonato().at(*i)->getPista().getPistas() > j) {
			campeonato.getAutodromosCampeonato().at(*i)->getPista().addCarroPista(c);
			c->getPiloto().setPosition(0, false, false);
			c->getPiloto().setLag();
			c->setSpeedManually(0);
			c->setPosition(0, j++);
			if (!isValid)
				isValid = !isValid;
		}
		else {
			campeonato.getAutodromosCampeonato().at(*i)->getGaragem().addCarroToGaragem(c);
			c->setPosition(x, y++);
			if (y >= campeonato.getAutodromosCampeonato().at(*i)->getGaragem().getHeight()) {
				x++;
				y = 0;
			}
		}
	}
	return isValid;
}

bool Simulador::addPilotosToAutodromo(int* i)
{
	for (Piloto* p : dgv.getPilotos()) {
		campeonato.getAutodromosCampeonato().at(*i)->getPilotos().push_back(p);
	}
	return true;
}

bool Simulador::addAutodromosToCampeonato(int fase, vector<string>* arguments)
{
	bool isValid = false;
	if (arguments->size() < 1)
		return isValid;
	for (string s : *arguments) {
		for (Autodromo* a : autodromos) {
			if (s == a->getName()) {
				campeonato.getAutodromosCampeonato().push_back(a);
				if (this->fase != fase)
					this->fase = fase;
				if (!isValid)
					isValid = true;
				break;
			}
		}
	}
	return isValid;
}

void Simulador::cria(vector<string>* arguments)
{
	try {
		if (adicionaObjecto(arguments))
			throw log.getElememtCreatedMsg();
		else
			throw log.getError() + log.getBadArgumentError();
	}
	catch (exception e) {
		throw log.getError() + log.getBadArgumentError();
	}
}

void Simulador::apaga(vector<string>* arguments)
{
	try {
		if (removeObjecto(arguments)) {
			throw log.getDeletedMessage();
		}
		else
			throw log.getError() + log.notFound();
	}
	catch (exception e) {
		throw log.getError() + log.getArgumentError();
	}
}

void Simulador::carregaP(vector<string>* arguments)
{
	if (fileLoader.getFileArgs(arguments->at(0), getDGV())) {
		throw log.getFileRead() + arguments->at(0);
	}
	else
		throw log.getError() + log.getFileError();
}

void Simulador::carregaC(vector<string>* arguments)
{
	if (fileLoader.getFileArgs(dgv.getCars(), arguments->at(0))) {
		throw log.getFileRead() + arguments->at(0);
	}
	else
		throw log.getError() + log.getFileError();
}

void Simulador::carregaA(vector<string>* arguments)
{
	try {
		if (autodromosDoFicheiro(arguments->at(0))) {
			throw log.getFileRead() + arguments->at(0);
		}
		else
			throw log.getError() + log.dadosIncorretos();
	}
	catch (exception) {
		throw log.getError() + log.getFileError();
	}
}

bool Simulador::autodromosDoFicheiro(string file_name)
{
	vector<string> args = fileLoader.getFileLines(file_name);
	string word;
	if (args.empty()) {
		return false;
	}
	vector<string> argmts;
	int pistas, comprimento;
	for (string str : args) {
		argmts.clear();
		stringstream ss(str);
		while (ss >> word) {
			argmts.push_back(word);
		}
		stringstream arg1(argmts.at(0));
		arg1 >> pistas;
		stringstream arg2(argmts.at(1));
		arg2 >> comprimento;
		if (comprimento < 1 || pistas < 1) {
			return false;
		}
		Autodromo* autodromo = new Autodromo(argmts.at(2), pistas, comprimento);
		addAutodromo(autodromo);
	}
	return true;
}

void Simulador::carregatudo(int* it)
{
	campeonato.getAutodromosCampeonato().at(*it)->carregaTudo();
}

void Simulador::carregabat(vector<string>* arguments, int it)
{
	exception e;
	double energia;
	stringstream ss(arguments->at(1));
	ss >> energia;
	if (!campeonato.getAutodromosCampeonato().at(it)->carregabat(energia, arguments->at(0).at(0)) || energia <= 0) {
		throw log.getError() + log.getBadArgumentError();
	}
}

bool Simulador::entraNoCarroFase2(vector<string>* arguments, int it)
{
	return campeonato.getAutodromosCampeonato().at(it)->entraNocarro(arguments);
}

bool Simulador::saiDoCarroFase2(vector<string>* arguments, int it)
{
	return campeonato.getAutodromosCampeonato().at(it)->saiDoCarro(arguments);
}















