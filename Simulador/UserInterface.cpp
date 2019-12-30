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

int UserInterface::executionCicle(bool* token_pos) {
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
				Simulador.cria(&arguments);
				break;
			case 1:
				Simulador.apaga(&arguments);
				break; 
			case 2:
				Simulador.carregaP(&arguments);
				break;
			case 3:
				Simulador.carregaC(&arguments);
				break;
			case 4:
				Simulador.carregaA(&arguments);
				break;
			case 5:
				Simulador.entranocarro(&arguments);
				break;
			case 6:
				Simulador.saidocarro(&arguments);
				break;
			case 7:
				lista();
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				campeonato(&arguments, &tempo);
				break;
			}
			return command_position;
		}
		else if (checkCommandFase2(command_position)) {
			switch (command_position) {
			case 5:
				Simulador.entraNoCarroFase2(&arguments, *it);
				break;
			case 6:
				Simulador.saiDoCarroFase2(&arguments, *it);
				break;
			case 7:
				listaFase2(token_pos);
				break;
			case 12:
				listacarros(token_pos);
				break;
			case 13:
				Simulador.carregabat(&arguments, *it);
				break;
			case 14:
				Simulador.carregatudo(it);
				break;
			case 15:
				nextRace();
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
				command_position = passaTempo(&tempo);
				*token_pos = !*token_pos;
			}
				break;
			case 20:
				break;
			case 21:
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

int UserInterface::passaTempo(int* tempo)
{
	int sair = 19;
	if(tempo <= 0)
		throw log.getError() + log.getBadArgumentError();
	try {
		while (Simulador.passaTempo(tempo, it)) {
			graphics.printAll(*Simulador.getCampeonato().getAutodromosCampeonato().at(*it), tempo);
		}
	}
	catch (exception) {
		(*it)++;
		if(*it >= Simulador.getCampeonato().getAutodromosCampeonato().size())
			sair = graphics.endRace();
		else {
			corrida();
		}		
	}
	return sair;
}

bool UserInterface::corrida()
{
	int tempo = 0;
	bool add_carros = Simulador.addCarrosToAutodromo(it);
	graphics.printAll(*Simulador.getCampeonato().getAutodromosCampeonato().at(*it), &tempo);
	return add_carros;
}

bool UserInterface::corrida(int* it)
{
	if (*it < Simulador.getCampeonato().getAutodromosCampeonato().size() - 1) {
		(*it)++;
		corrida();
		return true;
	}
	return false;
}

void UserInterface::nextRace()
{
	if (!corrida(it)) {
		throw log.getError() + log.ultimaCorrida();
	}
}

void UserInterface::printAll()
{
	int tempo = 0;
	graphics.printAll(*Simulador.getCampeonato().getAutodromosCampeonato().at(*it), &tempo);
}



void UserInterface::listaFase2(bool* token_pos)
{
	printAll();
	if (!graphics.listaElementosFase2(Simulador, it)) {
		throw log.getError() + log.listaErros();
	}
	*token_pos = !*token_pos;
}

void UserInterface::lista()
{
	if (!graphics.listaElementos(Simulador)) {
		throw log.getError() + log.listaErros();
	}
}

void UserInterface::campeonato(vector<string>* arguments, int* tempo)
{
	try {
		if (!startSimulador(arguments, tempo)) {
			abortStart();
			throw log.getError() + log.erroCamp();
		}
	}
	catch (exception e) {
		abortStart();
	}
}

void UserInterface::listacarros(bool* passa_tempo)
{
	printAll();
	graphics.listaCarros(Simulador, it);	
	*passa_tempo = !*passa_tempo;
}











