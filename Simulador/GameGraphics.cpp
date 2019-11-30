#include "GameGraphics.h"

void GameGraphics::gameInit()
{
	Consola::setScreenSize(9000, 140);
	Consola::resizeWindowPx(1200, 600, 320, 180);
	Consola::gotoxy(44, 2);
	Consola::setBackgroundColor(Consola::AZUL_CLARO);
	cout << log.getTitle() << endl << endl;
	Consola::setBackgroundColor(Consola::VERDE_CLARO);
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

bool GameGraphics::listaElementos(Campeonato& campeonato) const
{
	if (!campeonato.getDGV().getPilotos().empty() || !campeonato.getDGV().getCars().empty() || !campeonato.getAutodromos().empty()) {
		Consola::setTextColor(Consola::AMARELO);
		for (Carro* c : campeonato.getDGV().getCars()) {
			cout << c->getAsString();
		}
		Consola::setTextColor(Consola::AZUL_CLARO);
		for (Piloto* p : campeonato.getDGV().getPilotos()) {
			cout << p->getAsString();
		}
		Consola::setTextColor(Consola::VERDE_CLARO);
		for (Autodromo a : campeonato.getAutodromos()) {
			cout << a.getAsString();
		}
		Consola::setTextColor(Consola::BRANCO);
		return true;
	}
	else
		Consola::setTextColor(Consola::BRANCO);
		return false;
}

void GameGraphics::printPista(Pista& pista)
{
	Consola::maximizeWindow();
	Consola::setBackgroundColor(Consola::VERDE_CLARO);
	Consola::clrscr();
	Consola::setBackgroundColor(Consola::PRETO);
	Consola::setScreenSize(9999, pista.getComprimento() + 2);
	for (int i = 2; i < pista.getPistas() + 2; i++) {
		for (int j = 4; j < pista.getComprimento() ; j++) {
			Consola::gotoxy(j, i);
			cout << "_";
		}		
	}
	Consola::setBackgroundColor(Consola::VERDE_CLARO);
	cout << endl;
}

void GameGraphics::printCarros(Pista& pista, vector<Carro*>& carros)
{
	Consola::setBackgroundColor(Consola::AZUL_CLARO);
	Consola::setScreenSize(9000, pista.getComprimento() + 4);
	Consola::gotoxy(4, 2);
	for (auto i = 0; i < pista.getPistas(); i++) {
		try {
			cout << carros.at(i)->getId();
			Consola::gotoxy(4, i + 3);
			carros.at(i)->setPosition(4, i + 3);
		}
		catch (exception e) {

		}
	}
}

void GameGraphics::printGarage(Pista& pista, vector<Carro*>& carros)
{	
	if (carros.size() > pista.getPistas()) {
		Consola::gotoxy(4, 2);
	}
}

void printGarage(Pista& pista, vector<Carro*>& carros) 
{
}




