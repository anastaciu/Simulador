#include "GameGraphics.h"

GameGraphics::GameGraphics() : screenSet(false)
{
}

void GameGraphics::gameInit()
{
	setScreenSize();
	Consola::gotoxy(44, 2);
	Consola::setBackgroundColor(Consola::AZUL_CLARO);
	cout << log.getTitle() << endl << endl;
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	Consola::setTextColor(Consola::PRETO);
	Consola::gotoxy(59, 3);
	cout << log.getFase1();
	Consola::gotoxy(0, 10);
}

void GameGraphics::commandLine()
{
	Consola::setBackgroundColor(Consola::PRETO);
	Consola::setTextColor(Consola::BRANCO);
	cout << log.getCommandToken();
}

void GameGraphics::commandLineFase2()
{
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	Consola::setTextColor(Consola::PRETO);
	cout << log.getCommandToken();
}



bool GameGraphics::listaElementos(Simulador& Simulador) const
{
	if (!Simulador.getDGV().getPilotos().empty() || !Simulador.getDGV().getCars().empty() || !Simulador.getAutodromos().empty()) {
		Consola::setTextColor(Consola::AMARELO);
		for (Carro* c : Simulador.getDGV().getCars()) {
			cout << "    " << c->getAsString();
		}
		Consola::setTextColor(Consola::AZUL_CLARO);
		for (Piloto* p : Simulador.getDGV().getPilotos()) {
			cout << "    " << p->getAsString();
		}
		Consola::setTextColor(Consola::VERDE);
		for (Autodromo* a : Simulador.getAutodromos()) {
			cout << "    "  << a->getAsString();
		}
		Consola::setTextColor(Consola::BRANCO);
		return true;
	}
	else
		Consola::setTextColor(Consola::BRANCO);
	return false;
}

void GameGraphics::listaCarros(Simulador& Simulador, int* it) {
	Consola::gotoxy(0, Simulador.getCampeonato().getAutodromosCampeonato().at(*it)->getPista().getPistas() + Simulador.getCampeonato().getAutodromosCampeonato().at(*it)->getGaragem().getHeight() + 11);
	Consola::setTextColor(Consola::VERDE);
	cout << "   PISTA" << endl;
	for (Carro* c : Simulador.getCampeonato().getAutodromosCampeonato().at(*it)->getPista().getCarrosPista()) {
		cout << "    " << c->getAsString();
	}
	Consola::setTextColor(Consola::AZUL);
	cout << endl << "   GARAGEM" << endl;
	for (Carro* c : Simulador.getCampeonato().getAutodromosCampeonato().at(*it)->getGaragem().getCarrosGaragem()) {
		cout << "    " << c->getAsString();
	}
}

void GameGraphics::printPassatempo(Autodromo& autodromo, int* tempo)
{
	printPista(autodromo.getPista());
	printGarage(autodromo);
	printCarros(autodromo);
	printTempo(autodromo.getPista().getPistas() + 7, tempo);
}

bool GameGraphics::listaElementosFase2(Simulador& Simulador, int* it) const
{
	Consola::gotoxy(0, Simulador.getCampeonato().getAutodromosCampeonato().at(*it)->getPista().getPistas() + Simulador.getCampeonato().getAutodromosCampeonato().at(*it)->getGaragem().getHeight() + 11);
	return listaElementos(Simulador);
}

void GameGraphics::printPista(Pista& pista)
{
	Consola::setTextColor(Consola::BRANCO_CLARO);
	Consola::setBackgroundColor(Consola::PRETO);
	for (int j = 4; j < pista.getComprimentoNormal() + 7; j++) {
		for (int i = 6; i < pista.getPistas() + 6; i++) {
			Consola::gotoxy(j, i);
			cout << "_";
		}
	}
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	cout << endl;
}

