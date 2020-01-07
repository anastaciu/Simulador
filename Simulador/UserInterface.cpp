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
		graphics.printCommandLine(i, simulador, &passaTempo, it);
		try {
			sair = executionCicle(&passaTempo);
		}
		catch (string & log) {
			graphics.printLog(log, simulador, i, it);
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
				simulador.cria(&arguments);
				break;
			case 1:
				simulador.apaga(&arguments);
				break; 
			case 2:
				simulador.carregaP(&arguments);
				break;
			case 3:
				simulador.carregaC(&arguments);
				break;
			case 4:
				simulador.carregaA(&arguments);
				break;
			case 5:
				simulador.entranocarro(&arguments);
				break;
			case 6:
				simulador.saidocarro(&arguments);
				break;
			case 7:
				lista();
				break;
			case 8:
				simulador.saveDGV(&arguments);
				break;
			case 9:
				simulador.loadDGV(&arguments);
				break;
			case 10:
				simulador.delDGV(&arguments);
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
				entraNoCarroFase2(&arguments, token_pos);
				break;
			case 6:
				saiDoCarroFase2(&arguments, token_pos);
				break;
			case 7:
				listaFase2(token_pos);
				break;
			case 12:
				listacarros(token_pos);
				break;
			case 13:
				carregabat(&arguments);
				break;
			case 14:
				carregatudo();
				break;
			case 15:
				command_position = nextRace();
				break;
			case 16:
				acidente(&arguments, token_pos);
				break;
			case 17:
				stop(&arguments, token_pos);
				break;
			case 18:
				destroi(&arguments, token_pos);
				break;
			case 19:
				command_position = passatempo(&arguments, token_pos);
				break;
			case 20:
				printEventLog(token_pos);
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
	if ((position <= comandTreshold && simulador.getSimFase() == 1) && position != 21) {
		return true;
	}
	return false;
}

bool UserInterface::checkCommandFase2(int position)
{
	int comandTreshold = 11;
	if (position > comandTreshold&& simulador.getSimFase() == 2 || position == 5 || position == 6 || position == 7 || position == 21) {
		return true;
	}
	return false;
}

void UserInterface::deleteExcessArgs(int command_position, vector<string>& arguments)
{
	if (command_position != 0 && command_position != 1 && command_position != 5 && command_position != 6 && command_position != 11 && command_position != 17)
		while ((int)arguments.size() > COMMANDS_ARGS[command_position]) {
			arguments.pop_back();
		}
}

bool UserInterface::startSimulador(vector<string>* arguments, int *tempo)
{
	int i = 0;
	if (simulador.setFase(2, arguments, &i)) {
		graphics.printAll(*simulador.getCampeonato().getAutodromosCampeonato().at(i), tempo);
		return true;
	}
	return false;
}

void UserInterface::abortStart()
{
	simulador.setFaseAbort(1);
	throw log.getError() + log.erroCamp();
}

int UserInterface::passaTempo(int* tempo)
{
	int sair = 19;
	if(tempo <= 0)
		throw log.getError() + log.getBadArgumentError();
	try {
		while (simulador.passaTempo(tempo, it)) {
			graphics.printAll(*simulador.getCampeonato().getAutodromosCampeonato().at(*it), tempo);
		}
	}
	catch (exception) {
		(*it)++;
		if (*it >= (static_cast<int>(simulador.getCampeonato().getAutodromosCampeonato().size()))) {
			simulador.getDGV().sortPilotos();
			sair = graphics.endRace(simulador.getCampeonato(), simulador.getDGV());
		}
		else {
			simulador.getDGV().sortPilotos();
			graphics.printFinalPositions(*simulador.getCampeonato().getAutodromosCampeonato().at(static_cast<__int64>(*it) - 1), simulador.getDGV());
			corrida();
		}		
	}
	return sair;
}

