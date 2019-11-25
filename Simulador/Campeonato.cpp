#include "Campeonato.h"


Campeonato::Campeonato()
{

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

vector<Autodromo> Campeonato::getAutodromos()
{
	return autodromos;
}

bool Campeonato::adicionaObjecto(vector<string>* arguments)
{
	exception e;

	if (!arguments->at(0).compare("c")) {

		if (criaObjecto(this->dgv.getCars(), arguments))
			return true;
	}
	else if (!arguments->at(0).compare("a")) {
		criaObjecto(arguments);
		return true;
	}
	else if (!arguments->at(0).compare("p")) {
		criaObjecto(dgv.getPilotos(), arguments);
		return true;
	}
	else throw e;
	return false;
}

bool Campeonato::criaObjecto(vector<Carro*> &carros, vector<string>* arguments)
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
		Carro* carro = new Carro(v_max, energy, capacity, arguments->at(4), arguments->at(5));
		carros.push_back(carro);
		return true;
	}
	else if (arguments->size() == 5) {
		Carro* carro = new Carro(v_max, energy, capacity, arguments->at(4));
		carros.push_back(carro);
		return true;
	}
	else throw e;
	return false;
}

bool Campeonato::criaObjecto(vector<string>* arguments)
{
	Autodromo autodromo(arguments->at(1));
	addAutodromo(autodromo);
	return true;
}

bool Campeonato::criaObjecto(vector<Piloto*>& pilotos, vector<string>* arguments) 
{
	ostringstream str;
	if (!arguments->empty())
	{
		copy(arguments->begin()+1, arguments->end()-1,
			ostream_iterator<string>(str, " "));
		str << arguments->back();
		dgv.addPiloto(new Piloto(str.str()));
	}		
	return true;
}

DGV &Campeonato::getDGV()
{
	return dgv;
}









