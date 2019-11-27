#include "UserConsole.h"
#include "Consola.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <locale>
#include <random>
#include <fstream>
#include <codecvt>
#include <io.h>
#include <fcntl.h>




using namespace std;


int main()
{	
	
	UserConsole user;
	MessageLog log;

	cout << endl << log.getTitle() << endl << endl;

	int sair = -1;
	const int EXIT_POSITION = 21;
	do {	
		Consola::setTextColor(Consola::BRANCO);	
		Consola::setBackgroundColor(Consola::PRETO);
		Consola::setScreenSize(70, 200);
		cout << log.getCommandToken();
		try {
			sair = user.executionCicle();
		}
		catch (const string& log) {
			cout << log << endl;
		} 
		catch(exception e){
			cout << e.what() << endl;
		}
	} while (sair != EXIT_POSITION);

}