#pragma once
#include <string>
#include <sstream>

using namespace std;

class Carro;

class Piloto
{
private:
	string name;	
	Carro* carro = nullptr;

public:	
	
	Piloto(string name);
	virtual ~Piloto();
	string getName() const;
	void setName(string name);
	Carro& getCarro();
	void setCarro(Carro &carro);
	bool operator== (Piloto* piloto);
	virtual string getAsString() const = 0;
	bool operator!=(Piloto* piloto);
};

