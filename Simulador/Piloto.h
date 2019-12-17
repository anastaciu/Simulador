#pragma once
#include <string>
#include <sstream>


using namespace std;

class Carro;

class Piloto
{
private:
	string name;	
	int pontos;
	Carro* carro = nullptr;
public:	
	Piloto(string name);
	virtual ~Piloto();
	string getName() const;
	void setName(string name);
	Carro& getCarro() const;
	void setCarro(Carro *carro);
	bool operator== (Piloto* piloto);
	void setPontos(int pontos);
	int getPontos() const;
	virtual string getAsString() const = 0;
	virtual string getPilotDetais() const = 0;

};

