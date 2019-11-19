#pragma once
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class MessageLog
{
public:
	MessageLog();
	MessageLog(const MessageLog& orig);
	virtual ~MessageLog();
	void printLogError(string log) const;
	string getLogConfigError() const;
	string getNoCommandError() const;
	string getCommandToken() const;
	string getArgumentError() const;
	string getFileError() const;
	string getFase2Error() const;
	string getTitle() const;
	string getTitleFase1() const;
	string getTitleFase2() const;
	void printLogNoReturn(string log) const;
	void printLog(string log) const;
	string getFase1Error() const;
	string getShipCreationLog(const string& ship, const bool& status);

private:
	const string TITLE = "*----  ----*\n\n";
	const string TITLE_FASE1 = "Fase de configuracao:\n\n";
	const string TITLE_FASE2 = "\n\n\nFase de jogo:\n\n";
	const string ERRO = "ERRO: ";
	const string COMMANDTOKEN = "Comando: ";
	const string ERROR_CONFIG_DONE = "Configuracao ja efectuada";
	const string ERROR_CONFIG = "Configuracao nao efectuada";
	const string ERROR_NO_COMMAND = "Comando nao encontrado";
	const string ERROR_ARGUMENTS = "Número insuficiente de argumentos";
	const string ERROR_FILE = "Impossivel abrir ficheiro";
	const string ERROR_FASE2 = "Nao e possivel configurar jogo na fase 2";
	const string ERROR_FASE1 = "Comando não disponível nesta fase";
};

