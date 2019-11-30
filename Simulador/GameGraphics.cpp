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
		Consola::setTextColor(Consola::VERDE);
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

bool GameGraphics::listaElementosFase2(Campeonato& campeonato) const
{
	Consola::gotoxy(0, campeonato.getAutodromos().at(0).getPista().getPistas() + 40);
	return listaElementos(campeonato);
}

void GameGraphics::printPista(Pista& pista)
{
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	Consola::clrscr();
	Consola::setBackgroundColor(Consola::PRETO);
	Consola::maximizeWindow();
	Consola::setScreenSize(9999, pista.getComprimento() + 2);
	for (int i = 2; i < pista.getPistas() + 2; i++) {
		for (int j = 4; j < pista.getComprimento(); j++) {
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
		if ((&carros.at(i)->getPiloto() != nullptr)) {
			if (j < pista.getPistas()) {
				Consola::gotoxy(4, j + 2);
				cout << carros.at(i)->getId();
				carros.at(i)->setPosition(carros.at(i)->getXPosition(), j + 2);
				j++;
			}
			else {
				Consola::gotoxy(4 + z, pista.getPistas() + 6 + y);
				cout << carros.at(i)->getId();
				z++;
			}			
		}
		else {
			Consola::gotoxy(4 + z, pista.getPistas() + 6 + y);
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
		for (int j = pista.getPistas() + 6; j < 40; j++) {
			Consola::gotoxy(i, j);
			cout << " ";
		}
}

void GameGraphics::printAll(Pista& pista, vector<Carro*>& carros) {
	printPista(pista);
	printGarage(pista, carros);
	printCarros(pista, carros);
}