int UserInterface::passatempo(vector<string>* arguments, bool* token_pos)
{
	int tempo, command_position;
	stringstream ss(arguments->at(0));
	ss >> tempo;
	command_position = passaTempo(&tempo);
	*token_pos = !*token_pos;
	return command_position;
}

bool UserInterface::corrida()
{
	int tempo = 0;
	bool add_carros = simulador.addCarrosToAutodromo(it) && simulador.addPilotosToAutodromo(it);
	sort(simulador.getCampeonato().getAutodromosCampeonato().at(*it)->getPilotos().begin(),
		simulador.getCampeonato().getAutodromosCampeonato().at(*it)->getPilotos().end(),
		simulador.getCampeonato().getAutodromosCampeonato().at(*it)->sortPilotosByPosition);
	graphics.printAll(*simulador.getCampeonato().getAutodromosCampeonato().at(*it), &tempo);
	return add_carros;
}

bool UserInterface::corrida(int* it)
{
	if (*it < (int)simulador.getCampeonato().getAutodromosCampeonato().size() - 1) {
		(*it)++;
		corrida();
		return true;
	}
	return false;
}

int UserInterface::nextRace()
{
	int sair = 15;
	if (!corrida(it)) {
		simulador.getDGV().sortPilotos();
		sair = graphics.endRace(simulador.getCampeonato(), simulador.getDGV());
	}
	return sair;
}

void UserInterface::printAll()
{
	int tempo = 0;
	graphics.printAll(*simulador.getCampeonato().getAutodromosCampeonato().at(*it), &tempo);
}




void UserInterface::listaFase2(bool* token_pos)
{
	printAllNoRaceDetais();
	if (!graphics.listaElementosFase2(simulador, it)) {
		throw log.getError() + log.listaErros();
	}
	*token_pos = !*token_pos;
}

void UserInterface::lista()
{
	if (!graphics.listaElementos(simulador)) {
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

void UserInterface::listacarros(bool* token_pos)
{
	printAllNoRaceDetais();
	graphics.listaCarros(simulador, it);	
	*token_pos = !*token_pos;
}

void UserInterface::printEventLog(bool* token_pos)
{
	if (Log::getLogs().empty())
		throw log.getError() + log.listaErros();
	printAllNoRaceDetais();
	graphics.printEventLog(*simulador.getCampeonato().getAutodromosCampeonato().at(*it));
	*token_pos = !*token_pos;
}

void UserInterface::printAllNoRaceDetais()
{
	int tempo = 0;
	graphics.printAllNoRaceDetais(*simulador.getCampeonato().getAutodromosCampeonato().at(*it), &tempo);
}

void UserInterface::carregatudo()
{
	simulador.carregatudo(*it);
	graphics.printRaceClassification(*simulador.getCampeonato().getAutodromosCampeonato().at(*it));
}

void UserInterface::carregabat(vector<string>* arguments)
{
	simulador.carregabat(arguments, *it);
	graphics.printRaceClassification(*simulador.getCampeonato().getAutodromosCampeonato().at(*it));
}

void UserInterface::destroi(vector<string>* arguments, bool *token_pos)
{
	simulador.destroi(arguments, *it);
	*token_pos = !*token_pos;
	printAll();
}

void UserInterface::acidente(vector<string>* arguments, bool *token_pos)
{
	simulador.acidente(arguments, *it);
	*token_pos = !*token_pos;
	printAll();
}

void UserInterface::stop(vector<string>* arguments, bool *token_pos)
{
	simulador.stop(arguments, *it);
	*token_pos = !*token_pos;
	printAll();
}

void UserInterface::entraNoCarroFase2(vector<string>* arguments, bool* token_pos)
{
	simulador.entraNoCarroFase2(arguments, *it);
	*token_pos = !*token_pos;
	printAll();
}

void UserInterface::saiDoCarroFase2(vector<string>* arguments, bool* token_pos)
{
	simulador.saiDoCarroFase2(arguments, *it);
	*token_pos = !*token_pos;
	printAll();
}












