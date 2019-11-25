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
	string getNoCommandError() const;
	string getCommandToken() const;
	string getArgumentError() const;
	string getBadArgumentError() const;
	string getFileError() const;
	void printLogNoReturn(string log) const;
	void printLog(string log) const;
	string getFase1Error() const;
	string getElememtCreatedMsg() const;

private:

	const string ERRO = "ERRO: ";
	const string COMMANDTOKEN = "Comando: ";
	const string ERROR_NO_COMMAND = "Comando nao encontrado";
	const string ERROR_ARGUMENTS = "Número insuficiente de argumentos";
	const string ERROR_BAD_ARGUMENTS = "Argumentos inválidos";
	const string ERROR_FILE = "Impossivel abrir ficheiro";
	const string ERROR_FASE1 = "Comando não disponível nesta fase";
	const string ELEM_CRIADO = "Elemento criado";
};

