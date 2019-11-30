#pragma once
#include "Autodromo.h"
#include "DGV.h"
#include "Crazy.h"
#include "Slow.h"
#include "Fast.h"
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

class Campeonato
{
private:
	vector<Autodromo> autodromos;
	DGV dgv;
	int fase;

public:
	//construtor
	Campeonato();

	//define a fase do simulador
	void setFase(int fase);

	//ve fase do simulador
	int getSimFase() const;

	//Devolve referência para a DGV
	DGV& getDGV();

	//Adiciona autódromo com verificação de nome
	void addAutodromo(Autodromo autodromo);

	//verifica nomes duplicados
	bool isNameValid(Autodromo& autodromo);

	//gera string aleatória
	string random_string(size_t length);

	//Adiciona autódromo ao vetor
	void operator +=(Autodromo autodromo);

	//Devolvere referência para o vetor de autódromos
	vector<Autodromo> &getAutodromos();

	//Adiciona carro, piloto ou autódromo (comando cria)
	bool adicionaObjecto(vector<string> *arguments);

	//Cria carro, devolve true em caso de sucesso
	bool criaObjecto(vector<Carro*> &carros, vector<string>* arguments);

	//cria Autódromo, devolve true em caso de sucesso
	bool criaObjecto(vector<string>* arguments);

	//Cria piloto rápido, surpresa ou crazy, devolve true em caso de sucesso
	bool criaObjecto(DGV& dgv, vector<string>* arguments);

	//apaga carro, piloto ou autódromo, devolve true em caso de sucesso
	bool removeObjecto(vector<string>* arguments);

	//apaga carro, devolve true em caso de sucesso
	bool apagaObjeto(vector<Carro*>& carros, vector<string>* arguments);

	//apaga autódromo, devolve true em caso de sucesso
	bool apagaObjeto(vector<string>* arguments);

	//apaga piloto, devolve true em caso de sucesso
	bool apagaObjeto(vector<Piloto*>& pilotos, vector<string>* arguments);

	//associa carro a piloto e vice versa, verifica se é possível piloto entrar no carro
	//Devolve true em caso de sucesso
	bool entraNoCarro(vector<Piloto*> pilotos, vector<Carro*> carros, vector<string>* arguments);

	//Sai do carro por Id de carro ou por nome de piloto, devolve true em caso de sucesso
	bool saiDoCarro(vector<Piloto*> pilotos, vector<Carro*> carros, vector<string>* arguments);

	//sai do carro, apenas por ID de carro, devolve true em caso de sucesso
	bool saiDoCarro(vector<Carro*> carros, vector<string>* arguments);
	
};

