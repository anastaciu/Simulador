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
	Consola::setBackgroundColor(Consola::VERMELHO);
	return ERRO;
}

string MessageLog::getTitle() const
{
	Consola::setBackgroundColor(Consola::AZUL_CLARO);
	return TITLE;
}



