#include "UserInterface.h"

UserInterface::UserInterface() : it(new int(0))
{
}

UserInterface::~UserInterface()
{
	delete it;	
}

void UserInterface::start()
{
	graphics.gameInit();
	int sair = -1;
	int i = 0;
	bool passaTempo = false;	
	const int EXIT_POSITION = 21;
	do {
		graphics.printCommandLine(i, Simulador, &passaTempo, it);
		try {
			sair = executionCicle(&passaTempo);
		}
		catch (string & log) {
			graphics.printLog(log, Simulador, i, it);
		}
		catch (exception e) {
			//cout << e.what();
		}

	} while (sair != EXIT_POSITION);
}

int UserInterface::executionCicle(bool* passaTempo) {
	string word, command;
	exception e;
	vector<string> arguments;
	int command_position = -1, tempo = 0;
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
		if (static_cast<int>(arguments.size()) < COMMANDS_ARGS[command_position]) {
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
				if (Simulador.entraNoCarro(&arguments)) {
					throw log.entrou();
				}
				else
					throw log.getError() + log.getBadArgumentError();
				break;
			case 6:
				if (Simulador.saiDoCarro(&arguments)) {
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
					if (!startSimulador(&arguments, &tempo)) {
						abortStart();
						throw log.getError() + log.erroCamp();
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
				if (Simulador.entraNoCarro(&arguments)) {
					throw log.entrou();
				}
				else
					throw log.getError() + log.getBadArgumentError();
				break;
			case 6:
				if (Simulador.saiDoCarro(&arguments)) {
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
			case 19: {
				stringstream ss(arguments.at(0));
				ss >> tempo;
				command_position = passatempo(&tempo);
				*passaTempo = !*passaTempo;
			}
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
		while ((int)arguments.size() > COMMANDS_ARGS[command_position]) {
			arguments.pop_back();
		}
}

bool UserInterface::startSimulador(vector<string>* arguments, int *tempo)
{
	int i = 0;
	if (Simulador.setFase(2, arguments, &i)) {
		graphics.printAll(*Simulador.getCampeonato().getAutodromosCampeonato().at(i), tempo);
		return true;
	}
	return false;
}

void UserInterface::abortStart()
{
	Simulador.setFaseAbort(1);
	throw log.getError() + log.erroCamp();
}

int UserInterface::passatempo(int* tempo)
{
	int sair = 19;
	if (*tempo > 0)
		graphics.printTempo(Simulador.getCampeonato().getAutodromosCampeonato().at(*it)->getPista().getPistas() + 3, tempo);
	else {
		throw log.getError() + log.getBadArgumentError();
	}
	try {
		while (Simulador.getCampeonato().passaTempo(tempo, it)) {
			graphics.printAll(*Simulador.getCampeonato().getAutodromosCampeonato().at(*it), tempo);
		}
	}
	catch (exception) {
		(*it)++;
		if(*it >= Simulador.getCampeonato().getAutodromosCampeonato().size())
			sair = graphics.endRace();
		graphics.printAll(*Simulador.getCampeonato().getAutodromosCampeonato().at(*it), tempo);
	}
	return sair;
}









