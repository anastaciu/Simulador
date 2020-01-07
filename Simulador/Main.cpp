
#include "UserInterface.h"
#include "GameGraphics.h"
#include "Consola.h"

using namespace std;

int main()
{
	GameGraphics graphics;
	do {
		graphics.mainMenu();
		switch (Consola::getch()) {
		case 's':
		case 'S':
			return 0;
		case 'n':
		case 'N':
			Consola::clrscr();
			 UserInterface u;
			u.start();
			break;
		}
	} while (true);
}