#include "MessageLog.h"


MessageLog::MessageLog() {
}

MessageLog::MessageLog(const MessageLog& orig) {
}

MessageLog::~MessageLog() {
}

void MessageLog::printLogError(string log) const {
	cout << ERRO << log << endl;
}

void MessageLog::printLog(string log) const {
	cout << log << endl;
}

void MessageLog::printLogNoReturn(string log) const {
	cout << log;
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
	return ERROR_BAD_ARGUMENTS;
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


