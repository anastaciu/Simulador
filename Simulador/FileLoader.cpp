#include "FileLoader.h"


vector<string> FileLoader::getFileLines(string file_name) {
	vector<string> lines;
	ifstream file(file_name);
	string temp;
	if (file.is_open()) {
		while (getline(file, temp)) {
			lines.push_back(temp);
		}
	}
	file.close();
	return lines;
}

bool FileLoader::getFileArgs(Simulador& Simulador, string file_name)
{
	string word;
	vector<string> args = getFileLines(file_name);
	if (args.empty()) {
		return false;
	}
	vector<string> argmts;
	int pistas, comprimento;
	for (string str : args) {
		argmts.clear();
		stringstream ss(str);
		while (ss >> word) {
			argmts.push_back(word);
		}
		stringstream arg1(argmts.at(0));
		arg1 >> pistas;
		stringstream arg2(argmts.at(1));
		arg2 >> comprimento;
		Autodromo autodromo(argmts.at(2), pistas, comprimento);
		Simulador.addAutodromo(autodromo);
	}
	return true;
}

bool FileLoader::getFileArgs(string file_name, DGV& dgv)
{
	vector<string> args = getFileLines(file_name);
	if (args.empty()) {
		return false;
	}
	string word;
	vector<string> argmts;
	for (string str : args) {
		argmts.clear();
		stringstream ss(str);
		while (ss >> word) {
			argmts.push_back(word);
		}
		ostringstream str;
		if (argmts.empty())
			return false;
		copy(argmts.begin() + 1, argmts.end() - 1, ostream_iterator<string>(str, " "));
		str << argmts.back();
		if (!argmts.at(0).compare("crazy")) {
			dgv.addPiloto(new Crazy(str.str()));
		}
		else if (!argmts.at(0).compare("rapido")) {
			dgv.addPiloto(new Fast(str.str()));
		}
		else if (!argmts.at(0).compare("surpresa")) {
			dgv.addPiloto(new Slow(str.str()));
		}
	}
	return true;
}

bool FileLoader::getFileArgs(vector<Carro*>& carros, string file_name)
{
	vector<string> args = getFileLines(file_name);
	if (args.empty()) {
		return false;
	}
	string word;
	vector<string> argmts;
	int v_max;
	double energy, capacity;

	for (string str : args) {
		argmts.clear();
		stringstream ss(str);
		while (ss >> word) {
			argmts.push_back(word);
		}
		stringstream arg1(argmts.at(0));
		arg1 >> v_max;
		stringstream arg2(argmts.at(1));
		arg2 >> energy;
		stringstream arg3(argmts.at(2));
		arg3 >> capacity;
		if (argmts.size() == 5) {
			carros.push_back(new Carro(v_max, energy, capacity, argmts.at(3), argmts.at(4)));
		}
		else if (argmts.size() == 4) {
			carros.push_back(new Carro(v_max, energy, capacity, argmts.at(4)));
		}
	}
	return true;
}