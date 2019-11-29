#include "GameGraphics.h"

GameGraphics::GameGraphics()
{
	start();
}

void GameGraphics::start()
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
	int sair = -1;
	const int EXIT_POSITION = 21;
	Consola::gotoxy(0, 10);
	do {
		Consola::setBackgroundColor(Consola::PRETO);
		Consola::setTextColor(Consola::BRANCO);
		cout << log.getCommandToken();
		try {
			sair = userConsole.executionCicle();
		}
		catch (const string & log) {
			cout << log << endl;
		}
		catch (exception e) {
			cout << e.what() << endl;
		}
	} while (sair != EXIT_POSITION);
}


