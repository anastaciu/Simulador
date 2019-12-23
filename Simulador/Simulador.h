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
#include "MessageLog.h"
#include "FileLoader.h"


using namespace std;

class Simulador
{
private:
	vector<Autodromo*> autodromos;
	DGV dgv;
	int fase;
	Campeonato campeonato;
	MessageLog log;
	FileLoader fileLoader;

public:
	//construtores
	Simulador();
	~Simulador();

	//define a fase do simulador
	bool setFase(int fase, vector<string>* arguments, int* i);

	//faz reset ao comando setFase em caso de erro
	void setFaseAbort(int fase);

	//ve fase do simulador
	int getSimFase() const;

	//Devolve refer�ncia para a DGV
	DGV& getDGV();

	//Devolve campeonato em curso
	Campeonato& getCampeonato();

	//Adiciona aut�dromo com verifica��o de nome
	void addAutodromo(Autodromo* autodromo);

	//verifica nomes duplicados
	bool isNameValid(Autodromo& autodromo);

	//gera string aleat�ria
	string random_string(size_t length);

	//Adiciona aut�dromo ao vetor
	void operator +=(Autodromo* autodromo);

	//Devolvere refer�ncia para o vetor de aut�dromos
	vector<Autodromo*> &getAutodromos();

	//Adiciona carro, piloto ou aut�dromo (comando cria)
	bool adicionaObjecto(vector<string> *arguments);

	//cria Aut�dromo, devolve true em caso de sucesso
	bool criaObjecto(vector<string>* arguments);

	//apaga carro, piloto ou aut�dromo, devolve true em caso de sucesso
	bool removeObjecto(vector<string>* arguments);

	//apaga aut�dromo, devolve true em caso de sucesso
	bool apagaObjeto(vector<string>* arguments);

	//chama a fun��o entranocarro da classe DGV
	bool entraNoCarro(vector<string>* arguments);

	//comando entranocarro
	void entranocarro(vector<string>* arguments);

	//chama a fun��o entranocarro da classe DGV
	bool saiDoCarro(vector<string>* arguments);

	//comando saidocarro
	void saidocarro(vector<string>* arguments);
	
	//comando passatempo
	bool passaTempo(vector<string>* arguments);
	
	//coloca os carros no aut�dromo
	bool addCarrosToAutodromo(int* i);

	//coloca aut�dromos no campeonato
	bool addAutodromosToCampeonato(int fase, vector<string>* arguments);

	//comando cria
	void cria(vector<string>* arguments);

	//comando apaga
	void apaga(vector<string>* arguments);

	//comando carregaP
	void carregaP(vector<string>* arguments);

	//comando carregaC
	void carregaC(vector<string>* arguments);

	//comando carregaA
	void carregaA(vector<string>* arguments);

	//carrega ficheiro de autodromos
	bool autodromosDoFicheiro(string file_name);

	//comando carregatudo
	void carregatudo(int* it);

	//comando carregabat
	void carregabat(vector<string>* arguments, int it);

};

