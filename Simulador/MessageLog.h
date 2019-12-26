#pragma once
#include <string>

using namespace std;

class MessageLog
{
private:
	const string TITLE = "                *** RACE SIMULATOR ***               ";
	const string FASE1 = "       * FASE 1 *       ";
	const string ERRO = "ERRO: ";
	const string COMMANDTOKEN = "Comando: ";
	const string ERROR_NO_COMMAND = "Comando nao encontrado";
	const string ERROR_ARGUMENTS = "Numero insuficiente de argumentos";
	const string ERRO_BAD_ARGUMENTS = "Argumentos invalidos";
	const string ERROR_FILE = "Impossivel abrir ficheiro";
	const string ERROR_FASE1 = "Comando nao disponivel nesta fase";
	const string ELEM_CRIADO = "Elemento criado";
	const string FICHEIRO_LIDO = "Ficheiro lido: ";
	const string ELIMINADO = "Elemento apagado";
	const string NAO_ENCONTRADO = "Elemento nao encontrado";
	const string ERRO_LISTA = "Nao existem itens para mostrar";
	const string ENTROU = "Piloto entrou no carro";
	const string SAIU = "Piloto saiu do carro";
	const string CONTINUAR = "Prima qualquer tecla para continuar...";
	const string ERRO_SIMULADOR = "Nao e possivel iniciar Simulador, itens em falta...";
	const string DADOS_INCORRETOS = "Dados do ficheiro invalidos...";
	const string ENERGY_ERROR = "O carro nao existe ou nao estano autodromo...";
	const string ULTIMA_PISTA = "Nao ha mais corridas...";


public:
	MessageLog();
	MessageLog(const MessageLog& orig);
	~MessageLog();
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
	string entrou() const;
	string saiu() const;
	string continuar() const;
	string getFase1() const;
	string erroCamp() const;
	string dadosIncorretos() const;
	string energyError() const;
	string ultimaCorrida() const;
};

