#include "GameGraphics.h"

void GameGraphics::gameInit()
{

	Consola::resizeWindowPx(1200, 600, 320, 180);
	Consola::setScreenSize(9000, 145);
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
			cout << c->getAsString();
		}
		Consola::setTextColor(Consola::AZUL_CLARO);
		for (Piloto* p : Simulador.getDGV().getPilotos()) {
			cout << p->getAsString();
		}
		Consola::setTextColor(Consola::VERDE);
		for (Autodromo a : Simulador.getAutodromos()) {
			cout << a.getAsString();
		}
		Consola::setTextColor(Consola::BRANCO);
		return true;
	}
	else
		Consola::setTextColor(Consola::BRANCO);
	return false;
}

bool GameGraphics::listaElementosFase2(Simulador& Simulador) const
{
	Consola::gotoxy(0, Simulador.getAutodromosSimulador().at(0).getPista().getPistas() + 25);
	return listaElementos(Simulador);
}

void GameGraphics::printPista(Pista& pista)
{
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	Consola::clrscr();
	Consola::setBackgroundColor(Consola::PRETO);
	Consola::maximizeWindow();
	Consola::setScreenSize(9999, pista.getComprimento() + 2);
	for (int i = 2; i < pista.getPistas() + 2; i++) {
		for (int j = 4; j < pista.getComprimento() + 5; j++) {
			Consola::gotoxy(j, i);
			cout << "_";
		}
	}
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	cout << endl;
}

void GameGraphics::printCarros(Pista& pista, vector<Carro*>& carros)
{
	Consola::setBackgroundColor(Consola::AMARELO);
	Consola::setTextColor(Consola::PRETO);
	for (int i = 0, j = 0, z = 0, y = 0; i < carros.size(); i++) {
		if ((&carros.at(i)->getPiloto() != nullptr) /*&& !carros.at(i)->getGarage()*/) {
			if (j < pista.getPistas()) {
				Consola::gotoxy(carros.at(i)->getXPosition(), j + 2);
				cout << carros.at(i)->getId();
				carros.at(i)->setPosition(carros.at(i)->getXPosition(), j + 2);
				j++;
			}
			else {
				Consola::gotoxy(4 + z, pista.getPistas() + 6 + y);
				carros.at(i)->setGarage(true);
				cout << carros.at(i)->getId();
				z++;
			}			
		}
		else {
			Consola::gotoxy(4 + z, pista.getPistas() + 6 + y);
			carros.at(i)->setGarage(true);
			cout << carros.at(i)->getId();
			z++;
		}
		if (z > 75) {
			y++;
			z = 0;
		}
	}
}

void GameGraphics::printGarage(Pista& pista, vector<Carro*>& carros)
{

	Consola::setBackgroundColor(Consola::AZUL_CLARO);
	for (int i = 4; i < 80; i++)
		for (int j = pista.getPistas() + 6; j < 20 + pista.getPistas(); j++) {
			Consola::gotoxy(i, j);
			cout << " ";
		}
}

void GameGraphics::printAll(Pista& pista, vector<Carro*>& carros) {
	printPista(pista);
	printGarage(pista, carros);
	printCarros(pista, carros);
}

int GameGraphics::endRace()
{
	int sair = 21;
	Consola::clrscr();
	Consola::gotoxy(100, 20);
	Consola::setBackgroundColor(Consola::AMARELO);
	Consola::setTextColor(Consola::VERMELHO);
	cout << "Fim da corrida, toda a gente ganhou!";
	Consola::getch();
	return sair;
}

void GameGraphics::printCommandLine(int& i, Simulador& Simulador)
{
	if (Simulador.getSimFase() == 2) {
		Consola::gotoxy(90, Simulador.getAutodromosSimulador().at(0).getPista().getPistas() + 6 + i);
		i++;
		commandLineFase2();
	}
	else
		commandLine();

}

void GameGraphics::printLog(string& log, Simulador &Simulador, int& i)
{
	if (Simulador.getSimFase() == 2) {
		Consola::gotoxy(90, Simulador.getAutodromosSimulador().at(0).getPista().getPistas() + 6 + i);
		i++;
	}
	cout << log << endl;
}







