// Simulador.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "UserConsole.h"
#include "Carro.h"
#include "Consola.h"
#include "Crazy.h"
#include "DGV.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <locale>
#include <random>




using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	UserConsole user;
	//randomNumberInitializer();


	cout << "         **RACE SIMULATOR**" << endl << endl;

	//int sair = 0;
	//const int EXIT_POSITION = 21;
	//do {
	//	cout << "\nComando: ";
	//	try {
	//		sair = user.executionCicle();
	//	}
	//	catch (const string& log) {
	//		cout << log;
	//	}
	//} while (sair != EXIT_POSITION);

	
	int i = 0, j = 0;
	Consola::setBackgroundColor(Consola::AZUL);
	for (int i = 2; i < 20; i++) {
		for (int j = 10; j < 30; j++) {
			Consola::gotoxy(i, j);
			cout << '_';
		}
	}
	cout << endl;

	Consola::setBackgroundColor(Consola::VERDE);
	Carro *carro1 = new Carro(2, 1, 10, "opel");
	Carro *carro2 = new Carro(3, 10, 10, "bmw", "m3");
	Carro* carro3 = new Carro(4, 20, 30, "toyota");

	cout << carro1->getId() << carro1->getBrand() << carro1->getModel() << carro1->getMaxEnergy() << carro1->getEnergy() << endl;
	cout << carro2->getId() << carro2->getBrand() << carro2->getModel() << carro2->getMaxEnergy() << carro2->getEnergy() << endl;
	cout << carro3->getId() << carro3->getBrand() << carro3->getModel() << carro3->getMaxEnergy() << carro3->getEnergy() << endl;

	DGV* dgv = new DGV();	
	*dgv += *carro1;
	dgv->getCars().push_back(carro2);
	Piloto* piloto = new Crazy("alberto");
	Piloto* piloto2 = new Piloto("alberto");
	Piloto* piloto3 = new Piloto("alberto");
	dgv->addPiloto(piloto);
	dgv->addPiloto(piloto2);
	dgv->addPiloto(piloto3);

	cout << (piloto == piloto2) << endl;


	dgv->getCars().at(0)->setPiloto(*dgv->getPilotos().at(0));
	dgv->getCars().at(0)->setPiloto(*dgv->getPilotos().at(1));

	dgv->getPilotos().at(0)->setCarro(*dgv->getCars().at(0));
	try {
		carro1->manivela(8);
		cout << carro1->getId() << carro1->getBrand() << carro1->getModel() << carro1->getMaxEnergy() << carro1->getEnergy() << endl;
	}
	catch (exception e) {

	}
		
	cout << dgv->getCars().size() << endl;
	cout << dgv->getPilotos().size() << endl;
	cout << dgv->getPilotos().at(0)->getName() << endl;
	cout << dgv->getPilotos().at(1)->getName() << endl;
	cout << dgv->getPilotos().at(2)->getName() << endl;
	//cout << dgv->getCars().at(0)->getPiloto().getName() << endl;
	//cout << dgv->getCars().at(0)->getEnergy() << endl;
	//cout << dgv->getPilotos().at(0)->getCarro().getBrand();
	
}


