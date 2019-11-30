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
#include "Campeonato.h"

using namespace std;

class FileLoader
{
public:
	vector<string> getFile(string file_name);
	bool getFileArgs(Campeonato& campeonato, string file_name);
	bool getFileArgs(string file_name, DGV& dgv);
	bool getFileArgs(vector<Carro*>& carros, string file_name);
};

