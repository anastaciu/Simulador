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
	bool first, last;
	Carro* carro = nullptr;

protected:
	string tipo;
	int lag, position, prev_position;

public:	
	Piloto(string name);
	virtual ~Piloto();
	virtual string getName() const;
	virtual void setName(string name);
	virtual Carro& getCarro() const;
	virtual void setCarro(Carro *carro);
	virtual bool operator== (Piloto* piloto);
	virtual void addPontos(int pontos);
	virtual int getPontos() const;
	virtual string getAsString() const;
	virtual string getPilotDetais() const;
	virtual string getDriverDetails() const;
	virtual int randomIntGenerator(int start, int finish);
	virtual void setPosition(int position, bool first, bool last);
	virtual int getPosition() const;
	virtual bool getLast() const;
	virtual bool getFirst() const;
	virtual void nullifyCarro();
	virtual void passatempo() = 0;
	virtual void setLag() = 0;
	virtual int getLag();
	virtual bool getCrazyProb() = 0;
	virtual bool getFastProb() = 0;
	virtual bool getSlowProb() = 0;
	virtual Piloto* duplica() const = 0;
	virtual void setPrevPosition();
	virtual string getDriverDetailsClass() const;

};

