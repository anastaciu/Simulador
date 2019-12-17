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
		for (Autodromo* a : Simulador.getAutodromos()) {
			cout << a->getAsString();
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
	Consola::gotoxy(0, Simulador.getCampeonato().getAutodromosCampeonato().at(0)->getPista().getPistas() + 25);
	return listaElementos(Simulador);
}

void GameGraphics::printPista(Pista& pista)
{
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	Consola::clrscr();
	Consola::setTextColor(Consola::BRANCO_CLARO);
	Consola::setBackgroundColor(Consola::PRETO);
	Consola::maximizeWindow();
	Consola::setScreenSize(9999, pista.getComprimento() + 2);
	for (int i = 2; i < pista.getPistas() + 2; i++) {
		for (int j = 4; j < 165; j++) {
			Consola::gotoxy(j, i);
			cout << "_";
		}
	}
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	cout << endl;
}

void GameGraphics::printCarros(Autodromo& autodromo)
{
	Consola::setBackgroundColor(Consola::AMARELO);
	Consola::setTextColor(Consola::PRETO);
	for (Carro* c : autodromo.getPista().getCarrosPista()) {
		Consola::gotoxy(static_cast<int>(trunc(c->getXPosition())) + 4,  c->getYPosition() + 2);
 		cout << c->getId();
	}
	for (Carro* c : autodromo.getGaragem().getCarrosGaragem()) {

	}


	//for (int i = 0, j = 0, z = 0, y = 0; i < static_cast<int>(carrosPista.size()); i++) {
	//	if ((&carrosPista.at(i)->getPiloto() != nullptr)) {
	//		if (j < pista.getPistas()) {
	//			Consola::gotoxy(static_cast<int>(trunc(carrosPista.at(i)->getXPosition())) + 4, j + 2);
	//			cout << carrosPista.at(i)->getId();
	//			j++;
	//		}
	//		else {
	//			Consola::gotoxy(4 + z, pista.getPistas() + 6 + y);
	//			cout << carrosPista.at(i)->getId();
	//			z++;
	//		}			
	//	}
	//	else {
	//		Consola::gotoxy(4 + z, pista.getPistas() + 6 + y);
	//		cout << carrosPista.at(i)->getId();
	//		z++;
	//	}
	//	if (z > 75) {
	//		y++;
	//		z = 0;
	//	}
	//}
}

void GameGraphics::printGarage(Autodromo& autodromo)
{

	Consola::setBackgroundColor(Consola::AZUL_CLARO);
	for (int i = 4; i < autodromo.getGaragem().getWidth(); i++)
		for (int j = autodromo.getPista().getPistas() + 6; j < 20 + autodromo.getPista().getPistas(); j++) {
			Consola::gotoxy(i, j);
			cout << " ";
		}
}

void GameGraphics::printAll(Autodromo& autodromo, vector<Carro*>& carros, int* tempo) {

		printPista(autodromo.getPista());
		printGarage(autodromo);
		printCarros(autodromo);
		printTempo(autodromo.getPista().getPistas() + 3, tempo);
	
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
		Consola::gotoxy(90, Simulador.getCampeonato().getAutodromosCampeonato().at(0)->getPista().getPistas() + 6 + i);
		i++;
		commandLineFase2();
	}
	else
		commandLine();

}

void GameGraphics::printLog(string& log, Simulador &Simulador, int& i)
{
	if (Simulador.getSimFase() == 2) {
		Consola::gotoxy(90, Simulador.getCampeonato().getAutodromosCampeonato().at(0)->getPista().getPistas() + 6 + i);
		i++;
	}
	cout << log << endl;
}

void GameGraphics::printTempo(int posY, int *tempo)
{
	if (*tempo > 0) {
		Consola::setBackgroundColor(Consola::VERDE);
		Consola::setTextColor(Consola::BRANCO);
		Consola::gotoxy(4, posY);
		cout << "Tempo: " << *tempo;
		Consola::getch();
	}
}








