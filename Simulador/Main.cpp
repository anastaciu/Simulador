#include "UserConsole.h"
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

	int x = _setmode(_fileno(stdout), 0x00020000);
	UserConsole user;

	wcout << "         **RACE SIMULATOR**" << endl << endl;

	int sair = 0;
	const int EXIT_POSITION = 21;
	do {
		wcout << "\nComando: ";
		try {
			sair = user.executionCicle();
		}
		catch (const string & log) {
			wcout << log.c_str();
		}
	} while (sair != EXIT_POSITION);

	/*wcout << user.campeonato.getDGV().getCars().at(0)->getBrand().c_str() << user.campeonato.getDGV().getCars().at(0)->getModel().c_str() << user.campeonato.getDGV().getCars().at(0)->getEnergy() << endl;
	wcout << user.campeonato.getDGV().getPilotos().at(0)->getName().c_str() << endl;
	wcout << user.campeonato.getAutodromos().at(0).getName().c_str();*/

	string carros = "carros.txt";
	vector<string>* file = user.getFile(carros);
	for (string str : *file) {

	}

}