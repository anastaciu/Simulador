#pragma once
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include "Autodromo.h"
#include "DGV.h"
#include "Crazy.h"
#include "Slow.h"
#include "Fast.h"
#include "MessageLog.h"

using namespace std;

class FileLoader
{
private:
	MessageLog log;
public:
	vector<string> getFileLines(string file_name);
	vector<string> getFileArgs(string file_name);
	bool getFileArgs(string file_name, DGV& dgv);
	bool getFileArgs(vector<Carro*>& carros, string file_name);
};

