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

string MessageLog::getLogConfigError() const {
	return this->ERROR_CONFIG;
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

string MessageLog::getFileError() const {
	return this->ERROR_FILE;
}

string MessageLog::getFase2Error() const {
	return this->ERROR_FASE2;
}

string MessageLog::getFase1Error() const {
	return this->ERROR_FASE1;
}

string MessageLog::getShipCreationLog(const string& ship, const bool& status) {
	ostringstream oss;
	if (status)
		oss << "Navio " << ship << " criado" << endl;
	else
		oss << "Navio " << ship << " nao existe" << endl;
	return oss.str();
}

string MessageLog::getTitle() const {
	return this->TITLE;
}

string MessageLog::getTitleFase1() const {
	return this->TITLE_FASE1;
}

string MessageLog::getTitleFase2() const {
	return this->TITLE_FASE2;
}