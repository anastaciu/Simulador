#include "UserConsole.h"

UserConsole::UserConsole()
{
}

void UserConsole::start()
{
	graphics.gameInit();
	int sair = -1;
	const int EXIT_POSITION = 21;
	do {
		graphics.commandLine();
		try {
			sair = executionCicle();
		}
		catch (const string & log) {
			cout << log << endl;
		}
		catch (exception e) {
			//Consola::setTextColor(Consola::VERMELHO);
			//cout << e.what() << endl;
		}
	} while (sair != EXIT_POSITION);
}

int UserConsole::executionCicle() {
	string word, command;
	vector<string> arguments;
	int command_position = -1;
	if ((command = readCommandLine()).empty()) {
		return command_position;
	}
	stringstream ss(command);
	arguments.clear();
	while (ss >> word) {
		arguments.push_back(word);
	}
	command_position = findCommand(arguments.at(0));
	if (command_position != -1) {
		arguments.erase(arguments.begin());
		if (arguments.size() < COMMANDS_ARGS[command_position]) {
			throw log.getError() + log.getArgumentError();
		}
		deleteExcessArgs(command_position, arguments);
		if (checkCommandFase1(command_position)) {
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
				try {
					if (campeonato.removeObjecto(&arguments)) {
						throw log.getDeletedMessage();
					}
					else
						throw log.getError() + log.notFound();
				}
				catch (exception e) {
					throw log.getError() + log.getArgumentError();
				}
				break;
			case 2:
				if (fileLoader.getFileArgs(arguments.at(0), campeonato.getDGV())) {
					throw log.getFileRead() + arguments.at(0);
				}
				else
					throw log.getError() + log.getFileError();
				break;
			case 3:
				if (fileLoader.getFileArgs(campeonato.getDGV().getCars(), arguments.at(0))) {
					throw log.getFileRead() + arguments.at(0);
				}
				else
					throw log.getError() + log.getFileError();
				break;
			case 4:
				if (fileLoader.getFileArgs(campeonato, arguments.at(0))) {
					throw log.getFileRead() + arguments.at(0);
				}
				else
					throw log.getError() + log.getFileError();
				break;
			case 5:
				if (campeonato.entraNoCarro(campeonato.getDGV().getPilotos(), campeonato.getDGV().getCars(), &arguments)) {
					throw log.entrou();
				}
				else
					throw log.getError() + log.getBadArgumentError();
				break;
			case 6:
				if (campeonato.saiDoCarro(campeonato.getDGV().getPilotos(), campeonato.getDGV().getCars(), &arguments)) {
					throw log.saiu();
				}
				else
					throw log.getError() + log.getBadArgumentError();
				break;
			case 7:
				if (!graphics.listaElementos(campeonato)) {
					throw log.getError() + log.listaErros();
				}
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				campeonato.setFase(2);
				break;
			}
			return command_position;
		}
		else if (checkCommandFase2(command_position)) {
			switch (command_position) {
			case 12:
				break;
			case 13:
				break;
			case 14:
				break;
			case 15:
				break;
			case 16:
				break;
			case 17:
				break;
			case 18:
				break;
			case 19:
				break;
			case 20:
				break;
			default:
				break;
			}
			return command_position;
		}
		else {
			throw log.getError() + log.getFase1Error();
		}
	}
	else {
		throw log.getError() + log.getNoCommandError();
	}

	return command_position;
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

bool UserConsole::checkCommandFase1(int position)
{
	int comandTreshold = 11;
	if ((position <= comandTreshold && campeonato.getSimFase() == 1) && position != 21) {
		return true;
	}
	return false;
}

bool UserConsole::checkCommandFase2(int position)
{
	int comandTreshold = 11;
	if (position > comandTreshold&& campeonato.getSimFase() == 2 || position == 21) {
		return true;
	}
	return false;
}

void UserConsole::deleteExcessArgs(int command_position, vector<string>& arguments)
{
	if (command_position != 0 && command_position != 1 && command_position != 5 && command_position != 6 && command_position != 11)
		while (arguments.size() > COMMANDS_ARGS[command_position]) {
			arguments.pop_back();
		}
}









