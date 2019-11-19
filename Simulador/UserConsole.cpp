#include "UserConsole.h"


string UserConsole::readCommandLine() const {
	string commandLine;
	do {
		getline(cin, commandLine);
	} while (commandLine.empty());
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
	int command_position;

	stringstream ss(readCommandLine());
	arguments.clear();
	while (ss >> word)
		arguments.push_back(word);
	try {
		command_position = findCommand(arguments.at(0));
		command = arguments.at(0);
		if (command_position > comandTreshold && getFase() == 1) {
			throw log.getFase1Error();
		}
		arguments.erase(arguments.begin());
		if (command_position != -1) {
			if (arguments.size() < COMMANDS_ARGS[command_position]) {
				throw log.getArgumentError();
			}
			if (command_position != 0 && command_position != 11)
				while (arguments.size() > COMMANDS_ARGS[command_position]) {
					arguments.pop_back();
				}
			switch (command_position) {
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
				setFase(2);
				//cout << "Início da fase 2...";
				//break;
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
				cout << "comando lido, argumentos:";
				for (string x : arguments)
					cout << " " << x;
				cout << endl;
				break;
			default:
				break;
			}
			return command_position;
		}
		else
			throw log.getNoCommandError();
	}
	catch (out_of_range exception) {
	}
	return command_position;
}

int UserConsole::getMaxArgs()
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
