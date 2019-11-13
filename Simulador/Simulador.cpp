// Simulador.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Carro.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";
	Carro *carro1 = new Carro(20, 10, "opel");
	Carro *carro2 = new Carro(10, 10, "bmw", "m3");
	Carro* carro3 = new Carro(20, 30, "toyota");
	//Carro* carro4 = new Carro();
	//Carro* carro5 = new Carro();
	//Carro* carro6 = new Carro();
	//Carro* carro7 = new Carro();
	//Carro* carro8 = new Carro();
	cout << carro1->getId() << carro1->getBrand() << carro1->getModel() << carro1->getMaxEnergy() << carro1->getEnergy() << endl;
	cout << carro2->getId() << carro2->getBrand() << carro2->getModel() << carro2->getMaxEnergy() << carro2->getEnergy() << endl;
	cout << carro3->getId() << carro3->getBrand() << carro3->getModel() << carro3->getMaxEnergy() << carro3->getEnergy() << endl;
	//cout << carro4->getId();
	//cout << carro5->getId();
	//cout << carro6->getId();
	//cout << carro7->getId();
	//cout << carro8->getId();
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
