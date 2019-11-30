#include "MessageLog.h"
#include "Consola.h"

MessageLog::MessageLog() {
}

MessageLog::MessageLog(const MessageLog& orig) {
}

MessageLog::~MessageLog() {
}

string MessageLog::getNoCommandError() const {
	return this->ERROR_NO_COMMAND;
}

string MessageLog::getCommandToken()const {
	return this->COMMANDTOKEN;
}

string MessageLog::getArgumentError() const {
	return this->ERROR_ARGUMENTS;
}

string MessageLog::getBadArgumentError() const
{
	return ERRO_BAD_ARGUMENTS;
}

string MessageLog::getFileError() const {
	return this->ERROR_FILE;
}

string MessageLog::getFase1Error() const {
	return this->ERROR_FASE1;
}

string MessageLog::getElememtCreatedMsg() const
{
	return ELEM_CRIADO;
}

string MessageLog::getFileRead() const
{
	return FICHEIRO_LIDO;
}

string MessageLog::getError() const
{
	Consola::setTextColor(Consola::VERMELHO);
	return ERRO;
}

string MessageLog::getTitle() const
{
	return TITLE;
}

string MessageLog::getDeletedMessage() const
{
	return ELIMINADO;
}

string MessageLog::notFound() const
{
	return NAO_ENCONTRADO;
}

string MessageLog::listaErros() const
{
	return ERRO_LISTA;
}

string MessageLog::entrou() const
{
	return ENTROU;
}

string MessageLog::saiu() const
{
	return SAIU;
}

string MessageLog::continuar() const
{
	return CONTINUAR;
}

string MessageLog::getFase1() const
{
	return FASE1;
}

string MessageLog::erroCamp() const
{
	return ERRO_CAMPEONATO;
}



