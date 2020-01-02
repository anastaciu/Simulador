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
	vector<DGV> savedDGVs;
	vector<Autodromo*> autodromos;
	DGV dgv;
	int fase;
	Campeonato campeonato;
	MessageLog log;
	FileLoader fileLoader;

public:
	Simulador();
	~Simulador();
	bool setFase(int fase, vector<string>* arguments, int* i);
	void setFaseAbort(int fase);
	int getSimFase() const;
	DGV& getDGV();
	Campeonato& getCampeonato();
	void addAutodromo(Autodromo* autodromo);
	bool isNameValid(Autodromo& autodromo);
	string random_string(size_t length);
	void operator +=(Autodromo* autodromo);
	vector<Autodromo*> &getAutodromos();
	bool adicionaObjecto(vector<string> *arguments);
	bool criaObjecto(vector<string>* arguments);
	bool removeObjecto(vector<string>* arguments);
	bool apagaObjeto(vector<string>* arguments);
	bool entraNoCarro(vector<string>* arguments);
	void entranocarro(vector<string>* arguments);
	bool saiDoCarro(vector<string>* arguments);
	void saidocarro(vector<string>* arguments);
	bool passaTempo(int* tempo, int* i);
	bool addCarrosToAutodromo(int* i);
	bool addPilotosToAutodromo(int* i);
	bool addAutodromosToCampeonato(int fase, vector<string>* arguments);
	void cria(vector<string>* arguments);
	void apaga(vector<string>* arguments);
	void carregaP(vector<string>* arguments);
	void carregaC(vector<string>* arguments);
	void carregaA(vector<string>* arguments);
	bool autodromosDoFicheiro(string file_name);
	void carregatudo(int* it);
	void carregabat(vector<string>* arguments, int it);
	void entraNoCarroFase2(vector<string>* arguments, int it);
	void saiDoCarroFase2(vector<string>* arguments, int it);
	void stop(vector<string>* arguments, int it);
	void destroi(vector<string>* arguments, int it);
	void acidente(vector<string>* arguments, int it);
	void saveDGV(vector<string>* arguments);
	void loadDGV(vector<string>* arguments);
	void delDGV(vector<string>* arguments);

};

