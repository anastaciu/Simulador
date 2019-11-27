#include "UserConsole.h"


Campeonato& UserConsole::getCampeonato()
{
	return campeonato;
}

string UserConsole::readCommandLine() const {
	string commandLine;
	getline(cin, commandLine);
	return commandLine;
}

int UserConsole::findCommand(const string& command) const {
	int command_position = 0;
	for (string str : COMMANDS) {
		if (!str.compare(command))
			return command_position;
		command_position++;
	}
	return -1;
}

int UserConsole::executionCicle() {
	int comandTreshold = 11;
	string word, command;
	vector<string> arguments;
	int command_position = -1;

	stringstream ss(readCommandLine());
	arguments.clear();
	while (ss >> word)
		arguments.push_back(word);
	try {
		command_position = findCommand(arguments.at(0));
		command = arguments.at(0);
		if ((command_position > comandTreshold&& getFase() == 1) && command_position != 21) {
			throw log.getFase1Error();
		}
		arguments.erase(arguments.begin());
		if (command_position != -1) {
			if (arguments.size() < COMMANDS_ARGS[command_position]) {
				throw log.getError() + log.getArgumentError();
			}
			if (command_position != 0 && command_position != 11)
				while (arguments.size() > COMMANDS_ARGS[command_position]) {
					arguments.pop_back();
				}
			switch (command_position) {
			case 0:
				try {
					if (campeonato.adicionaObjecto(&arguments))
						throw log.getElememtCreatedMsg();
					else
						throw log.getError() + log.getBadArgumentError();
				}
				catch (exception e) {
					throw log.getError() + log.getBadArgumentError();
				}
				break;
			case 1:
			case 2:
				if (getFileArgs(campeonato.getDGV().getPilotos(), arguments.at(0), campeonato.getDGV())) {
					throw  log.getFileRead() + arguments.at(0);
				}
				else
					throw log.getError() + log.getFileError();
				break;
			case 3:
				if (getFileArgs(campeonato.getDGV().getCars(), arguments.at(0))) {
					throw log.getFileRead() + arguments.at(0);
				}
				else
					throw log.getError() + log.getFileError();
				break;
			case 4:
				if (getFileArgs(campeonato.getAutodromos(), arguments.at(0))) {
					throw log.getFileRead() + arguments.at(0);
				}
				else
					throw log.getError() + log.getFileError();
				break;
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
				setFase(2);
				break;
			case 12:
			case 13:
			case 14:
			case 15:
			case 16:
			case 17:
			case 18:
			case 19:
			case 20:
			case 21:
			default:
				break;
			}
			return command_position;
		}
		else
			throw log.getError() + log.getNoCommandError();
	}
	catch (exception e) {
		
	}
	return command_position;
}

int UserConsole::getMaxArgs() const
{
	return MAX_ARGS;
}

int UserConsole::getFase() const
{
	return fase;
}

void UserConsole::setFase(int fase)
{
	this->fase = fase;
}


vector<string> UserConsole::getFile(string file_name) {
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

bool UserConsole::getFileArgs(vector<Autodromo>& autodromos, string file_name)
{
	string word;
	vector<string> args = getFile(file_name);
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
		campeonato.addAutodromo(autodromo);
		cout << argmts.at(2);
	}
	return true;
}

bool UserConsole::getFileArgs(vector<Piloto*>& pilotos, string file_name, DGV& dgv)
{
	vector<string> args = getFile(file_name);
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
		copy(argmts.begin() + 1, argmts.end() - 1, ostream_iterator<string>(str, " "));
		str << argmts.back();
		cout << str.str() << endl;
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

bool UserConsole::getFileArgs(vector<Carro*>& carros, string file_name)
{
	vector<string> args = getFile(file_name);
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
			Carro* carro = new Carro(v_max, energy, capacity, argmts.at(3), argmts.at(4));
			carros.push_back(carro);
		}
		else if (argmts.size() == 4) {
			Carro* carro = new Carro(v_max, energy, capacity, argmts.at(4));
			carros.push_back(carro);
		}
		cout << argmts.at(4) << endl;
	}
	return true;
}






