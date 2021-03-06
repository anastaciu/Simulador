#pragma once
#include "Piloto.h"
#include "Crazy.h"
#include "Slow.h"
#include "Fast.h"
#include "Carro.h"
#include <vector>
#include <iterator>
#include <random>

using namespace std;

class DGV
{
private:
	string nome;
	vector<Piloto*> pilotos;
	vector<Carro*> carros;

public:
	DGV() = default;
	DGV(const DGV& orig);
	virtual ~DGV();
	DGV& operator = (const DGV& orig);
	vector<Carro*> &getCars();
	vector<Piloto*> &getPilotos();
	void addPiloto(Piloto* piloto);
	void operator += (Piloto& piloto);
	void operator += (Carro& carro);
	string random_string(size_t length);
	bool isNameValid(Piloto& piloto);
	DGV *getDGV();
	bool criaObjecto(vector<string>* arguments);
	bool criaObjecto(DGV& dgv, vector<string>* arguments);
	bool apagaObjeto(vector<string>* arguments);
	bool apagaObjeto(vector<Piloto*>& pilotos, vector<string>* arguments);
	bool entraNoCarro(vector<string>* arguments);
	bool saiDoCarro(vector<string>* arguments);
	void setName(string name);
	string getName() const;	
	static bool sortPilotosByPosition(Piloto* p1, Piloto* p2);
	void sortPilotos();
};