void GameGraphics::printCarros(Autodromo& autodromo)
{
	for (Carro* c : autodromo.getPista().getCarrosPista()) {
		if (c->getEmergency()) {
			Consola::setBackgroundColor(Consola::VERMELHO);
			Consola::setTextColor(Consola::BRANCO_CLARO);
		}
		else if(c->getDamage()) {
			Consola::setBackgroundColor(Consola::VERMELHO);
			Consola::setTextColor(Consola::PRETO);
		}
		else if (c->getStop()) {
			Consola::setBackgroundColor(Consola::BRANCO);
			Consola::setTextColor(Consola::VERMELHO);
		}
		else {
			Consola::setBackgroundColor(Consola::AMARELO);
			Consola::setTextColor(Consola::PRETO);
		}
		Consola::gotoxy(static_cast<int>(trunc(c->getXPosition())) + 4, c->getYPosition() + 6);
		cout << " " << c->getId() << " ";
	}
	for (Carro* c : autodromo.getGaragem().getCarrosGaragem()) {
		if (c->getEmergency()) {
			Consola::setBackgroundColor(Consola::VERMELHO);
			Consola::setTextColor(Consola::BRANCO_CLARO);
		}
		else if(c->getStop()){
			Consola::setBackgroundColor(Consola::BRANCO);
			Consola::setTextColor(Consola::VERMELHO);
		}
		else {
			Consola::setBackgroundColor(Consola::AMARELO);
			Consola::setTextColor(Consola::PRETO);
		}

		Consola::gotoxy(4 + static_cast<int>(trunc(c->getXPosition())), autodromo.getPista().getPistas() + 10 + c->getYPosition());
		cout << c->getId();
	}
}

void GameGraphics::printGarage(Autodromo& autodromo)
{
	Consola::setBackgroundColor(Consola::AZUL_CLARO);
	for (int i = 4; i < autodromo.getGaragem().getWidth(); i++)
		for (int j = autodromo.getPista().getPistas() + 10; j < autodromo.getGaragem().getHeight() + 10 + autodromo.getPista().getPistas(); j++) {
			Consola::gotoxy(i, j);
			cout << " ";
		}
}

void GameGraphics::printAll(Autodromo& autodromo, int* tempo) {
	printBackground();
	printPista(autodromo.getPista());
	printGarage(autodromo);
	printCarros(autodromo);
	printRaceDetails(autodromo);
	printAutodromoName(autodromo);
	printTempo(autodromo.getPista().getPistas() + 7, tempo);
}

int GameGraphics::endRace(Campeonato campeonato, DGV dgv)
{
	int sair = 21;
	Consola::clrscr();
	Consola::gotoxy(5, 5);
	Consola::setBackgroundColor(Consola::AZUL);
	Consola::setTextColor(Consola::BRANCO_CLARO);
	printFinalClassification(dgv);
	return sair;
}

void GameGraphics::printCommandLine(int& i, Simulador& Simulador, bool* passaTempo, int* it)
{
	if (Simulador.getSimFase() == 2) {
		if (*passaTempo) {
			i = 0;
			*passaTempo = !*passaTempo;
		}
		Consola::gotoxy(90, Simulador.getCampeonato().getAutodromosCampeonato().at(*it)->getPista().getPistas() + 10 + i);
		i++;
		commandLineFase2();
	}
	else
		commandLine();
}

void GameGraphics::printLog(string& log, Simulador& Simulador, int& i, int* it)
{
	if (Simulador.getSimFase() == 2) {
		Consola::gotoxy(90, Simulador.getCampeonato().getAutodromosCampeonato().at(*it)->getPista().getPistas() + 10 + i);
		i++;
	}
	cout << log << endl;
}

void GameGraphics::printTempo(int posY, int* tempo)
{
	if (*tempo > 0) {
		Consola::gotoxy(70, posY);
		cout << "                                                                                                           ";
		Consola::gotoxy(70, posY);
		Consola::setTextColor(Consola::BRANCO_CLARO);
		Consola::setBackgroundColor(Consola::VERDE);
		cout << "Tempo: " << *tempo << " seg" << " -> Prima uma tecla...";
		Consola::getch();
		Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	}
}

void GameGraphics::printAutodromoName(Autodromo autodromo)
{
	Consola::gotoxy(66, 1);
	Consola::setBackgroundColor(Consola::AZUL_CLARO);
	Consola::setTextColor(Consola::BRANCO);
	cout << "       **** Race Simulator ****       ";
	Consola::gotoxy(75, 2);
	Consola::setBackgroundColor(Consola::VERDE);
	Consola::setTextColor(Consola::BRANCO);
	cout << "     * Fase 2 *     ";
	Consola::gotoxy(72, 4);
	Consola::setBackgroundColor(Consola::VERMELHO_CLARO);
	Consola::setTextColor(Consola::PRETO);
	cout << "  Autodromo: " << autodromo.getName() <<",  "<<  autodromo.getPista().getComprimento() << " m  ";
	Consola::gotoxy(140, 5);
	Consola::setBackgroundColor(Consola::VERDE);
	Consola::setTextColor(Consola::BRANCO_CLARO);
	cout << " Instante: " << autodromo.getTempo() << " seg ";
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
}

