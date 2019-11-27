#pragma once
#include <string>

using namespace std;

class MessageLog
{
public:
	MessageLog();
	MessageLog(const MessageLog& orig);
	virtual ~MessageLog();
	string getNoCommandError() const;
	string getCommandToken() const;
	string getArgumentError() const;
	string getBadArgumentError() const;
	string getFileError() const;
	string getFase1Error() const;
	string getElememtCreatedMsg() const;
	string getFileRead() const;
	string getError() const;
	string getTitle() const;
	string getDeletedMessage() const;
	string notFound() const;
	string listaErros() const;

private:
	const string TITLE = "                **RACE SIMULATOR**                ";
	const string ERRO = "ERRO: ";
	const string COMMANDTOKEN = "Comando: ";
	const string ERROR_NO_COMMAND = "Comando nao encontrado";
	const string ERROR_ARGUMENTS = "Numero insuficiente de argumentos";
	const string ERRO_BAD_ARGUMENTS = "Argumentos invalidos";
	const string ERROR_FILE = "Impossivel abrir ficheiro";
	const string ERROR_FASE1 = "Comando não disponivel nesta fase";
	const string ELEM_CRIADO = "Elemento criado";
	const string FICHEIRO_LIDO = "Ficheiro lido: ";
	const string ELIMINADO = "Elemento apagado";
	const string NAO_ENCONTRADO = "Elemento nao encontrado";
	const string ERRO_LISTA = "Pelo menos uma lista de elementos esta vazia";
};

