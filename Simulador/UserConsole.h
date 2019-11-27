#pragma once
#include <vector>
#include<string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "MessageLog.h"
#include "Campeonato.h"

using namespace std;

class UserConsole
{
private:
	int fase = 1;
	const int MAX_ARGS = 100;
	const vector<string> COMMANDS = {"cria", "apaga", "carregaP", "carregaC", "carregaA", "entranocarro", "saidocarro", "lista", "savedgv", "loaddgv", "deldgv", "campeonato", "listacarros", "carregabat", "carregatudo", "corrida", "acidente", "stop", "destroi", "passatempo", "log", "sair",};
	const vector<int> COMMANDS_ARGS = { 0, 2, 1, 1, 1, 2, 1, 0, 1, 1, 1, 1, 0, 2, 0, 0, 1, 1, 1, 1, 0, 0 };
	const MessageLog log;
	Campeonato campeonato;

public:
	Campeonato &getCampeonato();
	string readCommandLine() const;
	int findCommand(const string& command) const;
	int executionCicle();
	int getMaxArgs()const;
	int getFase() const;
	void setFase(int fase);
	vector<string> getFile(string file_name);
	bool getFileArgs(vector<Autodromo>& autodromos, string file_name);
	bool getFileArgs(vector<Piloto*>& pilotos, string file_name, DGV& dgv);
	bool getFileArgs(vector<Carro*>& carros, string file_name);

};

