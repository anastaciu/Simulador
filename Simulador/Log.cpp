#include "Log.h"

vector<string>Log::logs;

vector<string> Log::getLogs()
{
	return logs;
}

void  Log::addLog(string log) {
	logs.push_back(log);
}