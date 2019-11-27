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

	int sair = 0;
	const int EXIT_POSITION = 21;
	do {
		Consola::setBackgroundColor(Consola::PRETO);
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

	
	try {
		cout << user.getCampeonato().getDGV().getCars().at(0)->getBrand() << " " << user.getCampeonato().getDGV().getCars().at(0)->getModel() << " " << user.getCampeonato().getDGV().getCars().at(0)->getEnergy() << " " << user.getCampeonato().getDGV().getCars().at(0)->getMaxEnergy() << " " << user.getCampeonato().getDGV().getCars().at(0)->getId() << endl;
		cout << user.getCampeonato().getDGV().getCars().at(1)->getBrand() << " " << user.getCampeonato().getDGV().getCars().at(1)->getModel() << " " << user.getCampeonato().getDGV().getCars().at(1)->getEnergy() << " " << user.getCampeonato().getDGV().getCars().at(1)->getMaxEnergy() << " " << user.getCampeonato().getDGV().getCars().at(1)->getId() << endl;
		cout << user.getCampeonato().getDGV().getPilotos().at(0)->getName() << endl;
		cout << user.getCampeonato().getDGV().getPilotos().at(1)->getName() << endl;
		cout << user.getCampeonato().getAutodromos().at(0).getName() << endl;
		cout << user.getCampeonato().getAutodromos().at(1).getName() << endl;
		cout << user.getCampeonato().getAutodromos().at(2).getName() << endl;
	}
	catch (exception e) {

	}
	

	//string carros = "dados/carros.txt";
	//vector<string> file = user.getFile(carros);
	//for (string str : file) {
	//	wcout << str.c_str() << endl;
	//}

}