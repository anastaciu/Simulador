#include "Log.h"

vector<string>Log::logs;
int Log::camp = 1;

Log::~Log()
{
	camp++;
}

vector<string> Log::getLogs()
{
	return logs;
}

void  Log::addLog(string log) {
	logs.push_back(log);
}

int Log::getCamp()
{
	return camp;
}
