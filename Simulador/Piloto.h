#pragma once
#include <string>

using namespace std;

class Carro;

class Piloto
{
private:
	string name;	
	Carro* carro;

public:	
	Piloto(string name);
	virtual ~Piloto();
	string getName() const;
	void setName(string name);
	Carro& getCarro();
	void setCarro(Carro &carro);
	bool operator== (Piloto* piloto);
};