void GameGraphics::printBackground()
{
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	Consola::clrscr();
}

void GameGraphics::setScreenSize()
{
	Consola::maximizeWindow();
	Consola::setScreenSize(2000, 170);
}

void GameGraphics::printRaceDetails(Autodromo autodromo) {

	Consola::gotoxy(0, autodromo.getPista().getPistas() + autodromo.getGaragem().getHeight() + 11);
	Consola::setTextColor(Consola::AZUL);
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	cout << "   Classificacao da corrida" << endl;
	for (Carro* c : autodromo.getPista().getCarrosPista()) {
		cout << "  " << c->getRaceDetails() << endl;
	}
	cout << endl;
	int i = 0;
	Consola::setTextColor(Consola::VERDE);
	cout << "   Classificacao dos pilotos presentes" << endl;
	for (Piloto* p : autodromo.getPilotos()) {
		cout << "    " << ++i << " - " << p->getDriverDetails();
	}
}

void GameGraphics::printEventLog(Autodromo autodromo)
{
	Consola::gotoxy(0, autodromo.getPista().getPistas() + autodromo.getGaragem().getHeight() + 11);
	Consola::setTextColor(Consola::VERMELHO);
	for (string logs : Log::getLogs()) {
		cout << "    " << logs << endl;
	}
}

void GameGraphics::mainMenu()
{
	Consola::setBackgroundColor(Consola::PRETO);
	Consola::setTextColor(Consola::BRANCO_CLARO);
	Consola::clrscr();
	Consola::gotoxy(2, 2);
	cout << "N - Novo Jogo";
	Consola::gotoxy(2, 3);
	cout << "S - Sair";
	Consola::gotoxy(2, 4);
	cout << "> ";
}

void GameGraphics::printAllNoRaceDetais(Autodromo& autodromo, int* tempo) {
	printBackground();
	printPista(autodromo.getPista());
	printGarage(autodromo);
	printCarros(autodromo);
	printAutodromoName(autodromo);
	printTempo(autodromo.getPista().getPistas() + 7, tempo);
}

void GameGraphics::printFinalPositions(Autodromo autodromo, DGV dgv)
{
	Consola::setBackgroundColor(Consola::AMARELO_CLARO);	
	Consola::clrscr();
	Consola::gotoxy(0, 5);
	Consola::setTextColor(Consola::AZUL);
	cout << "    Classificacao da corrida" << endl;
	for (Carro* c : autodromo.getPista().getCarrosPista()) {
		cout << "  " << c->getRaceDetails() << endl;
	}
	cout << endl;
	int i = 0;
	Consola::setTextColor(Consola::VERDE);
	cout << "    Classificacao geral" << endl;
	for (Piloto* p : dgv.getPilotos()) {
		cout << "    " << ++i << " - " << p->getDriverDetails();
	}
	Consola::setTextColor(Consola::VERMELHO);
	cout << endl;
	cout << "    Log" << endl;
	for (string logs: Log::getLogs()) {
		cout << "    " << logs << endl;
	}
	cout << endl << "    Prima uma tecla para continuar...";
	Consola::getch();
}

void GameGraphics::printRaceClassification(Autodromo autodromo)
{
	Consola::gotoxy(0, autodromo.getPista().getPistas() + autodromo.getGaragem().getHeight() + 11);
	Consola::setTextColor(Consola::AZUL);
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	cout << "   Classificacao da corrida" << endl;
	for (Carro* c : autodromo.getPista().getCarrosPista()) {
		cout << "  " << c->getRaceDetails() << endl;
	}
}

void GameGraphics::printFinalClassification(DGV dgv)
{
	int i = 0;
	Consola::setTextColor(Consola::BRANCO_CLARO);
	Consola::setBackgroundColor(Consola::AZUL);
	Consola::clrscr();
	cout << "    Classificacao geral final" << endl;
	for (Piloto* p : dgv.getPilotos()) {
		cout << "    " << ++i << " - " << p->getDriverDetails();
	}
	cout << endl;
	Consola::setTextColor(Consola::AMARELO_CLARO);
	cout << "    Log" << endl;
	for (string logs : Log::getLogs()) {
		cout << "    " << logs << endl;
	}
	cout << endl << "    Prima uma tecla para sair...";
	Consola::getch();
	

}







