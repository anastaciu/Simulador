#pragma once
#include <string>
#include <sstream>


using namespace std;

class Carro;

class Piloto
{
private:
	string name;	
	int pontos, position;
	bool first, last, has_car;
	Carro* carro = nullptr;
public:	
	Piloto(string name);
	virtual ~Piloto();
	string getName() const;
	void setName(string name);
	Carro& getCarro() const;
	void setCarro(Carro *carro);
	bool operator== (Piloto* piloto);
	void addPontos(int pontos);
	int getPontos() const;
	virtual string getAsString() const = 0;
	virtual string getPilotDetais() const = 0;
	int randomIntGenerator(int start, int finish);
	void setPosition(int position, bool first, bool last);
	int getPosition() const;
	bool getLast() const;
	bool getFirst() const;
	void nullifyCarro();
	bool hasCar();

};

