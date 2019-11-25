#pragma once
#include <string>


using namespace std;

class Autodromo
{
private:
	string name;
public:
	Autodromo(string name);
	bool operator == (Autodromo& autodromo);
	void setName(string name);
	string getName();
};

