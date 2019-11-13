// Simulador.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Carro.h"
#include "Consola.h"
#include "DGV.h"
#include <vector>

using namespace std;

int main()
{
	int i = 0, j = 0;
	Consola::setBackgroundColor(Consola::AZUL);
	for (int i = 2; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			Consola::gotoxy(i, j);
			cout << '_';
		}
	}
	cout << endl;

	Consola::setBackgroundColor(Consola::VERDE);
    cout << "Hello World!\n";
	Piloto *piloto1 = new Piloto("Alberto");
	Piloto* piloto2 = new Piloto("Carlos");
	Carro *carro1 = new Carro(20, 10, "opel");
	Carro *carro2 = new Carro(10, 10, "bmw", "m3");
	Carro* carro3 = new Carro(20, 30, "toyota");
	cout << carro1->getId() << carro1->getBrand() << carro1->getModel() << carro1->getMaxEnergy() << carro1->getEnergy() << endl;
	cout << carro2->getId() << carro2->getBrand() << carro2->getModel() << carro2->getMaxEnergy() << carro2->getEnergy() << endl;
	cout << carro3->getId() << carro3->getBrand() << carro3->getModel() << carro3->getMaxEnergy() << carro3->getEnergy() << endl;

	DGV* dgv = new DGV();
	
	dgv->getCars().push_back(carro1);
	dgv->getCars().push_back(carro2);

	cout << dgv->getCars().size();
	dgv->getCars().at(0)->setPiloto(*piloto1);
	cout << dgv->getCars().at(0)->getPiloto().getName();
	cout << dgv->getCars().at(0)->getEnergy();

	
	
	

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
