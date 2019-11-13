#pragma once
#include <string>

using namespace std;

class Piloto
{
private:
	string name;

public:
	Piloto(string name);
	string getName() const;
};

