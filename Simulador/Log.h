#pragma once
#include <string>
#include <vector>

using namespace std;

class Log
{
private:
	static vector<string> logs;
	static int camp;
	Log() = default;
	virtual ~Log();
public:
	static vector<string> getLogs();
	static void addLog(string log);
	static int getCamp();
};



