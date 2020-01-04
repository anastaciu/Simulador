#pragma once
#include <string>
#include <vector>

using namespace std;

class Log
{
private:
	static vector<string> logs;
	Log() = default;
public:
	static vector<string> getLogs();
	static void addLog(string log);
};



