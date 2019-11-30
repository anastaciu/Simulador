#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "MessageLog.h"
#include "Campeonato.h"
#include "GameGraphics.h"
#include "FileLoader.h"

using namespace std;

class UserConsole
{
private:
	const int MAX_ARGS = 100;
	const vector<string> COMMANDS = {"cria", "apaga", "carregaP", "carregaC", "carregaA", "entranocarro", "saidocarro", "lista", "savedgv", "loaddgv", "deldgv", "campeonato", "listacarros", "carregabat", "carregatudo", "corrida", "acidente", "stop", "destroi", "passatempo", "log", "sair",};
	const vector<int> COMMANDS_ARGS = { 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 2, 0, 0, 1, 1, 1, 1, 0, 0 };
	const MessageLog log;
	Campeonato campeonato;
	GameGraphics graphics;
	FileLoader fileLoader;

public:
	UserConsole();
	void start();
	string readCommandLine() const;
	int findCommand(const string& command) const;
	int executionCicle();
	bool checkCommandFase1(int position);
	bool checkCommandFase2(int position);
	void deleteExcessArgs(int command_position, vector<string>& arguments);

};

