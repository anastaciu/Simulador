#include "UserInterface.h"

UserInterface::UserInterface()
{
}

void UserInterface::start()
{
	graphics.gameInit();
	int sair = -1;
	int i = 0;
	const int EXIT_POSITION = 21;
	do {
		graphics.printCommandLine(i, Simulador);
		try {
			sair = executionCicle();
		}
		catch (string & log) {
			graphics.printLog(log, Simulador, i);
		}
		catch (exception e) {
			//cout << e.what();
		}

	} while (sair != EXIT_POSITION);
}

int UserInterface::executionCicle() {
	string word, command;
	exception e;
	vector<string> arguments;
	int command_position = -1;
	if ((command = readCommandLine()).empty()) {
		throw e;
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
					if (Simulador.adicionaObjecto(&arguments))
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
					if (Simulador.removeObjecto(&arguments)) {
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
				if (fileLoader.getFileArgs(arguments.at(0), Simulador.getDGV())) {
					throw log.getFileRead() + arguments.at(0);
				}
				else
					throw log.getError() + log.getFileError();
				break;
			case 3:
				if (fileLoader.getFileArgs(Simulador.getDGV().getCars(), arguments.at(0))) {
					throw log.getFileRead() + arguments.at(0);
				}
				else
					throw log.getError() + log.getFileError();
				break;
			case 4:
				if (fileLoader.getFileArgs(Simulador, arguments.at(0))) {
					throw log.getFileRead() + arguments.at(0);
				}
				else
					throw log.getError() + log.getFileError();
				break;
			case 5:
				if (Simulador.entraNoCarro(Simulador.getDGV().getPilotos(), Simulador.getDGV().getCars(), &arguments)) {
					throw log.entrou();
				}
				else
					throw log.getError() + log.getBadArgumentError();
				break;
			case 6:
				if (Simulador.saiDoCarro(Simulador.getDGV().getPilotos(), Simulador.getDGV().getCars(), &arguments)) {
					throw log.saiu();
				}
				else
					throw log.getError() + log.getBadArgumentError();
				break;
			case 7:
				if (!graphics.listaElementos(Simulador)) {
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
				try {
					if (!startSimulador(&arguments)) {
						throw log.getError() + log.getBadArgumentError();
					}
				}
				catch (exception e) {
					abortStart();
				}
				break;
			}
			return command_position;
		}
		else if (checkCommandFase2(command_position)) {
			switch (command_position) {
			case 5:
				if (Simulador.entraNoCarro(Simulador.getDGV().getPilotos(), Simulador.getDGV().getCars(), &arguments)) {
					throw log.entrou();
				}
				else
					throw log.getError() + log.getBadArgumentError();
				break;
			case 6:
				if (Simulador.saiDoCarro(Simulador.getDGV().getPilotos(), Simulador.getDGV().getCars(), &arguments)) {
					throw log.saiu();
				}
				else
					throw log.getError() + log.getBadArgumentError();
				break;
			case 7:
				if (!graphics.listaElementosFase2(Simulador)) {
					throw log.getError() + log.listaErros();
				}
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
				if (Simulador.passaTempo(&arguments)) {
					graphics.printAll(Simulador.getCampeonato().getAutodromosCampeonato().at(0).getPista(), Simulador.getDGV().getCars());
				}
				else
					return graphics.endRace();				
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

string UserInterface::readCommandLine() const {
	string commandLine;
	getline(cin, commandLine);
	return commandLine;
}

int UserInterface::findCommand(const string& command) const {
	int command_position = 0;
	for (string str : COMMANDS) {
		if (!str.compare(command))
			return command_position;
		command_position++;
	}
	return -1;
}

bool UserInterface::checkCommandFase1(int position)
{
	int comandTreshold = 11;
	if ((position <= comandTreshold && Simulador.getSimFase() == 1) && position != 21) {
		return true;
	}
	return false;
}

bool UserInterface::checkCommandFase2(int position)
{
	int comandTreshold = 11;
	if (position > comandTreshold&& Simulador.getSimFase() == 2 || position == 5 || position == 6 || position == 7 || position == 21) {
		return true;
	}
	return false;
}

void UserInterface::deleteExcessArgs(int command_position, vector<string>& arguments)
{
	if (command_position != 0 && command_position != 1 && command_position != 5 && command_position != 6 && command_position != 11)
		while (arguments.size() > COMMANDS_ARGS[command_position]) {
			arguments.pop_back();
		}
}

bool UserInterface::startSimulador(vector<string>* arguments)
{	
	if (Simulador.setFase(2, arguments)) {

		graphics.printAll(Simulador.getCampeonato().getAutodromosCampeonato().at(0).getPista(), Simulador.getDGV().getCars());
		return true;
	}
	return false;
}

void UserInterface::abortStart()
{
	Simulador.setFaseAbort(1);
	throw log.getError() + log.erroCamp();
}









