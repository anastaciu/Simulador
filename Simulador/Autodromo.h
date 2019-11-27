#pragma once
#include <string>
#include <sstream>


using namespace std;

class Autodromo
{
private:
	string name;
	int pistas, comprimento;
public:
	Autodromo(string name, int pistas, int comprimento);
	bool operator == (Autodromo& autodromo);
	void setName(string name);
	string getName();
	string getAsString() const;
};

