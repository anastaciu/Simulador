#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "MessageLog.h"
#include "Simulador.h"
#include "GameGraphics.h"
#include "FileLoader.h"

using namespace std;

class UserInterface
{
private:
	const int MAX_ARGS = 100;
	const vector<string> COMMANDS = {"cria", "apaga", "carregaP", "carregaC", "carregaA", "entranocarro", "saidocarro", "lista", "savedgv", "loaddgv", "deldgv", "campeonato", "listacarros", "carregabat", "carregatudo", "corrida", "acidente", "stop", "destroi", "passatempo", "log", "sair",};
	const vector<int> COMMANDS_ARGS = { 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 2, 0, 0, 1, 0, 1, 1, 0, 0 };
	const MessageLog log;
	Simulador simulador;
	GameGraphics graphics;
	FileLoader fileLoader;
	int* it;

public:
	UserInterface();
	~UserInterface();
	void start();
	string readCommandLine() const;
	int findCommand(const string& command) const;
	int executionCicle(bool* passaTempo);
	bool checkCommandFase1(int position);
	bool checkCommandFase2(int position);
	void deleteExcessArgs(int command_position, vector<string>& arguments);
	bool startSimulador(vector<string>* arguments, int* tempo);
	void abortStart();
	int passaTempo(int* tempo);
	int passatempo(vector<string>* arguments, bool* tempo);
	bool corrida();
	bool corrida(int* it);
	int nextRace();
	void printAll();
	void listaFase2(bool* token_pos);
	void lista();
	void campeonato(vector<string>* arguments, int* tempo);
	void listacarros(bool* passa_tempo);
	void printEventLog(bool* passa_tempo);
	void printAllNoRaceDetais();
	void carregatudo();
	void carregabat(vector<string>* arguments);
	void destroi(vector<string>* arguments, bool* token_pos);
	void acidente(vector<string>* arguments, bool* token_pos);
	void stop(vector<string>* arguments, bool* token_pos);
	void entraNoCarroFase2(vector<string>* arguments, bool* token_pos);
	void saiDoCarroFase2(vector<string>* arguments, bool* token_pos);
};

