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
#include "Simulador.h"

using namespace std;

class FileLoader
{
public:
	vector<string> getFileLines(string file_name);
	bool getFileArgs(Simulador& Simulador, string file_name);
	bool getFileArgs(string file_name, DGV& dgv);
	bool getFileArgs(vector<Carro*>& carros, string file_name);
};

