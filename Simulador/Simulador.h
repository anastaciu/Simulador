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

	//Devolve refer�ncia para a DGV
	DGV& getDGV();

	Campeonato& getCampeonato();

	//Adiciona aut�dromo com verifica��o de nome
	void addAutodromo(Autodromo autodromo);

	//verifica nomes duplicados
	bool isNameValid(Autodromo& autodromo);

	//gera string aleat�ria
	string random_string(size_t length);

	//Adiciona aut�dromo ao vetor
	void operator +=(Autodromo autodromo);

	//Devolvere refer�ncia para o vetor de aut�dromos
	vector<Autodromo> &getAutodromos();

	//Adiciona carro, piloto ou aut�dromo (comando cria)
	bool adicionaObjecto(vector<string> *arguments);

	//cria Aut�dromo, devolve true em caso de sucesso
	bool criaObjecto(vector<string>* arguments);

	//apaga carro, piloto ou aut�dromo, devolve true em caso de sucesso
	bool removeObjecto(vector<string>* arguments);

	//apaga carro, devolve true em caso de sucesso
	bool apagaObjeto(vector<Carro*>& carros, vector<string>* arguments);

	//apaga aut�dromo, devolve true em caso de sucesso
	bool apagaObjeto(vector<string>* arguments);

	//apaga piloto, devolve true em caso de sucesso
	bool apagaObjeto(vector<Piloto*>& pilotos, vector<string>* arguments);

	//chama a fun��o entranocarro da classe DGV
	bool entraNoCarro(vector<string>* arguments);

	//chama a fun��o entranocarro da classe DGV
	bool saiDoCarro(vector<string>* arguments);
	
	//comando passatempo
	bool passaTempo(vector<string>* arguments);
	
};

