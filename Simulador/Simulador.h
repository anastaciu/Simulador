#pragma once
#include "Campeonato.h"
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

class Simulador
{
private:
	vector<Autodromo> autodromos;
	DGV dgv;
	int fase;
	Campeonato campeonato;

public:
	//construtor
	Simulador();
	~Simulador();

	//define a fase do simulador
	bool setFase(int fase, vector<string>* arguments);

	//faz reset ao comando setFase em caso de erro
	void setFaseAbort(int fase);

	//ve fase do simulador
	int getSimFase() const;

	//Devolve referência para a DGV
	DGV& getDGV();

	Campeonato& getCampeonato();

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

	//cria Autódromo, devolve true em caso de sucesso
	bool criaObjecto(vector<string>* arguments);

	//apaga carro, piloto ou autódromo, devolve true em caso de sucesso
	bool removeObjecto(vector<string>* arguments);

	//apaga carro, devolve true em caso de sucesso
	bool apagaObjeto(vector<Carro*>& carros, vector<string>* arguments);

	//apaga autódromo, devolve true em caso de sucesso
	bool apagaObjeto(vector<string>* arguments);

	//apaga piloto, devolve true em caso de sucesso
	bool apagaObjeto(vector<Piloto*>& pilotos, vector<string>* arguments);

	//chama a função entranocarro da classe DGV
	bool entraNoCarro(vector<string>* arguments);

	//chama a função entranocarro da classe DGV
	bool saiDoCarro(vector<string>* arguments);
	
	//comando passatempo
	bool passaTempo(vector<string>* arguments);
	
};

