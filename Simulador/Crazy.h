#pragma once
#include "Piloto.h"

using namespace std;

class Crazy : public Piloto
{
public:
	Crazy(string name);
	string getAsString() const override;
	string getPilotDetais() const override;
};

